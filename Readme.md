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

## Future
The library will be kept backwards compatible. 

## Requirements
The library requires atleast C++11

## Usage
### Namespace
The entire library is wrapped in the namespace CMD.
It contains one single class, namely `commander`

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

`bool isFlagSet (const std::string& flagName)`
Returns wether the flag exists

`std::string getFlagValue (const std::string& flagName)`
Returns the flag exactly after the specified flag. Used for example with `-file filename.txt`.

`std::string getEverythingFrom (const std::string& flagName)`
Returns a string with all the flags beginning with the flag after flagName.


`std::string getEverythingFromTo (const std::string& flagName, const std::string& flagName2)`
Returns a string with all the flags beginning with the flag after flagName and ending with the flag "flagName2".

`int getFlagPosition (const std::string& flagName)`
Returns the position of the flag starting at 0.

`auto begin()`
Returns an iterator to the first argv

`auto end()`
Returns an iterator after the last argv

`std::string operator [] (const int index)` 
Allows for access to a single argument

`std::string at (const int index)` 
Allows for access to a single argument, with bounds check. Throws an std::out_of_range.

`std::vector<std::string> getAllFlagsLike (const std::regex&)`
Returns a vector of every flag that matches the given regex.

`std::vector<std::string> getAllFlagsUnlike (const std::regex&)`
Returns a vector of every flag that doesn't matches the given regex.

`std::vector<std::string> getAllFlagsAfter (const std::string&)`
Returns all the flags after the given flag.
