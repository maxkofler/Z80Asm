#include "log/log.h"
#include "asm/asm.h"

Log* hlog;

int main(int argc, char** argv){
    hlog = new Log(Log::F, false);

    Asm asmx;

    if (!asmx.loadSource("../test.asm"))
        return -1;

    if (!asmx.loadLookup("../lookup.txt"))
        return -1;

    if (!asmx.assemble(0x1000))
        return -1;

    if (!asmx.link())
        return -1;

    asmx.logProg();

    return 0;
}