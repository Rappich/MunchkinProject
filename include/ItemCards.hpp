#ifndef ITEMCARDS_HPP
#define ITEMCARDS_HPP

#include "Card.hpp"
#include <string>
#include <map>
#include <vector>

// Struct to store predefined item data
struct ItemData
{
    std::string name;                   // Name of the item
    std::string description;            // Description of the item
    int goldValue;                      // Monetary value of the item
    std::map<std::string, int> bonuses; // Bonuses provided by the item

    // Constructor for ItemData
    ItemData(const std::string &name, const std::string &description, int goldValue, const std::map<std::string, int> &bonuses)
        : name(name), description(description), goldValue(goldValue), bonuses(bonuses) {}
};

// ItemCard class inheriting from Card
class ItemCard : public Card
{
public:
    // Constructors
    ItemCard(); // Default constructor
    ItemCard(const std::string &name, const std::string &description, int goldValue, const std::map<std::string, int> &bonuses);

    // Accessor methods
    std::string getDescription() const;
    int getGoldValue() const;
    std::map<std::string, int> getBonuses() const;

    std::string getName() const;

    // Display card information
    void displayCardInfo() override;
    int getCombatStrengthValue() const;

private:
    std::string description;            // Description of the item
    int goldValue;                      // Monetary value of the item
    std::map<std::string, int> bonuses; // Bonuses provided by the item
};

// Utility functions for managing predefined item data
std::vector<ItemData> getItemData();
void displayItemDetails(const ItemData &itemData);

#endif
