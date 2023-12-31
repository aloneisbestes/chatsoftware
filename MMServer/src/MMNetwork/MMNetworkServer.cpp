#ifdef __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif 

#include <cstring>
#include "MMNetworkServer.h"
#include "../../include/MMError.h"
#include "MMNetworkClient.h"
#include "MMBaseHandler.h"
#include "../MMFactory/MMHandlerFactory.h"
#include <unordered_map>

std::unordered_map<int, std::shared_ptr<MMNetworkClient>> __clientMap;

// 线程处理函数
static void threadRun(std::shared_ptr<MMBaseHandler> handler) {
    // DebugPrint("to thread run.");
    handler->run();
}

MMNetworkServer::MMNetworkServer(int port, int epollMode, const std::string &ip)
    : MMBaseNetwork(-1, port, ip)
    , m_epollMode(epollMode)
{
#ifdef __linux__
    // 创建监听套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        throw __MMError_Code[MM_EnumError::MMEnumErrorType_CreateSocketError];
    }

    // 设置套接字复用
    setListenfdReuse(sockfd);

    MMSockaddrIn serverAddrIn;
    serverAddrIn.sin_family = AF_INET;
    serverAddrIn.sin_port=htons(port);
    serverAddrIn.sin_addr.s_addr=INADDR_ANY;

    if (bind(sockfd, (MMSockaddrPtr)&serverAddrIn, MMSOCKADDRIN_LEN) < 0) {
        throw __MMError_Code[MM_EnumError::MMEnumErrorType_BindPortError];
    }

    if (listen(sockfd, MM_LISTEN_MAX) < 0) {
        throw __MMError_Code[MM_EnumError::MMEnumErrorType_CreateListenError];
    }

    setSocketfd(sockfd);

    // 创建epollfd并将监听套接字添加到epoll事件中
    m_epollfd=epoll_create(1);
    if (m_epollfd < 0) {
        throw __MMError_Code[MM_EnumError::MMEnumErrorType_CreateEpollError];
    }

    struct epoll_event event;
    event.events = EPOLLIN; // 指定需要监听的事件类型，例如 EPOLLIN 表示读事件
    /*
    if (m_epollMode == MM_EPOLL_IN) 
        event.events = EPOLLIN; // 指定需要监听的事件类型，例如 EPOLLIN 表示读事件
    else 
        event.events = EPOLLIN;
    */
    event.data.fd = sockfd; // 设置关联的文件描述符

    if (epoll_ctl(m_epollfd, EPOLL_CTL_ADD, sockfd, &event) == -1) {
        throw __MMError_Code[MM_EnumError::MMEnumErrorType_AddEpollfdError];
    }

    // 创建处理线程
    m_handlerThreadSize=4;
    m_handlerThreadPool = new MMThreadPool(m_handlerThreadSize);
#endif 
}

MMNetworkServer::~MMNetworkServer() {
    
}

