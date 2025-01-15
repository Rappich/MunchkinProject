#include "ClassCard.hpp"
#include <iostream>

// Constructor
ClassCard::ClassCard(const std::string &name, const std::string &description, const std::map<std::string, int> &bonuses)
    : Card(name, "Class", 0), description(description), bonuses(bonuses) {}

// Accessor methods
std::string ClassCard::getDescription() const { return description; }
std::map<std::string, int> ClassCard::getBonuses() const { return bonuses; }

// Display method
void ClassCard::displayCardInfo()
{
    std::cout << "Class Card: " << name << "\n";
    std::cout << description << "\n";
    for (const auto &[key, value] : bonuses)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
}

// Function to get class data
std::vector<ClassData> getClassData()
{
    return {
        {"Warrior", "Gain a combat bonus of +2 and can use two-handed weapons with one hand.", {{"CombatBonus", 2}}},
        {"Thief", "Steal an item once per turn. Gain +1 to fleeing rolls.", {{"StealChance", 1}, {"FleeBonus", 1}}},
        {"Wizard", "Discard cards for additional combat strength. Gain +1 to magical item use.", {{"MagicBonus", 1}, {"DiscardCombat", 1}}},
        {"Cleric", "Gain +2 against undead monsters. Can discard cards to heal.", {{"UndeadBonus", 2}, {"HealBonus", 1}}}};
}

// Function to display class details
void displayClassDetails(const ClassData &classData)
{
    std::cout << "Class: " << classData.name << "\n";
    std::cout << classData.description << "\n";
    for (const auto &[bonus, value] : classData.bonuses)
    {
        std::cout << " - " << bonus << ": " << value << "\n";
    }
    std::cout << "\n";
}