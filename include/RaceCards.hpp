#ifndef RACECARDS_HPP
#define RACECARDS_HPP

#include "Card.hpp"
#include <string>
#include <map>

struct RaceData
{
    std::string name;
    std::string description;
    std::map<std::string, int> bonuses; // Bonuses provided by the race
};

class RaceCard : public Card
{
public:
    RaceCard(const std::string &name, const std::string &description, const std::map<std::string, int> &bonuses)
        : Card(name, "Race", 0), description(description), bonuses(bonuses) {}

    std::string getDescription() const { return description; }
    std::map<std::string, int> getBonuses() const { return bonuses; }

    void displayCardInfo() override;

private:
    std::string description;
    std::map<std::string, int> bonuses;
};

std::vector<RaceData> getRaceData();
void displayRaceDetails(const RaceData &raceData);

#endif