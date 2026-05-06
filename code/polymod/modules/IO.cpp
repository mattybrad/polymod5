#include "IO.h"

IO::IO() {
    _name = "IO";
    _sockets[MAIN_AUDIO_IN].init(VirtualSocket::INPUT, "Main Audio In");
}