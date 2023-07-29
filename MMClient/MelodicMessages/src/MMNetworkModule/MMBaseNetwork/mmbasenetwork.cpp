#include "mmbasenetwork.h"
#include <QTcpSocket>
#include <QTimer>
#include "MMDataFacotry.h"
#include "MMBaseDataJson.h"

MMBaseNetwork::MMBaseNetwork(const QString &tcpName, QObject *parent)
    : QObject{parent}
{
    m_baseSocket=nullptr;
    m_sendHeartBeatTimer=nullptr;
    m_port=-1;
    m_heartBeatTimerSecnMcs=-1;
    m_reconnectTiemr=nullptr;
    m_tcpName=tcpName;
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
        connect(m_baseSocket, &QTcpSocket::disconnected, this, &MMBaseNetwork::slotReconnectHandler);
        connect(m_baseSocket, &QTcpSocket::readyRead, this, &MMBaseNetwork::slotRecvData);
    }
    else {
        // 切换连接
        m_baseSocket->close();
    }
    m_baseSocket->connectToHost(m_ip, m_port);
    waitTcpConnect();
}

void MMBaseNetwork::slotReconnect()
{
    m_reconnectTiemr->stop();
    if (m_baseSocket->state() == QAbstractSocket::UnconnectedState) {
        m_baseSocket->connectToHost(m_ip, m_port);
        waitTcpConnect();
    }
}

void MMBaseNetwork::handlerHeartbeat(QSharedPointer<MMBaseData> data)
{

}

void MMBaseNetwork::sendData(QSharedPointer<MMBaseData> data)
{
    auto &header=data->getMMHeader();
    qint64 sendLen=0;
    if (header.messageType == (MMInt8)MessageFormat_Json) { // json
        // 发送头
        sendLen=m_baseSocket->write(reinterpret_cast<const char *>(&header), MMSTHEADER_SIZE);
        if (sendLen != MMSTHEADER_SIZE) {
            qCritical() << "send header error.";
            return;
        }
        // 发送内容
        QSharedPointer<MMBaseDataJson> dataJson = qSharedPointerCast<MMBaseDataJson>(data);
        sendLen=m_baseSocket->write(dataJson->getJsonstr().c_str(), header.dataLen);
        if (sendLen != header.dataLen) {
            qCritical() << "send content error.";
            return;
        }
        if (header.messageType != MM_ENMessageType::MessageType_Heart) {
            qDebug() << "send content success.";
        }

    }
    else if (header.messageType == (MMInt8)MessageFormat_Binary) {  // binary

    }
    else if (header.messageType == (MMInt8)MessageFormat_None) { // 无数据
        // 发送头
        sendLen=m_baseSocket->write(reinterpret_cast<const char *>(&header), MMSTHEADER_SIZE);
        if (sendLen != MMSTHEADER_SIZE) {
            qCritical() << "send header error.";
            return;
        }
        if ((header.mainCmd != (MMInt32)MMMainCmd_Heartbeat) ||
            (header.mainCmd != (MMInt32)MMMainCmd_Heartbeat_Resp)) {
            qDebug() << "send content success.";
        }
    }
    else {
        qInfo() << "MMBaseNetwork::sendData " << m_tcpName << ": header message type is error";
    }
}

void MMBaseNetwork::recvData()
{
    // 读取头部信息
    MM_STHeader header;
    qint64 recvLen=0;
    QByteArray recvContent;
    QSharedPointer<MMBaseData> resp=nullptr;
    recvLen=m_baseSocket->read(reinterpret_cast<char*>(&header), MMSTHEADER_SIZE);
    if (recvLen == MMSTHEADER_SIZE && header.check == MMCHECK_VERIFY) {
        while (1) {
            recvContent+=m_baseSocket->readAll();
            if (recvContent.size() == header.dataLen) {
                break;
            }
        }

        resp=MMDataFacotry::createResponse(header);
    }
    else {
        qWarning() << "MMBaseNetwork::recvData header check or recv len is error";
    }

    if (resp != nullptr)
        messageRelay(resp);
}

void MMBaseNetwork::sendHeartbeat()
{
    // 发送心跳包
    QSharedPointer<MMBaseData> heartbeat=MMDataFacotry::createHeartbeat();
    slotSendData(heartbeat);
}

void MMBaseNetwork::slotSendHeartbeat()
{
    sendHeartbeat();
}

void MMBaseNetwork::slotReconnectHandler()
{
    // 关闭心跳
    if (m_sendHeartBeatTimer)
        m_sendHeartBeatTimer->stop();

    if (m_reconnectTiemr == nullptr) {
        m_reconnectTiemr=new QTimer;
        m_reconnectTiemrMcs=3000;   // 3秒重连一次
        connect(m_reconnectTiemr, &QTimer::timeout, this, &MMBaseNetwork::slotReconnect);
    }

    m_reconnectTiemr->start(m_reconnectTiemrMcs);
}

void MMBaseNetwork::waitTcpConnect()
{
    if (m_baseSocket->waitForConnected(3000)) {
        // 连接成功
        m_connectError=MM_ENTcpConnectError::MMTcpConnectError_Success;
        if (m_sendHeartBeatTimer == nullptr) {
            m_sendHeartBeatTimer=new QTimer;
            m_heartBeatTimerSecnMcs=3000;   // 3 秒发送一个心跳
            connect(m_sendHeartBeatTimer, &QTimer::timeout, this, &MMBaseNetwork::slotSendHeartbeat);
        }
        m_sendHeartBeatTimer->start(m_heartBeatTimerSecnMcs);
        qDebug() << "connect ip: " << m_ip << " port: " << m_port << " is success";
    }
    else {
        // 连接失败
        m_connectError=MM_ENTcpConnectError::MMTcpConnectError_ConnectFialed;
        qDebug() << "connect ip: " << m_ip << " port: " << m_port << " is failed";
        slotReconnectHandler();
    }
    emit signalTcpConnectStatus(m_connectError);
}
