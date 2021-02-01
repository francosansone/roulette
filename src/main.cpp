#include<stdio.h>
#include <iostream>
#include "controller/roulette_controller.h"
#include "player/player.h"
#include "roulette/roulette.h"
#include "player/strategies/player_strategy_color.h"
#include "player/strategies/player_strategy_high.h"
#include "player/strategies/player_strategy_pair.h"
 

int main()
{
    Roulette roulette;

    RouletteController controller(&roulette);

    Player playerA(std::string("A"), new PlayerStrategyColor(Color::Red));
    Player playerB(std::string("B"), new PlayerStrategyColor(Color::Black));
    Player playerC(std::string("C"), new PlayerStrategyHigh(true));
    Player playerD(std::string("D"), new PlayerStrategyHigh(false));
    Player playerE(std::string("E"), new PlayerStrategyPair(true));
    Player playerF(std::string("F"), new PlayerStrategyPair(false));
 
    controller.addPlayer(playerA);
    controller.addPlayer(playerB);
    controller.addPlayer(playerC);
    controller.addPlayer(playerD);
    controller.addPlayer(playerE);
    controller.addPlayer(playerF);


    controller.startPlaying(5000);
    

    /* for(int i = 0; i < 500; i++){
        Bet playerABet = playerA.makeABet();

        std::cout << "Player A bet: " << playerABet.money << std::endl;

        Pocket value = roulette.spin();

        int payTo = 0;
        bool win = playerABet.value == value.color;
        if(win){
            payTo = playerABet.money * 2;
        }

        playerA.payBet(win, payTo);

        std::cout << "so we have number " 
            << value.number 
            << " and color " 
            << value.color
            << std:: endl;
    }
 */
/*     std::cout << "Final results: Invested: "
        <<  playerA.getInvestedMoney()
        << "Earned: "
        << playerA.getEarnedMoney(); */

    return 0;
}