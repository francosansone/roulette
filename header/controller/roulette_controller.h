#include <iostream>
#include <list>
#include <vector>
#include "player/bet.h"

class Player;
class Roulette;
class Pocket;

class RouletteController {

    std::vector<Player> players;
    std::vector<Bet> bets;

    long int moneyIn;
    long int moneyOut;

    bool isPlaying;

    Roulette *roulette;
    Pocket *numberWinner;

    void takeBets();
    void spin();
    void payBets();

    bool checkByColor(Bet bet);
    bool checkIsEven(Bet bet);
    bool checkIsHigh(Bet bet);

public:

    RouletteController(Roulette *roulette);
    ~RouletteController();

    void addPlayer(Player player);

    void startPlaying(unsigned int plays);

    void printBalance();
    
};