#include "asm.h"

bool Asm::link(){
    FUN();

    if (!this->_labels->link())
        return false;

    if (!this->_labels->insertAddrs(this->_prog))
        return false;

    return true;
}