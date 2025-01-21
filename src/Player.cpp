#include "Player.hpp"

// Constructor to initialize player attributes
Player::Player(std::string playerName)
    : name(playerName), level(1), combatStrength(1), characterClass(nullptr), race(nullptr) {}

// Getter methods
std::string Player::getName() const { return name; }
int Player::getLevel() const { return level; }
int Player::getCombatStrength() const { return combatStrength; }

const std::vector<std::unique_ptr<Card>> &Player::getInventory() const { return inventory; }
const std::vector<std::unique_ptr<ItemCard>> &Player::getEquippedItems() const { return equippedItems; }

std::string Player::getClassName() const { return characterClass ? characterClass->getName() : "None"; }
std::string Player::getRaceName() const { return race ? race->getName() : "None"; }

// Equip an item (move from inventory to equipped)
void Player::equipItem(std::unique_ptr<ItemCard> item)
{
    auto it = std::find_if(inventory.begin(), inventory.end(),
                           [&item](const std::unique_ptr<Card> &invItem)
                           { return invItem.get() == item.get(); });

    if (it != inventory.end())
    {
        equippedItems.push_back(std::move(item));
        inventory.erase(it); // Remove from inventory
        calculateCombatStrength();
        std::cout << item->getName() << " has been equipped.\n";
    }
    else
    {
        std::cout << "Item not found in inventory.\n";
    }
}

// Unequip an item (move from equipped to inventory)
void Player::unequipItem(std::unique_ptr<ItemCard> item)
{
    auto it = std::find_if(equippedItems.begin(), equippedItems.end(),
                           [&item](const std::unique_ptr<ItemCard> &equippedItem)
                           { return equippedItem.get() == item.get(); });

    if (it != equippedItems.end())
    {
        inventory.push_back(std::move(*it)); // Return the item to inventory
        equippedItems.erase(it);             // Remove from equipped items
        calculateCombatStrength();
        std::cout << item->getName() << " has been unequipped.\n";
    }
    else
    {
        std::cout << "Item not found in equipped items.\n";
    }
}

// Add an item to inventory
void Player::addItemToInventory(std::unique_ptr<Card> item)
{
    inventory.push_back(std::move(item));
    std::cout << item->getName() << " added to inventory.\n";
}

// Remove an item from inventory
void Player::removeItemFromInventory(const Card &item)
{
    auto it = std::find_if(inventory.begin(), inventory.end(),
                           [&item](const std::unique_ptr<Card> &invItem)
                           { return *invItem == item; });

    if (it != inventory.end())
    {
        inventory.erase(it);
        std::cout << item.getName() << " removed from inventory.\n";
    }
    else
    {
        std::cout << "Item not found in inventory.\n";
    }
}

// Level up (increase level and recalculate combat strength)
void Player::levelUp()
{
    level++;
    calculateCombatStrength();
    std::cout << name << " leveled up to Level " << level << "!\n";
}

// Level down (decrease level and recalculate combat strength)
void Player::levelDown()
{
    if (level > 1)
    {
        level--;
        calculateCombatStrength();
        std::cout << name << " lost a level! Now at Level " << level << "!\n";
    }
    else
    {
        std::cout << name << " cannot level down below Level 1.\n";
    }
}

// Calculate combat strength dynamically
void Player::calculateCombatStrength()
{
    combatStrength = level;

    // Add bonuses from equipped items
    for (const auto &item : equippedItems)
    {
        for (const auto &[bonus, value] : item->getBonuses())
        {
            combatStrength += value;
        }
    }

    // Add bonuses from class and race
    if (characterClass)
    {
        for (const auto &[bonus, value] : characterClass->getBonuses())
        {
            combatStrength += value;
        }
    }

    if (race)
    {
        for (const auto &[bonus, value] : race->getBonuses())
        {
            combatStrength += value;
        }
    }
}

// Display player status
void Player::displayStatus() const
{
    std::cout << "Player: " << name << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Combat Strength: " << combatStrength << "\n";
    std::cout << "Class: " << getClassName() << "\n";
    std::cout << "Race: " << getRaceName() << "\n";

    std::cout << "Inventory:\n";
    for (const auto &item : inventory)
    {
        std::cout << " - " << item->getName() << "\n";
    }

    std::cout << "Equipped Items:\n";
    for (const auto &item : equippedItems)
    {
        std::cout << " - " << item->getName() << "\n";
    }
}
