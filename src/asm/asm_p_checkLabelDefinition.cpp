#include "asm.h"


bool Asm::p_checkLabelDefinition(std::string curBlock, uint16_t curAddr){
    FUN();

    //Check if a label was detected
    if (curBlock.back() == ':'){

        //Push a new label onto the labels stack
        this->_labels.push_back(Label(curBlock.substr(0, curBlock.size()-1), curAddr));

        //Let the debugger know a new label has been defined
        LOGD("Defined label \"" + this->_labels.back().getName() + "\" - address " + Log::toHexString(curAddr));

        //Tell the caller that a label has been found
        return true;
    }

    //No label found
    return false;
}