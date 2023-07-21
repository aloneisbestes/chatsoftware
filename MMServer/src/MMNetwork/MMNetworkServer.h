#ifndef __MM_NETWORK_SERVER_H__
#define __MM_NETWORK_SERVER_H__

#include "../MMBase/MMBaseNetwork.h"
#include "../../include/MMCommon.h"

class MMNetworkServer : public MMBaseNetwork {
public:
    MMNetworkServer(int port=-1, int epollMode=MM_EPOLL_IN, const std::string &ip="0.0.0.0");
    ~MMNetworkServer();

    virtual void loop();

private:
    virtual int recvData() override;
    virtual int sendData() override;

private:
    std::shared_ptr<char*> m_buffer;
    int m_len;
    int m_epollfd;  // epollfd
    int m_epollMode;    // epoll模式
};


#endif // __MM_NETWORK_SERVER_H__