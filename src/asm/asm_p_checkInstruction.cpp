#include "asm.h"

#include "../tools/instruction.h"

int Asm::p_checkInstruction(Block& curLine, size_t curPos, uint16_t& curAddr){
    FUN();

    Instruction is;

    is.parse(curLine, curPos, curAddr, this->_labels);

    return 1;
}