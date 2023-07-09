#include "mmsystemglobal.h"
#include <QScreen>
#include <QGuiApplication>

MMSystemGlobal *MMSystemGlobal::__ins=nullptr;

MMSystemGlobal::~MMSystemGlobal()
{

}

MMSystemGlobal *MMSystemGlobal::instance()
{
    if (__ins == nullptr) {
        __ins = new MMSystemGlobal;
    }

    return __ins;
}

MMSystemGlobal::MMSystemGlobal(QObject *parent)
    : QObject{parent}
{
    m_dDefaultWidth=1920.0;
    m_dDfaultHeight=1080.0;
    // 获取主屏幕
    QScreen *screen = QGuiApplication::primaryScreen();
    // 获取屏幕的大小
    QSize screenSize = screen->size();
    m_dWidth=screenSize.width();
    m_dHeight=screenSize.height();
    // 设置宽高缩放比例
    m_dZoomHeight=m_dHeight/m_dDfaultHeight;
    m_dZoomWidth=m_dWidth/m_dDefaultWidth;
    m_dZoom=m_dZoomWidth;   // 默认比例以宽为比例
}
