#include "../block.h"

void Block::append(std::string s){
    FUN();
    
    if (!s.empty()){
        this->_blocks.push_back(s);
    }
}

void Block::append(Block b){
    FUN();

    for (std::string s : b._blocks){
        this->_blocks.push_back(s);
    }
}