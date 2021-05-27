#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

class Instruction;

#include <string>
#include <vector>

#include "../log/log.h"

#include "../parsers/block.h"
#include "labelmanager.h"

class Instruction{

public:
    Instruction();
    ~Instruction();

    /**
     *  Parses all the information needed to look up this instruction
     **/
    bool                        parse(Block& curBlock, size_t pos, uint16_t& curAddr, LabelManager* labels);

    /**
     *  Pushes a 16-bit hexadecimal value to the operand list
     *  @arg    num             A hexadecimal string containing the number
     **/
    void                        push16bHexString(std::string num);

    /**
     *  Pushes a 8-bit hexadecimal value to the operand list
     *  @arg    num             A hexadecimal string containing the number
     **/
    void                        push8bHexString(std::string num);

    size_t                      getOpCount(){return this->_operands.size();}
    std::string                 getUniformString(){return this->_uniformString;}

    /**
     *  Assembles the operands, increments curAddr to next instruction
     *  @arg    prog            A pointer to the program array
     *  @arg    curAddr         A reference to the current address variable
     **/
    bool                        assembleOperands(uint8_t* &prog, uint16_t& curAddr);

private:
    std::string                 _uniformString;
    uint8_t                     _opcode;
    std::vector<uint8_t>        _operands;

    bool                        _parsed;


    bool                        p_parseOP(std::string curBlock, uint16_t& curAddr, LabelManager* labels);
};

#endif