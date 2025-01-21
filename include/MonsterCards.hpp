#ifndef MONSTER_CARDS_HPP
#define MONSTER_CARDS_HPP

#include "Card.hpp"
#include "Player.hpp"
#include <vector>
#include <map>
#include <string>
#include <iostream>

// Struct to store predefined monster data
struct MonsterData
{
    std::string name;                    // Monster name
    std::string type;                    // Always "Monster"
    int level;                           // Monster strength level
    std::map<std::string, int> badStuff; // Penalties applied if the player loses
};

// MonsterCard class inheriting from Card
class MonsterCard : public Card
{
public:
    // Constructors
    MonsterCard();
    MonsterCard(const std::string &name, int level, const std::map<std::string, int> &badStuff);

    // Accessor methods
    int getLevel() const;
    std::map<std::string, int> getBadStuff() const;

    // Display monster card details
    void displayCardInfo() override;

    // Apply penalties to the player
    void applyBadStuff(Player &player);

private:
    int level;                           // Monster strength level
    std::map<std::string, int> badStuff; // Penalties for losing to this monster
};

// Function prototypes for predefined monster data
std::vector<MonsterData> getMonsterData();
void displayMonsterDetails(const MonsterData &monster);

#endif
