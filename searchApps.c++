// #include "searchApps.h"
#include <filesystem>
#include <iostream>

void detectOS();


int main() {
    #if defined(__linux__)
        std::cout << "Hello, GNU/Linux!" << '\n';
    #else
        std::cout << "Hello, Other!" << '\n';
    #endif
    return 0;
}

void detectOS() {
    if (__WIN64__) {
        printf("Your system is windows");
    } else {
        printf("Your system isnt windows");
    }
}