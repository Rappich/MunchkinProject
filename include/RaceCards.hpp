#ifndef RACECARDS_HPP
#define RACECARDS_HPP

#include "Card.hpp"
#include <string>
#include <map>
#include <vector>

// Struct to hold predefined race data
struct RaceData
{
    std::string name;                   // Name of the race
    std::string description;            // Description of the race
    std::map<std::string, int> bonuses; // Bonuses provided by the race
};

// RaceCard class inheriting from Card
class RaceCard : public Card
{
public:
    // Constructors
    RaceCard();
    RaceCard(const std::string &name, const std::string &description, const std::map<std::string, int> &bonuses);

    // Accessor methods
    std::string getDescription() const;
    std::map<std::string, int> getBonuses() const;

    // Display card information
    void displayCardInfo() override;

private:
    std::string description;            // Race description
    std::map<std::string, int> bonuses; // Race-specific bonuses
};

// Utility functions for predefined race data
std::vector<RaceData> getRaceData();
void displayRaceDetails(const RaceData &raceData);

#endif
