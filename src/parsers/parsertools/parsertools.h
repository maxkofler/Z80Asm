#ifndef __PARSERTOOLS_H__
#define __PARSERTOOLS_H__

class ParserTools;

#include <string>

#include "../../log/log.h"
#include "../block/block.h"

class ParserTools{

public:
    /**
     *  Parses a line to a block
     *  @arg    line            The line to parse to a block
     *  @arg    delimiter       The delimiter that splits the blocks
     *  @return                 A Block object containing the parsed block
     **/
    static Block                blockFromLine(std::string line, char delimiter = ';');

    /**
     *  Parses a line of source code to a block
     *  @arg    line            The line to parse from
     *  @return                 A Block object containing the parsed block
     **/
    static Block                blockFromCodeLine(std::string line);

};

#endif