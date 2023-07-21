#ifdef __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#endif 

#include "MMNetworkServer.h"
#include "../../include/MMError.h"

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
    if (m_epollMode == MM_EPOLL_IN) 
        event.events = EPOLLIN; // 指定需要监听的事件类型，例如 EPOLLIN 表示读事件
    else 
        m_epollMode = EPOLLIN | EPOLLET;
    event.data.fd = sockfd; // 设置关联的文件描述符

    if (epoll_ctl(m_epollfd, EPOLL_CTL_ADD, sockfd, &event) == -1) {
        throw __MMError_Code[MM_EnumError::MMEnumErrorType_AddEpollfdError];
    }
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
    for (;;) {
        nfds=epoll_wait(m_epollfd, events, MM_EPOLL_MAX, -1);
        if (nfds < 0) {
            continue;
        }

        for (int i = 0; i < nfds; ++i) {
            // 逻辑处理
            if (events[i].data.fd == listenfd) {

            } 

        }
    }
#endif
}


int MMNetworkServer::recvData() {
    return 0;
}
int MMNetworkServer::sendData() {
    return 0;
}