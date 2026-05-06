#pragma once

#include "Constants.h"
#include "VirtualSocket.h"
#include <stdio.h>

class Patchbay {
    public:
        Patchbay();
        void setSocket(int socket, VirtualSocket* virtualSocket);
        void simulateConnection(int srcSocket, int destSocket);
        void orderSockets();
    
    private:
        VirtualSocket* _sockets[MAX_PATCHBAY_SOCKETS];
        VirtualSocket* _orderedSockets[MAX_PATCHBAY_SOCKETS];
};