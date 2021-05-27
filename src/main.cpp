#include "log/log.h"
#include "asm/asm.h"

Log* hlog;

int main(int argc, char** argv){
    hlog = new Log(Log::I, false);

    Asm asmx;

    std::string srcFilePath;

    if (argc == 2){
        srcFilePath = argv[1];
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