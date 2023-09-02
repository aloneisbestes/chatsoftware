#ifndef __MM_OHTER_DATA_H__
#define __MM_OHTER_DATA_H__

#include "MMBaseData.h"

class MMOtherData : public MMBaseData {
public:
    MMOtherData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMOtherData();

    virtual void setData(const char *data)override;
    virtual const char *getConstData() const override;
    virtual char *getData()override; 
};

using MMHeartbeat = MMOtherData;

#endif // __MM_OHTER_DATA_H__
