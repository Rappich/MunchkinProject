#include "Game.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

// Constructor: Initializes the decks
Game::Game()
{
    doorDeck.SetdeckType(DeckType::DoorDeck);
    doorDeck.PopulateDeck(DeckType::DoorDeck);
    treasureDeck.SetdeckType(DeckType::TreasureDeck);
    treasureDeck.PopulateDeck(DeckType::TreasureDeck);

    currentTurn = 0;
    gameState = "Not Started";
}

std::vector<Player> &Game::GetPlayerList()
{
    return players;
}

// Start the game and distribute initial cards
void Game::startGame()
{
    std::cout << "Starting the game...\n";

    // Distribute 4 cards to each player from both decks
    for (Player &player : GetPlayerList())
    {
        for (int i = 0; i < 4; ++i)
        {
            if (!doorDeck.GetCards().empty())
                player.addItemToInventory(doorDeck.drawCard());
            else
                std::cout << "Door deck is empty. Cannot draw more cards.\n";

            if (!treasureDeck.GetCards().empty())
                player.addItemToInventory(treasureDeck.drawCard());
            else
                std::cout << "Treasure deck is empty. Cannot draw more cards.\n";
        }
        player.displayStatus();
    }

    gameState = "In Progress";
}

// Handle a player's turn
void Game::playerTurn(Player &player)
{
    std::cout << "\nIt's " << player.getName() << "'s turn!\n";

    // Step 1: Draw a door card
    if (doorDeck.GetCards().empty())
    {
        std::cout << "Door deck is empty. Shuffling discard pile...\n";
        // Logic to shuffle discard pile into the main deck
    }

    std::unique_ptr<Card> drawnCard = doorDeck.drawCard();
    drawnCard->displayCardInfo();

    // Step 2: Handle the card type
    if (auto monsterCard = dynamic_cast<MonsterCard *>(drawnCard.get()))
    {
        combat(player, *monsterCard);
    }
    else if (auto curseCard = dynamic_cast<CurseCard *>(drawnCard.get()))
    {
        player.applyCurse(*curseCard);
    }
    else if (auto classCard = dynamic_cast<ClassCard *>(drawnCard.get()))
    {
        player.setPlayerClass(*classCard); // Assuming setPlayerClass() is implemented
    }
    else if (auto raceCard = dynamic_cast<RaceCard *>(drawnCard.get()))
    {
        player.setPlayerRace(*raceCard); // Assuming setPlayerRace() is implemented
    }
    else
    {
        std::cout << "You found a special card. Adding it to your inventory.\n";
        player.addItemToInventory(std::move(drawnCard));
    }

    // Step 3: End of turn
    endTurn();
}

// Combat with a monster
void Game::combat(Player &player, MonsterCard &monsterCard)
{
    std::cout << "Combat with " << monsterCard.getCardName() << " initiated!\n";

    int playerStrength = player.calculateCombatStrengthValue();
    int monsterStrength = monsterCard.getLevel();

    std::cout << "Player strength: " << playerStrength << "\n";
    std::cout << "Monster strength: " << monsterStrength << "\n";

    if (playerStrength >= monsterStrength)
    {
        std::cout << "Victory! " << player.getName() << " defeated the monster.\n";
        player.levelUp();
        if (!treasureDeck.GetCards().empty())
        {
            auto treasure = treasureDeck.drawCard();
            player.addItemToInventory(std::move(treasure));
            std::cout << "You earned a treasure: " << treasure->getCardName() << "\n";
        }
    }
    else
    {
        std::cout << "Defeat! You must flee or suffer the consequences.\n";
        int fleeRoll = rand() % 6 + 1;
        std::cout << player.getName() << " rolled a " << fleeRoll << " to flee.\n";

        if (fleeRoll < 5)
        {
            std::cout << "Failed to flee. Applying bad stuff.\n";
            monsterCard.applyBadStuff(player);
        }
        else
        {
            std::cout << "Successfully fled the battle.\n";
        }
    }
}

// End the current turn
void Game::endTurn()
{
    currentTurn = (currentTurn + 1) % players.size();
    std::cout << "Turn ended. Next player: " << players[currentTurn].getName() << "\n";
}

// Check victory condition
bool Game::checkVictory(std::vector<Player> &players)
{
    for (const Player &player : players)
    {
        if (player.getLevel() >= 10)
        {
            std::cout << player.getName() << " has reached level 10 and won the game!\n";
            gameState = "Completed";
            return true;
        }
    }
    return false;
}

// Add a new player
void Game::AddPlayer(Player newPlayer)
{
    players.push_back(std::move(newPlayer));
    std::cout << "Player " << newPlayer.getName() << " has joined the game.\n";
}
