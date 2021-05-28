#ifndef __LABELMANAGER_H__
#define __LABELMANAGER_H__

class LabelManager;

#include <vector>
#include <string>
#include <map>

#include <log.h>

#include <tools/label.h>

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

    /**
     *  Links the usages in the buffer to the defined labels
     *  @return                         false when there is an undefined reference
     **/
    bool                                link();

    /**
     *  Replaces all label usages with the label addresses
     *  @arg    prog                    The program array to write to
     **/
    bool                                insertAddrs(uint8_t* &prog);

private:
    std::map<std::string, Label>                    _labels;

    std::vector<std::pair<std::string, uint16_t>>   _undefinedUsages;
};

#endif