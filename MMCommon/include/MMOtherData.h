#ifndef __MM_OHTER_DATA_H__
#define __MM_OHTER_DATA_H__

#include "MMBaseData.h"

class MMOtherData : public MMBaseData {
public:
    MMOtherData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMOtherData();

    virtual void setData(const char *data)override;

protected:
    // 创建数据
    virtual void createData()override;
    // 解析数据
    virtual void parseData()override;
};


using MMHeartbeat = MMOtherData;

#endif // __MM_OHTER_DATA_H__
