#include "log/log.h"

Log* hlog;

int main(int argc, char** argv){
    hlog = new Log(Log::A, false);
}