#ifndef PLAYER_STRATEGY_H
#define PLAYER_STRATEGY_H

class Bet;

class PlayerStrategy {

public:
    virtual Bet getBet() = 0;

};

#endif