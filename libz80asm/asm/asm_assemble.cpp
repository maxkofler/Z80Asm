#include "z80asm.h"

bool Z80Asm::assemble(uint16_t startAddr){
    FUN();

    this->clear();

    this->_startAddr = startAddr;
    this->_curAddr = startAddr;

    std::string curBlock;

    for (auto& line : this->_sourceFile->_lines){
        LOGD("Assembling line \"" + line.toString() + "\"");
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
                //No instruction found, break the assemble
                LOGE("Fatal - Could not find an instruction that is valid to assemble in this line: \"" + line.toString() + "\"");
                return false;
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