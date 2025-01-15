#ifndef ITEMCARD_HPP
#define ITEMCARD_HPP

#include "Card.hpp"
#include <string>
#include <map>
struct ItemData

{
    std::string name;
    std::string description;
    int goldValue;
    std::map<std::string, int> bonuses;

    ItemData(const std::string &name, const std::string &description, int goldValue, const std::map<std::string, int> &bonuses)

        : name(name), description(description), goldValue(goldValue), bonuses(bonuses)
    {
    }
};

class ItemCard : public Card
{
public:
    ItemCard(const std::string &name, const std::string &description, int goldValue, const std::map<std::string, int> &bonuses)
        : Card(name, "Item", goldValue), description(description), bonuses(bonuses) {}

    std::string getDescription() const { return description; }
    int getGoldValue() const { return goldValue; }
    std::map<std::string, int> getBonuses() const { return bonuses; }

    void displayCardInfo() override;

private:
    std::string description;
    int goldValue;
    std::map<std::string, int> bonuses;
};

std::vector<ItemData> getItemData();
void displayItemDetails(const ItemData &itemData);

#endif
