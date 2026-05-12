#include "systemDetection.h"
#include <filesystem>
#include <iostream>

int detectOS();
int detectOS() {
    #if defined(__linux__)
        return -1;
    #elif defined(_WIN32)
        return 0;
    #elif defined(__APPLE__)
        return -1; // LINUX & MACOS SHARE A SIMILAR FOLDER SYSTEM 
    #else
        return 1; // NOT DOING CODE FOR THAT ----
    #endif
}

