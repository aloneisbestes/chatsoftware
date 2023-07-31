#include "mmdatafacotry.h"
#include "MMOtherData.h"

std::shared_ptr<MMBaseData> MMDataFacotry::createRequest(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    std::shared_ptr<MMBaseData> sharedptr=nullptr;
    switch (mainCmd) {
    case MMMainCmd_Heartbeat_Req:
    case MMMainCmd_Heartbeat_Resp: {
        sharedptr=std::make_shared<MMHeartbeat>(mainCmd, subCmd);
        //sharedptr->getMMHeader().messageType=MM_ENMessageType::MessageType_Heart;
        //sharedptr->getMMHeader().messageFormat=MM_ENMessageFormat::MessageFormat_None;
        break;
    }
    default:
    {
        break;
    }
    }

    return sharedptr;
}


std::shared_ptr<MMBaseData> MMDataFacotry::createHeartbeat()
{
    return createRequest(MMMainCmd_Heartbeat_Req, 0);
}

std::shared_ptr<MMBaseData> MMDataFacotry::createResponse(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    return MMDataFacotry::createRequest(mainCmd, subCmd);
}

std::shared_ptr<MMBaseData> MMDataFacotry::createResponse(const MM_STHeader &header)
{
    std::shared_ptr<MMBaseData> sharePtr=MMDataFacotry::createRequest(header.mainCmd, header.subCmd);
    sharePtr->setMMHeader(header);
    return sharePtr;
}
