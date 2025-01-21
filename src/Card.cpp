#include "Card.hpp"
#include <string>

// Default constructor
Card::Card()
    : name("Unnamed Card"), type("Undefined"), value(0), badStuff({})
{
    // Default initialization for a generic card
}

// Virtual method for displaying card information
void Card::displayCardInfo()
{
    std::cout << "Card Info:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Value: " << value << "\n";

    // Display badStuff only if it's relevant (usually for MonsterCard)
    if (!badStuff.empty())
    {
        std::cout << "Bad Stuff:\n";
        for (const auto &effect : badStuff)
        {
            std::cout << "- " << effect.first << ": " << effect.second << "\n";
        }
    }
    else
    {
        std::cout << "No specific penalties associated with this card.\n";
    }
    std::cout << "\n";
}
