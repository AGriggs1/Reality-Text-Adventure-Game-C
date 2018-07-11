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
    int _numItems;
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
                _numItems = 0;
        }
        //Getters
        int getLocale() {return _currentLocaleID;}
        int getScore() {return _score;}
        int getMoves() {return _moves;}
        int getItemByIndex(std::string item) {
            int index = -1;
            for(int i = 0; i < _numItems; i++) {
                if(_inventory[i] == item) index = i;
            }
            return index;
        }
        //Setters
        void updateID(int newLocaleID) {
            _currentLocaleID = newLocaleID;
            _moves++;
            }
        void setMoves(int moves) {_moves = moves;}
       // void SetScore(int score) {_score = score;}
        void updateScore(int score) {_score += score;} //This seems more pratical
        bool addItem(std::string item) {
            int index = getItemByIndex("");
            if(index > -1) _inventory[index] = item;
                //Otherwise, put the item at _numItems and increment
            else {
                _inventory[_numItems] = item;
                _numItems++;
            }
        }
        void removeItem(int indexAt) {
            _inventory[indexAt] = "";
        }
        void printItems() {
            for(int i = 0; i < _numItems; i++) {
                if (!(_inventory[i] == "")) std::cout << _inventory[i];
            }
        }
        void clearInventory() {
            for(int i = 0; i < _numItems; i++) _inventory[i] = "";
            _numItems = 0;
        }
};


#endif //REALITY_PLAYER_H
