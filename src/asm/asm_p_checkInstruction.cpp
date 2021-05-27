#include "asm.h"

#include "../tools/instruction.h"

int Asm::p_checkInstruction(Block& curLine, size_t curPos, uint16_t& curAddr){
    FUN();

    Instruction is;

    if (is.parse(curLine, curPos, curAddr, this->_labels)){
        curAddr++;
        curAddr += is.getOpCount();
        lookupIS curIs = this->_lookuptable->lookup(is.getUniformString());
        if (curIs.len > 0){
            LOGD("Assembling instruction...");
        }else{
            return -1;
        }
    }else{
        //ERROR
        return -1;
    }


    return 1;
}