#ifndef MMLOGINDATA_H
#define MMLOGINDATA_H

#include "MMBaseDataJson.h"

class MMLoginData : public MMBaseDataJson
{
public:
    MMLoginData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMLoginData();

protected:
    // 将子类对象序列化为json数据
    virtual void serializedData()override;

    // 将json数据序列表为子类对象中的数据
    virtual void deserializedData()override;

private:

};

#endif // MMLOGINDATA_H
