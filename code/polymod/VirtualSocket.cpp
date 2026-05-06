#include "VirtualSocket.h"

VirtualSocket::VirtualSocket()
{
    _socketType = UNUSED;
}

void VirtualSocket::init(int socketType)
{
    _socketType = socketType;
}