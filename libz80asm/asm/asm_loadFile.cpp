#include "z80asm.h"

bool Asm::loadSource(std::string file){
    FUN();

    return this->_sourceFile->parseSourceFile(file) > 0;
}