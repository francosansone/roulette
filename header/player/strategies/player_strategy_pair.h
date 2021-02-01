#ifndef PLAYER_STRATEGY_PAIR_H
#define PLAYER_STRATEGY_PAIR_H

#include "player/strategies/player_strategy.h"
//#include "roulette/roulette.h"

class PlayerStrategyPair : public PlayerStrategy {
    
    Bet *bet;

public:
    PlayerStrategyPair(bool isPair);

    Bet getBet();

};

#endif