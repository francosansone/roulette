#include "player/strategies/player_strategy_even.h"
#include "player/bet.h"

PlayerStrategyEven::PlayerStrategyEven(bool isEven)
    : PlayerStrategy()
{
    bet = new Bet(BetType::EvenBet, isEven);
}

PlayerStrategyEven::~PlayerStrategyEven(){
    delete bet;
}

Bet PlayerStrategyEven::getBet(){
    return *bet;
}

 