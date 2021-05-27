#include "../label.h"

bool Label::applyUsages(uint8_t* &prog){
    FUN();

    for (auto usage : this->_usages){
        prog[usage] = this->_address;
        prog[usage+1] = this->_address >> 8;
    }

    return true;
}