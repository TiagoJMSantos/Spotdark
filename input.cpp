#include "input.h"
#include <iostream>
#include <sstream>

CMD read(){
    string intru;
    if(!std::getline(std::cin, intru)) return {0};
        return parseInput(intru);
}

CMD parseInput(const std::string& input){
    CMD cmd;
    std::string word;
    std::stringstream ss(input);

    if(ss >> word){
        cmd.appName = word;
}
    while(ss >> word){ //o >> skips all spaces
        cmd.args.push_back(word);
}
    return cmd;
}