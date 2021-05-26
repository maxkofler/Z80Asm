#include "parsertools.h"

Block ParserTools::blockFromCodeLine(std::string line){
    FUN();

    Block curBlock;
    Block retBlock;
    Block buf;

    //First of all strip all spaces and split into blocks:
    //  LD A, 0xFE  ->  [LD][A,][0xFE]
    //  LD A,0xFE   ->  [LD][A,0xFE]
    buf = ParserTools::blockFromLine(line, ' ');
    if (!buf.empty())
        curBlock.append(buf);
    else
        LOGE("Nothing to parse in this line: \"" + line + "\"");

    //Now strip out the ',':
    //  [LD][A,][0xFE]  ->  [LD][A][0xFE]
    //  [LD][A,0xFE]    ->  [LD][A][0xFE]
    for (size_t i = 0; i < curBlock.length(); i++){
        buf = ParserTools::blockFromLine(line, ',');
        if (!buf.empty())
            retBlock.append(buf);
        else
            LOGE("Nothing to parse in this block: \"" + line + "\"");
    }

    return retBlock;
}