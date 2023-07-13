#ifndef MMCOMMON_H
#define MMCOMMON_H

/* 公共头文件 */
#include <QColor>
#include "MMProtocol.h"
class QWidget;

/************************ 枚举 Start ************************/
typedef enum tagMMPushButtonState {
    MMPushButtonState_Normal=0,
    MMPushButtonState_Hover,
    MMPushButtonState_Pressed
}MM_PushButtonState;


/************************ 枚举定义 End ************************/

/************************ 外部链接变量 Start ************************/
// close按钮图标的三种状态
extern char __close_icon_path[3][128];
/************************ 外部链接变量 End ************************/


/************************ 公共函数 Start ************************/
// 设置窗口当前的阴影部分
void setWindowShadow(QWidget *parent, QWidget *w, QColor color=QColor(0,0,0,150));

// 设置MM协议头
void setMMHeader(MM_STHeader &header, MMUInt32 mainCmd, MMUInt32 subCmd, MMUInt8 messageFormat=MessageFormat_Json,
                 MMUInt32 cmdState=0, MMUInt8 messageType=MessageType_Msg, MMUInt32 dataLen=0);
/************************ 公共函数 End ************************/


#endif // MMCOMMON_H
