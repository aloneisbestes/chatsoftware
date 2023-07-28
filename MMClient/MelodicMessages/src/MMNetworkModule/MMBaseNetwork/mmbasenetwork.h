    #ifndef MMBASENETWORK_H
#define MMBASENETWORK_H

#include <QObject>

#include "MMBaseData.h"
#include "mmcommon.h"

class QTcpSocket;
class QTimer;

class MMBaseNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MMBaseNetwork(QObject *parent = nullptr);
    ~MMBaseNetwork();

public slots:
    void slotSendData(QSharedPointer<MMBaseData> data);
    void slotRecvData();
    void slotConnect(const QString &ip, int port, MM_ENTcpConnectMode connectMode=MM_ENTcpConnectMode::MMTcpConnectMode_Create);   //0: 表示创建连接，1: 表示切换连接
    void slotReconnect();   // 断线重连

public:
    void setConnectIP(const QString &ip);
    const QString &getConnectIP() const { return m_ip; }

    void setConnectPort(int port) { m_port=port; }
    int getConnectPort() const { return m_port; }

protected:
    virtual void sendData(QSharedPointer<MMBaseData> data)=0;
    virtual void recvData()=0;
    virtual void sendHeartbeat();

protected slots:
    void slotSendHeartbeat();

signals:
    void signalRecvData(QSharedPointer<MMBaseData> data);
    void signalTcpConnectStatus(MM_ENTcpConnectError error);

private:
    QTcpSocket *m_baseSocket;
    QString m_ip;
    int m_port;
    QTimer *m_sendHeartBeatTimer;   // 心跳包发送定时器
    int m_heartBeatTimerSecnMcs;    // 心跳包间隔毫秒
    MM_ENTcpConnectError m_connectError;             // 连接错误信息
};

#endif // MMBASENETWORK_H
