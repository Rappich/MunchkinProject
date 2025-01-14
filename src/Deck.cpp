#include "Deck.hpp"

Deck::Deck(DeckType deckType)
{
    this->deckType = deckType;
    switch (this->deckType)
    {
    case DeckType::DoorDeck:

        break;
    }
}

void Deck::PopulateDeck(DeckType deckType)
{
    std::vector<MonsterData> monsterData = getMonsterData();
    if (deckType == DeckType::DoorDeck)
    {
        // Populate Door Deck
        for(MonsterData data : monsterData)
        {
            cards.push_back(Card(data.name,data.type,data.level,data.badStuff));
        }

        // cards.push_back(Card("Level 1 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key", "Item", 2));
        // cards.push_back(Card("Level 2 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 2", "Item", 2));
        // cards.push_back(Card("Level 3 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 3 ", "Item", 2));
        // cards.push_back(Card("Level 4 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 4", "Item", 2));
        // cards.push_back(Card("Level 5 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 5", "Item", 2));
        // cards.push_back(Card("Level 1 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key", "Item", 2));
        // cards.push_back(Card("Level 2 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 2", "Item", 2));
        // cards.push_back(Card("Level 3 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 3 ", "Item", 2));
        // cards.push_back(Card("Level 4 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 4", "Item", 2));
        // cards.push_back(Card("Level 5 Skeleton", "Monster", 1));
        // cards.push_back(Card("Curse! Lose 1 Level", "Curse", 0));
        // cards.push_back(Card("Magic Key 5", "Item", 2));
        shuffleDeck();
    }
    else
    {
        //Populate Treasure Deck
        cards.push_back(Card("Boots of Butt-Kicking", "Item", 2));
        cards.push_back(Card("Potion of Heroism", "Item", 5));
        cards.push_back(Card("Bag of Gold", "Treasure", 100));
        cards.push_back(Card("Boots of Butt-Kicking", "Item", 2));
        cards.push_back(Card("Potion of Heroism", "Item", 5));
        cards.push_back(Card("Bag of Gold", "Treasure", 100));
        cards.push_back(Card("Boots of Butt-Kicking", "Item", 2));
        cards.push_back(Card("Potion of Heroism", "Item", 5));
        cards.push_back(Card("Bag of Gold", "Treasure", 100));
        cards.push_back(Card("Boots of Butt-Kicking", "Item", 2));
        cards.push_back(Card("Potion of Heroism", "Item", 5));
        cards.push_back(Card("Bag of Gold", "Treasure", 100));
        cards.push_back(Card("Boots of Butt-Kicking", "Item", 2));
        cards.push_back(Card("Potion of Heroism", "Item", 5));
        cards.push_back(Card("Bag of Gold", "Treasure", 100));
        cards.push_back(Card("Boots of Butt-Kicking", "Item", 2));
        cards.push_back(Card("Potion of Heroism", "Item", 5));
        cards.push_back(Card("Bag of Gold", "Treasure", 100));
        shuffleDeck();
    }
}

void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

Card Deck::drawCard()
{
    Card drawnCard = cards.back(); // Draw the top card
    cards.pop_back();              // Remove it from the deck
    return drawnCard;
}

void Deck::SetdeckType(DeckType deckType)
{
    this->deckType = deckType;
}
