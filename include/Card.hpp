#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Card
{
public:
    std::string name; // Name of card
    std::string type; // "Monster", "Curse", "Item", etc.
    int value;        // Combat strength, treasure value, etc.
    std::map<std::string, int> badStuff; // For monster cards

    Card();
    Card(std::string n, std::string t, int v, std::map<std::string, int> bs = {})
        : name(n), type(t), value(v), badStuff(bs) {}

    void displayCardInfo();
    // Equality operator
    bool operator==(const Card& other) const
    {
        return name == other.name && type == other.type && value == other.value;
    }
};

#endif
