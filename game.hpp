/*Written by Steve Nwachukwu and Nick Larkin*/

#ifndef game
#define game

#include "tools.hpp"
#include "dice.hpp"
#include "column.hpp"
#include "player.hpp"
#include "board.hpp"
#include "CList.hpp"

class Game {
private:
    Dice* dices;
    Player player1;
    Board Printer;
    void Gameroll();
    void Gamestop();
    void checkData();
    CList <Player> activePlayers;

public:
    Game(); //the constructor for game
    ~Game(); //the destructor for game
    void getNewPlayer();
    void oneTurn(Player* pp);
    void start();
    ifstream inputFile2;
    void getPlayers();

};
#endif
