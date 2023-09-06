#include "mmdatafacotry.h"
#include "MMOtherData.h"
#include "mmlogindata.h"
#include "mmcommon.h"

QSharedPointer<MMBaseData> MMDataFacotry::createRequest(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    QSharedPointer<MMBaseData> sharedptr=nullptr;
    MM_ENMessageFormat messageFormat=MM_ENMessageFormat::MessageFormat_Json;
    MMUInt32 cmdType=MM_CommandSet(mainCmd, subCmd);
    switch (cmdType) {
        // 心跳
        case MM_CommandSet(MMMainCmd_Heartbeat_Req, MMHeartbeatCmdType_None):
        case MM_CommandSet(MMMainCmd_Heartbeat_Resp, MMHeartbeatCmdType_None):
        {
            sharedptr=QSharedPointer<MMHeartbeat>(new MMHeartbeat(mainCmd, subCmd));
            sharedptr->getMMHeader().messageType=MM_ENMessageType::MessageType_Heart;
            sharedptr->getMMHeader().messageFormat=MM_ENMessageFormat::MessageFormat_None;
        }
        break;
        // 登录信息
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Account):
        {
            sharedptr=QSharedPointer<MMLoginData>(new MMLoginData(mainCmd,subCmd));
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


QSharedPointer<MMLoginData> MMDataFacotry::createReqMMLoingData(const MMUserData& userData)
{
    auto baseData=MMDataFacotry::createRequest(MMMainCmd_Login_Req, MMLoginCmdType_Account);
    QSharedPointer<MMLoginData> loginData=qSharedPointerDynamicCast<MMLoginData>(baseData);
    loginData->setMMUserData(userData);
    return loginData;
}

QSharedPointer<MMBaseData> MMDataFacotry::createHeartbeat()
{
    return createRequest(MMMainCmd_Heartbeat_Req, 0);
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
