#include "RaceCards.hpp"

std::vector<RaceData> getRaceData()
{
    return {
        {"Elf", "Gain +1 to fleeing rolls and +1 bonus when assisting in combat.", {{"FleeBonus", 1}, {"AssistBonus", 1}}},
        {"Dwarf", "Can carry one extra Big item. Gain +1 combat bonus in dungeons.", {{"ExtraBigItem", 1}, {"DungeonCombatBonus", 1}}},
        {"Halfling", "Can sell items for double their value. Gain +2 when fighting alone.", {{"SellBonus", 2}, {"SoloCombatBonus", 2}}},
        {"Human", "No special abilities but can use all items. Gain +1 to all rolls.", {{"GeneralRollBonus", 1}}}};
}

void displayRaceDetails(const RaceData &raceData)
{
    std::cout << "Race: " << raceData.name << "\n";
    std::cout << raceData.description << "\n";
    for (const auto &[key, value] : raceData.bonuses)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
    std::cout << "\n";
}

void RaceCard::displayCardInfo()
{
    std::cout << "Race Card: " << name << "\n";
    std::cout << description << "\n";
    for (const auto &[key, value] : bonuses)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
}
