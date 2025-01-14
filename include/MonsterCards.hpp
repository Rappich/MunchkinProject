#ifndef MONSTER_CARDS_HPP
#define MONSTER_CARDS_HPP

#include "Card.hpp"
#include "Player.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

struct MonsterData
{
    std::string name;
    std::string type;
    int level;
    std::map<std::string, int> badStuff;
};

// Function prototypes
std::vector<MonsterData> getMonsterData();
void displayMonsterDetails(const MonsterData& monster);
Card initializeMonster(const MonsterData& monster);
void applyBadStuff(Player& player, const std::map<std::string, int>& badStuff);


#endif
