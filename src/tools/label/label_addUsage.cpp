#include "label.h"

void Label::addUsage(uint16_t addr){
    FUN();
    
    this->_usages.push_back(addr);
}