#ifndef __SOURCE_FILE_PARSER_H__
#define __SOURCE_FILE_PARSER_H__

class FileParser;

#include <fstream>
#include <string>

#include "../../log/log.h"

#include "../block/block.h"
#include "../parsertools/parsertools.h"

class FileParser{
public:
    FileParser();
    ~FileParser();

    /**
     *  Parses a source file
     *  @arg    path            The path to the source file
     **/
    size_t                      parseFile(std::string path);

private:
    std::string                 _pathCurFile;   
    std::ifstream               _curFile;

    std::vector<Block>          _blocks;
};

#endif