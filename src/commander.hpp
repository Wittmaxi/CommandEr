#ifndef commander_hpp 
#define commander_hpp 

#include <vector>
#include <string>
#include <algorithm>

namespace CMD {
namespace UTIL {
    std::string removeUntil (std::string toProcess, char until) {
        auto it = std::find(toProcess.begin(), toProcess.end(), until);
        if (it == toProcess.end()) 
            return "";
        return std::string (++it, toProcess.end());
    }

    std::string getUntil (std::string toProcess, char until) {
        auto it = std::find(toProcess.begin(), toProcess.end(), until);
        return std::string (toProcess.begin(), it);
    }
}

class commander {
public:
    commander(const std::vector<std::string>& inputs) {
        arguments = inputs;
    }
    commander(int argc, char** argv) {
        for (int i = 0; i < argc; i++)
            arguments.push_back(std::string (argv[i]));
    }
    bool isFlagSet (std::string flagName) {
        return (std::find (arguments.begin(), arguments.end(), flagName) != arguments.end());
    }
    std::string getFlagValue (std::string flagName) {
        return (std::find (arguments.begin(), arguments.end(), flagName) + 1);
    }
    std::string getEverythingBeginningFrom (std::string flagName) {
        auto i = std::find (arguments.begin(), arguments.end(), flagName);
        std::string temp;
        for (auto j = i; i != arguments.end(); i++)
            temp += *j + " ";
    }
    typename std::vector<std::string>::iterator begin() {
        return arguments.begin();
    }
    typename std::vector<std::string>::iterator end() {
        return arguments.end();
    }
private:
    std::vector<std::string> arguments;
};
}

#endif