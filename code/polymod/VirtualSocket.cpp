#include "VirtualSocket.h"

VirtualSocket::VirtualSocket()
{
    _socketType = UNUSED;
    order = -1;
    orderIsSet = false;
}

void VirtualSocket::init(int socketType, const char* name)
{
    _socketType = socketType;
    _name = name;
}

int VirtualSocket::getType() const
{
    return _socketType;
}

void VirtualSocket::setSource(VirtualSocket* sourceSocket)
{
    _connectedSourceSocket = sourceSocket;
}

void VirtualSocket::setOrder(int newOrder)
{
    if(orderIsSet) {
        printf("Order already set for socket %s.\n", _name);
        return;
    }
    printf("Setting order of socket %s to %d\n", _name, newOrder);
    order = newOrder;
    orderIsSet = true;
    if(_socketType == INPUT) {
        if(_connectedSourceSocket != nullptr) {
            _connectedSourceSocket->setOrder(newOrder+1);
        }
    } else if(_socketType == OUTPUT) {
        for(int i = 0; i < MAX_MODULE_SOCKETS; i++) {
            if(_pseudoSourceSockets[i] != nullptr) {
                _pseudoSourceSockets[i]->setOrder(newOrder+1);
            }
        }
    }
}