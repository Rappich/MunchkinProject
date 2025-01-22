#include <iostream>
#include "Game.hpp"

int main()
{
    std::cout << "Welcome to the Munchkin Game!" << std::endl;

    // Initialize the game
    Game munchkinGame;

    // Add players
    int numPlayers = 0;
    std::cout << "Enter the number of players (2-6): ";
    std::cin >> numPlayers;

    if (numPlayers < 2 || numPlayers > 6)
    {
        std::cout << "Invalid number of players. The game supports 2 to 6 players." << std::endl;
        return 1;
    }

    for (int i = 1; i <= numPlayers; ++i)
    {
        std::string playerName;
        std::cout << "Enter the name for Player " << i << ": ";
        std::cin >> playerName;
        munchkinGame.AddPlayer(Player(playerName));
    }

    // Start the game
    munchkinGame.startGame();

    // Main game loop
    while (true)
    {
        // Check victory conditions
        if (munchkinGame.checkVictory(munchkinGame.GetPlayerList()))
        {
            std::cout << "Game over. Thanks for playing!" << std::endl;
            break;
        }

        // Get the current player
        std::vector<Player> &players = munchkinGame.GetPlayerList();
        static int turnCounter = 0;
        Player &currentPlayer = players[turnCounter % numPlayers];
        ++turnCounter;

        // Execute the player's turn
        munchkinGame.playerTurn(currentPlayer);

        // End the turn
        munchkinGame.endTurn();
    }

    return 0;
}
