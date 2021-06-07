#include "parsers/fileparser.h"

size_t FileParser::parseSourceFile(std::string path){
    FUN();
    
    this->_lines.clear();

    this->_pathCurFile = path;
    
    this->_curFile.open(this->_pathCurFile);

    if (!this->_curFile.is_open()){
        LOGE("Could not open file " + this->_pathCurFile);
        this->_curFile.close();
        return -1;
    }

    std::string buf;
    Block curBlock;
    while (!this->_curFile.eof()){
        getline(this->_curFile, buf);
        curBlock = ParserTools::blockFromCodeLine(buf);
        this->_lines.push_back(curBlock);
        LOGD("Fetched block: " + this->_lines.back().toString());
    }

    this->_curFile.close();

    return this->_lines.size();
}