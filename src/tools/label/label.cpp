#include "../label.h"

Label::Label(){
    FUN();
}

Label::Label(std::string name){
    FUN();

    this->setName(name);
}

Label::Label(std::string name, uint16_t addr){
    FUN();

    this->setName(name);
    this->setAddress(addr);
}


Label::~Label(){
    FUN();
}