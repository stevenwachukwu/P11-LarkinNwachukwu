/*Written by Steve Nwachukwu and Nick Larkin*/
#include <iostream>
#include <fstream>
#include "dice.hpp"
#include "player.hpp"
#include "tools.hpp"
#include "Enum.hpp"
#include "column.hpp"
#include "game.hpp"
#include "board.hpp"
#include "CList.hpp"

//function prototypes for the program
void testGame(Game&);
void unitCList();
//-----------------------------------------------
int main() {
    Game gaming;
    gaming.start();
    //unitCList();
    bye();
    return 0;
}
//-----------------------------------------------

void unitCList() {
    ofstream CListNames ("CList.txt");

    upp test1 = make_unique <Player> (Player("Jacob", ECcolor::blue));
    upp test2 = make_unique <Player> (Player("Derek", ECcolor::green));
    upp test3 = make_unique <Player> (Player("Olivia", ECcolor::orange));
    upp test4 = make_unique <Player> (Player("Sadie", ECcolor::white));

Cell<upp> * person1 = new Cell <upp>(move (test1));
Cell<upp> * person2 = new Cell <upp>(move (test2));
Cell<upp> * person3 = new Cell <upp>(move (test3));
Cell<upp> * person4 = new Cell <upp>(move (test4));

CList <upp> obj;
obj.addCell(person1);
obj.addCell(person2);
obj.addCell(person3);
obj.addCell(person4);
obj.print(CListNames);
obj.init();
obj.next();
obj.remove();
obj.print(cout);

obj.remove();

obj.remove();

obj.remove();

upp test5 = make_unique <Player> (Player("Marcus", ECcolor::blue));
upp test6 = make_unique <Player> (Player("Kelly", ECcolor::green));
upp test7 = make_unique <Player> (Player("Maria", ECcolor::orange));
upp test8 = make_unique <Player> (Player("Lucas", ECcolor::white));

Cell<upp> * person5 = new Cell <upp>(move (test5));
Cell<upp> * person6 = new Cell <upp>(move (test6));
Cell<upp> * person7 = new Cell <upp>(move (test7));
Cell<upp> * person8 = new Cell <upp>(move (test8));

obj.addCell(person5);
obj.addCell(person6);
obj.addCell(person7);
obj.addCell(person8);

obj.init();
obj.next();
obj.next();
obj.next();
obj.next();
obj.print(CListNames);
} //the unit test for CList
