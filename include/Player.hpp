#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Card.hpp"

class Player 
{
private:
    std::string name;
    int level;
    std::vector<Card> inventory;
    std::vector<Card> equippedItems; 
    std::string characterClass;   
    std::string race;             
    int combatStrength;           

public:
    Player(std::string playerName);
    std::string getName() const;
    int getLevel() const;
    int getCombatStrength() const;
    std::vector<Card> getInventory() const;
    std::vector<Card> getEquippedItems() const;
    std::string getClass() const;
    std::string getRace() const;

    void equipItem(const Card& item);
    void unequipItem(const Card& item);
    void addItemToInventory(const Card& item);
    void removeItemFromInventory(const Card& item);

    void levelUp();
    void levelDown();

    void displayStatus() const;
};

#endif

