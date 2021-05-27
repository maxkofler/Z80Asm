#include "../labelmanager.h"

bool LabelManager::labelUsage(std::string name, uint16_t addr){
    FUN();

    //Check if the label is anywhere to register it
    if (this->_labels.count(name) > 0){
        LOGD("Registering usage of label \"" + name + "\" at " + Log::toHexString(addr));
        this->_labels[name].addUsage(addr);
    }else{
        //If not, add it to the buffer
        LOGD("Buffering usage of label \"" + name + "\" at " + Log::toHexString(addr));
        this->_undefinedUsages.push_back(std::make_pair(name, addr));
    }

    return true;
}