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

            int resCheckInstruction = this->p_checkInstruction(line, blockPos, curAddr);

            if (resCheckInstruction == 0){
                //No instruction found
                continue;
            }else if (resCheckInstruction > 0){
                blockPos = line.length();
                continue;
            }else{
                //A fatal error occured, break the assemble
                LOGE("Fatal error in assembling");
                return false;
            }
        }
    }

    return true;
}