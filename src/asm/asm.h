#ifndef __ASM_H__
#define __ASM_H__

class Asm;

#include <string>
#include <vector>

#include "../log/log.h"
#include "../parsers/fileparser.h"
#include "../tools/label.h"
#include "../parsers/block.h"

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
     *  Assembles the currently loaded file
     *  make sure to call fetchLabels first
     *  @arg    startAddr           The starting address of the assemble
     **/
    bool                            assemble(uint16_t startAddr);

    /**
     *  Get a pointer to the specified label
     *  @arg    name                The name to search for
     **/
    Label*                          getLabel(std::string name);

private:
    FileParser*                     _sourceFile;

    std::vector<Label>              _labels;

    /**
     *  assemble()  Check if the current block is a label definition and insert the current address
     *  @arg    curBlock            The block to check
     *  @arg    curAddr             The current address
     **/
    bool                            p_checkLabelDefinition(std::string curBlock, uint16_t curAddr);

    /**
     *  assemble()  Check for an instruction and assemble it if needed
     *  @arg    curLine             The line to process 
     *  @arg    curPos              The current position in the line to check from this position on
     *  @arg    curAddr             A reference to the current Address, needed to assemble the instruction
     *  
     *  @return                     0   nothing to assemble
     *                              1   assembled ok
     * 
     *                              -1  invalid instruction
     *                              -2  undefined reference to a label (label not found)
     **/
    int                             p_checkInstruction(Block& curLine, size_t curPos, uint16_t& curAddr);
};

#endif