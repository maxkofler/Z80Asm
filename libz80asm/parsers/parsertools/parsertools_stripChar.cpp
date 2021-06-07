#include "parsers/parsertools.h"

std::string ParserTools::stripChar(std::string in, char strip){
    FUN();

    for (size_t i = 0; i < in.length(); i++){
        if (in.at(i) == strip){
            in.erase(in.begin() + i);
            i--;
        }
    }

    return in;
}