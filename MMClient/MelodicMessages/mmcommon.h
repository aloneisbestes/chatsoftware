#ifndef MMCOMMON_H
#define MMCOMMON_H

/* 公共头文件 */
#include <QColor>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "MMProtocol.h"
class QWidget;

/************************ 枚举 Start ************************/
typedef enum tagMMPushButtonState {
    MMPushButtonState_Normal=0,
    MMPushButtonState_Hover,
    MMPushButtonState_Pressed
}MM_PushButtonState;


typedef enum tagMMTcpConnectMode {
    MMTcpConnectMode_Create,    // 创建连接
    MMTcpConnectMode_Change,    // 切换连接
}MM_ENTcpConnectMode;

typedef enum tagMMTcpConnectError {
    MMTcpConnectError_Success=0,        // 用于表示连接成功
    MMTcpConnectError_ConnectFialed,    // 连接失败
    MMTcpConnectError_Accident,         // 意外断开连接
    MMTcpConnectError_Initiative,       // 主动断开连接
}MM_ENTcpConnectError;
/************************ 枚举定义 End ************************/



/************************ 宏定义 Start ************************/
#define MM_HEADER_CHECK 112233
#define MM_DEBUG
/************************ 宏定义 end ************************/



/************************ 外部链接变量 Start ************************/
// close按钮图标的三种状态
extern char __close_icon_path[3][128];
/************************ 外部链接变量 End ************************/




/************************ 公共函数 Start ************************/
// 设置窗口当前的阴影部分
void setWindowShadow(QWidget *parent, QWidget *w, QColor color=QColor(0,0,0,150));

// 设置MM协议头
void setMMHeader(MM_STHeader &header, MMUInt32 mainCmd, MMUInt32 subCmd, MMUInt8 messageFormat=MessageFormat_Json,
                 MMUInt32 cmdState=0, MMUInt8 messageType=MessageType_Msg, MMUInt32 dataLen=0, MMUInt32 check=MM_HEADER_CHECK);

// qt 自定义日志系统
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

// 注册类型
void MMQRegisterMetaType();

// 设置字体大小
void setMMFont(int fontSize, QWidget *widget);

/************************ 公共函数 End ************************/

#endif // MMCOMMON_H
