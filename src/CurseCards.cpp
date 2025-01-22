#include "CurseCards.hpp"
#include <iostream>

CurseCard::CurseCard(const std::string &name, const std::string &description, const std::map<std::string, int> &badStuff)
    : Card(name, "Curse", 0), description(description), badStuff(badStuff) {}

// Returns a collection of predefined curse cards
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

// Displays detailed information about a specific curse
void displayCurseDetails(const CurseData &curseData)
{
    std::cout << "==================\n";
    std::cout << "Curse: " << curseData.name << "\n";
    std::cout << curseData.description << "\n";
    std::cout << "Effects:\n";
    for (const auto &[key, value] : curseData.effects)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
    std::cout << "==================\n\n";
}

// Displays detailed information about the curse card
void CurseCard::displayCardInfo()
{
    std::cout << "Curse Card: " << getCardName() << "\n";
    std::cout << description << "\n";
    for (const auto &[key, value] : badStuff)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
}
