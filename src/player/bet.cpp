#include "player/bet.h"

Bet::Bet(){};


Bet::Bet(BetType type, int value) :
    type(type),
    value(value)
{}