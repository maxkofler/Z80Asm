#include "label.h"

Label::Label(){
    FUN();
}

Label::Label(std::string name){
    FUN();

    this->setName(name);
}

Label::~Label(){
    FUN();
}