#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "Card.hpp"
#include "ClassCards.hpp"
#include "RaceCards.hpp"
#include "ItemCards.hpp"

class Player
{
private:
    std::string name;                                     // Player's name
    int level;                                            // Player's current level
    int combatStrength;                                   // Player's calculated combat strength
    std::vector<std::unique_ptr<Card>> inventory;         // Cards in the player's possession
    std::vector<std::unique_ptr<ItemCard>> equippedItems; // Equipped item cards
    std::unique_ptr<ClassCard> characterClass;            // Player's current class
    std::unique_ptr<RaceCard> race;                       // Player's current race

public:
    // Constructor
    explicit Player(std::string playerName);

    // Accessors
    std::string getName() const;
    int getLevel() const;
    int getCombatStrength() const;
    const std::vector<std::unique_ptr<Card>> &getInventory() const;
    const std::vector<std::unique_ptr<ItemCard>> &getEquippedItems() const;
    std::string getClassName() const;
    std::string getRaceName() const;

    // Inventory and Equipment Management
    void equipItem(std::unique_ptr<ItemCard> item);
    void unequipItem(std::unique_ptr<ItemCard> item);
    void addItemToInventory(std::unique_ptr<Card> item);
    void removeItemFromInventory(const Card &item);

    // Level Management
    void levelUp();
    void levelDown();

    // Combat Strength Calculation
    void calculateCombatStrength();

    // Display Player Status
    void displayStatus() const;
};

#endif
