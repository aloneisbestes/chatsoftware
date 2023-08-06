#include "MMCommon.h"
#ifdef __linux__
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#endif // 


#ifdef __linux__
// 设置非阻塞
bool setnonblocking(int sockfd) {
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0)
        return false;
    flags |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, flags) < 0)
        return false;
    return true;
}

bool addEpollEvent(int epollfd, int sockfd, int epollMode) {
    struct epoll_event ev;
    ev.data.fd = sockfd;
    if (epollMode == MM_EPOLL_IN)
        ev.events = EPOLLIN;
    else 
        ev.events = EPOLLET|EPOLLIN;
    ev.events |= EPOLLRDHUP;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) < 0) {
        return false;
    }
    return true;
}

void deleteEpollEvent(int epollfd, int sockfd) {
    epoll_ctl(epollfd, EPOLL_CTL_DEL, sockfd, nullptr);
}

// 设置socket监听套接字复用
void setListenfdReuse(int fd) {
    int flag=1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
}

#endif // 

void setMMHeader(MM_STHeader &header, MMUInt32 mainCmd, MMUInt32 subCmd, MMUInt8 messageFormat,
                 MMUInt32 cmdState, MMUInt8 messageType, MMUInt32 dataLen, MMUInt32 check)
{
    header.mainCmd=mainCmd;
    header.subCmd=subCmd;
    header.messageFormat=messageFormat;
    header.cmdState=cmdState;
    header.messageType=messageType;
    header.dataLen=dataLen;
    header.check=check;
}

int getSocketfdToClientMap(int sockfd) {
    
}

int getSessionIDToClientMap(MMInt64 sessionID) {
    
}