#include <string>

enum BetType {
    ColorBet,
    EvenBet,
    HighBet,
};


class Bet {
    std::string colorValueToString(int value);
    std::string evenValueToString(bool value);
    std::string highValueToString(bool value);
public:
    BetType type;
    int value;
    unsigned money;

    Bet();

    Bet(BetType type, int value);

    std::string toString();
};