#ifndef __MM_HANDLERFACTORY_H__
#define __MM_HANDLERFACTORY_H__

#include <memory>
#include "MMProtocol.h"
#include "MMBaseHandler.h"
#include "../../MMCommon/include/MMBaseData.h"

class MMHandlerFactory{
public:
    static std::shared_ptr<MMBaseHandler> createHandlerData(MMUInt32 mainCmd, MMUInt32 subCmd); 
    static std::shared_ptr<MMBaseHandler> createHandlerData(std::shared_ptr<MMBaseData> data);

private:
    MMHandlerFactory()=delete;
    ~MMHandlerFactory(){}
    MMHandlerFactory(const MMHandlerFactory &other)=delete;
    MMHandlerFactory operator=(const MMHandlerFactory &other)=delete;
};

#endif // __MM_HANDLERFACTORY_H__