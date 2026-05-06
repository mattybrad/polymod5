#include "VCO.h"

VCO::VCO()
{
    _name = "VCO";
    _sockets[FREQ_IN].init(VirtualSocket::INPUT, "Freq In");
    _sockets[SQUARE_OUT].init(VirtualSocket::OUTPUT, "Square Out");
    _sockets[SAW_OUT].init(VirtualSocket::OUTPUT, "Saw Out");
}