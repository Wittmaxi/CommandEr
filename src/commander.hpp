#ifndef commander_hpp
#define commander_hpp

#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <regex>
#include <exception>
#include <sstream>

namespace CMD
{
template <class T>
struct serializer
{
    static_assert("CMD::serializer was not specialized for the required type.");
};

template <>
struct serializer<std::string>
{
    static std::string convert(const std::string &other);
};

template <>
struct serializer<int>
{
    static int convert(const std::string &other);
};

template <>
struct serializer<double>
{
    static double convert(const std::string &other);
};

template <>
struct serializer<float>
{
    static float convert(const std::string &other);
};

class commander
{
  public:
    explicit commander(const std::vector<std::string> &inputs);
    commander(int argc, char **argv);
    commander(int argc, const char **argv);
    size_t getFlagCount() const;
    bool isFlagSet(const std::string &flagName) const;
    int getFlagPosition(const std::string &flagName) const;
    typename std::vector<std::string>::const_iterator begin() const;
    typename std::vector<std::string>::const_iterator end() const;

    template <class T = std::string>
    T getFlagValue(const std::string &flagName) const
    {
        auto temp = std::find(arguments.begin(), arguments.end(), flagName);
        if (temp == arguments.end())
            return T();
        return serializer<T>::convert(*(temp + 1));
    }

    template <class T = std::string>
    std::vector<T> getEverythingFrom(const std::string &flagName) const
    {
        std::vector<T> temp;
        for (auto i = std::find(arguments.begin(), arguments.end(), flagName) + 1; i != arguments.end(); i++)
            temp.push_back(serializer<T>::convert(*i));
        return temp;
    }

    template <class T = std::string>
    std::vector<T> getEverythingFromTo(const std::string &flagName, const std::string &flagName2) const
    {
        std::vector<T> temp;
        for (auto i = std::find(arguments.begin(), arguments.end(), flagName) + 1; i != std::find(arguments.begin(), arguments.end(), flagName2); i++)
            temp.push_back(serializer<T>::convert(*i));
        return temp;
    }

    template <class T = std::string>
    std::vector<T> getAllFlagsAfter(const std::string &flag) const
    {
        std::vector<T> temp;
        for (auto i = std::find(arguments.begin(), arguments.end(), flag); i != arguments.end(); i++)
            temp.push_back(serializer<T>::convert(*i));
        return temp;
    }

    template <class T = std::string>
    std::vector<T> getAllFlagsLike(const std::regex &pattern) const
    {
        std::vector<T> temp;
        for (const auto &i : arguments)
            if (std::regex_match(i, pattern))
                temp.push_back(serializer<T>::convert(i));
        return temp;
    }

    template <class T = std::string>
    std::vector<T> getAllFlagsUnlike(const std::regex &pattern) const
    {
        std::vector<std::string> temp;
        for (const auto &i : arguments)
            if (!std::regex_match(i, pattern))
                temp.push_back(serializer<T>::convert(i));
        return temp;
    }

    template <class T = std::string>
    T operator[](const int index) const
    {
        return serializer<T>::convert(arguments[index]);
    }
    
    template <class T = std::string>
    T at(const int index) const
    {
        if (index < arguments.size())
            return serializer<T>::convert(arguments[index]);
        throw std::out_of_range("Amount of arguments for commander::at too high");
    }

  private:
    std::vector<std::string> arguments;
};
} // namespace CMD

#endif