#ifndef PLAYER_STRATEGY_COLOR_H
#define PLAYER_STRATEGY_COLOR_H

#include "player/strategies/player_strategy.h"


class PlayerStrategyColor : public PlayerStrategy {

    Bet *bet;

public:
    PlayerStrategyColor(int color);

    Bet getBet();

};

#endif