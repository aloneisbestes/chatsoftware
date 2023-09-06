#include "mmclientnetwork.h"

MMClientNetwork::MMClientNetwork(QObject *parent)
    : MMBaseNetwork{"MMClientNetork", parent}
{

}

MMClientNetwork::~MMClientNetwork()
{

}

void MMClientNetwork::messageRelay(QSharedPointer<MMBaseData> data)
{
    MM_STHeader header=data->getMMHeader();

    MMUInt32 cmdType=MM_CommandSet(header.mainCmd,header.subCmd);
    switch (cmdType) {
    case MM_CommandSet(MMMainCmd_Heartbeat_Resp,0):
    {
        // 处理心跳
        handlerHeartbeat(data);
    }
    break;
    default:
    {
        qDebug() << "main cmd or sub cmd is error";
    }
    break;
    }
}
