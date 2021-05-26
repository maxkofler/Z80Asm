#include "block.h"

void Block::append(Block b){
    FUN();

    for (std::string s : b._blocks){
        this->_blocks.push_back(s);
    }
}