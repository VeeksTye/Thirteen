#ifndef DECK_H
#define DECK_H

//include Card.h to make Deck aware of the Card class
#include "Card.h"

class Deck
{
private:
    Card arrCards[52];
    
public:
    void SetUpCards();
    
};

#endif /* DECK_H */

