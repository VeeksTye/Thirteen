#ifndef DECK_H
#define DECK_H

//include Card.h to make Deck aware of the Card class
//include Player.h to set player hand from deck class
#include "Card.h"
#include "Player.h"
#include <list>
#include <queue>
#include <stack>

class Deck
{
private:
    Card* arrCards[52];
    Player player[4];
    
    std::list<int> round;
    std::stack<int> players;
    std::queue<int> turn;
    
    std::list<int> hand[4];
    std::list<int> play;
    
    int choice;
    int currentPlayer;
    bool activePlayers[4] = {true, true, true, true};
    
public:
    //default constructor
    Deck();
    ~Deck(); //destructor
    
    void SetUpCards();
    //void PrintAll();      Can be used later for debugging
    void SetPlayerHand();
    void PrintHand(std::list<int>);
    void Menu(int, int);
    void Instructions();
    void PrintRound(int);

    void GameLoop();
    void InitializeTurnOrder(int startingPlayer);
    
    bool isValidPlay(int, std::list<int>);
    bool PlayerTurn(int playerIndex);
    void resetActivePlayers();
    int DealCards();
};

#endif /* DECK_H */