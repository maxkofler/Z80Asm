#include "z80asm.h"

void Z80Asm::clear(){
    FUN();

    for (size_t i = 0; i < UINT16_MAX; i++)
        this->_prog[i] = 0;

    delete this->_labels;
    this->_labels = new LabelManager();

    delete this->_sourceFile;
    this->_sourceFile = new FileParser();
}