#include "asm.h"

bool Asm::fetchLabels(){
    FUN();

    std::string curBlock;
    for (auto& line : this->_parser->_lines){
        for (size_t blockPos = 0; blockPos < line.length(); blockPos++){
            
            curBlock = line.at(blockPos);

            if (curBlock.back() == ':'){
                this->_labels.push_back(Label(curBlock.substr(0, curBlock.size()-1)));
                LOGD("Label found in block: [" + curBlock + "] -> \"" + this->_labels.back().getName() + "\"");
            }
        }
    }

    return true;
}