#ifndef CLASSCARD_HPP
#define CLASSCARD_HPP

#include <string>
#include <map>
#include <vector>
#include "Card.hpp"

struct ClassData
{
    std::string name;
    std::string description;
    std::map<std::string, int> bonuses; // Bonuses provided by the class
};

class ClassCard : public Card
{
public:
    ClassCard(const std::string &name, const std::string &description, const std::map<std::string, int> &bonuses);

    std::string getDescription() const;
    std::map<std::string, int> getBonuses() const;

    void displayCardInfo() override;

private:
    std::string description;
    std::map<std::string, int> bonuses;
};

std::vector<ClassData> getClassData();

void displayClassDetails(const ClassData &classData);

#endif
