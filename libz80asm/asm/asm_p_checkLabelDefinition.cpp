#include "z80asm.h"


bool Asm::p_checkLabelDefinition(std::string curBlock, uint16_t curAddr){
    FUN();

    //Check if a label was detected
    if (curBlock.back() == ':'){

        //Push a new label onto the labels stack
        this->_labels->defineLabel(curBlock.substr(0, curBlock.size()-1), curAddr);

        //Tell the caller that a label has been found
        return true;
    }

    //No label found
    return false;
}