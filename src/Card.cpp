#include "Card.hpp"
#include <string>

// Default constructor
Card::Card() : name(""), type(""), value(0), badStuff({}) {}

// Parameterized constructor
Card::Card(std::string n, std::string t, int v, std::map<std::string, int> bs)
    : name(n), type(t), value(v), badStuff(bs) {}

// Method to get the card name
std::string Card::getCardName() const
{
    return name;
}

// Virtual method for displaying card information
void Card::displayCardInfo()
{
    std::cout << "Card Name: " << name << "\n";
    std::cout << "Card Type: " << type << "\n";
    std::cout << "Card Value: " << value << "\n";
    if (!badStuff.empty())
    {
        std::cout << "Bad Stuff:\n";
        for (const auto &pair : badStuff)
        {
            std::cout << " - " << pair.first << ": " << pair.second << "\n";
        }
    }
}
