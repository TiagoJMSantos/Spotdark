#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

using std::string;

struct CMD{
std::string appName; // saving the name of the application 
std::vector<std::string> args; // for feutures
};

CMD read();
CMD parseInput(const std::string& input);


#endif