#ifndef __ASM_H__
#define __ASM_H__

class Asm;

#include <string>
#include <vector>

#include "../log/log.h"
#include "../parsers/fileparser.h"
#include "../tools/label.h"

class Asm{

public:
    Asm();
    ~Asm();

    /**
     *  Loads a file into this assembler, replaces a firstly loaded file
     *  @arg    file                The file to be loaded
     **/
    bool                            loadSource(std::string file);

    /**
     *  Fetches all the labels and notes down their names
     **/
    bool                            fetchLabels();

    /**
     *  Assembles the currently loaded file
     *  make sure to call fetchLabels first
     *  @arg    startAddr           The starting address of the assemble
     **/
    bool                            assemble(uint16_t startAddr);

private:
    FileParser*                     _parser;

    std::vector<Label>              _labels;
};

#endif