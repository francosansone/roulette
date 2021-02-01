#include "player/strategies/player_strategy_pair.h"
#include "player/bet.h"

PlayerStrategyPair::PlayerStrategyPair(bool isPair)
    : PlayerStrategy()
{
    bet = new Bet(BetType::PairBet, isPair);
}

Bet PlayerStrategyPair::getBet(){
    return *bet;
}

 