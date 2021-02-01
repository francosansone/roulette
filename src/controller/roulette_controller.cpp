#include "controller/roulette_controller.h"
#include "roulette/roulette.h"
#include "player/player.h"

#include <stdexcept>

RouletteController::RouletteController(Roulette *roulette)
    : isPlaying(false)
    , roulette(roulette)
{}

void RouletteController::addPlayer(Player player){
    if(isPlaying) return;
    for(unsigned i = 0; i < players.size(); i++){
        if(players[i].getName() == player.getName()){
            throw std::invalid_argument("Player's name is repeated");
        }
    }
    players.push_back(player);
}

void RouletteController::startPlaying(unsigned int plays){
    isPlaying = true;

    for(unsigned int i = 0; i < plays; i++){
        takeBets();
        spin();
        payBets();
    }

    isPlaying = false;

    std::cout << "Results: "
        << "Money in: "
        << moneyIn
        << "Money paid"
        << moneyOut;
}

void RouletteController::takeBets(){
    bets.clear();
    for(unsigned i = 0; i < players.size(); i++){
        Bet bet = players[i].makeABet();
        moneyIn += bet.money;
        bets.push_back(bet);
    }
}

void RouletteController::spin(){
    roulette->spin();
}

void RouletteController::payBets(){
    for(unsigned i = 0; i < bets.size(); i++){
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

        case BetType::PairBet:
            win = checkIsPair(bet);
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

        default:
            break;
        }

        moneyOut += pay;

        players[i].payBet(win, pay);
        
    }
}

bool RouletteController::checkByColor(Bet bet){
    return Color(bet.value) == numberWinner->color;
}

bool RouletteController::checkIsPair(Bet bet){
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