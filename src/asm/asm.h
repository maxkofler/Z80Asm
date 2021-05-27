#ifndef __ASM_H__
#define __ASM_H__

class Asm;

#include <string>
#include <vector>
#include <utility>

#include "../log/log.h"
#include "../parsers/fileparser.h"
#include "../tools/labelmanager.h"
#include "../tools/istable.h"
#include "../tools/label.h"
#include "../parsers/block.h"

class Asm{

public:
    Asm();
    ~Asm();

    /**
     *  Parses the lookup table from the provided file
     *  @arg    file                The file to parse from
     **/
    bool                            loadLookup(std::string file);

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

private:
    FileParser*                     _sourceFile;
    LabelManager*                   _labels;
    ISTable*                        _lookuptable;


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

    /**
     *  assemble()  Converts the current string to a uniform string for lookup for the opcode
     *  @arg    curLine             The line to process
     *  @arg    curPos              The current position in the line to assemble from
     *  @return bool                success
     *          string              The string to look up
     **/
    std::pair<bool, std::string>    p_makeUniformString(Block& curLine, size_t curPos);

    /**
     *  assemble()  Convert the provided block to a unified operand for lookup
     *  @arg    block               The block to parse
     *  @return                     The uniform string to add to the lookup string
     **/
    std::string                     p_makeUniformOperand(std::string block);
};

#endif