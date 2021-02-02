#include "controller/roulette_controller.h"
#include "roulette/roulette.h"
#include "player/player.h"
#include "utils/utils.h"

#include <stdexcept>

using namespace std;

RouletteController::RouletteController(Roulette *roulette)
    : moneyIn(0)
    , moneyOut(0)
    , isPlaying(false)
    , roulette(roulette)
{
    numberWinner = new Pocket();
}

RouletteController::~RouletteController(){
    //delete roulette;
    //delete numberWinner;
}

void RouletteController::addPlayer(Player player){
    if(isPlaying) return;
    for(unsigned i = 0; i < players.size(); i++){
        if(players[i].getName() == player.getName()){
            throw invalid_argument("Player's name is repeated");
        }
    }
    players.push_back(player);
}

void RouletteController::startPlaying(unsigned int plays){
    isPlaying = true;

    for(unsigned int i = 0; i < plays; i++){
        string output = "\n**** Start play number ";
        output += to_string(i);
        output += " ****";

        Utils::getInstance()->debug(output.c_str());

        takeBets();
        spin();
        payBets();
    }

    isPlaying = false;
}

void RouletteController::takeBets(){
    string output;
    Utils::getInstance()->debug("\nTaking bets");

    bets.clear();
    for(unsigned i = 0; i < players.size(); i++){
        Bet bet = players[i].makeABet();
        moneyIn += bet.money;
        bets.push_back(bet);

        output = "Player ";
        output += players[i].getName();
        output += " bet to ";
        output += bet.toString();


        Utils::getInstance()->debug(output.c_str());
    }
}

void RouletteController::spin(){
    *numberWinner = roulette->spin();
    string output = "Spin result: ";
    output += to_string(numberWinner->number);
    output += " ";
    output += Utils::colorToString(numberWinner->color);

    Utils::getInstance()->debug(output.c_str());
}

void RouletteController::payBets(){
    Utils::getInstance()->debug("paying bets");
    for(unsigned i = 0; i < players.size(); i++){
        Bet bet = bets[i];
        bool win = false;
        int pay = 0;

        switch (bet.type)
        {
        case BetType::ColorBet:
            win = checkByColor(bet);
            if(win){
                pay = bet.money * 2;
            }    
            break;

        case BetType::EvenBet:
            win = checkIsEven(bet);
            if(win){
                pay = bet.money * 2;
            }    
            break;

        case BetType::HighBet:
            win = checkIsHigh(bet);
            if(win){
                pay = bet.money * 2;
            }
            break;
        }

        moneyOut += pay;

        players[i].payBet(win, pay);

        string output = "Paying to ";
        output += players[i].getName();
        output += " ";
        output += to_string(pay);

        Utils::getInstance()->debug(output.c_str());
    }
}

bool RouletteController::checkByColor(Bet bet){
    return Color(bet.value) == numberWinner->color;
}

bool RouletteController::checkIsEven(Bet bet){
    if(bet.value)
        return numberWinner->number % 2 == 0;
    else
        return numberWinner->number % 2 != 0;
}

bool RouletteController::checkIsHigh(Bet bet){
    if(bet.value)
        return numberWinner->number > 18;
    else
        return numberWinner->number <= 18;

}

void RouletteController::printBalance() {

    string output = "----------------------------------------";
    output += "\n";
    output += "FINAL RESULTS";

    Utils::getInstance()->debug(output.c_str());

    for(unsigned i = 0; i < players.size(); i++)
        players[i].printBalance();

    string output2 = "Casino: \n";
    output2 += "Input: $";
    output2 += to_string(moneyIn);
    output2 += "\noutput: $";
    output2 += to_string(moneyOut);
    output2 += "\n";

    Utils::getInstance()->debug(output2.c_str());

    Utils::getInstance()->debug("----------------------------------------");
    
}
