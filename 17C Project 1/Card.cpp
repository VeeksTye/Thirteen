#include "Card.h"
#include <iostream>

void Card::PrintSuit()
{
    if (suit == Suits::SPADES)
    {
        std::cout << "spades";
    }
    else if (suit == Suits::CLUBS)
    {
        std::cout << "clubs";
    }
    else if (suit == Suits::DIAMONDS)
    {
        std::cout << "diamonds";
    }
    else if (suit == Suits::HEARTS)
    {
        std::cout << "hearts";
    }
    
        // Print a space to separate suit and name/value
    std::cout << " ";
    
    // Print the card's name or value
    switch (name)
    {
        case CardNames::THREE:
            std::cout << "3"; 
            break;
        case CardNames::FOUR:
            std::cout << "4"; 
            break;
        case CardNames::FIVE:    
            std::cout << "5"; 
            break;
        case CardNames::SIX:     
            std::cout << "6"; 
            break;
        case CardNames::SEVEN:   
            std::cout << "7"; 
            break;
        case CardNames::EIGHT:   
            std::cout << "8"; 
            break;
        case CardNames::NINE:    
            std::cout << "9"; 
            break;
        case CardNames::TEN:     
            std::cout << "10"; 
            break;
        case CardNames::JACK:    
            std::cout << "Jack"; 
            break;
        case CardNames::QUEEN:   
            std::cout << "Queen"; 
            break;
        case CardNames::KING:    
            std::cout << "King"; 
            break;
        case CardNames::ACE:     
            std::cout << "Ace"; 
            break;
        case CardNames::TWO:     
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