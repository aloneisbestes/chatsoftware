#ifndef MMSYSTEMGLOBAL_H
#define MMSYSTEMGLOBAL_H

#include <QObject>
#include "MMBaseDataJson.h"
#include <QFile>

class MMSystemGlobal : public QObject
{
    Q_OBJECT
public:
    ~MMSystemGlobal();

    static MMSystemGlobal *instance();

    double m_dWidth;
    double m_dHeight;

    double m_dZoomHeight;
    double m_dZoomWidth;
    double m_dZoom;

    double m_dDefaultWidth;
    double m_dDfaultHeight;

    QString m_sExePath;     // 可执行文件路径
    QString m_sHomePath;    // 用户家目录
    QFile *m_fileLog;       // log文件
    bool m_isFileLogOpen;   // 是否打开log日志文件

    int m_port;   // 服务器端口
    QString m_sServerIp;    // 服务器ip

    void init();

private:
    QByteArray m_sConfigJson;   // 配置内容
    MMJson m_configRoot;
    QString m_sLogPath;     // log日志文件路径
    QString m_sLogName;     // log日志文件名
    QString m_sConfigName;  // 配置文件名
    QString m_sConfigPath;   // 配置文件路径

private:
    static MMSystemGlobal *__ins;

private:
    explicit MMSystemGlobal(QObject *parent = nullptr);
};

#endif // MMSYSTEMGLOBAL_H
