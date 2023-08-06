#ifndef __MM_LOGINHANDLER_H__
#define __MM_LOGINHANDLER_H__

#include "../MMBase/MMBaseHandler.h"
#include "../../MMCommon/include/mmlogindata.h"

class MMHandlerLogin : public MMBaseHandler {
public:
    MMHandlerLogin();
    ~MMHandlerLogin();
    virtual void run()override;

protected:
    void accountLoginReq(); // 用户名密码登录处理
    void QRCodeLoginReq();  // 二维码登录处理
    void logoutReq();   // 退出登录处理
    void accountLoginResp();
    void QRCodeLoginResp();

private:
    std::shared_ptr<MMLoginData> m_loginData;
};

#endif //  __MM_LOGINHANDLER_H__