#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <list>

class Player
{
private:
    std::string name;
    int score;
    bool turn, skipped;

public:
    //default constructor
    Player();
    Player(std::string, int, bool, bool);
    
    //functions
    std::list<int>& GetHand();
    void AddCard(int card);
    void RemoveCard(int card);
    void sortHand();
    void beginHand();
    
    void getName(std::string);
    void getScore(int);
    void getTurn(bool);
    void getSkip(bool);
    
    std::string setName();
    int setScore();
    bool setTurn();
    bool setSkip();
};

#endif /* PLAYER_H */

