#include "MMLoginHandler.h"
#include "../../include/MMCommon.h"
#include "../../MMCommon/include/MMProtocol.h"

MMHandlerLogin::MMHandlerLogin() 
    : MMBaseHandler()
{

}
MMHandlerLogin::~MMHandlerLogin() 
{

}

void MMHandlerLogin::run() {
    MMPrint("MMHandler login run\n");
    m_loginData=std::dynamic_pointer_cast<MMLoginData>(getHandlerData());
    if (m_loginData == nullptr) {
        MMPrint("std::shared_ptr<MMBaseData> pointer transition std::shared_ptr<MMLoginData> error, \
            The conversion type does not match\n");
        // 错误处理
        return;
    }

    auto &header=m_loginData->getMMHeader();
    MMUInt32 cmdType=MM_CommandSet(header.mainCmd, header.subCmd);
    switch (cmdType) {
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Account):
        {
            accountLoginReq();
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_QRCode):
        {
            QRCodeLoginReq();
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Logout):
        {
            logoutReq();
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Resp, MMLoginCmdType_Account):
        {
            accountLoginResp();
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Resp, MMLoginCmdType_QRCode):
        {
            QRCodeLoginResp();
        }
        break;
        default:
        {
            MMPrint("MMHandlerLogin::run mainCmd: %u, subCmd: %u\n", header.mainCmd, header.subCmd);
        } 
        break;
    }
}

void MMHandlerLogin::accountLoginReq() {

}

void MMHandlerLogin::QRCodeLoginReq() {

}

void MMHandlerLogin::logoutReq() {

}

void MMHandlerLogin::accountLoginResp() {

}

void MMHandlerLogin::QRCodeLoginResp() {

}