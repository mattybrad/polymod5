#include "IO.h"

IO::IO() {
    _sockets[MAIN_AUDIO_IN]->init(VirtualSocket::INPUT);
}