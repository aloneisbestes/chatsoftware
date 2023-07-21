#include "MMBaseNetwork.h"

#ifdef __linux__
#include <sys/socket.h>
#endif

#ifdef __linux__
MMBaseNetwork::MMBaseNetwork(int sockfd, int port, const std::string &ip) 
    : m_socketfd(sockfd), m_port(port), m_ip(ip)
{

}
#endif 


MMBaseNetwork::~MMBaseNetwork() {

}

int MMBaseNetwork::recvData(char *data, int len, int flags) {
#ifdef __linux__
    return recv(m_socketfd, data, len, flags);
#endif
}

int MMBaseNetwork::sendData(const char *data, int len, int flags) {
#ifdef __linux__
    return send(m_socketfd, data, len, flags);
#endif 
}