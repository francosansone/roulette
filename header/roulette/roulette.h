#ifndef ROULETTE_H
#define ROULETTE_H

#include <string>

/*

This is the roulette. It has 37 different numbers, with its colors.
Spin will return a random number, simulating the actual spin.

*/

#define NUMBER_OF_POCKETS 37

enum Color {
    Zero,
    Red,
    Black
};


typedef struct Pocket {
    
    Pocket(unsigned number, const Color color) :
        number(number),
        color(color)
    {};

    Pocket(){}

    unsigned number;
    Color color;
}Pocket;

class Roulette 
{
private:
    Color colors[37] = { 
        Zero,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
        Black,
        Red,
    };

public:
    Roulette();

    const Pocket spin();
    
};

#endif