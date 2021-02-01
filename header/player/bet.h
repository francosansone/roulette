enum BetType {
    ColorBet,
    PairBet,
    HighBet,
};


class Bet {
public:
    BetType type;
    int value;
    unsigned money;

    Bet();

    Bet(BetType type, int value);
};