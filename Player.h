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
        /*
         * returns _currentLocaleID, the ID of the Locale the player is at
         */
        int getLocale() {return _currentLocaleID;}
        /*
         * getScore
         * returns _score
         */
        int getScore() {return _score;}
        /*
         * getMoves
         * returns _moves
         */
        int getMoves() {return _moves;}
        /*
         * getItemByIndex
         * iterates _inventory
         * if the passed string, item is found, return the index it was found at
         * otherwise return -1
         */
        int getItemByIndex(std::string item) {
            int index = -1;
            for(int i = 0; i < _numItems; i++) {
                if(_inventory[i] == item) index = i;
            }
            return index;
        }
        //Setters
        /*
         * updateID
         * used for navigation
         * changes _currentLocaleID to reflect the player's movement
         * increments _moves
         */
        void updateID(int newLocaleID) {
            _currentLocaleID = newLocaleID;
            _moves++;
            }
        /*
         * setMoves
         * overrides _moves with the passed parameter
         */
        void setMoves(int moves) {_moves = moves;}
       // void SetScore(int score) {_score = score;}
        /*
         * updateScore
         * adds the passed int to _score
         */
        void updateScore(int score) {_score += score;} //This seems more pratical
        /*
         * addItem
         * Finds an open index in _inventory, and adds the passed string to that index
         */
        void addItem(std::string item) {
            int index = getItemByIndex("");
            if(index > -1) _inventory[index] = item;
                //Otherwise, put the item at _numItems and increment
            else {
                _inventory[_numItems] = item;
                _numItems++;
            }
        }
        /*
         * removeItem
         * sets the item at indexAt to nothing, and returns the item found at indexAt
         */
        std::string removeItem(int indexAt) {
            std::string item = _inventory[indexAt];
            _inventory[indexAt] = "";
            return item;
        }
        /*
         * printItem
         * prints all items in the player's inventory
         */
        void printItems() {
            std::cout << "Inventory:\n";
            for(int i = 0; i < _numItems; i++) {
                if (!(_inventory[i] == "")) std::cout << _inventory[i] << std::endl;
            }
        }
        /*
         * clearInventory
         * removes all items in the player's inventory
         */
        void clearInventory() {
            for(int i = 0; i < _numItems; i++) _inventory[i] = "";
            _numItems = 0;
        }
};


#endif //REALITY_PLAYER_H
