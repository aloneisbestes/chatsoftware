#ifndef __MM_BASE_NETWORK_H__
#define __MM_BASE_NETWORK_H__

#include <string>
#include <memory>

class MMBaseNetwork {
public:
#ifdef __linux__
    MMBaseNetwork(int sockfd=-1, int port=-1, const std::string &ip="0.0.0.0");
    ~MMBaseNetwork();

    void setSocketfd(int socketfd) { m_socketfd=socketfd; }
    int getSocketfd() const { return m_socketfd; }
#endif

    void setPort(int port) { m_port=port; }
    int getPort() const { return m_port; }

    void setIp(const std::string &ip) { m_ip=ip; }
    const std::string &getIp() const { return m_ip; }

    virtual int recvData()=0;
    virtual int sendData()=0;

protected:
    virtual int recvData(char *data, int len, int flag=0);
    virtual int sendData(const char *data, int len, int flag=0);

protected:
    int m_error;

private:
#ifdef __linux__
    int m_socketfd;
#endif
    int m_port;
    std::string m_ip;
};

#endif // __MM_BASE_NETWORK_H__