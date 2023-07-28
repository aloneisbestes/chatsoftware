#include "mmbasenetwork.h"
#include <QTcpSocket>
#include <QTimer>

MMBaseNetwork::MMBaseNetwork(QObject *parent)
    : QObject{parent}
{
    m_baseSocket=nullptr;
    m_sendHeartBeatTimer=nullptr;
    m_port=-1;
    m_heartBeatTimerSecnMcs=-1;
}

MMBaseNetwork::~MMBaseNetwork()
{
    if (m_baseSocket) m_baseSocket->deleteLater();
    if (m_sendHeartBeatTimer) m_sendHeartBeatTimer->deleteLater();
}

void MMBaseNetwork::slotSendData(QSharedPointer<MMBaseData> data)
{
    sendData(data);
}

void MMBaseNetwork::slotRecvData()
{
    recvData();
}

void MMBaseNetwork::slotConnect(const QString &ip, int port, MM_ENTcpConnectMode connectMode)
{
    m_ip=ip;
    m_port=port;

    if (m_sendHeartBeatTimer) {
        m_sendHeartBeatTimer->stop();
        m_heartBeatTimerSecnMcs=-1;
    }

    if (connectMode == MM_ENTcpConnectMode::MMTcpConnectMode_Create) {
        // 创建连接
        if (m_baseSocket) {
            m_baseSocket->deleteLater();
            m_baseSocket=nullptr;
        }
        m_baseSocket=new QTcpSocket();
    }
    else {
        // 切换连接
        m_baseSocket->close();
    }
    m_baseSocket->connectToHost(m_ip, m_port);

    if (m_baseSocket->waitForConnected(3000)) {
        // 连接成功
        m_connectError=MM_ENTcpConnectError::MMTcpConnectError_Success;
        if (m_sendHeartBeatTimer == nullptr) {
            m_sendHeartBeatTimer=new QTimer;
            m_heartBeatTimerSecnMcs=3000;   // 3秒发送一个心跳
            connect(m_sendHeartBeatTimer, &QTimer::timeout, this, &MMBaseNetwork::slotSendHeartbeat);
        }
        m_sendHeartBeatTimer->start(m_heartBeatTimerSecnMcs);
    }
    else {
        // 连接失败
        m_connectError=MM_ENTcpConnectError::MMTcpConnectError_ConnectFialed;
    }
    emit signalTcpConnectStatus(m_connectError);
}

void MMBaseNetwork::slotReconnect()
{

}

void MMBaseNetwork::sendHeartbeat()
{
    // 发送心跳包
}

void MMBaseNetwork::slotSendHeartbeat()
{
    sendHeartbeat();
}
