#include "player/strategies/player_strategy_color.h"
#include "roulette/roulette.h"
#include "player/bet.h"

PlayerStrategyColor::PlayerStrategyColor(int color)
    : PlayerStrategy()

{
    bet = new Bet(BetType::ColorBet, color);
}

PlayerStrategyColor::~PlayerStrategyColor(){
    delete bet;
}


Bet PlayerStrategyColor::getBet(){
    return *bet; 
}