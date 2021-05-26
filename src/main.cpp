#include "log/log.h"
#include "parsers/fileparser/fileparser.h"

Log* hlog;

int main(int argc, char** argv){
    hlog = new Log(Log::MEM, false);

    FileParser p;
    p.parseFile("../test.asm");
}