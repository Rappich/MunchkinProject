#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <memory>    // for std::unique_ptr
#include <algorithm> // for std::shuffle
#include <random>    // for random number generation
#include "Card.hpp"
#include "MonsterCards.hpp"
#include "RaceCards.hpp"
#include "CurseCards.hpp"
#include "ItemCards.hpp"

enum DeckType
{
    DoorDeck,
    TreasureDeck,
    DoorDiscardDeck,
    TreasureDiscardDeck,
};

class Deck
{
private:
    DeckType deckType;                        // Type of the deck (e.g., Door or Treasure)
    std::vector<std::unique_ptr<Card>> cards; // Cards in the deck (supports polymorphism)

public:
    // Constructors
    Deck();
    Deck(DeckType deckType);

    // Methods
    void PopulateDeck(DeckType deckType);     // Populate the deck with cards based on type
    void shuffleDeck();                       // Shuffle the cards in the deck
    std::unique_ptr<Card> drawCard();         // Draw and remove the top card from the deck
    void AddCard(std::unique_ptr<Card> card); // Add a card to the deck

    // Accessors and Mutators
    void SetdeckType(DeckType deckType);                        // Set the type of the deck
    DeckType GetdeckType() const;                               // Get the type of the deck
    const std::vector<std::unique_ptr<Card>> &GetCards() const; // Get a reference to the cards
};

#endif
