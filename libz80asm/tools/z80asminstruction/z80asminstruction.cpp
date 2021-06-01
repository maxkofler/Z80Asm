#include "tools/z80asminstruction.h"

Z80AsmInstruction::Z80AsmInstruction(){
    FUN();

    this->_parsed = false;
}

Z80AsmInstruction::~Z80AsmInstruction(){
    FUN();
}