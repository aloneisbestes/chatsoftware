#ifndef __MM_NETWORK_CLIENT_H__
#define __MM_NETWORK_CLIENT_H__

#include "../MMBase/MMBaseNetwork.h"
#include <list>

class MMBaseData;

class MMNetworkClient : public MMBaseNetwork {
public:
#ifdef __linux__
    MMNetworkClient(int sockfd, int port, const std::string &ip);
#endif 
    ~MMNetworkClient();

    virtual std::shared_ptr<MMBaseData> recvData() override;
    virtual bool sendData(std::shared_ptr<MMBaseData> data) override;

    void setEpollMode(int epollMode);

    void run();

private:
    int m_epollMode;
    std::list<char> m_buffer;
};

#endif // __MM_NETWORK_CLIENT_H__