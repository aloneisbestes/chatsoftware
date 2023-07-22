#include "MMDataFactory.h"
#include "../MMData/MMLoginData.h"

std::shared_ptr<MMBaseData> MMDataFactory::createData(MMInt32 mainCmd, MMInt32 subCmd, std::shared_ptr<char> data=nullptr) {
    std::shared_ptr<MMBaseData> sharedPtr=nullptr;
    switch (mainCmd) {
        case MMMainCmd_Login_Req:
        case MMMainCmd_Login_Resp:
            {
                sharedPtr=std::shared_ptr<MMLoginData>(new MMLoginData);
                break;
            }
            
    }

    return sharedPtr;
}