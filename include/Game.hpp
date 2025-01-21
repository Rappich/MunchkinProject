#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Player.hpp"
#include "Deck.hpp"

class Game
{
private:
    int currentTurn;             // Index of the current player's turn
    std::string gameState;       // Current state of the game (e.g., "In Progress", "Completed")
    std::vector<Player> players; // List of players in the game

    Deck doorDeck;            // Main deck for door cards
    Deck treasureDeck;        // Main deck for treasure cards
    Deck doorDiscardDeck;     // Discard pile for door cards
    Deck treasureDiscardDeck; // Discard pile for treasure cards

public:
    // Constructor
    Game();

    // Game Management
    void startGame();                                // Initializes the game, populates decks, and deals initial cards
    void playerTurn(Player &player);                 // Executes a single player's turn
    void endTurn();                                  // Ends the current turn and advances to the next player
    bool checkVictory(std::vector<Player> &players); // Checks if a player has won the game

    // Combat Management
    void combat(Player &player, MonsterCard &monsterCard); // Handles combat with a drawn monster card

    // Player Management
    void AddPlayer(Player newPlayer);     // Adds a new player to the game
    std::vector<Player> &GetPlayerList(); // Retrieves the list of players

    // Accessors
    const Deck &GetDoorDeck() const { return doorDeck; }
    const Deck &GetTreasureDeck() const { return treasureDeck; }
    const Deck &GetDoorDiscardDeck() const { return doorDiscardDeck; }
    const Deck &GetTreasureDiscardDeck() const { return treasureDiscardDeck; }
};

#endif
