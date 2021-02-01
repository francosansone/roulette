#include "roulette/roulette.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

Roulette::Roulette() {
    srand (time(NULL));
}

const Pocket Roulette::spin() {
    unsigned value = rand() % NUMBER_OF_POCKETS;
    return Pocket(value, colors[value]);
}