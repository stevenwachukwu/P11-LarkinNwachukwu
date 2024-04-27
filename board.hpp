/*Written by Steve Nwachukwu and Nick Larkin*/
#include "column.hpp"
#ifndef board_hpp
#define board_hpp

class Board {
private:
    int towerCounter = 0;
    int towerList[3];
    Column* backBone [13];
    Player* currentPlayer;

public:
    Board();
    ~Board();
    ostream& print(ostream& boardOutput);
    void startTurn(Player*);
    bool move(int column);
    void stop();
    void bust();
};
inline ostream& operator << (ostream& output, Board& b) {return b.print(output);}
#endif
