// CurseCard.hpp
#ifndef CURSECARDS_HPP
#define CURSECARDS_HPP

#include "Card.hpp"
#include <vector>
#include <map>

struct CurseData
{
    std::string name;
    std::string description;
    std::map<std::string, int> effects; // Effects applied by the curse
};

class CurseCard : public Card
{
public:
    CurseCard(const std::string &name, const std::string &description, const std::map<std::string, int> &effects)
        : Card(name, "Curse", 0), description(description), effects(effects) {}

    // Accessor methods
    std::string getDescription() const { return description; }
    std::map<std::string, int> getEffects() const { return effects; }

    // Display method
    void displayCardInfo() override;

private:
    std::string description;
    std::map<std::string, int> effects;
};

// Function prototypes for Curse data
std::vector<CurseData> getCurseData();
void displayCurseDetails(const CurseData &curseData);

#endif
