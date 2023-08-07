#include "mmdatafacotry.h"
#include "MMOtherData.h"
#include "mmlogindata.h"
#include "mmcommon.h"

std::shared_ptr<MMBaseData> MMDataFacotry::createRequest(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    std::shared_ptr<MMBaseData> sharedptr=nullptr;
    MM_ENMessageFormat messageFormat=MM_ENMessageFormat::MessageFormat_Json;
    MMUInt32 cmdType=MM_CommandSet(mainCmd, subCmd);
    switch (cmdType) {
        // 心跳
        case MM_CommandSet(MMMainCmd_Heartbeat_Req, MMHeartbeatCmdType_None):
        case MM_CommandSet(MMMainCmd_Heartbeat_Resp, MMHeartbeatCmdType_None):
        {
            sharedptr=std::make_shared<MMHeartbeat>(mainCmd, subCmd);
            sharedptr->getMMHeader().messageType=MM_ENMessageType::MessageType_Heart;
            sharedptr->getMMHeader().messageFormat=MM_ENMessageFormat::MessageFormat_None;
        }
        break;
        // 登录信息
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Account):
        {
            sharedptr=std::make_shared<MMLoginData>(mainCmd, subCmd);
        }
        break;
        default:
        {
            break;
        }
    }

    setMMHeader(sharedptr->getMMHeader(), mainCmd, subCmd, messageFormat);
    return sharedptr;
}


std::shared_ptr<MMLoginData> MMDataFacotry::createReqMMLoingData(std::shared_ptr<MMUserData> userData)
{
    auto baseData=MMDataFacotry::createRequest(MMMainCmd_Login_Req, MMLoginCmdType_Account);
    std::shared_ptr<MMLoginData> loginData=std::dynamic_pointer_cast<MMLoginData>(baseData);
    loginData->setMMUserData(userData);
    return loginData;
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
