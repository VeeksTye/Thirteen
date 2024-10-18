#include "Deck.h"
#include <iostream>
#include <cstdlib>
#include <random>

//constructor that calls card set up automatically
Deck::Deck()
{
    SetUpCards();
}
//destructor to free allocated memory
Deck::~Deck()
{
    for (int i = 0; i < 52; i++)
    {
        delete arrCards[i];
    }
}

void Deck::SetUpCards()
{
    int index = 0; //tracks the position in the deck array

    //loop through suits from SPADES to HEARTS
    for (int col = (int)Suits::SPADES; col <= (int)Suits::HEARTS; col++)
    {
        //loop through card names from THREE to TWO
        for (int rows = (int)CardNames::THREE; rows <= (int)CardNames::TWO; rows++)
        {
            //allocates memory for new Card object
            Card* c = new Card; 
            
            //setting suit and card name depending on row and column
            c->suit = (Suits)col;
            c->name = (CardNames)rows;
            
            //for card assigning, starting at 3 of spades
            c->value = (int)c->name;

            //set the play order index, which combines both suit and rank
            c->playOrderIndex = c->value * 4 + col;
            
            //assign the card to the correct position in the array
            arrCards[index] = c;
            index++;  //move to the next position in the deck
        }
    }
}

void Deck::PrintAll()
{
    for (int i = 0; i < 52; i++)  //loop through the deck
    {
        arrCards[i]->PrintSuit();
        std::cout << " ";  //separate each card suit by a space
    }
    std::cout << std::endl;
}

int ShuffleCards()
{
    int min = 4;
    int max = 55;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    
    
    return 0;
}

int DealCards()
{
    return 0;
}