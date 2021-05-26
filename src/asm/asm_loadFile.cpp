#include "asm.h"

bool Asm::loadSource(std::string file){
    FUN();

    return this->_parser->parseSourceFile(file) > 0;
}