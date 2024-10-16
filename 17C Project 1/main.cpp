/* 
 * File:    main.cpp
 * Author:  Tyeson Nguyen
 * Date:    10/7/2024
 * Program: Tiến lên (Thirteen)
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"

using namespace std;

//function declaration
void Deck::SetUpCards()
{
    Card arrCards[52];
    
    //loops setup to initialize every card
    for (int col = (int)Suits::CLUBS; col <= (int)Suits::HEARTS; col++)
    {
        for (int rows = (int)CardNames::THREE; rows <= (int)CardNames::TWO; rows++)
        {
            Card c;
            c.suit = (Suits)col;
            c.name = (CardNames)rows; 
            
            if (c.name == CardNames::JACK)
            {
                c.value = 10;
            }
            if (c.name == CardNames::QUEEN)
            {
                c.value = 10;
            }
            if (c.name == CardNames::KING)
            {
                c.value = 10;
            }
            else
            {
                c.value = (int)c.name;
            }
            
            cout << (int)c.name << " of " << (int)c.value << endl;
            
            int index = (13 * col) + (rows-1);
            arrCards[index] = c;
        }
    }
}

int main() 
{
    Deck deck;
    deck.SetUpCards();
    
    return 0;
}
