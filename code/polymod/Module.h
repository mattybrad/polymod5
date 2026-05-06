#pragma once

#include "Constants.h"
#include "VirtualSocket.h"

class Module {
    public:
        Module();
        VirtualSocket* getSocket(int socket) { return &_sockets[socket]; }
        
    protected:
        VirtualSocket _sockets[MAX_MODULE_SOCKETS];
        const char* _name;
    
    private:
    
};
