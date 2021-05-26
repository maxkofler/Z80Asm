#include "asm.h"

Asm::Asm(){
    FUN();

    this->_parser = new FileParser();
}

Asm::~Asm(){
    FUN();

    delete this->_parser;
}