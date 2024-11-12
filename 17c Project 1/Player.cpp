#include "Player.h"
#include <iostream>

Player::Player()
{
    name = "player";
    score = 0;
    turn = 0;
    skipped = false;
}

Player::Player(std::string n, int s, bool t, bool sp)
{
    name = n;
    score = s;
    turn = t;
    skipped = sp;
}

//WILL BE USED LATER SO PLAYER CAN UPDATE NAME, INDIVIDUALLY CALL SCORE, ETC.
//n = name, s = score, t = turn, sp = skipped
void Player::getName(std::string n)
{
    name = n;
}
    
void Player::getScore(int s)
{
    score = s;
}
    
void Player::getTurn(bool t)
{
    turn = t;
}
    
void Player::getSkip(bool sp)
{
    skipped = sp;
}

std::string Player::setName()
{
    return name;
}
        
int Player::setScore()
{
    return score;
}

bool Player::setTurn()
{
    return turn;
}

bool Player::setSkip()
{
    return skipped;
}