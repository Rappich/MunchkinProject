#ifndef CLASSCARDS_HPP
#define CLASSCARDS_HPP

#include <string>
#include <map>
#include <vector>
#include "Card.hpp"

// Struct to hold predefined class data
struct ClassData
{
    std::string name;                   // Name of the class
    std::string description;            // Description of the class
    std::map<std::string, int> bonuses; // Bonuses provided by the class
};

// ClassCard inherits from Card
class ClassCard : public Card
{
public:
    // Constructors
    ClassCard();
    ClassCard(const std::string &name, const std::string &description, const std::map<std::string, int> &bonuses);

    // Accessor methods
    std::string getDescription() const;
    std::map<std::string, int> getBonuses() const;

    // Display information about the card
    void displayCardInfo() override;

private:
    std::string description;            // Class description
    std::map<std::string, int> bonuses; // Class bonuses
};

// Utility functions for managing class data
std::vector<ClassData> getClassData();
void displayClassDetails(const ClassData &classData);

#endif
