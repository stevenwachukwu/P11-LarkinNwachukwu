/*Written by Steve Nwachukwu and Nick Larkin*/
#ifndef column
#define column
#include "tools.hpp"
#include "Enum.hpp"
#include "player.hpp"

class Column {
private:
    int columnVal [13] = {0, 0, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5,
                          3}; //the array stores the actual column lengths
    short int columnPosition [5]; //the array represents column length and current square positions
    int columnNum;
    enum columnState {Available, Pending, Captured};
    int columnMarker [5] = {-1, -1, -1, -1, -1};
    columnState state = Available;
    const string colstates[3] = {"Available", "Pending", "Captured"};
    int TowerMarker;

public:
    Column(int columnNum); //the constructor
    ~Column(); //the destructor
    int getState();
    ostream& print(ostream& columnOutput);
    bool startTower(Player* player);
    bool move();
    void stop(Player* player);
    void bust(); // Stub function with empty body
};
inline ostream& operator<<(ostream& output, Column& c) {return c.print(output);}
#endif
