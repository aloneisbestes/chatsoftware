#include "mmlogindata.h"

MMLoginData::MMLoginData(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseDataJson(mainCmd, subCmd)
{

}

MMLoginData::~MMLoginData()
{


}

void MMLoginData::serializedData()
{
    auto &header=getMMHeader();
    MMUInt32 cmdType=MM_CommandSet(header.mainCmd, header.subCmd);
    MMJson jsonRoot;
    switch (cmdType) {
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Account):
        {
            // 用户名密码登录
            jsonRoot["account"]=m_userData->m_account.c_str();
            jsonRoot["password"]=m_userData->m_password.c_str();
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_QRCode):
        {
            // 二维码登录
        }
        break;
        case MM_CommandSet(MMMainCmd_Login_Req, MMLoginCmdType_Logout):
        {
            // 退出登录
        }
        break;
    }
    setJsonroot(jsonRoot);
}

void MMLoginData::deserializedData()
{

}
