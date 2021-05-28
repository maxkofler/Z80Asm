#ifndef __ISTABLE_H__
#define __ISTABLE_H__

class ISTable;

#include <map>
#include <string>
#include <istream>
#include <inttypes.h>

#include <log.h>

typedef struct s_lookupIS{

    //The length of the instruction in bytes (excluding operands)
    uint8_t                 len = 0;

    //The uniform string this instruction can be found with
    std::string             uniformString = "";

    //The vector containing the opcode(s)
    std::vector<uint8_t>    opcode;

    std::string             toString(){
        std::string ret;
        ret += "Uniform string: \"" + uniformString + "\"";
        ret += " Ammount of opcodes: " + std::to_string(len);
        ret += " Opcodes: ";
        for(auto i : opcode){
            ret += "[" + Log::toHexString(i) + "]";
        }
        return ret;
    }

}lookupIS;


class ISTable{

public:

    /**
     *  Parses the lookup table from a provided stream
     *  @arg    a                       The stream to parse from
     **/
    bool                                parseStream(std::istream& s);

    /**
     *  Looks up the instruction with its uniform string
     *  @arg    uniformstring           The string to look up the instruction by
     **/
    lookupIS                            lookup(std::string uniformString);

private:
    std::map<std::string, lookupIS>     _lookuptable;
};

#endif