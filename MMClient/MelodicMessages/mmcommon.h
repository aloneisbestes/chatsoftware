#ifndef MMCOMMON_H
#define MMCOMMON_H

/* 公共头文件 */
#include <QColor>
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
/************************ 外部链接变量 End ************************/


#endif // MMCOMMON_H
