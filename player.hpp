/*Written by Steve Nwachukwu and Nick Larkin*/
#ifndef player_hpp
#define player_hpp
#include "Enum.hpp"
#include "tools.hpp"

class Player {
private:
    string playerName;
    ECcolor colorVal;
    int score = 0;
    int scoreboard [3];


public:
    Player() = default;
    //constructors and destructor for player
    Player(string playerName, ECcolor color);
    ~Player() = default;
    ECcolor color();
    ostream& print(ostream& playerOutput);
    int getScore();
    bool wonColumn(int colNum);
};

class BadPlayer {
protected:
    string incorrectPlayer;
public:
    BadPlayer (string bp):incorrectPlayer(bp) {};
    virtual string basePrint (){
        return string ("Your invalid input was "  + incorrectPlayer);
    }
};

class BadName:public BadPlayer {
    string incorrectName;
public:
    BadName (const string& bn): BadPlayer(bn) {
    };
    string basePrint () override {
        return string ("Name is already being used " + incorrectName);
    }
};

class BadColor:public BadPlayer {
    string incorrectColor;
public:
    BadColor (const string bc) : BadPlayer(bc) {
    };
    string basePrint() override {
        return incorrectColor + "Wrong color input!";
    }
};

class BadChoice {
    string incorrectChoice;
public:
    BadChoice(string bdChoice):incorrectChoice(bdChoice) {};
    virtual string basePrint () {
        return string("Your invalid choice was " + incorrectChoice);
    }
};

class DuplicateSlot:public BadChoice {
    string incorrectDuplicateSlot;
public:
    DuplicateSlot(string ds) : BadChoice(ds) {}
    string basePrint() override {
        return string("Duplicate slot selected: " + incorrectDuplicateSlot);
    }
};

class BadSlot : public BadChoice {
    int incorrectBadSlot;
public:
    BadSlot(int errorCode) : BadChoice("the improper value that was detected"), incorrectBadSlot(errorCode) {}
    string basePrint() override {
        return "Error code: " + to_string(incorrectBadSlot) + ", " + BadChoice::basePrint();
    }
};

inline ostream& operator << (ostream&  output, Player& p) {return p.print(output);}
#endif
