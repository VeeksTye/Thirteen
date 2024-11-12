#include "Card.h"
#include <iostream>

//the purpose of this class cpp is to convert the class of enums into outputs
void Card::PrintSuit()
{
    if (suit == Suits::SPADES)
    {
        std::cout << "Spades";
    }
    else if (suit == Suits::CLUBS)
    {
        std::cout << "Clubs";
    }
    else if (suit == Suits::DIAMONDS)
    {
        std::cout << "Diamonds";
    }
    else if (suit == Suits::HEARTS)
    {
        std::cout << "Hearts";
    }
    
        // Print a space to separate suit and name/value
    std::cout << " ";
    
    // Print the card's name or value
    switch (name)
    {
        case Rank::THREE:
            std::cout << "3"; 
            break;
        case Rank::FOUR:
            std::cout << "4"; 
            break;
        case Rank::FIVE:    
            std::cout << "5"; 
            break;
        case Rank::SIX:     
            std::cout << "6"; 
            break;
        case Rank::SEVEN:   
            std::cout << "7"; 
            break;
        case Rank::EIGHT:   
            std::cout << "8"; 
            break;
        case Rank::NINE:    
            std::cout << "9"; 
            break;
        case Rank::TEN:     
            std::cout << "10"; 
            break;
        case Rank::JACK:    
            std::cout << "Jack"; 
            break;
        case Rank::QUEEN:   
            std::cout << "Queen"; 
            break;
        case Rank::KING:    
            std::cout << "King"; 
            break;
        case Rank::ACE:     
            std::cout << "Ace"; 
            break;
        case Rank::TWO:     
            std::cout << "2"; 
            break;
        default:                 
            std::cout << "Unknown"; 
            break;
    }
    
    // Print the card's value
    std::cout << " (value: " << playOrderIndex << ")";
    
    // Add a newline for better formatting
    std::cout << std::endl;
}

bool CanPlay(const Card* lastCard, const Card* newCard)
{
    return newCard->playOrderIndex > lastCard->playOrderIndex;
}