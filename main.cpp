#include <iostream>
#include <string>

//Author: Anthony Griggs
//5-24-18
//Reality Text Adventure Game vC++
//Branch Part1
//This branch is concerned with figuring out input/output for the game.
//Most of my info for writing C++ programs is coming from http://www.cplusplus.com/doc/tutorial/

using namespace std; //used so we don't have to type std::cout

//Define our locations as strings for now
string nowhere = "You find yourself in an empty, white space. A void. How? Why? Where? Who? Many thoughts race through your head, with no definitive answer manifesting...";
string office = "You now find yourself in an office. Elegant. Wait. WAIT. What happened to every, erm, nothing? You were just in the middle of nowhere! This isn't right!";
string forest = "The office disappears, and turns into a forest. You begin to figure it out: you must be dreaming! You breathe a sigh of relief. Soon this wierd dream will all be over, you'll wake up, and return to normal life.";
string bed = "You are in your bed. Finally! It's over.";

string cont = "<Press enter to ";
int main() {
    // << is concatenation
    string dummy;
    cout << nowhere << endl << cont << "continue>" << endl; //endl--endline--Would make more sense if it was endln, but whatever
    //Use cin to give the player control?
  //  cin; //Doesn't work. Doing cin >> <string> requires the user to input a character before hitting enter, and that's not what I want.
    getline(cin, dummy); //This seems to work, and will be better to use
    cout << office << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    cout << forest << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    cout << bed << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    return 0;
}