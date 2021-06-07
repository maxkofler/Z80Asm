#include "log.h"
#include "z80asm.h"

#include <argparser.h>

Log* hlog;

int main(int argc, char** argv){
    Argparser parser(Log::I);
    parser.parse(argc, argv);
    
    if (parser.checkFlag("-vvvv"))
        hlog = new Log(Log::FUNCALLS, true); 
    else if (parser.checkFlag("-vvv"))
        hlog = new Log(Log::MEM, true);   
    else if (parser.checkFlag("-vv"))
        hlog = new Log(Log::MEM, false);
    else if (parser.checkFlag("-v"))
        hlog = new Log(Log::D, false);
    else
        hlog = new Log(Log::I, false);

    Z80Asm asmx;
    uint16_t startAddr = 0x0000;

    //The path to the source file
    std::string srcFilePath;
    //The path to the executable ".hex"
    std::string exePath;

    if (parser.checkOption("-i")){
        srcFilePath = parser.getOption("-i");
    }else if (parser.getArgumentsCount() == 2){
        srcFilePath = parser.getArgumentAt(1);
    }else{
        LOGE("Please provide a source file");
        return -1;
    }

    if (parser.checkOption("-o")){
        exePath = parser.getOption("-o");
    }else if (parser.getArgumentsCount() == 3){
        exePath = parser.getArgumentAt(2);
    }else{
        exePath = "a.hex";
    }

    if (parser.checkOption("--start")){
        startAddr = stoul(parser.getOption("--start"), nullptr, 16);
    }

    if (parser.checkOption("--lookup")){
        if (!asmx.loadLookup(parser.getOption("--lookup")))
            return -1;
    }else{
        if (!asmx.loadLookup("../z80lookup.txt"))
            return -1;
    }


    if (!asmx.loadSource(srcFilePath)){
        LOGE("Aborting");
        return -1;
    }

    if (!asmx.assemble(startAddr)){
        LOGE("Aborting");
        return -1;
    }

    if (!asmx.link()){
        LOGE("Aborting");
        return -1;
    }

    asmx.logProg();

    {
        //Output the program
        std::ofstream f;
        f.open(exePath);
        
        //Check if the file is valid
        if (!f.is_open()){
            LOGE("Could not open output file \"" + exePath + "\"");
            f.close();
            return -1;
        }

        auto prog = asmx.getProg();

        for (uint8_t i : prog){
            f << i;
        }

        f.close();
    }

    return 0;
}