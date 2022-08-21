#include<iostream>
using namespace std;
#include "demo_lib/hello_great.h"

int main(int argc, char *argv[])
{
    cout << get_great("world...") << endl;
    return 0;
}