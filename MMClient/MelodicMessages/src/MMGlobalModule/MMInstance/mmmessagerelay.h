#ifndef MMMESSAGERELAY_H
#define MMMESSAGERELAY_H

#include <QObject>
#include "MMBaseData.h"
#include "mmcommon.h"

/**
 * @brief The MMMessageRelay class
 * 该类主要用于做消息转发
 */

class QThread;
class MMClientNetwork;

class MMMessageRelay : public QObject
{
    Q_OBJECT
public:
    ~MMMessageRelay();

    static MMMessageRelay *instance();
    static void disInstance();

signals:
    void signalConnectClientTcp(const QString &ip, int port, MM_ENTcpConnectMode connectMode);
    void signalClientNetworkReq(QSharedPointer<MMBaseData> data);

protected slots:
    void slotHandlerClientNetworkResp(QSharedPointer<MMBaseData> data);

private:
    static MMMessageRelay *__ins;

private:
    explicit MMMessageRelay(QObject *parent = nullptr);
    MMMessageRelay(const MMMessageRelay &other)=delete;
    void operator =(const MMMessageRelay &other)=delete;
    QThread *m_clientTcpThread;
    MMClientNetwork *m_clientTcp;
};

#endif // MMMESSAGERELAY_H
