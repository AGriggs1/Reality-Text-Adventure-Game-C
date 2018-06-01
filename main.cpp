#include <iostream>
#include <string>

//Author: Anthony Griggs
//5-24-18
//Reality Text Adventure Game vC++
//Branch part2
//This branch will be concerned with created the Player and Locale objects, and begin creating the utilty functions used by the game.
//Most of my info for writing C++ programs is coming from http://www.cplusplus.com/doc/tutorial/

using namespace std; //used so we don't have to type std::cout

//Define our locations as strings for now
string nowhere = "You find yourself in an empty, white space. A void. How? Why? Where? Who? Many thoughts race through your head, with no definitive answer manifesting...";
string office = "You now find yourself in an office. Elegant. Wait. WAIT. What happened to every, erm, nothing? You were just in the middle of nowhere! This isn't right!";
string forest = "The office disappears, and turns into a forest. You begin to figure it out: you must be dreaming! You breathe a sigh of relief. Soon this wierd dream will all be over, you'll wake up, and return to normal life.";
string bed = "You are in your bed. Finally! It's over.";

string cont = "<Press enter to ";
/*
 *
 * UTILITY FUNCTIONS
 *
 */

/*
 * copyright
 * Accepts an int and a boolean
 * prints out a standard copyright message, and acts the gameover message if elligible
 */
bool copyright(int score, bool gameOver) {
    string message = "Copyright Anthony Griggs, Anthony.Griggs1@marist.edu";
    if(gameOver) {
        cout << "Final score: " << score << endl;
        cout << "Gameover!\nThanks for playing!" << endl << message;
        //TODO: insert prompt for user to restart, once we reach that capability
        return false;
    }
    cout << message;
    //TODO: look into a finding a method that will force terminate the program.
}
/*
 *
 *  INITIALIZATION FUNCTION
 *
 */
int main() {
    // << is concatenation
    string dummy;
    copyright(0, false);
    cout << endl;
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
    cout << "You hop out of bed, eager to start your day. You open the door leading to the rest of your home, and are met with shock." << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    cout << "Nothing but shock. Nothing, but, shock. There's nothing. Just the vast empty space you started off in. What is going on?! This cannot be real! You must still be sleeping! Why can't you just wake up?!" << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    //Dios ayudale. It's him.
    cout << "???: Wrong. You cannot be dreaming. In fact, you are more conscious than you've ever been in your life." << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    cout << "Who said that?! And how did they know what you were thinking?! This is starting to feel malicious!" << endl << cont << "continue>" << endl;
    getline(cin, dummy);
    cout << "???: Humans are always so predictable. It's quite dull, really. You are awake. What you see before you, or rather, what you don't, is real. Like it or not, this... this is your reality." << endl << cont << "continue>" << endl;
    copyright(10, true);
    return 0;
}