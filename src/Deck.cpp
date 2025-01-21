#include "Deck.hpp"
#include "MonsterCards.hpp"
#include "RaceCards.hpp"
#include "ItemCards.hpp"
#include "CurseCards.hpp"

// Constructor
Deck::Deck(DeckType deckType)
{
    this->deckType = deckType;
    PopulateDeck(deckType);
}

// Populate the deck with cards based on the deck type
void Deck::PopulateDeck(DeckType deckType)
{
    if (deckType == DeckType::DoorDeck)
    {
        // Add Monster Cards
        std::vector<MonsterData> monsterData = getMonsterData();
        for (const MonsterData &data : monsterData)
        {
            cards.push_back(std::make_unique<MonsterCard>(data.name, data.level, data.badStuff));
        }

        // Add Race Cards
        std::vector<RaceData> raceData = getRaceData();
        for (const RaceData &data : raceData)
        {
            cards.push_back(std::make_unique<RaceCard>(data.name, data.description, data.bonuses));
        }

        // Add Curse Cards
        std::vector<CurseData> curseData = getCurseData();
        for (const CurseData &data : curseData)
        {
            cards.push_back(std::make_unique<CurseCard>(data.name, data.description, data.effects));
        }
    }
    else if (deckType == DeckType::TreasureDeck)
    {
        // Add Item Cards
        std::vector<ItemData> itemData = getItemData();
        for (const ItemData &data : itemData)
        {
            cards.push_back(std::make_unique<ItemCard>(data.name, data.description, data.goldValue, data.bonuses));
        }
    }

    shuffleDeck();
}

// Shuffle the deck
void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

// Draw a card from the top of the deck
std::unique_ptr<Card> Deck::drawCard()
{
    if (cards.empty())
    {
        throw std::runtime_error("The deck is empty. Cannot draw a card.");
    }

    std::unique_ptr<Card> drawnCard = std::move(cards.back());
    cards.pop_back();
    return drawnCard;
}

// Add a card to the deck
void Deck::AddCard(std::unique_ptr<Card> card)
{
    cards.push_back(std::move(card));
}

// Set the deck type
void Deck::SetdeckType(DeckType deckType)
{
    this->deckType = deckType;
}

// Get the deck type
DeckType Deck::GetdeckType() const
{
    return deckType;
}

// Get all cards in the deck
const std::vector<std::unique_ptr<Card>> &Deck::GetCards() const
{
    return cards;
}
