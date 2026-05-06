#pragma once

#include "Constants.h"
#include "VirtualSocket.h"

class Patchbay {
    public:
        Patchbay();
        void setSocket(int socket, VirtualSocket* virtualSocket);
        void simulateConnection(int socketA, int socketB);
    
    private:
        VirtualSocket* sockets[MAX_PATCHBAY_SOCKETS];
};