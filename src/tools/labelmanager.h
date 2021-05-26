#ifndef __LABELMANAGER_H__
#define __LABELMANAGER_H__

class LabelManager;

#include <vector>
#include <string>
#include <map>

#include "../log/log.h"

#include "label.h"

class LabelManager{

public:
    LabelManager();
    ~LabelManager();

    /**
     *  Defines a label, checks for undefined usages and adds them to the usages
     *  @arg    name                    The name of the label
     *  @arg    addr                    The address the label is located at
     **/
    bool                                defineLabel(std::string name, uint16_t addr);

    /**
     *  Registers a new label usage
     *  Usages of undefined labels get buffered and registered later
     *  @arg    name                    The name of the label to register the usage on
     *  @arg    addr                    The address of the FIRST (LS) byte of the label
     **/
    bool                                labelUsage(std::string name, uint16_t addr);

private:
    std::map<std::string, Label>                    _labels;

    std::vector<std::pair<std::string, uint16_t>>   _undefinedUsages;
};

#endif