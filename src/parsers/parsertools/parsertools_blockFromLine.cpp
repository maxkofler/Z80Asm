#include "parsertools.h"

Block ParserTools::blockFromLine(std::string line, char delimiter){
    FUN();
    
    Block newBlock;

    size_t pos = 0;
    std::string block;

    while ((pos = line.find(delimiter)) != std::string::npos){
        block = line.substr(0, pos);
        if (!block.empty())
            newBlock.append(block);
        else
            LOGD("Not appending empty block");
        line.erase(0, pos + 1);
    }

    return newBlock;
}