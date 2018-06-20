#include <iostream>
#include <string>
#include "Locale.h"
#include "Player.h"

//Author: Anthony Griggs
//5-24-18
//Reality Text Adventure Game vC++
//Branch part2
//This branch will be concerned with created the Player and Locale objects, and begin creating the utilty functions used by the game.
//Most of my info for writing C++ programs is coming from http://www.cplusplus.com/doc/tutorial/

using namespace std; //used so we don't have to type std::cout


/*
 * Define Locales
 */
string longDesc = "You find yourself in an empty, white space. A void. How? Why? Where? Who? Many thoughts race through your head, with no definitive answer manifesting...";
string shortDesc = "You are nowhere, it seems.";
string examineDesc = "You see nothing of use.";
string items[100];

Locale nowhere(0, items, longDesc, shortDesc, examineDesc);
Locale office(1, items, "You now find yourself in an office. Elegant. Wait. WAIT. What to happened to every, erm, nothing? You were just in the middle of nowhere! This isn't right!", "You're in an office.", examineDesc);
Locale forest(2, items, "The office disappears, and turns into a forest. You being to figure it out: you must be dreaming! You breathe a sigh of relief. Soon this weird dream will all be over, you'll wake up, and return to normal life.", "You're in a forest.", examineDesc);
Locale bed(3, items, "You are in your bed. Finally! It's over.", "Wakey-wakey!", examineDesc);

//Create an array to act as a dictionary for the locales
Locale locations[50] = {nowhere, office, forest, bed};

string cont = "continue";
/*
 *
 * UTILITY FUNCTIONS
 *
 */
//
/*
 * copyright
 * Accepts an int and a boolean
 * prints out a standard copyright message, and acts the gameover message if elligible
 */
bool copyright(int score, bool gameOver) {
    string message = "Copyright Anthony Griggs, Anthony.Griggs1@marist.edu";
    if(gameOver) {
        cout << "Final score: " << score << endl;
        cout << "Gameover!\nThanks for playing!" << endl << message << endl;
        cout << "Play again? y | n";
        cin >> message;
        //TODO: insert prompt for user to restart, once we reach that capability
        if(message == "y") return true;
        return false;

    }
    cout << message;
    return true;
    //TODO: look into a finding a method that will force terminate the program.
}
/*
 * prompt
 * used for prompts for the user to continue
 */
void prompt(string keyword) {
    cout << "<Press enter to " << keyword << ">";
}

/*
 * compareLocations
 * compares two passed Locales by their IDS
 * Hmmmm, this function was tacked on very late in the Python version's development... perhaps it might be redundant?
 */
bool compareLocations(Locale one, Locale two) {
    return one.getID() == two.getID();
}
/*
 * examineLocation
 * prints the examine results at that location, as well as any item that may be there
 */
void examineLocation(Locale locale) {
    cout << locale._examineDescription << endl;
    cout << "You see a/an: " << endl;
    locale.printItems();
}
/*
 *
 *  INITIALIZATION FUNCTION
 *
 */
int main() {
    // << is concatenation
    string dummy;
    cout << dummy;
    if(dummy == "") cout << "true";
    copyright(0, false);
    cout << endl;
    cout << "Please enter your name.";
    getline(cin, dummy);
    //Create the player, initialize their start
    Player mag(dummy, 0);
    //Simulate the first location
    //cout << nowhere.getLocationDescription() << endl;
    cout << locations[mag.GetLocale()].getLocationDescription() << endl; //Just to show what it should like
    prompt(cont);
    getline(cin, dummy); //This seems to work, and will be better to use
    //Second location
    cout << office.getLocationDescription() << endl;
    prompt(cont);
    getline(cin, dummy);
    //Third location
    cout << forest.getLocationDescription() << endl;
    prompt(cont);
    getline(cin, dummy);
    //Final location
    cout << bed.getLocationDescription() << endl;
    prompt(cont);
    getline(cin, dummy);
    cout << "You hop out of bed, eager to start your day. You open the door leading to the rest of your home, and are met with shock." << endl;
    prompt(cont);
    getline(cin, dummy);
    //Final sequence
    cout << "Nothing but shock. Nothing, but, shock. There's nothing. Just the vast empty space you started off in. What is going on?! This cannot be real! You must still be sleeping! Why can't you just wake up?!" << endl;
    prompt(cont);
    getline(cin, dummy);
    //Dios ayudale. It's him.
    cout << "???: Wrong. You cannot be dreaming. In fact, you are more conscious than you've ever been in your life." << endl;
    prompt(cont);
    getline(cin, dummy);

    cout << "Who said that?! And how did they know what you were thinking?! This is starting to feel malicious!" << endl;
    prompt(cont);
    getline(cin, dummy);

    cout << "???: Humans are always so predictable. It's quite dull, really. You are awake. What you see before you, or rather, what you don't, is real. Like it or not, this... this is your reality." << endl;
    //prompt(cont);
    copyright(10, true);
    return 0;
}