#include<stdio.h>
#include <iostream>
#include "controller/roulette_controller.h"
#include "player/player.h"
#include "roulette/roulette.h"
#include "player/strategies/player_strategy_color.h"
#include "player/strategies/player_strategy_high.h"
#include "player/strategies/player_strategy_even.h"
#include "utils/utils.h"
 
 #define DEFAULT_PLAYS 10000

int main(int argc, char *argv[])
{
    int plays;
    if(argc > 1){
        plays = atoi(argv[1]);
    } else {
        plays = DEFAULT_PLAYS;
    }

    Roulette roulette;

    RouletteController controller(&roulette);

    Player playerA(std::string("A"), new PlayerStrategyColor(Color::Red));
    Player playerB(std::string("B"), new PlayerStrategyColor(Color::Black));
    Player playerC(std::string("C"), new PlayerStrategyHigh(true));
    Player playerD(std::string("D"), new PlayerStrategyHigh(false));
    Player playerE(std::string("E"), new PlayerStrategyEven(true));
    Player playerF(std::string("F"), new PlayerStrategyEven(false));
 
    controller.addPlayer(playerA);
    controller.addPlayer(playerB);
    controller.addPlayer(playerC);
    controller.addPlayer(playerD);
    controller.addPlayer(playerE);
    controller.addPlayer(playerF);
 
    controller.startPlaying(plays);

    controller.printBalance();

    Utils::getInstance()->destroy();
    
    return 0;
}