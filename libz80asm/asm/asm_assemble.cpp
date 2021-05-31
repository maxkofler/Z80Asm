#include "z80asm.h"

bool Asm::assemble(uint16_t startAddr){
    FUN();

    this->_startAddr = startAddr;
    this->_curAddr = startAddr;

    std::string curBlock;

    for (auto& line : this->_sourceFile->_lines){
        for (size_t blockPos = 0; blockPos < line.length(); blockPos++){

            //Get the current block
            curBlock = line.at(blockPos);

            //Check if the block is empty, continue if so
            if(curBlock.empty()){
                LOGD("Not processing empty block");
                continue;
            }
        
            //First of all check for a label and if so, give it the required address
            if (this->p_checkLabelDefinition(curBlock, this->_curAddr))
                continue;

            int resCheckInstruction = this->p_checkInstruction(line, blockPos, this->_curAddr);

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