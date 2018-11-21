# Commander
Simple tool that helps parse Command Line Arguments

## Inclusion
Simply include commander.hpp in your C++ project. 

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
Flags are any token separated by two spaces. 

#### `bool isFlagSet (std::string)`
Returns wether the flag exists

#### `std::string getFlagValue (std::string flagName)`
Returns the flag exactly after the specified flag. Used for example with `-file filename.txt`.

#### `std::string getEverythingBeginningFrom (std::string flagName)`
Returns a string with all the flags beginning with the flag after flagName.

#### `auto begin()`
Returns an iterator to the first argv

#### `auto end()`
Returns an iterator after the last argv

#### `std::string operator []` 
Allows for access to a single argument