#ifndef MMDATAFACOTRY_H
#define MMDATAFACOTRY_H

#include "MMBaseData.h"
#include <QSharedPointer>

class MMDataFacotry
{
public:
    /* 登录 */
    // 创建登录请求
    // static QSharedPointer<MMLoginData> createReqMMLoingData(const MMLoginData &loginData);

    /* 心跳 */
    // 创建心跳请求
    static QSharedPointer<MMBaseData> createHeartbeat();

    /* 创建响应数据 */
    static QSharedPointer<MMBaseData> createResponse(MMUInt32 mainCmd, MMUInt32 subCmd);
    static QSharedPointer<MMBaseData> createResponse(const MM_STHeader &header);

private:
    static QSharedPointer<MMBaseData> createRequest(MMUInt32 mainCmd, MMUInt32 subCmd);
    // static QSharedPointer<MMBaseData> createRequest(MMUInt32 mainCmd, MMUInt32 subCmd);
};

#endif // MMDATAFACOTRY_H
