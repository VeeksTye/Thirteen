#ifndef DECK_H
#define DECK_H

//include Card.h to make Deck aware of the Card class
//include Player.h to set player hand from deck class
#include "Card.h"
#include "Player.h"

class Deck
{
private:
    Card* arrCards[52];
    Player player[4];
    int choice;
public:
    //default constructor
    Deck();
    ~Deck(); //destructor
    
    void SetUpCards();
    void PrintAll();
    void SetPlayerHand();
    void Menu(int);
    void Instructions();
    
    int randomfunc(int);
    int DealCards();
    
};

#endif /* DECK_H */

