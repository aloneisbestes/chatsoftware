#include "MMNetworkClient.h"
#include "MMCommon.h"
#include "../../../MMCommon/include/mmdatafacotry.h"

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
    char *contentBuffer=nullptr;
    std::shared_ptr<MMBaseData> sharedPtrData=nullptr;
    MM_STHeader header;
    recvSize=MMBaseNetwork::recvData(reinterpret_cast<char*>(&header), MMSTHEADER_SIZE, 0);
    if (recvSize < 0) {
        MMError("error: %s\n", strerror(errno));
        return nullptr;
    }

    // 判断头是否正确
    if (recvSize != MMSTHEADER_SIZE || header.check != MM_HEADER_CHECK) {
        if (recvSize != MMSTHEADER_SIZE) {
            MMError("error: recv size is: %d, real size is: %ld.\n", recvSize, MMSTHEADER_SIZE);
        }
        else {
            MMError("error: recv check is: %d, real check is: %d.\n", header.check, MM_HEADER_CHECK);
        }
        return nullptr;
    }

    if (m_epollMode == MM_EPOLL_IN) {   // EPOLLIN
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
        if (header.dataLen != 0) {
            int surplusSize=header.dataLen;
            int recv_bytes=0;
            int realRecvBtyes=0;
            contentBuffer=new char[surplusSize+5];
            memset(contentBuffer, 0, surplusSize+5);
            char *bufferPtr=contentBuffer;
            do {
                recv_bytes = MMBaseNetwork::recvData(bufferPtr+realRecvBtyes, surplusSize);
                if (recv_bytes < 0) {
                    // 如果错误为 EAGAIN 或 EWOULDBLOCK，则表明当前没有数据可读，可以跳出循环
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        continue;
                    } else {
                        MMError("socket: %d, failed read socket fd.\n", getSocketfd());
                        return nullptr;
                    }
                }
                surplusSize-=recv_bytes;
                realRecvBtyes+=recv_bytes;
            } while(surplusSize > 0);
        }
        else {
            MMPrint("No data, just the protocol header\n");
        }
    }

    sharedPtrData=MMDataFacotry::createResponse(header);
    if (contentBuffer != nullptr) {
        sharedPtrData->setData(contentBuffer);
    }

    return sharedPtrData;
}

bool MMNetworkClient::sendData(std::shared_ptr<MMBaseData> data) {

    return true;
}