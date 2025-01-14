#include "Player.hpp"

// Constructor to initialize player attributes
Player::Player(std::string playerName) 
{
    name = playerName;
    level = 1;
    combatStrength = level;
    characterClass = "None";
    race = "None";
}

// Getter methods
std::string Player::getName() const 
{
    return name;
}

int Player::getLevel() const 
{
    return level;
}

int Player::getCombatStrength() const 
{
    return combatStrength;
}

std::vector<Card> Player::getInventory() const 
{
    return inventory;
}

std::vector<Card> Player::getEquippedItems() const 
{
    return equippedItems;
}

std::string Player::getClass() const 
{
    return characterClass;
}

std::string Player::getRace() const 
{
    return race;
}

// Equip an item (move from inventory to equipped)
void Player::equipItem(const Card& item) 
{
    // Check if the item is already in inventory before equipping
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        equippedItems.push_back(item);
        inventory.erase(it);  // Remove from inventory
        combatStrength += item.value; // Update combat strength based on item
        std::cout << item.name << " has been equipped.\n";
    } else {
        std::cout << "Item not found in inventory.\n";
    }
}

// Unequip an item (move from equipped to inventory)
void Player::unequipItem(const Card& item) 
{
    auto it = std::find(equippedItems.begin(), equippedItems.end(), item);
    if (it != equippedItems.end()) {
        inventory.push_back(item); // Return the item to inventory
        equippedItems.erase(it);   // Remove from equipped items
        combatStrength -= item.value; // Update combat strength
        std::cout << item.name << " has been unequipped.\n";
    } else {
        std::cout << "Item not found in equipped items.\n";
    }
}

// Add item to inventory (without equipping)
void Player::addItemToInventory(const Card& item) 
{
    inventory.push_back(item);
    std::cout << item.name << " added to inventory.\n";
}

// Remove item from inventory
void Player::removeItemFromInventory(const Card& item) 
{
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) 
    {
        inventory.erase(it);
        std::cout << item.name << " removed from inventory.\n";
    } else {
        std::cout << "Item not found in inventory.\n";
    }
}

// Level up (increase level and combat strength)
void Player::levelUp() {
    level++;
    combatStrength = level + (equippedItems.size() * 2); // Example of simple scaling with items
    std::cout << name << " leveled up to Level " << level << "!\n";
}

// Level down (decrease level and combat strength)
void Player::levelDown() {
    if (level > 1) {
        level--;
        combatStrength = level + (equippedItems.size() * 2); // Adjust strength
        std::cout << name << " lost a level! Now at Level " << level << "!\n";
    } else {
        std::cout << name << " cannot level down below Level 1.\n";
    }
}

// Display player status (for debugging or gameplay feedback)
void Player::displayStatus() const 
{
    std::cout << "Player: " << name << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Combat Strength: " << combatStrength << "\n";
    std::cout << "Class: " << characterClass << "\n";
    std::cout << "Race: " << race << "\n";
    std::cout << "Inventory: \n";
    for (const auto& item : inventory) {
        std::cout << "- " << item.name << "\n";
    }
    std::cout << "Equipped Items: \n";
    for (const auto& item : equippedItems) {
        std::cout << "- " << item.name << "\n";
    }
}
