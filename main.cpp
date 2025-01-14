#include "Game.hpp"
#include "MonsterCards.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    Game Munchkin;

    std::cout << "Enter player name: " << std::endl;
    std::string inputName;
    std::cin >> inputName;
    Player player1 = {inputName};
    std::cout << "Enter player2's name: " << std::endl;
    std::cin >> inputName;
    Player player2 = inputName;
    Munchkin.AddPlayer(player1);
    //Munchkin.AddPlayer(player2);

     Munchkin.startGame();
     bool playerWin = false;
     do
     {
         for (Player &player : Munchkin.GetPlayerList())
         {
             Munchkin.playerTurn(player);
             playerWin = Munchkin.checkVictory(Munchkin.GetPlayerList());
             if(playerWin)
             {
                 break;
             }
         }
     } while (!playerWin);

       // Get all monster data
    // auto monsters = getMonsterData();

    // //Simulate drawing a random monster card
    // srand(time(0)); // Seed for randomness
    // int randomIndex = rand() % monsters.size();
    // const MonsterData &drawnMonster = monsters[randomIndex];

    //Display the drawn monster
    //displayMonsterDetails(drawnMonster);

    //If needed, initialize the monster as a Card for further actions
    //Card monsterCard = initializeMonster(drawnMonster);

    //Example: Use the monsterCard in combat or other logic
    //std::cout << "The monster " << monsterCard.name << " is ready for combat!\n";

    return 0; 

    
}
