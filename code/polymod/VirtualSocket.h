#pragma once

class VirtualSocket {
    public:
        VirtualSocket();
        void init(int socketType);
        enum {INPUT, OUTPUT, UNUSED};
        
    protected:
    
    private:
        int _socketType;
    
};
