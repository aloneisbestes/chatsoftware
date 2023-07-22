#ifndef __MM_DATA_FACTORY_H__
#define __MM_DATA_FACTORY_H__

#include "../MMBase/MMBaseData.h"
#include "../../include/MMProtocol.h"

class MMDataFactory {
public:
    static std::shared_ptr<MMBaseData> createData(MMInt32 mainCmd, MMInt32 subCmd, std::shared_ptr<char> data=nullptr);
};

#endif // __MM_DATA_FACTORY_H__