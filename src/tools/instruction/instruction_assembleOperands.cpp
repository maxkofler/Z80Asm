#include "../instruction.h"

bool Instruction::assembleOperands(uint8_t* &prog, uint16_t &curAddr){
    FUN();

    for (auto i : this->_operands){
        LOGD(   "[" + Log::toHexString(curAddr) + "] < " + Log::toHexString(i) +
                " old: " + Log::toHexString(prog[curAddr]));
        prog[curAddr] = i;
        curAddr++;
    }

    return true;
}