#include "cyber/cyber.h"

int main(int argc, char*argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "Hello world";
    return 0;
}