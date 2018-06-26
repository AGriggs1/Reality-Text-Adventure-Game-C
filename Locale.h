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
            _visited = false;
            //Don't worry about copying, as this should never actully be used once it's complete
        }

        //Constructor
        Locale(int ID, std::string items[], std::string longDescription, std::string shortDescription, std::string examineDescription) {
            _ID = ID;
            _longDescription = longDescription;
            _shortDescription = shortDescription;
            _examineDescription = examineDescription;
            _visited = false;
            DESC_LONG = longDescription;
            DESC_SHORT = shortDescription;
            DESC_EXAMINE = examineDescription;
            //Doing arr1 = arr2 usually results in arr2 simply referencing arr1 in most languages, and my intuition tells me C++ is the same
            for (int i = 0; i < 100; i++) {
                _items[i] = items[i];
                ITEMS[i] = items[i];
                if(items[i] != "") _numItems++; //If the string is blank, it cannot be an item!
            }
        }
        //getters
        std::string getLocationDescription() {
            if(_visited) return _shortDescription;
            return _longDescription;
        }
        int getID() {return _ID;}
      //  int getItemByIndex(std::string item)
        //setters
        //other
        void updateVisited() {
            if(!(_visited)) _visited = true;
        }
       // std::string RemoveItem(std::string item);
   //     bool addItem(std::string item);
        void printItems() {
            for(int i = 0; i <= _numItems; i++) std::cout << _items[i] << std::endl;
        };
     //   void reset();
};
//I know I can define the methods outside of the class definition, but why?
#endif //REALITY_LOCALE_H
