#include "player/player.h"
#include "player/bet.h"
#include "player/strategies/player_strategy.h"
#include <iostream>

Player::Player(std::string name, PlayerStrategy *strategy)
    : strategy(strategy)
    , name(name)
    , investedMoney(0)
    , earnedMoney(0)

    
{
    notepad = std::list<int>();
    notepad.push_back(1);
    notepad.push_back(2);
    notepad.push_back(3);
    notepad.push_back(4);
}

void Player::initNotepad(){
    notepad.clear();
    notepad.push_back(1);
    notepad.push_back(2);
    notepad.push_back(3);
    notepad.push_back(4);
}

void Player::checkBorderConditions(){
    if(notepad.size() < 2){
        initNotepad();
    } else if(notepad.front() + notepad.back() < 5)
        initNotepad();
    else if(notepad.front() + notepad.back() > 4000)
        initNotepad();
#if PLAYER_DEBUG
    std::cout << "notepad of " << name <<":" << std::endl;
    for(std::list<int>::iterator it = notepad.begin(); it != notepad.end();++it)
        std::cout << *it << ", ";
    std::cout << std::endl;
#endif
}

int Player::moneyFromNotepad(){
    checkBorderConditions();
    return notepad.front() + notepad.back();
}

const Bet Player::makeABet(){
    Bet bet = strategy->getBet();
    int money = moneyFromNotepad();
    investedMoney += money;
    lastBet = money;
    bet.money = money;
#if PLAYER_DEBUG
    std::cout << "Bet of " << name << ": " << money << std::endl;
#endif
    return bet;
}

void Player::payBet(bool win, int money){
    int earned = money - lastBet;
    if(win){
        notepad.push_back(earned);
    }
    else {
        notepad.pop_front();
        notepad.pop_back();
    }

    earnedMoney += money;
}