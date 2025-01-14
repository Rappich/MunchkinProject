#ifndef DECK_HPP
#define DECK_HPP
#include <vector>
#include "Card.hpp"
#include <algorithm> // for std::shuffle
#include <random> 
#include "MonsterCards.hpp"

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
    DeckType deckType;

public:
    Deck(){};
    Deck(DeckType deckType);
    void PopulateDeck(DeckType deckType);
    void shuffleDeck();
    Card drawCard();
    void AddCard();
    std::vector<Card> cards;

    void SetdeckType(DeckType deckType);
    
};

#endif