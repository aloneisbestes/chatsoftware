#ifndef MMDATAFACOTRY_H
#define MMDATAFACOTRY_H

#include "MMDataBase.h"
#include "mmlogindata.h"

class MMDataFacotry
{
public:
    /* 登录 */
    // 创建登录请求
    static QSharedPointer<MMLoginData> createReqMMLoingData(const MMLoginData &loginData);

private:
    static QSharedPointer<MMDataBase> createRequest(MMUInt32 mainCmd, MMUInt32 subCmd);
    static QSharedPointer<MMDataBase> createRequest(MMUInt32 mainCmd, MMUInt32 subCmd, const MMDataBase &dataBase);
};

#endif // MMDATAFACOTRY_H
