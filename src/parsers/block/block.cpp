#include "../block.h"

Block::Block(){
    FUN();
}

Block::~Block(){
    FUN();
}

std::string Block::toString(){
    FUN();
    
    std::string ret = "";

    for (auto i : this->_blocks){
        ret += "[" + i + "]";
    }

    return ret;
}