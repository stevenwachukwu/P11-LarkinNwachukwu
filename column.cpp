/*Written by Steve Nwachukwu and Nick Larkin*/
#include "column.hpp"

Column::Column(int columnNum):columnNum(columnNum) {TowerMarker = -1;}


Column::~Column(){}

int Column::getState() {
    return state;
}
void Column::bust() {

} //bust function
bool Column::move() {
    // Check if any player has a tile in this column
    TowerMarker +=1;
    if (TowerMarker == columnVal[columnNum]) {
        state = Pending;
    }
    cout << TowerMarker << endl;
    return true;
}

bool Column::startTower(Player * player) {
    // Check if the player has a tile in this column
    if (columnMarker[(int)player->color()] != -1) {
        // Player already has a tile in this column, find the next available square
        int nextSquare = columnMarker[(int)player->color()] +1;
        TowerMarker = columnMarker[(int)player->color()] +1;

        // Check if moving to the next square would capture the column
        if (nextSquare == columnVal[columnNum]) {
            // Move would capture the column, set state to pending
            state = Pending;
            return false;
        }

        // Move tower to the next square
        columnMarker[(int)player->color()] = nextSquare;
    } else {
        // Player has no tile in this column, place tower at position 1
        columnMarker[(int)player->color()] = 0;
        TowerMarker = 0;
    }

    return true;
}

void Column::stop(Player * player) {
    // Get the color of the player's tiles
    string tileColor = colorStrings[(int)player->color()];
    columnMarker [(int)player->color()] = TowerMarker;
    TowerMarker = -1;
    if (state == Pending) {
        state = Captured;
        player -> wonColumn(columnNum);
    }
}
    ostream& Column::print (ostream& columnOutput) {
        columnOutput << columnNum << " " << colstates[state] << " ";
        char c;
        for (int k = 0; k < columnVal[columnNum]; k++) {
             c = '-';
            if (k == TowerMarker) {
                c = 'T';
            }
            else {
            for (int j = 0; j < 5; j++) {
                if (columnMarker[j] == k) {
                    c = MarkerColorStrings[j];
                }
            }
          }
            columnOutput << c;
        }
        return columnOutput;
    }
