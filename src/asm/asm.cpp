#include "asm.h"

Asm::Asm(){
    FUN();

    this->_sourceFile = new FileParser();
}

Asm::~Asm(){
    FUN();

    delete this->_sourceFile;
}