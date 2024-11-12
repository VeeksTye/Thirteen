#ifndef CARDTYPES_H
#define CARDTYPES_H

enum class Suits
{
    //enum class for all the types of card suits
    SPADES,
    CLUBS,
    DIAMONDS,
    HEARTS,
};

enum class Rank
{
    //due to the fact that the games lowest value is 3, 
    //we will switch the order in which cards are ranked
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