#include <stdio.h>
#include "MMNetwork/MMNetworkServer.h"

int main() {
    MMNetworkServer *server=nullptr;
    try
    {
        server = new MMNetworkServer(10000, MM_EPOLL_ET);
        MMPrint("create MMNetwork Server success.\n");
        MMPrint("start listen---------------------------------------------------\n");
    }
    catch(const std::exception& e)
    {
        MMError("error: %s", e.what());
        server=nullptr;
    }

    if (server == nullptr)
        return -1;
    server->loop();

    return 0;
}