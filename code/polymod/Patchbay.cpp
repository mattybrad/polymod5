#include "Patchbay.h"

Patchbay::Patchbay()
{
    
}

void Patchbay::setSocket(int socket, VirtualSocket* virtualSocket)
{
    sockets[socket] = virtualSocket;
}