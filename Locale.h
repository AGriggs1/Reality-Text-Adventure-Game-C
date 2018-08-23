#ifndef REALITY_LOCALE_H
#define REALITY_LOCALE_H
#include <iostream>
#include <string>

//TODO: Implement logic for items
//TODO: write out reset function when the time comes
class Locale {
    //private instance variables
    int _ID;
    int _numItems;
    bool _visited;
    std::string _items[100];
    //These are used for resetting everything on restarts
    std::string ITEMS[100];
    std::string DESC_LONG;
    std::string DESC_SHORT;
    std::string DESC_EXAMINE;
    public:
        //public instance variables
        std::string _longDescription;
        std::string _shortDescription;
        std::string _examineDescription;
        bool _searched;
        bool _canTake[100];
        //Null constructor
        Locale() {
            _ID = -1;
            _longDescription = "This location has not been initiated, is this therefore nil. For real this time.";
            _shortDescription = "nil";
            _examineDescription = "nil";
            _visited = false;
            //Don't worry about copying, as this should never actully be used once it's complete
        }

        //Constructor
        Locale(int ID, std::string longDescription, std::string shortDescription, std::string examineDescription) {
            _ID = ID;
            _longDescription = longDescription;
            _shortDescription = shortDescription;
            _examineDescription = examineDescription;
            _visited = false;
            _searched = false;
            DESC_LONG = longDescription;
            DESC_SHORT = shortDescription;
            DESC_EXAMINE = examineDescription;
            //Doing arr1 = arr2 usually results in arr2 simply referencing arr1 in most languages, and my intuition tells me C++ is the same
        }
        //getters
        /*
         * getLocationDescription
         * returns _shortDescription or _longDescription based on whether or not the player has visited the location
         */
        std::string getLocationDescription() {
            if(_visited) return _shortDescription;
            return _longDescription;
        }
        /*
         * getID
         * returns _ID
         */
        int getID() {return _ID;}
        /*
         * getVisited
         * returns _visited
         */
        bool getVisited() {return _visited;}
        /*
         * getItemByIndex
         * accepts a string
         * iterates through the items added to _items
         * if one of those is item, returns the index it was found at
         */
        int getItemByIndex(std::string item) {
            int index = -1;
            for(int i = 0; i < _numItems; i++) {
                if(_items[i] == item) index = i;
            }
            return index;
        }
        //setters
        //other
        /*
         * updateVisited
         * if _visited is false, make _visited true
         */
        void updateVisited() {
            if(!(_visited)) _visited = true;
        }
        /*
         * removeItem
         * sets _items at the passed index to be nothing
         * returns the item that was at that index
         */
        std::string removeItem(int indexAt) {
            std::string item = _items[indexAt];
           _items[indexAt] = "";
           return item;
        }
        /*
         * addItem
         * takes in a string and a boolean
         * adds the given string to _items at whatever free index can be found
         * init determines if this is the first time the item has been placed at this location or not
         */
        void addItem(std::string item, bool init) {
            //First, see if there are any indexes open within the limits of _numItems
            int index = getItemByIndex("");
            if(index > -1) {
                _items[index] = item;
                if(init) _canTake[index] = false;
                else _canTake[index] = true;
            }
            //Otherwise, put the item at _numItems and increment
            else {
                _items[_numItems] = item;
                _numItems++;
                if(init) _canTake[index] = false;
                else _canTake[index] = true;
            }

        }
        /*
         * printItems
         * if examine is false, prints every item at this location
         * otherwise, only prints items whose _canTake index is true
         */
        void printItems(bool examine) {
            for(int i = 0; i <= _numItems; i++) {
                if (!(_items[i] == "")) {
                    if(examine) {
                        if(_canTake[i]) std::cout << _items[i] << std::endl;
                    }
                    else std::cout << _items[i] << std::endl;
                }
            }
        }
        /*
         * reset
         * resets the object
         */
       void reset() {
           _longDescription = DESC_LONG;
           _shortDescription = DESC_SHORT;
           _examineDescription = DESC_EXAMINE;
           _visited = false;
           _searched = false;
           //So there's no built-in method to clear arrays (doing _items = new string[100] does not work).
                   //I mean, why would there be?? Jeez
           for(int i = 0; i < 100; i++) _items[i] = "";
          // for(int i = 0; i < _numItems; i++) _items[i] = ITEMS[i];
       }
       /*
        * copyItems
        * moves strings from ITEMS to _items
        */
       void copyItems() {
           for (int i = 0; i < 100; i++)  ITEMS[i] = _items[i];
        }
};
//I know I can define the methods outside of the class definition, but why?
#endif //REALITY_LOCALE_H