/* 
 * File:    main.cpp
 * Author:  Tyeson Nguyen
 * Date:    10/7/2024
 * Program: Tiến lên (Thirteen)
 */

#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "CardTypes.h"

using namespace std;

//function declaration

int main() 
{
    int choice = 0;
    Deck deck;
    
    deck.Menu(choice);
    deck.PrintAll();
    return 0;
}
