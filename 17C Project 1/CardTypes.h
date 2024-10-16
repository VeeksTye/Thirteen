#ifndef CARDTYPES_H
#define CARDTYPES_H

enum class Suits
{
    SPADES,
    CLUBS,
    DIAMONDS,
    HEARTS,
};

enum class CardNames
{
    //due to the fact that the games lowest value is 3, 
    //we will switch the order in which cards are ranked
    //this does NOT effect the   
    THREE = 1,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    TWO,
};

#endif /* CARDTYPES_H */

