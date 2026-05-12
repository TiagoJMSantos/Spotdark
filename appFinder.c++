#include "appFinder.h"
#include <iostream>

void findApps(int os) {
    switch(os) {
        case -1:
            std::cout << "Finding all apps in your system";
            break;
        case 0:
            std::cout << "Finding all apps in your system";
            break;
        case 1:
            std::cout << "This application does not support your system.";
            break;
    }
    return;
}