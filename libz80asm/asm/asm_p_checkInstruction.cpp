#include "z80asm.h"

#include "tools/z80asminstruction.h"

int Z80Asm::p_checkInstruction(Block& curLine, size_t curPos, uint16_t& curAddr){
    FUN();

    Z80AsmInstruction is;

    if (is.parse(curLine, curPos, curAddr, this->_labels)){
        lookupIS curIs = this->_lookuptable->lookup(is.getUniformString());
        if (curIs.len > 0){
            for(auto i : curIs.opcode){
                LOGD(   "(instruction)[" + Log::toHexString(curAddr) + "] < " + Log::toHexString(i) +
                        " old: " + Log::toHexString(this->_prog[curAddr]));
                this->_prog[curAddr] = i;
                curAddr++;
            }
            if(!is.assembleOperands(this->_prog, curAddr)){
                return -1;
            }
        }else{
            return -1;
        }
    }else{
        //ERROR
        LOGE("Could not parse Instruction");
        return -1;
    }


    return 1;
}