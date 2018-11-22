#ifndef commander_hpp 
#define commander_hpp 

#include <vector>
#include <string>
#include <algorithm>

namespace CMD {
class commander {
public:
    explicit commander(const std::vector<std::string>& inputs) {
        arguments = inputs;
    }
    commander(int argc, char** argv) {
        for (int i = 0; i < argc; i++)
            arguments.push_back(std::string (argv[i]));
    }
    commander(int argc, const char** argv) {
        for (int i = 0; i < argc; i++)
            arguments.push_back(std::string (argv[i]));
    }
    bool isFlagSet (const std::string& flagName) const {
        return (std::find (arguments.begin(), arguments.end(), flagName) != arguments.end());
    }
    std::string getFlagValue (const std::string& flagName) const {
        return *(std::find (arguments.begin(), arguments.end(), flagName) + 1);
    }
    std::string getEverythingBeginningFrom (const std::string& flagName) const {
        std::string temp;
        for (auto i = std::find (arguments.begin(), arguments.end(), flagName) + 1; i != arguments.end(); i++)
            temp += (*i) + " ";
        return temp;
    }
    std::string operator[] (int index) const {
        return arguments[index];
    }
    typename std::vector<std::string>::const_iterator begin() const {
        return arguments.begin();
    }
    typename std::vector<std::string>::const_iterator end() const {
        return arguments.end();
    }
private:
    std::vector<std::string> arguments;
};
}

#endif