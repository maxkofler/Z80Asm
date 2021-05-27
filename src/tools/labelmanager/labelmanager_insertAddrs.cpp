#include "../labelmanager.h"

bool LabelManager::insertAddrs(uint8_t* &prog){
    FUN();

    Label curLabel;
    for(auto i : this->_labels){
        curLabel = i.second;
        if (!curLabel.applyUsages(prog))
            return false;
    }

    return true;
}