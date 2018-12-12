# Commander
Simple tool that helps parse Command Line Arguments

## Installation
Copy this repository and call `make install` in it.
```console
git clone https://github.com/Wittmaxi/CommandEr
cd CommandEr
make install
```

## Inclusion
Simply include commander.hpp like this:
```c++
#include <commander.hpp>
``` 
When compiling, add the `-lCMD` flag!

## Requirements
The library requires atleast C++11

## Usage
### Namespace
The entire library is wrapped in the namespace CMD.
It contains one single class meant to be used, namely `commander`

### Constructor
```C++
commander(const std::vector<std::string>& inputs);
commander(int argc, char** argv);
commander(int argc, const char** argv);
```
Simply retrieve argc and argv from the main function and feed them into `commander::commander`

### Flags 
Flags are any tokens separated from others by a space. In a usual context, you may call them "command line arguments"
Eg:
```console
myCoolApp hello World 

Tokens:
myCoolApp
hello
world
```
Call the following functions on your instance of commander:

```c++
bool isFlagSet (const std::string& flagName)
```
Returns wether the flag exists

```c++
template<class T = std::string>
T getFlagValue (const std::string& flagName)
```
Returns the flag exactly after the specified flag. Used for example with `-file filename.txt`.

```c++
template<class T = std::string>
std::vector<T> getEverythingFrom (const std::string& flagName)
```
Returns a string with all the flags beginning with the flag after flagName.

```c++
template<class T = std::string>
std::vector<T> getEverythingFromTo (const std::string& flagName, const std::string& flagName2)
```
Returns a string with all the flags beginning with the flag after flagName and ending with the flag "flagName2".

```c++
int getFlagPosition (const std::string& flagName)
```
Returns the position of the flag starting at 0.

```c++
auto begin()
```
Returns an iterator to the first argv

```c++
auto end()
```
Returns an iterator after the last argv

```c++
template<class T = std::string>
T operator [] (const int index)
```
Allows for access to a single argument

```c++
template<class T = std::string>
T at (const int index)
```
Allows for access to a single argument, with bounds check. Throws an std::out_of_range.

```c++
template<class T = std::string>
std::vector<T> getAllFlagsLike (const std::regex&)
```
Returns a vector of every flag that matches the given regex.

```c++
template<class T = std::string>
std::vector<T> getAllFlagsUnlike (const std::regex&)
```
Returns a vector of every flag that doesn't matches the given regex.

```c++
template<class T = std::string>
std::vector<T> getAllFlagsAfter (const std::string&)
```
Returns all the flags after the given flag.

### Types
The templated members of commander allow for typecasted retrieval of the flags. 
A flag `"1"` could thus be converted to an integer type. 
For conversions to types that are not yet supported, 
```
template<class T>
CMD::serializer {

};
```
has to be specialized for the required task. 
It needs to contain the function
```static Type convert (const std::string& other);```
