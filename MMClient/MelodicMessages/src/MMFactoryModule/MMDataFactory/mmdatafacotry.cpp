#include "mmdatafacotry.h"
#include "mmcommon.h"

QSharedPointer<MMLoginData> MMDataFacotry::createReqMMLoingData(const MMLoginData &loginData)
{

}

QSharedPointer<MMDataBase> MMDataFacotry::createRequest(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    QSharedPointer<MMDataBase> dataBase=nullptr;
    switch (mainCmd) {
        case MMMainCmd_Login_Req:
        case MMMainCmd_Login_Resp:
        {
            dataBase = QSharedPointer<MMLoginData>(new MMLoginData);
            break;
        }
    }

    setMMHeader(dataBase->header(), mainCmd, subCmd);

    return dataBase;
}

QSharedPointer<MMDataBase> MMDataFacotry::createRequest(MMUInt32 mainCmd, MMUInt32 subCmd, const MMDataBase &dataBase)
{

}
