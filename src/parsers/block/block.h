#ifndef __BLOCK_H__
#define __BLOCK_H__

class Block;

#include <vector>
#include <string>

#include "../../log/log.h"

class Block{

public:
    Block();
    ~Block();

    void                        append(std::string s){this->_blocks.push_back(s);}

private:
    std::vector<std::string>    _blocks;

};

#endif