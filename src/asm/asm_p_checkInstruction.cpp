#include "asm.h"

#include "../tools/instruction.h"

int Asm::p_checkInstruction(Block& curLine, size_t curPos, uint16_t& curAddr){
    FUN();

    Instruction is;

    if (is.parse(curLine, curPos, curAddr, this->_labels)){
        lookupIS curIs = this->_lookuptable->lookup(is.getUniformString());
        if (curIs.len > 0){
            for(auto i : curIs.opcode){
                LOGD(   "(instruction)[" + Log::toHexString(curAddr) + "] < " + Log::toHexString(i) +
                        " old: " + Log::toHexString(this->_prog[curAddr]));
                this->_prog[curAddr] = i;
                curAddr++;
            }
            is.assembleOperands(this->_prog, curAddr);
        }else{
            return -1;
        }
    }else{
        //ERROR
        return -1;
    }


    return 1;
}