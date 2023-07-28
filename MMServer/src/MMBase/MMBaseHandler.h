#ifndef __MM_BASEHANDLER_H__
#define __MM_BASEHANDLER_H__

#include "MMBaseData.h"
#include <memory>

class MMBaseHandler {
public:
    MMBaseHandler() {}
    ~MMBaseHandler() {}

    std::shared_ptr<MMBaseData> getHandlerData() { return m_handlerData; }
    void setHandlerData(std::shared_ptr<MMBaseData> data) { m_handlerData=data; }

    virtual void run()=0;

private:
    std::shared_ptr<MMBaseData> m_handlerData;
};

#endif // __MM_BASEHANDLER_H__