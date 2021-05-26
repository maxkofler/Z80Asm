#include "../instruction.h"

#include <ctype.h>

bool Instruction::p_parseOP(std::string curBlock){
    FUN();

    std::string operand = "";

    switch(curBlock.size()){
        case 1:
            //  8-bit register
            //  [A]
            operand = curBlock;
            break;

        case 2:
            if(isalpha(curBlock.at(0)) && isalpha(curBlock.at(1))){
                //  16-bit register
                //  [BC]
                operand = curBlock;
            }else{
                LOGE("Could not identify operator type of \"" + curBlock + "\"");
                return false;
            }
            break;

        case 3:
            if (curBlock.at(0) == '(' && curBlock.at(2) == ')'){
                if (isalpha(curBlock.at(1))){
                    //  8-bit indirect address
                    //  [(A)]
                    operand = curBlock;
                }else{
                    LOGE("Could not identify operator type of \"" + curBlock + "\"");
                    return false;
                }
            }else if (curBlock.back() == 'H'){
                //  8-bit immediate
                //  [*]     [F6h]
                operand = "*";
            }else{
                //  3 long label
                //  [FUN]
                operand = "**";
            }
            break;

        case 4:
            if (curBlock.at(0) == '(' && curBlock.at(3) == ')'){
                if (isalpha(curBlock.at(1)) && isalpha(curBlock.at(2)))
                    //  16-bit indirect address
                    //  [(BC)]
                    operand = curBlock;
                else{
                    LOGE("Could not identify operator type of \"" + curBlock + "\"");
                    return false;
                }
            }else{
                //  4 long label
                //  [LOOP]
                operand = "**";
            }
            break;
        
        case 5:
            if (curBlock.at(0) == '(' && curBlock.at(4) == ')'){
                if (curBlock.at(3) == 'H'){
                    //  8-bit direct address
                    //  [(*)]   [(F6h)]
                    operand = "(*)";
                }else{
                    LOGE("Could not identify operator type of \"" + curBlock + "\"");
                    return false;
                }
            }else if(curBlock.at(4) == 'H'){
                //  16-bit immediate
                //  [**]    [F6A1h]
                operand = "**";
            }else{
                //  5 long label
                //  [LOOP1]
                operand = "**";
            }
            break;

        case 6:
            //  6 long label
            //  [LOOPER]
            operand = "**";
            break;

        case 7:
            if (curBlock.at(0) == '(' && curBlock.at(6) == ')'){
                if (curBlock.at(5) == 'H'){
                    //  16-bit direct address
                    //  [(**)]  [(F6A1h)]
                    operand = "(**)";
                }else{
                    LOGE("Could not identify operator type of \"" + curBlock + "\"");
                    return false;
                }
            }else{
                //  7 long label
                //  [LOOPER1]
                operand = "**";
            }
            break;

        default:
            //  label
            operand = "**";
    }

    this->_unifiedString += "," + operand;

    return true;
}