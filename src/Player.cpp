#include "Player.hpp"
#include "ItemCards.hpp"
#include <algorithm>
#include <iostream>

Player::Player(const std::string &name) : name(name), level(1), combatStrength(0) {}

// Getter methods
std::string Player::getName() const { return name; }
int Player::getLevel() const { return level; }
int Player::getCombatStrength() const { return combatStrength; }

std::vector<std::shared_ptr<Card>> &Player::getInventory() { return inventory; }
const std::vector<std::shared_ptr<ItemCard>> &Player::getEquippedItems() const
{
    return equippedItems;
}

std::string Player::getClassName() const { return characterClass ? characterClass->getCardName() : "No Class"; }
std::string Player::getRaceName() const { return race ? race->getCardName() : "No Race"; }

// Equip an item (move from inventory to equipped)
void Player::equipItem(std::shared_ptr<ItemCard> item)
{
    equippedItems.push_back(std::move(item));
}

// Unequip an item (move from equipped to inventory)
void Player::unequipItem(std::shared_ptr<ItemCard> item)
{
    auto it = std::find_if(equippedItems.begin(), equippedItems.end(),
                           [&item](const std::shared_ptr<ItemCard> &i)
                           { return i->getCardName() == item->getCardName(); });
    if (it != equippedItems.end())
    {
        equippedItems.erase(it);
    }
}

// Add an item to inventory
void Player::addItemToInventory(std::shared_ptr<Card> item)
{
    inventory.push_back(std::move(item));
}

// Remove an item from inventory
void Player::removeItemFromInventory(const Card &item)
{
    auto it = std::find_if(inventory.begin(), inventory.end(),
                           [&item](const std::shared_ptr<Card> &i)
                           { return i->getCardName() == item.getCardName(); });
    if (it != inventory.end())
    {
        inventory.erase(it);
    }
}

// Level up (increase level and recalculate combat strength)
void Player::levelUp()
{
    ++level;
    calculateCombatStrength();
}

// Level down (decrease level and recalculate combat strength)
void Player::levelDown()
{
    if (level > 1)
    {
        --level;
        calculateCombatStrength();
    }
}

// Calculate combat strength dynamically
void Player::calculateCombatStrength()
{
    combatStrength = level;

    // Add bonuses from equipped items
    for (const auto &item : equippedItems)
    {
        combatStrength += item->getCombatStrengthValue();
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
    for (const auto &card : inventory)
    {
        card->displayCardInfo();
    }

    std::cout << "Equipped Items:\n";
    for (const auto &item : equippedItems)
    {
        std::cout << " - " << item->getName() << "\n";
    }
}

void Player::applyCurse(const CurseCard &curseCard)
{
    std::cout << "Applying curse: " << curseCard.getCardName() << " to player " << getName() << "\n";
    level = std::max(1, level - 1); // Example: reduce player's level
}

void Player::setPlayerClass(const ClassCard &classCard)
{
    characterClass = std::make_unique<ClassCard>(classCard);
    std::cout << "Player " << getName() << " is now a " << characterClass->getCardName() << "\n";
}

void Player::setPlayerRace(const RaceCard &raceCard)
{
    race = std::make_unique<RaceCard>(raceCard);
    std::cout << "Player " << getName() << " is now a " << race->getCardName() << "\n";
}

int Player::calculateCombatStrengthValue() const
{
    int combatStrength = level;
    for (const auto &card : inventory)
    {
        // Assuming each card has a method to get its combat strength value
        if (auto itemCard = dynamic_cast<ItemCard *>(card.get()))
        {
            combatStrength += itemCard->getCombatStrengthValue();
        }
    }
    return combatStrength;
}
