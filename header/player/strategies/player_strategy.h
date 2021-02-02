#ifndef PLAYER_STRATEGY_H
#define PLAYER_STRATEGY_H

/*

This abstract class represents what the players will bet.

I implemented only three simple strategies.

*/


class Bet;

class PlayerStrategy {

public:
    virtual Bet getBet() = 0;

};

#endif