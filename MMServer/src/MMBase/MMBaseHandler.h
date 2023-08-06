#ifndef __MM_BASEHANDLER_H__
#define __MM_BASEHANDLER_H__

#include "MMBaseData.h"
#include <memory>

#define MM_HANDLER_VERSION  1

class MMBaseHandler {
private:
    enum MessageRelayType {
        MessageRelayType_Socket=0,      // 通过socket转发
        MessageRelayType_SessionID,      // 通过会话ID查询到对应的socket，然后在转发
    };

public:
    MMBaseHandler() {}
    virtual ~MMBaseHandler() {}

    std::shared_ptr<MMBaseData> getHandlerData() { return m_handlerData; }
    void setHandlerData(std::shared_ptr<MMBaseData> data) { m_handlerData=data; }

    void setRecvSockfd(int sockfd) { m_sockfd=sockfd; }
    int getRecvSockfd() const { return m_sockfd; }

    virtual void run()=0;

protected:
    /**
     *  将消息转发到 指定的 sockfd
     *  type: 标识使用 sessionID 还是直接使用 sockfd
     *  condition: 表示 sessionID or sockfd
     */
    virtual void messageRelaying(std::shared_ptr<MMBaseHandler> *data, MMInt64 condition, MessageRelayType type);

private:
    std::shared_ptr<MMBaseData> m_handlerData;
    int m_sockfd;   // 请求处理的原始socket fd
};

#endif // __MM_BASEHANDLER_H__