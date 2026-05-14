#include "appFinder.h"
#include <iostream>
#include <filesystem>
#include <fstream>

std::string paste_LINUX = "/usr/share/applications";

void findApps(int os,std::string name) {
    switch(os) {
        case -1:
            std::cout << "Finding all apps in your system";
            finderl(name);
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

int finderl(const std::string& name){
    std::string name_d = name + ".desktop";
    int found = 0;
    for (const auto& entry : std::filesystem::directory_iterator(paste_LINUX)){
        std::string file_name = entry.path().filename().string();
        if (name_d == file_name){
            std::cout << "encontrei\n";
            found = 1;
            break;
}
}
    if (!found){
        std::cout <<"Upsie\n";
        return 0;
}
    else return 1;

}

void execL(const std::string& name){
    std::ifstream file(name);
    std::string text;
    while(getline(file, text)){
        if(text.find("Exec=")==0){
        text = text.substr(5);

        break;
}
}

    file.close();
}


/*
int main(){
std::string app = "discord";
findApps(-1,app);
std::string paste_of_application = paste_LINUX + "/" + app+".desktop";
execL(paste_of_application);

return 0;
}

*/