void MMNetworkServer::loop() {
#ifdef __linux__
    // 开始监听
    int nfds=0;
    struct epoll_event events[MM_EPOLL_MAX];
    int listenfd = getSocketfd();
    socklen_t clientLen=0;
    MMSockaddrIn clientAddrIn;
    std::memset(&clientAddrIn, 0, MMSOCKADDRIN_LEN);
    socklen_t len=MMSOCKADDRIN_LEN;
    int clientfd=-1;
    for (;;) {
        nfds=epoll_wait(m_epollfd, events, MM_EPOLL_MAX, -1);
        if (nfds < 0) {
            continue;
        }

        for (int i = 0; i < nfds; ++i) {
            // 逻辑处理
            if (events[i].data.fd == listenfd) {
                clientLen=len;
                clientfd=accept(listenfd, (MMSockaddrPtr)&clientAddrIn, &clientLen);
                if (clientfd < 0) {
                    MMError("error: %s, %s\n", __MMError_Code[MM_EnumError::MMEnumErrorType_AccpetGetError], strerror(errno));
                    continue;
                }

                MMPrint("ip: %s, port: %d, connect socket fd: %d\n", inet_ntoa(clientAddrIn.sin_addr), ntohs(clientAddrIn.sin_port),
                    clientfd);

                // 根据epoll mode设置socket模式
                if (m_epollMode == MM_EPOLL_ET) {
                    if (setnonblocking(clientfd) == false) {
                        MMError("failed to set a non-blocking socket setting.\n");
                    } 
                } 

                // 添加到epoll监听事件
                if (addEpollEvent(m_epollfd, clientfd, m_epollMode) == true) {
                    // 创建客服端相关信息
                    // ......
                }
                else {
                    MMPrint("description Failed to add an epoll event.\n");
                    MMError("error: %s\n", strerror(errno));
                    // 关闭连接
                    close(clientfd);
                }

                // 添加该客服端对象
                std::shared_ptr<MMNetworkClient> clientSharedPtr(
                    new MMNetworkClient(clientfd, ntohs(clientAddrIn.sin_port), inet_ntoa(clientAddrIn.sin_addr)));
                clientSharedPtr->setEpollfd(m_epollfd);
                clientSharedPtr->setEpollMode(m_epollMode);
                __clientMap[clientfd]=clientSharedPtr;
            } 
            else if ((events[i].events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))) {
                // 关闭套接字
                MMPrint("close a connection with socket %d.\n", events[i].data.fd);
                deleteEpollEvent(m_epollfd, events[i].data.fd);
                close(events[i].data.fd);
            }
            else if (events[i].events & EPOLLIN || events[i].events & EPOLLET) {
                // 数据到达
                int clientfd=events[i].data.fd;
                if (clientfd < 3) {
                    MMPrint("the current file descriptor is the system's standard input, output, and error streams.\n");
                    continue;
                }

                // 查询是否存在这个sockfd的记录
                auto client=__clientMap.find(clientfd);
                if (client == __clientMap.end()) {
                    MMError("client socked fd: %d, not find information.\n", clientfd);
                    continue;
                }
                
                // 读取数据
                auto handlerData=client->second->recvData();
                if (handlerData == nullptr) {
                    MMError("recv from ip: %s, prot: %d, read data failed.\n", 
                        client->second->getIp().c_str(), client->second->getPort());
                    continue;
                }
                MMPrint("recv from ip: %s, port: %d, read data suceess. cmd: %d:%d\n",
                    client->second->getIp().c_str(), client->second->getPort(), 
                    handlerData->getMMHeader().mainCmd, handlerData->getMMHeader().subCmd);

                if (handlerData->getConstData() != nullptr && 
                    handlerData->getMMHeader().messageFormat == (int)MM_ENMessageFormat::MessageFormat_Json) {
                    MMPrint("JSON data: %s\n", handlerData->getConstData());
                }

                // 获取处理类
                auto handler = MMHandlerFactory::createHandlerData(handlerData);

                // 设置处理函数，并且放入线程处理
                if (handler) {
                    handler->setSrcSockfd(clientfd);
                    handler->setHandlerData(handlerData);
                    m_handlerThreadPool->enqueue(threadRun, handler);
                }
                else {
                    MMPrint("handler class is nullptr.\n");
                } 
            }
            else if (events[i].events & EPOLLOUT) {
                // 获取发送的处理类
                if (events[i].data.ptr == nullptr) {
                    MMPrint("handler data is empty.\n");
                    continue;
                }
                MMBaseHandler *handler=reinterpret_cast<MMBaseHandler*>(events[i].data.ptr);
                int sockfd=handler->getDestSockfd();

                if (__clientMap.find(sockfd) == __clientMap.end()) {
                    MMError("this device does not exist and cannot be sent.\n");
                    continue;
                }

                auto handlerClient=__clientMap[sockfd];
                if (handlerClient->sendData(handler->getHandlerData())) {
                    MMPrint("send to ip: %s, port: %d data is success.\n", handlerClient->getIp().c_str(), 
                        handlerClient->getPort());
                }
            }
            else {
                MMError("epoll events is not find.\n");
            }
        }
    }
#endif
}

std::shared_ptr<MMBaseData> MMNetworkServer::recvData() {
    return nullptr;
}

bool MMNetworkServer::sendData(std::shared_ptr<MMBaseData> data) {
    return true;
}