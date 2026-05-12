#include "systemDetection.h"
#include "appFinder.h"
#include "print.h"
#include <iostream>
using std::cout;

int main(int argc, char *argv[])
{
    printBanner();
    int os = detectOS(); // -1 for Linux/Macos, 0 for Windows, 1 For others(no support available)
    findApps(os);
    return 0;
}

    