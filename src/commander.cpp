#include "commander.hpp"

namespace CMD
{
std::string serializer<std::string>::convert(const std::string &other)
{
    return other;
}

int serializer<int>::convert(const std::string &other)
{
    std::stringstream stream(other);
    int temp;
    stream >> temp;
    return temp;
}

double serializer<double>::convert(const std::string &other)
{
    std::stringstream stream(other);
    double temp;
    stream >> temp;
    return temp;
}

float serializer<float>::convert(const std::string &other)
{
    std::stringstream stream(other);
    float temp;
    stream >> temp;
    return temp;
}

commander::commander(const std::vector<std::string> &inputs)
{
    arguments = inputs;
}
commander::commander(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
        arguments.push_back(std::string(argv[i]));
}
commander::commander(int argc, const char **argv)
{
    for (int i = 0; i < argc; i++)
        arguments.push_back(std::string(argv[i]));
}
size_t commander::getFlagCount() const
{
    return arguments.size();
}
bool commander::isFlagSet(const std::string &flagName) const
{
    return (std::find(arguments.begin(), arguments.end(), flagName) != arguments.end());
}
int commander::getFlagPosition(const std::string &flagName) const
{
    return std::distance(arguments.begin(), std::find(arguments.begin(), arguments.end(), flagName));
}
typename std::vector<std::string>::const_iterator commander::begin() const
{
    return arguments.begin();
}
typename std::vector<std::string>::const_iterator commander::end() const
{
    return arguments.end();
}
} // namespace CMD