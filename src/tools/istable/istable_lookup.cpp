#include "../istable.h"

lookupIS ISTable::lookup(std::string uniformString){
    FUN();

    lookupIS retIs;
    retIs.len = 0;
    retIs.uniformString = "";

    //Check if the instruction is available in this form
    if (this->_lookuptable.count(uniformString) == 0){
        LOGE("Could not find the following uniform string: " + uniformString);
        return retIs;
    }

    retIs = this->_lookuptable[uniformString];
    return retIs;
}