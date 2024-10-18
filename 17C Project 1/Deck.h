#ifndef DECK_H
#define DECK_H

//include Card.h to make Deck aware of the Card class
#include "Card.h"

class Deck
{
private:
    Card* arrCards[52];
    
public:
    //default constructor
    Deck();
    ~Deck(); //destructor
    
    void SetUpCards();
    void PrintAll();
    int ShuffleCards();
    int DealCards();
};

#endif /* DECK_H */

