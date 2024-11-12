#ifndef CARD_H
#define CARD_H

#include "CardTypes.h"
#include "Player.h"
#include <map>

class Card
{
public:
    Rank name;
    Suits suit;
    int value;
    int playOrderIndex;
    Player playerInfo;

    void PrintSuit();
    bool CanPlay(const &, const &);
};

#endif /* CARD_H */