/*Written by Steve Nwachukwu and Nick Larkin*/
#ifndef dice
#define dice


#include "tools.hpp"

class Dice {
private:
    int nDice;

protected:
    int* diceVal;
public:
    Dice(int n);
    virtual ~Dice();
    ostream& print(ostream&);
    virtual const int* roll();
};

class CantStopDice:public Dice {
private:
    int dicePair [2];
public:
    CantStopDice();
    virtual const int* roll();
};

class FakeDice:public CantStopDice {
private:
    ifstream inputFile;

public:
    FakeDice();
    virtual ~FakeDice() override;
    virtual const int *roll() override;
};

inline ostream& operator << (ostream& output, Dice& d) {return d.print(output);}

#endif
