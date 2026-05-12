#include "systemDetection.h"

int main(int argc, char *argv[])
{
    int os = detectOS(); // -1 for Linux/Macos, 0 for Windows, 1 For others(no support available)
    return 0;
}
