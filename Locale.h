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
            DESC_LONG = longDescription;
            DESC_SHORT = shortDescription;
            DESC_EXAMINE = examineDescription;
            //Doing arr1 = arr2 usually results in arr2 simply referencing arr1 in most languages, and my intuition tells me C++ is the same
        }
        //getters
        std::string getLocationDescription() {
            if(_visited) return _shortDescription;
            return _longDescription;
        }
        int getID() {return _ID;}
        bool getVisited() {return _visited;}
        int getItemByIndex(std::string item) {
            int index = -1;
            for(int i = 0; i < _numItems; i++) {
                if(_items[i] == item) index = i;
            }
            return index;
        }
        //setters
        //other
        void updateVisited() {
            if(!(_visited)) _visited = true;
        }
        void removeItem(int indexAt) {
           _items[indexAt] = "";
        }
        void addItem(std::string item) {
            //First, see if there are any indexes open within the limits of _numItems
            int index = getItemByIndex("");
            if(index > -1) _items[index] = item;
            //Otherwise, put the item at _numItems and increment
            else {
                _items[_numItems] = item;
                _numItems++;
            }
        };
        void printItems() {
            for(int i = 0; i <= _numItems; i++) {
                if (!(_items[i] == "")) std::cout << _items[i] << std::endl;
            }
        }
       void reset() {
           _longDescription = DESC_LONG;
           _shortDescription = DESC_SHORT;
           _examineDescription = DESC_EXAMINE;
           _visited = false;
           //So there's no built-in method to clear arrays (doing _items = new string[100] does not work).
                   //I mean, why would there be?? Jeez
           for(int i = 0; i < 100; i++) _items[i] = "";
           for(int i = 0; i < _numItems; i++) _items[i] = ITEMS[i];
       }
       void copyItems() {
           for (int i = 0; i < 100; i++)  ITEMS[i] = _items[i];
        }
};
//I know I can define the methods outside of the class definition, but why?
#endif //REALITY_LOCALE_H
