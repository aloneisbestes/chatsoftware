#ifndef MMPROTOCOL_H
#define MMPROTOCOL_H

/******************** 类型定义 Start ********************/
typedef unsigned int        MMUInt32;
typedef int                 MMInt32;
typedef long long           MMInt64;
typedef char                MMInt8;
typedef unsigned char       MMUInt8;
typedef short               MMInt16;
typedef unsigned short      MMUInt16;
/******************** 类型定义 End ********************/




/********************* 协议头 Start *********************/
typedef struct _st_MMHeader
{
    MMInt32         check;          // 校验码
    MMInt32         mainCmd;        // 主命令码
    MMInt32         subCmd;         // 子命令码
    MMInt8          messageType;    // 消息类型，0: 消息    1: 心跳
    MMInt8          messageFormat;  // 消息格式，0: json    1: 二进制
    MMInt32         cmdState;       // 命令状态
    MMInt32         dataLen;        // 数据长度
}MM_STHeader;

#define MMSTHEADER_SIZE     sizeof(MM_STHeader)
/********************* 协议头 End *********************/




/********************* 主命令码 Start *********************/
#define CMD_RESPONSE_NUM    100000
typedef enum _en_MMMainCmd
{
    MMMainCmd_None=-1,              // 无命令码
    MMMainCmd_Login_Req=1,          // 登录主命令请求


    MMMainCmd_Login_Resp=MMMainCmd_Login_Req+CMD_RESPONSE_NUM,  //  响应主命令登录
}MM_ENMainCmd;
/********************* 主命令码 End *********************/




/********************* 子命令码 Start *********************/
typedef enum _en_LoginCmd
{
    LoginCmd_None=-1,
    LoginCmd_Account=0,     // 用户名登录
    LoginCmd_Out,           // 退出登录
}MM_ENLoginCmd;
/********************* 子命令码 End *********************/




/********************* 类型定义 Start *********************/
// 定义数据类型
typedef enum _en_MessageType
{
    MessageType_None=-1,
    MessageType_Msg=0,          // 消息
    MessageType_Heart,          // 心跳
}MM_ENMessageType;

// 定义数据格式
typedef enum _en_MessageFormat
{
    MessageFormat_None=-1,
    MessageFormat_Json=0,          // json
    MessageFormat_Binary,          // 二进制
}MM_ENMessageFormat;
/********************* 类型定义 End *********************/

#endif // MMPROTOCOL_H
