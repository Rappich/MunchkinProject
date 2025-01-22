#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Card
{
public:
    std::string name;                    // Name of the card
    std::string type;                    // Type of the card (e.g., "Monster", "Item", etc.)
    int value;                           // Value of the card (combat strength, treasure value, etc.)
    std::map<std::string, int> badStuff; // Penalties (used for Monster cards)

    // Constructors
    Card(); // Default constructor
    Card(std::string n, std::string t, int v, std::map<std::string, int> bs = {});

    // Virtual method for displaying card information (to be overridden in derived classes)
    virtual void displayCardInfo();

    // Operator overload for card equality (compares attributes)
    bool operator==(const Card &other) const
    {
        return name == other.name && type == other.type && value == other.value;
    }

    // Method to get the card name
    std::string getCardName() const;

    // Virtual destructor for proper cleanup in derived classes
    virtual ~Card() = default;
};

#endif