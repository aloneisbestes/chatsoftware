#include <stdio.h>
#include "MMNetwork/MMNetworkServer.h"

int main() {
    try
    {
        MMNetworkServer server(10012, MM_EPOLL_ET);
        MMPrint("create MMNetwork Server success.\n");
        MMPrint("start listen---------------------------------------------------\n");
        server.loop();
    }
    catch(const std::exception& e)
    {
        MMError("error: %s", e.what());
    }

    return 0;
}