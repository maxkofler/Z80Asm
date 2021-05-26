#include "../instruction.h"

Instruction::Instruction(){
    FUN();

    this->_parsed = false;
}

Instruction::~Instruction(){
    FUN();
}