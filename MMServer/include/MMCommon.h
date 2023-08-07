#ifndef __MM_COMMON_H__
#define __MM_COMMON_H__

#include "../../MMCommon/include/MMProtocol.h"
#include <unordered_map>
#include <memory>
#include "../src/MMNetwork/MMNetworkClient.h"
#include "../../MMCommon/include/MMProtocol.h"

// socket结构体别名
typedef struct sockaddr_in      MMSockaddrIn;
typedef struct sockaddr         MMSockaddr;
typedef struct sockaddr_in *    MMSockaddrInPtr;
typedef struct sockaddr *       MMSockaddrPtr;

#define MMSOCKADDRIN_LEN        sizeof(MMSockaddrIn)
#define MMSOCKADDR_LEN          sizeof(MMSockaddr)

// 设置连接监听队列大小
#define MM_LISTEN_MAX           10

// 设置epoll模式
#define MM_EPOLL_ET             1           // 边缘触发
#define MM_EPOLL_IN             2           // 水平触发

// 设置epoll数组的大小
#define MM_EPOLL_MAX            10

// 宏定义打印时显示的颜色
#define COLOR_NONE  "\033[0m"
#define RED         "\033[1;31m"
#define BLUE        "\033[1;34m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"

// 设置打印宏
#define __MM_DEBUG__
#ifdef __MM_DEBUG__
#include <stdio.h>
// printf("%s to %s line %d: \n", __FILE__, __FUNCTION__, __LINE__);
#define MMPrint(format, ...) do {\
    printf("%s to line %d: \n", __FILE__, __LINE__);\
    printf(GREEN);\
    printf(format, ##__VA_ARGS__);\
    printf(COLOR_NONE);\
}while(0)
#else
#define MMPrintf(format, ...)
#endif // __MM_DEBUG__

// 设置错误宏
#define __MM_ERROR__
#ifdef __MM_ERROR__
#include<stdio.h>
#define MMError(format, ...) do {\
    printf("%s to line %d: \n", __FILE__, __LINE__);\
    printf(RED);\
    printf(format, ##__VA_ARGS__);\
    printf(COLOR_NONE);\
}while(0)
#else
#define MMError(format, ...)
#endif // __MM_ERROR__

// 设置非阻塞
bool setnonblocking(int sockfd);

// 添加epoll事件
bool addEpollEvent(int epollfd, int sockfd, int epollMode);

// 删除epoll事件
void deleteEpollEvent(int epollfd, int sockfd);

// 校验码定义
#define MM_HEADER_CHECK     MMCHECK_VERIFY

// 设置socket监听套接字复用
void setListenfdReuse(int fd);

// 设置MM协议头
void setMMHeader(MM_STHeader &header, MMUInt32 mainCmd, MMUInt32 subCmd, MMUInt8 messageFormat=MessageFormat_Json,
                 MMUInt32 cmdState=0, MMUInt8 messageType=MessageType_Msg, MMUInt32 dataLen=0, MMUInt32 check=MM_HEADER_CHECK);

// 设备存储映射列表
extern std::unordered_map<int, std::shared_ptr<MMNetworkClient>> __clientMap;

// 获取socket是否在设备存储映射列表中
int getSocketfdToClientMap(int sockfd);

// 获取sessionID对应的sockfd
int getSessionIDToClientMap(MMInt64 sessionID);

#endif // __MM_COMMON_H__