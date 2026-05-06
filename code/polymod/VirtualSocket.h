#pragma once

#include "Constants.h"
#include <stdio.h>

class VirtualSocket {
    public:
        VirtualSocket();
        void init(int socketType, const char* name = nullptr);
        void setSource(VirtualSocket* sourceSocket);
        int getType() const;
        const char* getName() const { return _name; }
        int order;
        bool orderIsSet;
        void setOrder(int newOrder);
        enum {INPUT, OUTPUT, UNUSED};
        
    protected:
    
    private:
        int _socketType;
        VirtualSocket* _connectedSourceSocket;
        VirtualSocket* _pseudoSourceSockets[MAX_MODULE_SOCKETS];
        const char* _name;

    
};
