#ifndef __MM_NETWORK_SERVER_H__
#define __MM_NETWORK_SERVER_H__

#include <map>

#include "../MMBase/MMBaseNetwork.h"
#include "../../include/MMCommon.h"
#include "MMNetworkClient.h"
#include "../../include/MMThreadPool.h"

class MMNetworkServer : public MMBaseNetwork {
public:
    MMNetworkServer(int port=-1, int epollMode=MM_EPOLL_IN, const std::string &ip="0.0.0.0");
    ~MMNetworkServer();

    virtual void loop();

private:
    virtual std::shared_ptr<MMBaseData> recvData()override;
    virtual bool sendData(std::shared_ptr<MMBaseData> data)override;

private:
    std::shared_ptr<char*> m_buffer;
    int m_len;
    int m_epollfd;  // epollfd
    int m_epollMode;    // epoll模式
    std::map<int, std::shared_ptr<MMNetworkClient>> m_clientMap;
    MMThreadPool *m_handlerThreadPool;
    int m_handlerThreadSize;
};


#endif // __MM_NETWORK_SERVER_H__