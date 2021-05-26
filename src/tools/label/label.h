#ifndef __LABEL_H__
#define __LABEL_H__

class Label;

#include <string>
#include <vector>
#include <stdint.h>

#include "../../log/log.h"

class Label{

public:
    Label();
    Label(std::string name);
    ~Label();

    /**
     *  Sets the address of the label, only do this once!
     *  @arg    addr            The address the label is at
     **/
    void                        setAddress(uint16_t addr);

    /**
     *  Sets the name of this label
     *  @arg    name            The name of the label
     **/
    void                        setName(std::string name);

    /**
     *  Adds a usage to the Label stack
     *  @arg    addr            The start address of this usage
     **/
    void                        addUsage(uint16_t addr);

private:
    std::string                 _name;
    uint16_t                    _address;
    std::vector<uint16_t>       _usages;

};

#endif