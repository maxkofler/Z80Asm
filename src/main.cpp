#include "log/log.h"
#include "asm/asm.h"

Log* hlog;

int main(int argc, char** argv){
    hlog = new Log(Log::MEM, false);

    Asm asmx;
}