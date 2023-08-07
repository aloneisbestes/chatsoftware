#include "mmmessagerelay.h"
#include "mmclientnetwork.h"
#include <QThread>

MMMessageRelay *MMMessageRelay::__ins=nullptr;

MMMessageRelay::MMMessageRelay(QObject *parent)
    : QObject{parent}
{
    m_clientTcpThread=new QThread;
    m_clientTcp=new MMClientNetwork;
    m_clientTcp->moveToThread(m_clientTcpThread);
    connect(m_clientTcp, &MMClientNetwork::signalClientNetworkResp,
            this, &MMMessageRelay::slotHandlerClientNetworkResp);
    connect(this, &MMMessageRelay::signalConnectClientTcp, m_clientTcp, &MMClientNetwork::slotConnect);
    connect(this,&MMMessageRelay::signalClientNetworkReq, m_clientTcp,&MMClientNetwork::slotSendData);
    m_clientTcpThread->start();
}

MMMessageRelay::~MMMessageRelay()
{
    m_clientTcpThread->quit();
    m_clientTcpThread->wait();
    if (m_clientTcpThread) delete m_clientTcpThread;
    m_clientTcp->deleteLater();
}

MMMessageRelay *MMMessageRelay::instance()
{
    if (MMMessageRelay::__ins==nullptr) {
        MMMessageRelay::__ins=new MMMessageRelay;
    }

    return MMMessageRelay::__ins;
}

void MMMessageRelay::disInstance()
{
    if (MMMessageRelay::__ins)
        MMMessageRelay::__ins->deleteLater();
    MMMessageRelay::__ins=nullptr;
}

void MMMessageRelay::slotHandlerClientNetworkResp(std::shared_ptr<MMBaseData> data)
{

}
