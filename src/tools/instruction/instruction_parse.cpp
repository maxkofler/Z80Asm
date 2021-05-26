#include "../instruction.h"

bool Instruction::parse(Block& block, size_t pos, uint16_t& curAddr, LabelManager* labels){
    FUN();

    //Clear the internal string
    this->_unifiedString = "";

    //The first block is the opcode, directly store it
    this->_unifiedString += block.at(pos);

    curAddr++;
    pos++;

    //Check for a 1. operand
    if (pos < block.length()){
        std::string curBlock = block.at(pos);
        if (!p_parseOP(curBlock, curAddr, labels))
            return false;
    }

    pos++;

    //Check for a 1. operand
    if (pos < block.length()){
        std::string curBlock = block.at(pos);
        if (!p_parseOP(curBlock, curAddr, labels))
            return false;
    }

    curAddr += this->_operands.size();
    LOGD("String to look up: \"" + this->_unifiedString + "\"");

    return true;
}