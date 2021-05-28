#include "log/log.h"
#include "asm/asm.h"

#include <argparser.h>

Log* hlog;

int main(int argc, char** argv){
    Argparser parser(Log::I);
    parser.parse(argc, argv);
    
    if (parser.checkFlag("-v"))
        hlog = new Log(Log::D, false);
    else
        hlog = new Log(Log::I, false);

    Asm asmx;

    std::string srcFilePath;

    if (parser.getArgumentsCount() == 2){   //Just the input file provided
        srcFilePath = parser.getArgumentAt(1);
    }else{
        LOGE("Please provide a source file");
        return -1;
    }

    if (!asmx.loadSource(srcFilePath))
        return -1;

    if (!asmx.loadLookup("../z80lookup.txt"))
        return -1;

    if (!asmx.assemble(0x1000))
        return -1;

    if (!asmx.link())
        return -1;

    asmx.logProg();

    return 0;
}