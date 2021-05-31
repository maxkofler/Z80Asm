#include "tools/labelmanager.h"

bool LabelManager::link(){
    FUN();

    std::string name;
    uint16_t addr;

    for (auto i : this->_undefinedUsages){

        name = i.first;
        addr = i.second;

        //Check if the label is anywhere to register it
        if (this->_labels.count(name) > 0){
            LOGD("Registering usage of label \"" + name + "\" at " + Log::toHexString(addr));
            this->_labels[name].addUsage(addr);
        }else{
            LOGE("Undefined reference to label \"" + name + "\" used at " + Log::toHexString(addr));
            return false;
        }
    }

    return true;
}