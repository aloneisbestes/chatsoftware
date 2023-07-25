    #ifndef MMBASENETWORK_H
#define MMBASENETWORK_H

#include <QObject>

#include "MMDataBase.h";

class QTcpSocket;

class MMBaseNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MMBaseNetwork(QObject *parent = nullptr);

public slots:
    void slotSendData(QSharedPointer<MMDataBase> data);
    void slotRecvData();
    void slotConnect(const QString &ip, int port, int connectMode=0);   //0: 表示连接，1: 表示切换连接
    void slotReconnect();   // 断线重连

public:
    void setConnectIP(const QString &ip);
    const QString &getConnectIP() const { return m_ip; }

    void setConnectPort(int port) { m_port = port; }
    iint getConnectPort() const { return m_port; }

protected:
    virtual void sendData(QSharedPointer<MMDataBase> data);
    virtual void recvData();

signals:
    void signalRecvData(QSharedPointer<MMDataBase> data);

private:
    QTcpSocket *m_baseSocket;
    QString m_ip;
    int m_port;
};

#endif // MMBASENETWORK_H
