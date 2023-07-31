#include "mmcommon.h"
#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include "mmsystemglobal.h"
#include <QDateTime>
#include <QFont>
#include <MMBaseData.h>

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

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context)
    // QString logFileName = "application.log";
    QTextStream textStream(MMSystemGlobal::instance()->m_fileLog);
    // 获取当前时间
    QDateTime currentDateTime = QDateTime::currentDateTime();
    // 格式化时间为 "yy-MM-dd hh:mm:ss" 的字符串
    QString formattedTime = currentDateTime.toString("yy-MM-dd hh:mm:ss");
    switch ((int)type)
    {
    /*case QtDebugMsg:
        qDebug() << msg;
        break;*/
    case QtInfoMsg:
        textStream << formattedTime << " [Info]: " << msg << "\n";
        break;
    case QtWarningMsg:
        textStream << formattedTime << " [Warning]: " << msg << "\n";
        break;
    case QtCriticalMsg:
        textStream << formattedTime << " [Critical]: " << msg << "\n";
        break;
    case QtFatalMsg:
        textStream << formattedTime << " [Fatal]: " << msg << "\n";
        break;
    }
}

void MMQRegisterMetaType()
{
    qRegisterMetaType<MM_ENTcpConnectMode>("MM_ENTcpConnectMode");
    qRegisterMetaType<std::shared_ptr<MMBaseData>>("std::shared_ptr<MMBaseData>");
}

void setMMFont(int fontSize, QWidget *widget)
{
    static double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    static QFont tmpFont(MMSystemGlobal::instance()->m_fontFamily);

    tmpFont.setPixelSize(fontSize*zoomWidth);
    widget->setFont(tmpFont);
}
