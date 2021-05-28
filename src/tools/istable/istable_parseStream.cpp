#include "tools/istable.h"

#include "parsers/parsertools.h"

bool ISTable::parseStream(std::istream& s){
    FUN();

    if (s.bad()){
        LOGE("Error in parsing, file is bad!");
        return false;
    }


    std::string curLine;
    while (!s.eof()){

        getline(s, curLine);
        Block curBlock = ParserTools::blockFromLine(curLine, ';');

        //Check for right length (>=3)
        if (curBlock.length() < 3){
            LOGW("Invalid block size for parsing for lookup: " + curBlock.toString());
            continue;
        }

        //The 1st block is the uniform string
        lookupIS newIs;

        newIs.uniformString = curBlock.at(curBlock.length()-1);

        //Check the 2nd block for a number and fetch it
        //The length of the opcode
        if (!std::isdigit(curBlock.at(0).at(0))){
            LOGE("2nd block is not the length of the opcode: " + curBlock.at(1));
            continue;
        }

        newIs.len = std::stoi(curBlock.at(0));

        bool err = false;
        //Now parse all the opcodes
        for(uint8_t i = 1; i < newIs.len+1; i++){

            //Check if the block is even existing
            if (i >= curBlock.length()){
                LOGE("The block is not existing!")
                err = true;
                break;
            }

            newIs.opcode.push_back(std::stoul(curBlock.at(i), nullptr, 16));
        }

        //Check if an error occured during parsing
        if (err)
            continue;

        //Check if the instruction is not already present
        if (this->_lookuptable.count(newIs.uniformString) > 0){
            LOGE("Instruction already in lookup table!");
            continue;
        }

        this->_lookuptable[newIs.uniformString] = newIs;
        LOGF("Added lookup: " + newIs.toString());
    }

    return true;
}