#include "asm.h"

Asm::Asm(){
    FUN();

    this->_sourceFile = new FileParser();
    this->_labels = new LabelManager();
    this->_lookuptable = new ISTable();
}

Asm::~Asm(){
    FUN();

    delete this->_sourceFile;
    delete this->_labels;
    delete this->_lookuptable;
}