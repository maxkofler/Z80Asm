#include "tools/z80asminstruction.h"

void Z80AsmInstruction::push16bHexString(std::string str){
    FUN();

    //Parse the number
    uint16_t num = stoul(str, nullptr, 16);

    //Push the low byte first
    this->_operands.push_back(num);
    LOGD("Pushed " + Log::toHexString(this->_operands.back()) + " to operands stack");
    this->_operands.push_back(num >> 8);
    LOGD("Pushed " + Log::toHexString(this->_operands.back()) + " to operands stack");
}

void Z80AsmInstruction::push8bHexString(std::string str){
    FUN();

    //Parse the number
    uint8_t num = stoul(str, nullptr, 16);

    //Push the low byte first
    this->_operands.push_back(num);
    LOGD("Pushed " + Log::toHexString(this->_operands.back()) + " to operands stack");
}