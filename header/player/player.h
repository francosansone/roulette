#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <string>
#include <list>

#define PLAYER_DEBUG 0

class Bet;
class PlayerStrategy;

class Player {
    PlayerStrategy *strategy;
    std::string name;
    std::list<int> notepad;
    int lastBet;
    int investedMoney;
    int earnedMoney;

    void initNotepad();
    int moneyFromNotepad();
    void checkBorderConditions();

public:
    Player(std::string name, PlayerStrategy *strategy);

    const std::string getName(){ return name; }

    const Bet makeABet();
    void payBet(bool win, int money = 0);

    const int getInvestedMoney() { return investedMoney; }
    const int getEarnedMoney() { return earnedMoney; }

    void printBalance();

};

#endif