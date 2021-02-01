#include "player/strategies/player_strategy_color.h"
#include "roulette/roulette.h"
#include "player/bet.h"

PlayerStrategyColor::PlayerStrategyColor(int color)
    : PlayerStrategy()

{
    bet = new Bet(BetType::ColorBet, color);
}


Bet PlayerStrategyColor::getBet(){
    return *bet; 
}