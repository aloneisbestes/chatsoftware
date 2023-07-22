#include "MMError.h"

char __MMError_Code[][1024] =
{
    "success.",
    "description failed to create a network socket.",       // 创建socket套接字失败
    "the local address is bound to the port number.",       // 绑定ip端口失败
    "failed to create a listening socket. procedure.",      // 创建监听套接字失败
    "failed to create epollfd.",                            // 创建epollfd失败
    "failed to add the socket to epoll event listening.",    // 将套接字添加到epoll事件监听失败
    "accept, failed to obtain the socket in the listening queue.", // accept，获取监听队列中的套接字失败
};