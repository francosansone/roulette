#ifndef PLAYER_STRATEGY_HIGH_H
#define PLAYER_STRATEGY_HIGH_H

#include "player/strategies/player_strategy.h"

//class Bet;

class PlayerStrategyHigh : public PlayerStrategy {

    Bet *bet;

public:
    PlayerStrategyHigh(bool high);

    Bet getBet();

};

#endif