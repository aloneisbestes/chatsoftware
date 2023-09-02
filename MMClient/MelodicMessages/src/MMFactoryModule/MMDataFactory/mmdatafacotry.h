#ifndef MMDATAFACOTRY_H
#define MMDATAFACOTRY_H

#include "MMBaseData.h"
#include <memory>
#include "mmlogindata.h"

class MMDataFacotry
{
public:
    /* 登录 */
    // 创建登录请求
    static std::shared_ptr<MMLoginData> createReqMMLoingData(std::shared_ptr<MMUserData> userData);

    /* 心跳 */
    // 创建心跳请求
    static std::shared_ptr<MMBaseData> createHeartbeat();

    /* 创建响应数据 */
    static std::shared_ptr<MMBaseData> createResponse(MMUInt32 mainCmd, MMUInt32 subCmd);
    static std::shared_ptr<MMBaseData> createResponse(const MM_STHeader &header);

private:
    static std::shared_ptr<MMBaseData> createRequest(MMUInt32 mainCmd, MMUInt32 subCmd);
    // static QSharedPointer<MMBaseData> createRequest(MMUInt32 mainCmd, MMUInt32 subCmd);
};

#endif // MMDATAFACOTRY_H
