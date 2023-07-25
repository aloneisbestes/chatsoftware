#include "mmcommon.h"
#include <QGraphicsDropShadowEffect>
#include <QWidget>

char __close_icon_path[3][128] = {
    ":/Global/close.png",
    ":/Global/close_hover.png",
    ":/Global/close_pressed.png"
};

void setWindowShadow(QWidget *parent, QWidget *w, QColor color)
{
    // 设置边框背景从父窗口设置
    QGraphicsDropShadowEffect* shadow=new QGraphicsDropShadowEffect(parent);
    shadow->setBlurRadius(10);
    shadow->setColor(color);
    shadow->setOffset(0,0);
    w->setGraphicsEffect(shadow);
}

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
