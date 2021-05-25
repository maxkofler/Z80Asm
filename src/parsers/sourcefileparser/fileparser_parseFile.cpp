#include "fileparser.h"

size_t FileParser::parseFile(std::string path){
    this->_pathCurFile = path;

    this->_curFile.open(this->_pathCurFile);

    if (!this->_curFile.is_open()){
        LOGE("Could not open file " + this->_pathCurFile);
        return -1;
    }

    std::string buf;
    while (!this->_curFile.eof()){
        getline(this->_curFile, buf);
        this->_blocks.push_back(this->blockFromLine(buf));
    }

    return this->_blocks.size();
}