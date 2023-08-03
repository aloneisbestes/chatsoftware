#include "MMHandlerFactory.h"
#include "MMCommon.h"

std::shared_ptr<MMBaseHandler> MMHandlerFactory::createHandlerData(MMUInt32 mainCmd, MMUInt32 subCmd) {
    MMUInt32 cmdType=MM_CommandSet(mainCmd, subCmd);
    std::shared_ptr<MMBaseHandler> handler=nullptr;
    switch (cmdType) {
        case MM_CommandSet(MMMainCmd_Heartbeat_Req, 0):
        {
            
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