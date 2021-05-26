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

    std::string                 at(size_t i){return this->_blocks.at(i);}
    size_t                      length(){return this->_blocks.size();}
    bool                        empty(){return this->_blocks.empty();}

    void                        append(std::string s){this->_blocks.push_back(s);}
    void                        append(Block b);

private:
    std::vector<std::string>    _blocks;

};

#endif