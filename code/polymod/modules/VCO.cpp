#include "VCO.h"

VCO::VCO()
{
    _sockets[FREQ_IN]->init(VirtualSocket::INPUT);
    _sockets[SQUARE_OUT]->init(VirtualSocket::OUTPUT);
    _sockets[SAW_OUT]->init(VirtualSocket::OUTPUT);
}