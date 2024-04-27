/*Written by Steve Nwachukwu and Nick Larkin*/
#include "Player.hpp"
Player::Player(string playerName, ECcolor color):playerName(playerName) , colorVal(color) {

} //the constructor for player

ostream& Player::print(ostream& playerOutput) {
    playerOutput << "\nPlayer Name: " << playerName << endl;
    playerOutput << "Player's color: " << colorStrings[(int)colorVal] << endl;
    playerOutput << "Player's score: " << score << endl;
    playerOutput << "The scoreboard: ";
    for (int k = 0; k < score; k++) {
        playerOutput << scoreboard[k] << " ";
    }
    return playerOutput;
} //the print function to output the player's information

ECcolor Player::color() {
    return colorVal;
} //accessor function for color

int Player::getScore() {
    return score;
} //accessor function for the score

bool Player::wonColumn(int colNum) {
    scoreboard[score] = colNum;
    score++;
    if (score >= 3) {
        cout << "You won!" << endl;
        return true;
    }
    else {

        cout << "Not Yet!" << endl;
        return false;
    }
}
