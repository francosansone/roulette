#include "player/bet.h"
#include "utils/utils.h"

Bet::Bet(){};


Bet::Bet(BetType type, int value) :
    type(type),
    value(value)
{}

std::string Bet::toString(){
    std::string output;

    switch (type)
    {
    case BetType::ColorBet:
        output = "[Bet] Type: Color ";
        output += colorValueToString(value);
        break;
    case BetType::EvenBet:
        output = "[Bet] Type: ";
        output += evenValueToString(value);
        break;
    case BetType::HighBet:
        output = "[Bet] ";
        output += highValueToString(value);
        break;
    default:
        output = "";
    }

    return output;
}

std::string Bet::colorValueToString(int value){
    return Utils::colorToString(Color(value));
}

std::string Bet::evenValueToString(bool value){
    if(value)
        return "Is even";

    return "Is odd";
}

std::string Bet::highValueToString(bool value){
    if(value)
        return "Is high";

    return "Is low";
}