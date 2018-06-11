#ifndef REALITY_LOCALE_H
#define REALITY_LOCALE_H
#include <iostream>
#include <string>


class Locale {
    //private instance variables
    int _ID;
    bool _visited;
    std::string _items[100];
    //These are used for resetting everything on restarts
    std::string ITEMS[100];
    std::string DESC_LONG;
    std::string DESC_SHORT;
    std::string DESC_EXAMINE;
    public:

        Locale(int ID, std::string items[], std::string longDescription, std::string shortDescription, std::string examineDescription) {
            _ID = ID;
          //  _items = items; Not even allowed to create a reference. Cool. Nice. Easy. Intuitive.
            _longDescription = longDescription;
            _shortDescription = shortDescription;
            _examineDescription = examineDescription;
            _visited = false;
            DESC_LONG = longDescription;
            DESC_SHORT = shortDescription;
            DESC_EXAMINE = examineDescription;
            //so getting the size of the array through something like arr.size() doesn't work, despite my IDE listing it. What is wrong with this language?
            //So if I wanted the size of the array, I'd also have to pass its length in the constructor, but nah.
            //Doing arr1 = arr2 usually results in arr2 simply referencing arr1 in most languages, and my intuition tells me C++ is the same
            for(int i = 0; i < 100; i++) {
                _items[i] = items[i];
                ITEMS[i] = items[i];
            }
        }
        //public instance variables
        std::string _longDescription;
        std::string _shortDescription;
        std::string _examineDescription;
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
    //    void printItems();
     //   void reset();
};
//I know I can define the methods outside of the class definition, but why?
#endif //REALITY_LOCALE_H
