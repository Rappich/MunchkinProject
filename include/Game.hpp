#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Deck.hpp"

class Game 
{
private:
    int currentTurn;
    std::string gameState;
   
    std::vector<Player> players;
    
public:
    Game();
    void startGame();
    void playerTurn(Player& player);
    void endTurn();
    bool checkVictory(std::vector<Player>& players);
    void combat(Player &player, Card &drawnDoorCard);

    Deck doorDeck;
    Deck treasureDeck;
    Deck doorDiscardDeck;
    Deck treasureDiscardDeck;

    //Getters
    std::vector<Player>& GetPlayerList() {return players;}

    //Setters
    void AddPlayer(Player newPlayer);
};

#endif