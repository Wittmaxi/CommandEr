#include <iostream>
#include "commander.hpp"

void assert (bool worked) {
    if (!worked)
        std::cout << "didn't work well \n";
}

int main () {
    std::vector <const char*> args {"smoothiemaker", "-shakeBananas", "-allowMistakes", "-sprinkleChocolate", "brown"};
    CMD::commander a(5, args.data());
    assert (a.isFlagSet("-allowMistakes") == true);
    assert (a.isFlagSet("-stirIngredients") == false);
    assert (a.getFlagValue("-sprinkleChocolate") == "brown");
    assert (a.getEverythingFrom("-allowMistakes") == "-sprinkleChocolate brown ");
    assert (a.getEverythingFromTo("-shakeBananas", "-sprinkleChocolate") == "-allowMistakes ");
    for (auto i : a) {
        
    }
}