
#include "MonsterCards.hpp"
#include <cstdlib>
#include <ctime>

// Returns a collection of predefined monster data
std::vector<MonsterData> getMonsterData()
{
    return {
        {"3,872 Orcs", "Monster", 10, {{"LoseLevels", 2}}},
        {"Amazon", "Monster", 8, {{"LoseItem", 1}}},
        {"Bigfoot", "Monster", 12, {{"LoseItem", 1}}},
        {"Bullrog", "Monster", 18, {{"LoseLevels", 3}, {"DiscardHand", 1}}},
        {"Crabs", "Monster", 6, {{"LoseItem", 1}}},
        {"Drooling Slime", "Monster", 1, {{"LoseItem", 1}}},
        {"Face Sucker", "Monster", 8, {{"LoseItem", 1}, {"LoseLevels", 1}}},
        {"Floating Nose", "Monster", 10, {{"LoseLevels", 2}}},
        {"Flying Frogs", "Monster", 6, {{"LoseItem", 1}}},
        {"Gazebo", "Monster", 8, {{"LoseLevels", 2}}},
        {"Gelatinous Octahedron", "Monster", 2, {{"LoseItem", 1}}},
        {"Ghoulfiends", "Monster", 8, {{"LoseLevels", 3}}},
        {"Harpies", "Monster", 4, {{"LoseItem", 2}}},
        {"Hippogriff", "Monster", 16, {{"LoseLevels", 1}, {"DiscardCards", 2}}},
        {"King Tut", "Monster", 16, {{"LoseLevels", 2}, {"DiscardTreasures", 1}}},
        {"Lame Goblin", "Monster", 1, {{"LoseTreasure", 1}}},
        {"Large Angry Chicken", "Monster", 2, {{"LoseLevels", 1}}},
        {"Lawyers", "Monster", 6, {{"DiscardHand", 1}}},
        {"Leperchaun", "Monster", 4, {{"LoseLevels", 1}, {"LoseItem", 1}}},
        {"Maul Rat", "Monster", 2, {{"LoseItem", 1}}},
        {"Mr. Bones", "Monster", 4, {{"LoseLevels", 1}}},
        {"Net Troll", "Monster", 10, {{"LoseLevels", 1}, {"LoseItem", 1}}},
        {"Pit Bull", "Monster", 3, {{"LoseItem", 1}}},
        {"Platycore", "Monster", 8, {{"LoseLevels", 1}, {"DiscardCards", 1}}},
        {"Plutonium Dragon", "Monster", 20, {{"Death", 1}}},
        {"Potted Plant", "Monster", 1, {{"LoseItem", 1}}},
        {"Pukachu", "Monster", 6, {{"LoseLevels", 1}}},
        {"Shrieking Geek", "Monster", 6, {{"DiscardCards", 2}}},
        {"Snails on Speed", "Monster", 4, {{"LoseLevels", 1}}},
        {"Squidzilla", "Monster", 18, {{"LoseItem", 3}}},
        {"Stoned Golem", "Monster", 14, {{"LoseItem", 2}}},
        {"Tongue Demon", "Monster", 12, {{"LoseLevels", 2}, {"DiscardCards", 1}}},
        {"Undead Horse", "Monster", 4, {{"LoseLevels", 1}, {"LoseItem", 1}}},
        {"Unspeakably Awful Indescribable Horror", "Monster", 14, {{"LoseLevels", 2}, {"LoseItem", 3}}},
        {"Wannabe Vampire", "Monster", 12, {{"LoseLevels", 2}, {"DiscardCards", 1}}},
        {"Wight Brothers", "Monster", 20, {{"LoseLevels", 2}, {"LoseTreasures", 2}}}};
}

// Displays monster details (generalized for future card types)
void displayMonsterDetails(const MonsterData &monster)
{
    std::cout << "==================\n";
    std::cout << "Monster Card: " << monster.name << "\n";
    std::cout << "Type: " << monster.type << "\n";
    std::cout << "Level: " << monster.level << "\n";
    std::cout << "Bad Stuff:\n";
    for (const auto &[effect, value] : monster.badStuff)
    {
        std::cout << " - " << effect << ": " << value << "\n";
    }
    std::cout << "==================\n\n";
}

// Initializes a MonsterCard object from MonsterData
MonsterCard initializeMonster(const MonsterData &monster)
{
    return MonsterCard(monster.name, monster.level, monster.badStuff);
}

// Applies penalties to the player based on bad stuff
void applyBadStuff(Player &player, const std::map<std::string, int> &badStuff)
{
    for (const auto &[effect, value] : badStuff)
    {
        if (effect == "LoseLevels")
        {
            for (int i = 0; i < value; ++i)
            {
                player.levelDown();
            }
        }
        else if (effect == "LoseItem")
        {
            auto equippedItems = player.getEquippedItems();
            if (!equippedItems.empty())
            {
                srand(static_cast<unsigned>(time(0)));
                int randomIndex = rand() % equippedItems.size();
                Card itemLost = equippedItems[randomIndex];
                player.unequipItem(itemLost);
                player.removeItemFromInventory(itemLost);
                std::cout << player.getName() << " lost a random item: " << itemLost.name << ".\n";
            }
            else
            {
                std::cout << player.getName() << " has no items to lose!\n";
            }
        }
        else if (effect == "DiscardHand")
        {
            player.getInventory().clear();
            std::cout << player.getName() << " discarded their entire hand.\n";
        }
        else if (effect == "Death")
        {
            std::cout << player.getName() << " dies. Game over for them!\n";
        }
        else
        {
            std::cout << "Unhandled bad stuff: " << effect << "\n";
        }
    }
}
