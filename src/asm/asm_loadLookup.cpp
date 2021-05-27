#include "asm.h"

bool Asm::loadLookup(std::string fPath){
    FUN();

    LOGD("Loading lookup table from " + fPath);

    std::ifstream file;
    file.open(fPath);

    if (!file.is_open()){
        LOGE("Could not open file for loading!");
        file.close();
        return false;
    }

    if (this->_lookuptable->parseStream(file)){
        LOGD("Loaded lookuptable!");
        file.close();
        return true;
    }
    
    file.close();
    return false;    
}