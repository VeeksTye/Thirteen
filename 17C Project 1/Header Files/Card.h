#ifndef CARD_H
#define CARD_H

#include "CardTypes.h"
#include "Player.h"

class Card
{
public:
    CardNames name;
    Suits suit;
    int value;
    int playOrderIndex;
    
    Player playerInfo;
    
    //functions
    void PrintSuit();
    bool CanPlay(const &, const &);
};

#endif /* CARD_H */

