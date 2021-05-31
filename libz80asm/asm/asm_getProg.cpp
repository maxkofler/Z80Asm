#include "z80asm.h"

std::vector<uint8_t> Asm::getProg(){
    FUN();

    std::vector<uint8_t> prog;

    for (uint16_t i = 0; i < this->_curAddr; i++){
        prog.push_back(this->_prog[i]);
    }

    return prog;
}