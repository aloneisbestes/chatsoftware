#ifndef MMDATABASE_H
#define MMDATABASE_H

#include <QJsonObject>
#include "MMProtocol.h"

/* 所有json数据的基类 */

class MMDataBase
{
public:
    MMDataBase(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMDataBase();

    MM_STHeader &header();
    void setHeader(const MM_STHeader &newHeader);

protected:
    // 解析和创建数据
    virtual void parseData()=0;
    virtual void createData()=0;

private:
    MM_STHeader m_header;
};

#endif // MMDATABASE_H
