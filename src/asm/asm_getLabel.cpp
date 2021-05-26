#include "asm.h"

Label* Asm::getLabel(std::string name){
    FUN();

    for (Label& label : this->_labels){
        if (label.getName() == name)
            return &label;
    }

    LOGE("Could not find label \"" + name + "\"");

    return nullptr;
}