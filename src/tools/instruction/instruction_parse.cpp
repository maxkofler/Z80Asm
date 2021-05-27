#include "../instruction.h"

bool Instruction::parse(Block& block, size_t pos, uint16_t& curAddr, LabelManager* labels){
    FUN();

    //Clear the internal string
    this->_uniformString = "";

    //The first block is the opcode, directly store it
    this->_uniformString += block.at(pos);

    pos++;

    //Check for a 1. operand
    if (pos < block.length()){
        std::string curBlock = block.at(pos);
        if (!p_parseOP(curBlock, curAddr, labels))
            return false;
    }

    pos++;

    //Check for a 2. operand
    if (pos < block.length()){
        std::string curBlock = block.at(pos);
        if (!p_parseOP(curBlock, curAddr, labels))
            return false;
    }

    LOGD("String to look up: \"" + this->_uniformString + "\", begin of instruction: " + Log::toHexString(curAddr));
    return true;
}