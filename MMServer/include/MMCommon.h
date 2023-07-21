#ifndef __MM_COMMON_H__
#define __MM_COMMON_H__

// socket结构体别名
typedef struct sockaddr_in      MMSockaddrIn;
typedef struct sockaddr         MMSockaddr;
typedef struct sockaddr_in *    MMSockaddrInPtr;
typedef struct sockaddr *       MMSockaddrPtr;

#define MMSOCKADDRIN_LEN        sizeof(MMSockaddrIn)
#define MMSOCKADDR              sizeof(MMSockaddr)

// 设置连接监听队列大小
#define MM_LISTEN_MAX           10

// 设置epoll模式
#define MM_EPOLL_ET             1           // 边缘触发
#define MM_EPOLL_IN             2           // 水平触发

// 设置epoll数组的大小
#define MM_EPOLL_MAX            10

#endif // __MM_COMMON_H__