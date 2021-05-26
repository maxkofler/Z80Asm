#include "../labelmanager.h"

bool LabelManager::defineLabel(std::string name, uint16_t addr){
    FUN();

    //Check if the label already exists
    if (this->_labels.count(name) > 0){
        LOGE(   "Redefinition of Label \"" + name + "\" at " + Log::toHexString(addr) + 
                " first defined at " + Log::toHexString(this->_labels[name].getAddress()));
        return false;
    }

    LOGD("Adding label \"" + name + "\"(" + Log::toHexString(addr) + ") to defined labels");
    this->_labels[name] = Label(name, addr);

    return true;
}