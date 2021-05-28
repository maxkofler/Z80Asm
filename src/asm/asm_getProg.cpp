#include "asm.h"

std::vector<uint8_t> Asm::getProg(){
    FUN();

    std::vector<uint8_t> prog;

    for (uint16_t i = 0; i < this->_curAddr; i++){
        prog.push_back(this->_prog[i]);
    }

    //Push a HALT for security reasons
    prog.push_back(0x76);

    return prog;
}