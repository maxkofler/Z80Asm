#include "../instruction.h"

void Instruction::push16bHexString(std::string str){
    FUN();

    //Parse the number
    uint16_t num = stoul(str, nullptr, 16);

    //Push the low byte first
    this->_operands.push_back(num);
    this->_operands.push_back(num >> 8);
}