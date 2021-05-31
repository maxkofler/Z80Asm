#include "asm.h"

Asm::Asm(){
    FUN();

    this->_sourceFile = new FileParser();
    this->_labels = new LabelManager();
    this->_lookuptable = new ISTable();

    this->_prog = new uint8_t [UINT16_MAX];
    for (size_t i = 0; i < UINT16_MAX; i++)
        this->_prog[i] = 0;
}

Asm::~Asm(){
    FUN();

    delete this->_sourceFile;
    delete this->_labels;
    delete this->_lookuptable;
}