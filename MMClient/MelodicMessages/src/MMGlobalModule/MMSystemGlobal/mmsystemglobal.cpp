#include "mmsystemglobal.h"
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>
#include <QDir>
#include <QStandardPaths>
#include "mmcommon.h"
#include "mmmessagerelay.h"
#include "mmcommon.h"

MMSystemGlobal *MMSystemGlobal::__ins=nullptr;

MMSystemGlobal::~MMSystemGlobal()
{
    m_fileLog->close();
    if (m_fileLog) delete m_fileLog;
}

MMSystemGlobal *MMSystemGlobal::instance()
{
    if (__ins == nullptr) {
        __ins = new MMSystemGlobal;
    }

    return __ins;
}

void MMSystemGlobal::init()
{
    // 读取配置文件
    QString configFile=m_sConfigPath+"/"+m_sConfigName;
    QFile file(configFile);
    bool isSuccess;
    if (!(isSuccess=file.open(QIODevice::ReadOnly))) {
        Q_ASSERT_X(isSuccess==true, "MMSystemGlobal::init()", "open config file error");
        qCritical() << "Failed to open the configuration file. Procedure.";
    }
    else {
        // 读取配置文件
        m_sConfigJson=file.readAll();
        bool isSuccess;
        m_configRoot=MMBaseDataJson::parseJson(m_sConfigJson.data(), isSuccess);
        if (!isSuccess) {
            qCritical() << "Failed to read the configuration file.";
        }
        else {
            if (m_configRoot.contains("serverIp")) {
                m_sServerIp=m_configRoot["serverIp"].toString();
            }

            if (m_configRoot.contains("serverPort")) {
                m_port=m_configRoot["serverPort"].toInt();
            }
            qInfo() << "The configuration file was read successfully. Procedure.";
        }
    }

    // 初始化消息转发类
    MMMessageRelay::instance();

    // 初始化tcp
    emit MMMessageRelay::instance()->signalConnectClientTcp(m_sServerIp, m_port,
        MM_ENTcpConnectMode::MMTcpConnectMode_Create);
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

    // 获取程序所在路径
    m_sExePath=QCoreApplication::applicationDirPath();
    qDebug() << "m_sExePath: " << m_sExePath;

    m_sHomePath=QDir::homePath();
    qDebug() << "m_sHomePath: " << m_sHomePath;

    m_sLogPath=m_sExePath;
    qDebug() << "m_sLogPath: " << m_sLogPath;

    m_sLogName="MMLog.log";

    // 打开log日志文件
    m_fileLog=new QFile(m_sLogPath+"/"+m_sLogName);
    m_isFileLogOpen=m_fileLog->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    if (m_isFileLogOpen==false) {
        delete m_fileLog;
        m_fileLog=nullptr;
        qDebug() << "Failed to open the log file. The log system is not used.";
    }
    else {
        qDebug() << "The log file is successfully opened, and the log system is used.";
    }

#ifdef MM_DEBUG
    // 配置文件路径
    std::string fullPath=m_sExePath.toStdString();
    m_sConfigPath=fullPath.substr(0, fullPath.find("/build/debug")).c_str();
    m_sConfigPath+="/configuration";
    qDebug() << "m_sConfigPath: " << m_sConfigPath;
#endif // MM_DEBUG

    m_sConfigName="MMConfig.conf";
}
