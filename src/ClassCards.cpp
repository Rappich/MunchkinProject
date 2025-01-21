#include "ClassCards.hpp"
#include <iostream>

// Default constructor
ClassCard::ClassCard()
    : Card("Unnamed Class", "Class", 0), description("No description"), bonuses({}) {}

// Parameterized constructor
ClassCard::ClassCard(const std::string &name, const std::string &description, const std::map<std::string, int> &bonuses)
    : Card(name, "Class", 0), description(description), bonuses(bonuses) {}

// Accessor methods
std::string ClassCard::getDescription() const { return description; }
std::map<std::string, int> ClassCard::getBonuses() const { return bonuses; }

// Display class card details
void ClassCard::displayCardInfo()
{
    std::cout << "Class Card: " << name << "\n";
    std::cout << description << "\n";
    for (const auto &[key, value] : bonuses)
    {
        std::cout << " - " << key << ": " << value << "\n";
    }
    std::cout << "\n";
}

// Predefined class data
std::vector<ClassData> getClassData()
{
    return {
        {"Warrior", "Gain a combat bonus of +2 and can use two-handed weapons with one hand.", {{"CombatBonus", 2}}},
        {"Thief", "Steal an item once per turn. Gain +1 to fleeing rolls.", {{"StealChance", 1}, {"FleeBonus", 1}}},
        {"Wizard", "Discard cards for additional combat strength. Gain +1 to magical item use.", {{"MagicBonus", 1}, {"DiscardCombat", 1}}},
        {"Cleric", "Gain +2 against undead monsters. Can discard cards to heal.", {{"UndeadBonus", 2}, {"HealBonus", 1}}}};
}

// Display details of a specific class
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
