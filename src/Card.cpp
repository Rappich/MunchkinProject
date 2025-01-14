#include "Card.hpp"
#include <string>

Card::Card()
{
}

void Card::displayCardInfo()
{
    std::cout << "You drew a Monster Card!\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Level: " << value << "\n";
    std::cout << "Bad Stuff: \n";
     for (const auto &effect : badStuff)
    {
        std::cout << "- " << effect.first << ": " << effect.second << "\n";
    }
    std::cout << "\n";
}
