#ifndef PLAYER_STRATEGY_EVEN_H
#define PLAYER_STRATEGY_EVEN_H

#include "player/strategies/player_strategy.h"
//#include "roulette/roulette.h"

class PlayerStrategyEven : public PlayerStrategy {
    
    Bet *bet;

public:
    PlayerStrategyEven(bool isEven);
    ~PlayerStrategyEven();

    Bet getBet();

};

#endif