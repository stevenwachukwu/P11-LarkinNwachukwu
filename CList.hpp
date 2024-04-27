//Written by Steve Nwachukwu and Nick Larkin
#ifndef clist
#define clist

#include "tools.hpp"
#include "player.hpp"
using upp = unique_ptr<Player>;

template <typename c>
class Cell {
private:
    c wrapper;
    Cell <c>* next;
public:Cell (c wrapper):wrapper(move(wrapper)) , next (nullptr){}
    template <typename> friend class CList;
    ~Cell() = default;
    c getWrapper() {
        return wrapper;}
};
//---------------------
template <typename t>
class CList {
private:
    int cellCount;
    Cell <t> * head = nullptr;
    Cell <t> * tail;
    Cell <t> * currentCell;
public:
    CList();
    ~CList();
    int count () {return cellCount;};
    bool empty();
    ostream& print(ostream& CListOutput);
    void addCell(Cell<t> * it);
    void init();
    Cell <t> * next();
    void remove();
};
template <typename t> inline ostream& operator << (ostream&  output, CList<t> &c) {return c.print(output);}


template <typename t> CList<t>::CList() : cellCount(0), head(nullptr), tail(nullptr), currentCell(nullptr) {}  //constructor for CList

template <typename t> CList<t>::~CList() {
    currentCell = head;
    Cell<t>* temp = currentCell -> next;
    for (int i = 0; i < cellCount; i++) {
        delete currentCell;
        currentCell = temp;
        temp = temp -> next;
    }
}; //destructor for CList

template <typename t> bool CList<t>::empty() {
    return cellCount == 0;
}

template <typename t> ostream& CList<t>::print(ostream& CO) {
    currentCell = head;
    if (cellCount == 0) {
        return CO;
    }
    for (int i = 0; i < cellCount; i++) {
        currentCell->wrapper->print(CO);
        currentCell = currentCell -> next;
    }
    return CO;
} //CO is the shortened identifier of the output

template <typename t> void CList <t>::addCell(Cell<t> * it) {
    if (head == nullptr && tail == nullptr) {
        head = it;
        tail = it;
        currentCell = head;
        cellCount++;
        return;
    }
    tail -> next = it;
    tail = it;
    it -> next = head;
    cellCount++;
}

template <typename t> void CList <t> ::init() {
    currentCell = head;
}

template <typename t> Cell<t>* CList <t>::next() {
    if (head == nullptr && tail == nullptr) {
        return nullptr;
    }
    currentCell = currentCell -> next;
    return currentCell;
}

template <typename t> void CList <t> ::remove() {
    if (currentCell == nullptr) {
        return;
    }
    if (head == tail) {
        delete currentCell;
        head = tail = currentCell = nullptr;
        cellCount = 0;
        return;
    }
    Cell<t>* prevCell = head;
    while (prevCell->next != currentCell) {
        prevCell = prevCell->next;
    }
    prevCell->next = currentCell->next;
    if (currentCell == head) {
        head = head->next; // the head updates whenever the removed cell was the head
    }
    if (currentCell == tail) {
        tail = prevCell; // the tail updates whenever the removed cell was the tail
    }
    delete currentCell;
    currentCell = prevCell;
    cellCount--;
}
#endif
