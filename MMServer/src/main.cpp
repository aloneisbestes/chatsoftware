#include <stdio.h>
#include "MMNetwork/MMNetworkServer.h"

int main() {
    try
    {
        MMNetworkServer server(10012, MM_EPOLL_ET);
        printf("create MMNetwork Server success.\n");
        printf("start listen---------------------------------------------------\n");
        server.loop();
    }
    catch(const std::exception& e)
    {
        fprintf(stderr, "%s", e.what());
    }

    return 0;
}