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

    // epoll相关信息
    void setEpollMode(int epollMode) { m_epollMode=epollMode; }
    int getEpollMode() const { return m_epollMode; }
    void setEpollfd(int epollfd) { m_epollfd=epollfd; }
    int getEpollfd() const { return m_epollfd; }

    void addEpollOut(int sockfd, void *dataPtr);
    void delEpollOut(int sockfd);

private:
    int m_epollMode;
    int m_epollfd;
    std::list<char> m_buffer;
};

#endif // __MM_NETWORK_CLIENT_H__