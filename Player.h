//
// Created by Anthony on 6/14/2018.
//
#ifndef REALITY_PLAYER_H
#define REALITY_PLAYER_H

#include <string>
#include "Locale.h"

class Player {

    //private instance variables
    int _currentLocaleID;
    int _score;
    int _moves;
    std::string _inventory[100];
    public:
        //public instance variables
        std::string _name;
        //Constructor
            Player(std::string name, int startLocaleID) {
                _name = name;
                _currentLocaleID = startLocaleID;
                _score = 0;
                _moves = 0;
            }


};


#endif //REALITY_PLAYER_H
