#include "player/strategies/player_strategy_high.h"
#include "player/bet.h"

PlayerStrategyHigh::PlayerStrategyHigh(bool high)
    : PlayerStrategy()
{
    bet = new Bet(BetType::HighBet, high);
}

PlayerStrategyHigh::~PlayerStrategyHigh(){
    delete bet;
}

Bet PlayerStrategyHigh::getBet(){
    return *bet;
}

