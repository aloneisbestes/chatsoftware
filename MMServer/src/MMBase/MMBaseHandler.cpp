#include "MMBaseHandler.h"
#include "../../include/MMCommon.h"

void MMBaseHandler::messageRelaying(std::shared_ptr<MMBaseHandler> *data, MMInt64 condition, MessageRelayType type) {
    int sockfd=-1;
    if (type == MessageRelayType::MessageRelayType_SessionID) {
        // 获取sessionID对应的sockfd
        sockfd=getSessionIDToClientMap(condition);
    }
    else {
        sockfd=condition;
    }

    if (sockfd == -1) {
        auto sendClient=__clientMap[m_sockfd];
        MMPrint("messageRelaying func, send ip: %s, prot: %d.\n", sendClient->getIp().c_str(), sendClient->getPort());
        std::string typeName = type == MessageRelayType::MessageRelayType_SessionID ? "sessionID" : "sockfd";
        MMPrint("messageRelaying func, message relay to %s: %ld error.\n", typeName.c_str(), condition);
        return ;
    }

    auto relayClient=__clientMap[sockfd];
    relayClient->addEpollOut(sockfd, static_cast<void*>(data));
}