#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <string>

#include "roulette/roulette.h"

using namespace std;

class Utils {

    Utils();
    static Utils *pinstance;

    string fileName;
    static ofstream debugFile;

public:

    static Utils *getInstance();

    void debug(const char *data);

    void destroy();

    static string colorToString(Color color);

};

#endif