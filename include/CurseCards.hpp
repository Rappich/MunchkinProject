#ifndef CURSECARDS_HPP
#define CURSECARDS_HPP

#include "Card.hpp"
#include <vector>
#include <map>
#include <string>

// Struct to store predefined curse data
struct CurseData
{
    std::string name;                   // Name of the curse
    std::string description;            // Description of the curse
    std::map<std::string, int> effects; // Effects applied by the curse
};

// CurseCard class inheriting from Card
class CurseCard : public Card
{
public:
    // Constructors
    CurseCard(const std::string &name, const std::string &description, const std::map<std::string, int> &badStuff);

    // Display card information
    void displayCardInfo() override;

private:
    std::string description;             // Description of the curse
    std::map<std::string, int> badStuff; // Effects applied by the curse
};

// Utility functions for managing predefined curse data
std::vector<CurseData> getCurseData();
void displayCurseDetails(const CurseData &curseData);

#endif
