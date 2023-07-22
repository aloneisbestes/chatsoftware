#ifndef __MM_LOGINDATA_H__
#define __MM_LOGINDATA_H__

#include "../MMBase/MMBaseData.h"

class MMLoginData : public MMBaseData {
public:
    MMLoginData();
    ~MMLoginData();

protected:
    // 创建json str
    virtual void createJsonstr() override;
    // 解析json str
    virtual void parseJsonstr() override;

private:

};

#endif // __MM_LOGINDATA_H__