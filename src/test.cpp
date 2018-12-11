#include <iostream>
#include <commander.hpp>

void assert (bool worked) {
    if (!worked)
        std::cout << "!! didn't work well !!\n";
}

void testSerializers() {
    assert(CMD::serializer<std::string>::convert ("hi") == "hi");
    assert(CMD::serializer<int>::convert ("1123") == 1123);
    assert(CMD::serializer<double>::convert ("123.123") == 123.123);
    assert(CMD::serializer<float>::convert ("123.1") == 123.1f);
}

void testCommander () {
    std::vector <const char*> args {"smoothiemaker", "-shakeBananas", "-allowMistakes", "-sprinkleChocolate", "brown", "-effort", "10"};
    CMD::commander a(7, args.data());
    assert (a.isFlagSet("-allowMistakes") == true);
    assert (a.isFlagSet("-stirIngredients") == false);
    assert (a.getFlagValue("-sprinkleChocolate") == "brown");
    assert (a.getEverythingFrom("-allowMistakes") == std::vector<std::string> {"-sprinkleChocolate", "brown", "-effort", "10"});
    assert (a.getEverythingFromTo("-shakeBananas", "-sprinkleChocolate") == std::vector<std::string>{"-allowMistakes"});
    assert (a.getFlagPosition("-allowMistakes") == 2);
    assert (a[2] == "-allowMistakes");
    assert (a.at(2) == "-allowMistakes");
    bool threw = false;
    try {
        a.at(100);
    } catch (const std::exception& ex) {
        threw = true;
    }
    assert (threw);
    assert (a.getAllFlagsLike(std::regex ("-\\w*")) == std::vector<std::string> {"-shakeBananas", "-allowMistakes", "-sprinkleChocolate", "-effort"});
    assert (a.getAllFlagsUnlike(std::regex ("-\\w*")) == std::vector<std::string> {"smoothiemaker", "brown", "10"});
    assert (a.getFlagValue<int> ("-effort") == 10);
    for (auto i : a) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main () {
    testCommander();
    testSerializers();
}