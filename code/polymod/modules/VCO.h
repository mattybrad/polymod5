#pragma once
#include "Module.h"

// Module setup:
// SOCKETS
// 0 (in) Freq mod in
// 1 (out) Square wave out
// 2 (out) Saw wave out

class VCO : public Module {
    public:
        VCO();
        enum {FREQ_IN, SQUARE_OUT, SAW_OUT};
    
    private:
};
