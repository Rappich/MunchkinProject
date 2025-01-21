#include "ItemCards.hpp"
#include <iostream>

// Returns a collection of predefined item data
std::vector<ItemData> getItemData()
{
    return {
        {"Boots of Butt-Kicking", "Provides a combat bonus to the player.", 400, {{"CombatBonus", 2}}},
        {"Chainsaw of Bloody Dismemberment", "A powerful weapon that offers a significant combat bonus.", 600, {{"CombatBonus", 3}}},
        {"Horny Helmet", "Grants a combat bonus when equipped.", 300, {{"CombatBonus", 1}}},
        {"Staff of Napalm", "A magical item providing a combat advantage.", 800, {{"MagicBonus", 4}}},
        {"Mithril Armor", "Offers substantial protection with a high combat bonus.", 1000, {{"CombatBonus", 5}}},
        {"Flaming Sword", "Deals extra damage in combat.", 700, {{"CombatBonus", 4}}},
        {"Potion of Strength", "Single-use item providing a temporary combat boost.", 200, {{"TemporaryBonus", 5}}},
        {"Sneaky Sneakers", "Grants a bonus to fleeing rolls.", 500, {{"FleeBonus", 2}}},
        {"Wand of Dowsing", "Retrieve the top card from the discard pile.", 600, {{"SpecialEffect", 1}}},
        {"Cloak of Invisibility", "Provides a significant bonus to fleeing rolls.", 900, {{"FleeBonus", 4}}},
        {"Helm of Courage", "Increases combat strength and prevents level loss from curses.", 700, {{"CombatBonus", 3}, {"CurseResistance", 1}}},
        {"Magic Missile", "A single-use item to damage monsters.", 300, {{"TemporaryBonus", 6}}},
        {"Dragon Boots", "Grants immunity to fire-based attacks.", 600, {{"FireResistance", 1}}},
        {"Golden Sword", "A high-value item with moderate combat benefits.", 1200, {{"CombatBonus", 2}}},
        {"Shield of Invincibility", "Provides combat protection and bonus.", 1000, {{"CombatBonus", 3}, {"DamageResistance", 1}}}};
}

// Displays detailed information about a specific item
void displayItemDetails(const ItemData &itemData)
{
    std::cout << "==================\n";
    std::cout << "Item: " << itemData.name << "\n";
    std::cout << itemData.description << "\n";
    std::cout << "Value: " << itemData.goldValue << " gold pieces\n";
    std::cout << "Bonuses:\n";
    for (const auto &[key, value] : itemData.bonuses)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
    std::cout << "==================\n\n";
}

// Displays detailed information about the item card
void ItemCard::displayCardInfo()
{
    std::cout << "==================\n";
    std::cout << "Item Card: " << name << "\n";
    std::cout << description << "\n";
    std::cout << "Value: " << value << " gold pieces\n";
    std::cout << "Bonuses:\n";
    for (const auto &[key, value] : bonuses)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
    std::cout << "==================\n\n";
}
