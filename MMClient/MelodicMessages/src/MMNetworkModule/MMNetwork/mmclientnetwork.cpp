#include "mmclientnetwork.h"

MMClientNetwork::MMClientNetwork(QObject *parent)
    : MMBaseNetwork{"MMClientNetork", parent}
{

}

MMClientNetwork::~MMClientNetwork()
{

}

void MMClientNetwork::messageRelay(std::shared_ptr<MMBaseData> data)
{
    MM_STHeader header=data->getMMHeader();
    switch (header.mainCmd) {
    case MMMainCmd_Heartbeat_Req:
    case MMMainCmd_Heartbeat_Resp:
    {
        // 处理心跳
        handlerHeartbeat(data);
        break;
    }
    default:
        break;
    }
}
