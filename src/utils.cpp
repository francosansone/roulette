#include "utils/utils.h"
#include <ctime>
#include <stdio.h>
#include <filesystem>
#include <bits/stdc++.h> 
#include <iostream> 
#include <sys/stat.h> 
#include <sys/types.h> 

using namespace std;

Utils *Utils::pinstance = 0;
ofstream Utils::debugFile = ofstream();

Utils::Utils(){

    mkdir("log/", 0755);  

    time_t now = time(0);
   
    tm *ltm = localtime(&now);

    fileName = "log/";
    fileName += std::to_string(ltm->tm_mday);
    fileName += ("_");
    fileName += (std::to_string(ltm->tm_mon));
    fileName += ("_");
    fileName += (std::to_string(ltm->tm_hour));
    fileName += ("_");
    fileName += (std::to_string(ltm->tm_hour));
    fileName += (std::to_string(ltm->tm_min));
    fileName += (std::to_string(ltm->tm_sec));
    fileName += ".log";

    debugFile.open(fileName.c_str(), ios_base::app); 
    // We keep the file open for performance reasons
}

Utils *Utils::getInstance(){
    if(pinstance == 0)
        pinstance = new Utils();

    return pinstance;
}

void Utils::debug(const char *data){
    debugFile << data << endl;
    cout << data << endl;
}

void Utils::destroy(){
    debugFile.close();
    delete pinstance;
    pinstance = NULL;
}

string Utils::colorToString(Color color){
    switch (color)
    {
    case Color::Red:
        return "Red";
    
    case Color::Black:
        return "Black";

    case Color::Zero:
        return "Zero";
    }

    return "";
}