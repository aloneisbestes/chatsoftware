#ifndef MMCLIENTNETWORK_H
#define MMCLIENTNETWORK_H

#include "mmbasenetwork.h"

class MMClientNetwork : public MMBaseNetwork
{
    Q_OBJECT
public:
    explicit MMClientNetwork(QObject *parent = nullptr);
    ~MMClientNetwork();

    virtual void messageRelay(std::shared_ptr<MMBaseData> data)override;

signals:
    void signalClientNetworkResp(std::shared_ptr<MMBaseData> data);
};

#endif // MMCLIENTNETWORK_H
