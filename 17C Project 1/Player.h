#ifndef PLAYER_H
#define PLAYER_H

#include <string>

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

