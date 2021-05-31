#include "z80asm.h"

void Asm::logProg(){
    FUN();

    for(int i = this->_startAddr; i < this->_curAddr; i++){
        LOGD("[" + Log::toHexString(i) + "]: " + Log::toHexString(this->_prog[i]));
    }
}