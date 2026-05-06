#include "Patchbay.h"

Patchbay::Patchbay()
{
    for(int i = 0; i < MAX_PATCHBAY_SOCKETS; i++) {
        _sockets[i] = nullptr;
    }
}

void Patchbay::setSocket(int socket, VirtualSocket* virtualSocket)
{
    printf("Setting patchbay socket %d to %s\n", socket, virtualSocket ? virtualSocket->getName() : "nullptr");
    _sockets[socket] = virtualSocket;
}

void Patchbay::simulateConnection(int srcSocket, int destSocket)
{
    if (_sockets[srcSocket] == nullptr) {
        printf("Source socket %d is not connected.\n", srcSocket);
        return;
    }
    if (_sockets[destSocket] == nullptr) {
        printf("Destination socket %d is not connected.\n", destSocket);
        return;
    }
    if (_sockets[srcSocket]->getType() != VirtualSocket::OUTPUT) {
        printf("Source socket %d is not an output.\n", srcSocket);
        return;
    }
    if (_sockets[destSocket]->getType() != VirtualSocket::INPUT) {
        printf("Destination socket %d is not an input.\n", destSocket);
        return;
    }

    _sockets[destSocket]->setSource(_sockets[srcSocket]);
}

void Patchbay::orderSockets() {
    for(int i = 0; i < MAX_PATCHBAY_SOCKETS; i++) {
        _orderedSockets[i] = nullptr;
    }
    
    int orderIndex = 0; // this number is HIGHEST at end of signal chain (opposite of how order is set in VirtualSocket::setOrder)

	for (int i = MAX_PATCHBAY_SOCKETS - 1; i >= 0; i--)
	{
		// for each socket...
		for (int j = 0; j < MAX_PATCHBAY_SOCKETS; j++)
		{
			if (_sockets[j] != nullptr && _sockets[j]->order == i)
			{
				_orderedSockets[orderIndex] = _sockets[j];
				orderIndex++;
			}
		}
	}

    for(int i = 0; i < MAX_PATCHBAY_SOCKETS; i++) {
        if(_orderedSockets[i] != nullptr) {
            printf("Ordered socket %d: %s (order %d)\n", i, _orderedSockets[i]->getName(), _orderedSockets[i]->order);
        }
    }
}