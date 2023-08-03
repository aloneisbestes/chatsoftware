#ifndef __MM_HANDLERFACTORY_H__
#define __MM_HANDLERFACTORY_H__

#include <memory>
#include "MMProtocol.h"
#include "MMBaseHandler.h"

class MMHandlerFactory{
public:
    static std::shared_ptr<MMBaseHandler> createHandlerData(MMUInt32 mainCmd, MMUInt32 subCmd); 

private:
    MMHandlerFactory()=delete;
    ~MMHandlerFactory(){}
    MMHandlerFactory(const MMHandlerFactory &other)=delete;
    MMHandlerFactory operator=(const MMHandlerFactory &other)=delete;
};

#endif // __MM_HANDLERFACTORY_H__