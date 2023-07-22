#ifndef __MM_ERROR_H__
#define __MM_ERROR_H__

// 错误码
typedef enum tagMMEnumErrorType {
    MMEnumErrorType_Success=0,                          // 成功
    MMEnumErrorType_CreateSocketError,                  // 创建socket套接字失败
    MMEnumErrorType_BindPortError,                      // 绑定端口失败
    MMEnumErrorType_CreateListenError,                  // 创建监听套接字失败
    MMEnumErrorType_CreateEpollError,                   // 创建epollfd失败
    MMEnumErrorType_AddEpollfdError,                    // 添加到epollfd事件中失败
    MMEnumErrorType_AccpetGetError,                     // 获取队列中的套接字失败
}MM_EnumError;

// 错误码对应的错误提示
extern char __MMError_Code[][1024];

#endif // __MM_ERROR_H__