#include "player/player.h"
#include "player/bet.h"
#include "player/strategies/player_strategy.h"
#include "utils/utils.h"

#include <iostream>

using namespace std;

Player::Player(std::string name, PlayerStrategy *strategy)
    : strategy(strategy)
    , name(name)
    , investedMoney(0)
    , earnedMoney(0)

    
{
    notepad = list<int>();
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
    cout << "notepad of " << name <<":" << endl;
    for(list<int>::iterator it = notepad.begin(); it != notepad.end();++it)
        cout << *it << ", ";
    cout << endl;
#endif
}

int Player::moneyFromNotepad(){
    checkBorderConditions();
    cout << "Player::moneyFromNotepad " << notepad.size() << endl;
    return notepad.front() + notepad.back();
}

const Bet Player::makeABet(){
    Bet bet = strategy->getBet();
    int money = moneyFromNotepad();
    cout << "Player::makeABet " << notepad.size() << endl;
    investedMoney += money;
    lastBet = money;
    bet.money = money;
#if PLAYER_DEBUG
    cout << "Bet of " << name << ": " << money << endl;
#endif
    return bet;
}

void Player::payBet(bool win, int money){

    //cout << "Player::payBet notepad size: " << notepad.size() << endl;

    #if PLAYER_DEBUG
    cout << "notepad of " << name <<":" << endl;
    for(list<int>::iterator it = notepad.begin(); it != notepad.end();++it)
        cout << *it << ", ";
    cout << endl;
    #endif

    int earned = money - lastBet;
    if(win){
        notepad.push_back(earned);
    }
    else {
        notepad.pop_front();
        notepad.pop_back();
    }

#if 0
    cout << "payBet " << name << ": " << money << " " << earnedMoney << " " << investedMoney << endl;
#endif

    earnedMoney += money;

    cout << "Player::payBet notepad size: " << notepad.size() << endl;
}

void Player::printBalance(){

    string output = "\nPlayer ";
    output += name;
    output += "\nInvested: $";
    output += to_string(investedMoney);
    output += " Won: $";
    output += to_string(earnedMoney);
    output += "\n";

    Utils::getInstance()->debug(output.c_str());

}