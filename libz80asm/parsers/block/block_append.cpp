#include "parsers/block.h"

void Block::append(std::string s){
    FUN();
    
    if (!s.empty()){

        std::string appString = "";

        for (size_t pos = 0; pos < s.size(); pos++){
            appString += std::toupper(s[pos]);
        }

        this->_blocks.push_back(appString);
    }
}

void Block::append(Block b){
    FUN();

    for (std::string s : b._blocks){
        this->_blocks.push_back(s);
    }
}