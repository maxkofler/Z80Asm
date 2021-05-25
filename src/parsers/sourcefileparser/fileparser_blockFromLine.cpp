#include "fileparser.h"

Block FileParser::blockFromLine(std::string line){
    FUN();
    
    Block newBlock;

    size_t pos = 0;
    std::string block;

    while ((pos = line.find(';')) != std::string::npos){
        block = line.substr(0, pos);
        newBlock.append(block);
        line.erase(0, pos + 1);
    }

    return newBlock;
}