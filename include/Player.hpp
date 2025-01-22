#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <memory>
#include "Card.hpp"
#include "CurseCards.hpp"
#include "ClassCards.hpp"
#include "RaceCards.hpp"
#include "ItemCards.hpp"

class Player
{
public:
    Player(const std::string &name);

    std::string getName() const;
    int getLevel() const;
    int getCombatStrength() const;
    std::vector<std::shared_ptr<Card>> &getInventory();
    const std::vector<std::shared_ptr<ItemCard>> &getEquippedItems() const;
    std::string getClassName() const;
    std::string getRaceName() const;

    void equipItem(std::shared_ptr<ItemCard> item);
    void unequipItem(std::shared_ptr<ItemCard> item);
    void addItemToInventory(std::shared_ptr<Card> item);
    void removeItemFromInventory(const Card &item);

    void levelUp();
    void levelDown();

    void calculateCombatStrength();

    void displayStatus() const;

    void applyCurse(const CurseCard &curseCard);
    void setPlayerClass(const ClassCard &classCard);
    void setPlayerRace(const RaceCard &raceCard);
    int calculateCombatStrengthValue() const;

private:
    std::string name;
    int level;
    int combatStrength;
    std::vector<std::shared_ptr<Card>> inventory;
    std::vector<std::shared_ptr<ItemCard>> equippedItems;
    std::unique_ptr<ClassCard> characterClass;
    std::unique_ptr<RaceCard> race;
};

#endif // PLAYER_HPP
