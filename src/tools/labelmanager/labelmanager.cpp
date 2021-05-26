#include "../labelmanager.h"

LabelManager::LabelManager(){
    FUN();

    this->_labels.clear();
    this->_undefinedUsages.clear();
}

LabelManager::~LabelManager(){
    FUN();
}