#include "asm.h"

bool Asm::assemble(uint16_t startAddr){
    FUN();

    uint16_t curAddr = startAddr;

    std::string curBlock;

    for (auto& line : this->_sourceFile->_lines){
        for (size_t blockPos = 0; blockPos < line.length(); blockPos++){

            //Get the current block
            curBlock = line.at(blockPos);
        
            //First of all check for a label and if so, give it the required address
            if (this->p_checkLabelDefinition(curBlock, curAddr))
                continue;

            if (this->p_checkInstruction(line, blockPos, curAddr)){
                //Go to the next block
                blockPos = line.length();          
                continue;
            }
        }
    }

    return true;
}