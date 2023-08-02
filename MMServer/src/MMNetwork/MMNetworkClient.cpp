#include "MMNetworkClient.h"
#include "MMCommon.h"

#ifdef __linux__


#endif // 

#ifdef __linux__
MMNetworkClient::MMNetworkClient(int sockfd, int port, const std::string &ip) 
    : MMBaseNetwork(sockfd, port, ip)
{

}
#endif // 


MMNetworkClient::~MMNetworkClient() {

}


std::shared_ptr<MMBaseData> MMNetworkClient::recvData() {
    int recvSize=0;
    
    std::shared_ptr<MMBaseData> sharedPtrData=nullptr;
    if (m_epollMode == MM_EPOLL_IN) {   // EPOLLIN
        MM_STHeader header;
        recvSize=MMBaseNetwork::recvData(reinterpret_cast<char*>(&header), MMSTHEADER_SIZE, 0);
        if (recvSize < 0) {
            MMError("error: %s\n", strerror(errno));
            return nullptr;
        }

        // 判断头是否正确
        if (recvSize != MMSTHEADER_SIZE && header.check != MM_HEADER_CHECK) {
            if (recvSize != MMSTHEADER_SIZE) {
                MMError("error: recv size is: %d, real size is: %ld.\n", recvSize, MMSTHEADER_SIZE);
            }
            else {
                MMError("error: recv check is: %d, real check is: %d.\n", header.check, MM_HEADER_CHECK);
            }
            return nullptr;
        }

        // 读取内容
        std::shared_ptr<char> sharedBuffer=nullptr;
        if (header.dataLen != 0) {
            sharedBuffer=std::shared_ptr<char>(new char[header.dataLen+5]);
            recvSize=MMBaseNetwork::recvData(sharedBuffer.get(), header.dataLen, 0);
            if (recvSize != header.dataLen) {
                MMError("error: recv protocol content error. real size: %d, recv size: %d\n", header.dataLen, recvSize);
                return nullptr;
            }
        }
    }
    else {  // EPOLLET

    }

    return sharedPtrData;
}

bool MMNetworkClient::sendData(std::shared_ptr<MMBaseData> data) {

    return true;
}

void MMNetworkClient::run() {
    MMPrint("MMNetwork run: handler client request");
}