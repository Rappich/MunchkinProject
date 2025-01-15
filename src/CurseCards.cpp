#include "CurseCards.hpp"

std::vector<CurseData> getCurseData()
{
    return {
        {"Lose a Level", "You lose one level immediately.", {{"LoseLevels", 1}}},
        {"Lose an Item", "Randomly lose one equipped item.", {{"LoseItem", 1}}},
        {"Lose All Hand Items", "All items in your hand are discarded.", {{"DiscardHand", 1}}},
        {"Lose Big Item", "Lose one Big item if you have any.", {{"LoseBigItem", 1}}},
        {"Shrink by One", "Your combat strength is reduced by 1.", {{"ReduceCombat", 1}}},
        {"Duck of Doom", "Lose two levels immediately.", {{"LoseLevels", 2}}},
        {"Lose Your Class", "You must discard your current Class card, if any.", {{"LoseClass", 1}}},
        {"Lose Your Race", "You must discard your current Race card, if any.", {{"LoseRace", 1}}},
        {"Income Tax", "Discard items totaling at least 1,000 Gold Pieces in value.", {{"DiscardValue", 1000}}},
        {"Lose Your Headgear", "You must discard your equipped Headgear item.", {{"LoseHeadgear", 1}}},
        {"Lose Your Footgear", "You must discard your equipped Footgear item.", {{"LoseFootgear", 1}}}};
}

void displayCurseDetails(const CurseData &curseData)
{
    std::cout << "Curse: " << curseData.name << "\n";
    std::cout << curseData.description << "\n";
    for (const auto &[key, value] : curseData.effects)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
    std::cout << "\n";
}

void CurseCard::displayCardInfo()
{
    std::cout << "Curse Card: " << name << "\n";
    std::cout << description << "\n";
    for (const auto &[key, value] : effects)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
}
