#include "player/strategies/player_strategy_high.h"
#include "player/bet.h"

PlayerStrategyHigh::PlayerStrategyHigh(bool high)
    : PlayerStrategy()
{
    bet = new Bet(BetType::HighBet, high);
}

Bet PlayerStrategyHigh::getBet(){
    return *bet;
}

