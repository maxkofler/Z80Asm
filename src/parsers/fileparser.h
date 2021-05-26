#ifndef __SOURCE_FILE_PARSER_H__
#define __SOURCE_FILE_PARSER_H__

class FileParser;

#include <fstream>
#include <string>

#include "../log/log.h"

#include "../asm/asm.h"
#include "./block.h"
#include "./parsertools.h"

class FileParser{
public:
    FileParser();
    ~FileParser();

    /**
     *  Parses a source file
     *  @arg    path            The path to the source file
     **/
    size_t                      parseSourceFile(std::string path);


    friend class                Asm;
private:
    std::string                 _pathCurFile;   
    std::ifstream               _curFile;

    std::vector<Block>          _lines;
};

#endif