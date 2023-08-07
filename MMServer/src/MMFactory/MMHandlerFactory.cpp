#include "MMHandlerFactory.h"
#include "MMCommon.h"
#include "../MMHandler/MMLoginHandler.h"

std::shared_ptr<MMBaseHandler> MMHandlerFactory::createHandlerData(MMUInt32 mainCmd, MMUInt32 subCmd) {
    MMUInt32 cmdType=MM_CommandSet(mainCmd, subCmd);
    std::shared_ptr<MMBaseHandler> handler=nullptr;
    switch (cmdType) {
        case MM_CommandSet(MMMainCmd_Heartbeat_Req, 0):
        {
            
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Account):
        {
            handler=std::make_shared<MMHandlerLogin>();
        }
        break;
        default:
        {
            MMPrint("main cmd: %u, sub cmd: %u is not find cmd.\n", mainCmd, subCmd);
        }
        break;
    }
    return handler;
}

std::shared_ptr<MMBaseHandler> MMHandlerFactory::createHandlerData(std::shared_ptr<MMBaseData> data) {
    auto &header=data->getMMHeader();
    std::shared_ptr<MMBaseHandler> handler=createHandlerData(header.mainCmd, header.subCmd);
    if (handler != nullptr)
        handler->setHandlerData(data);
    return handler;
}