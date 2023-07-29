#include "mmdatafacotry.h"
#include "MMOtherData.h"
#include <QDebug>

QSharedPointer<MMBaseData> MMDataFacotry::createRequest(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    QSharedPointer<MMBaseData> sharedptr=nullptr;
    switch (mainCmd) {
    case MMMainCmd_Heartbeat:
    case MMMainCmd_Heartbeat_Resp: {
        sharedptr=QSharedPointer<MMBaseData>(new MMOtherData(mainCmd, subCmd));
        sharedptr->getMMHeader().messageType=MM_ENMessageType::MessageType_Heart;
        sharedptr->getMMHeader().messageFormat=MM_ENMessageFormat::MessageFormat_None;
        break;
    }
    default:
    {
        qDebug() << "MMMainCmd is error";
        break;
    }
    }

    return sharedptr;
}


QSharedPointer<MMBaseData> MMDataFacotry::createHeartbeat()
{
    return createRequest(MMMainCmd_Heartbeat, 0);
}

QSharedPointer<MMBaseData> MMDataFacotry::createResponse(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    return MMDataFacotry::createRequest(mainCmd, subCmd);
}

QSharedPointer<MMBaseData> MMDataFacotry::createResponse(const MM_STHeader &header)
{
    QSharedPointer<MMBaseData> sharePtr=MMDataFacotry::createRequest(header.mainCmd, header.subCmd);
    sharePtr->setMMHeader(header);
    return sharePtr;
}
