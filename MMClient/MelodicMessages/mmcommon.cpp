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
    shadow->setColor(QColor(0,0,0,150));
    shadow->setOffset(0,0);
    w->setGraphicsEffect(shadow);
}
