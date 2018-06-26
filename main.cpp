#include <iostream>
#include <string>
#include "Locale.h"
#include "Player.h"

//Author: Anthony Griggs
//5-24-18
//Reality Text Adventure Game vC++
//Branch part3
//In this branch, we'll finally get some gameplay! This version will focus on simple commands and navigation between Locales
//Most of my info for writing C++ programs is coming from http://www.cplusplus.com/doc/tutorial/

using namespace std; //used so we don't have to type std::cout


/*
 * Define Locales
 */
string longDesc = "You find yourself in an empty, white space. A void. How? Why? Where? Who? Many thoughts race through your head, with no definitive answer manifesting...";
string shortDesc = "You are nowhere, it seems.";
string examineDesc = "You see nothing of use.";
string items[100];
Locale voidDummy(0, items, longDesc, "NULL", "NULL");

//Locale nowhere(0, items, longDesc, shortDesc, examineDesc);
//Locale office(1, items, "You now find yourself in an office. Elegant. Wait. WAIT. What to happened to every, erm, nothing? You were just in the middle of nowhere! This isn't right!", "You're in an office.", examineDesc);
//Locale forest(2, items, "The office disappears, and turns into a forest. You being to figure it out: you must be dreaming! You breathe a sigh of relief. Soon this weird dream will all be over, you'll wake up, and return to normal life.", "You're in a forest.", examineDesc);
//Locale bed(3, items, "You are in your bed. Finally! It's over.", "Wakey-wakey!", examineDesc);

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
        if(message.at(0) == 'y' || message.at(0) == 'Y') return true; //it would seem that strings do not have a case-insensitive comparison, or a way to change case...
        return false;

    }
    cout << message;
    return true;
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
 * GAMEPLAY FUNCTIONS
 *
 */
void tutorial(Player love) {
    //TODO: tutorial
    bool completed = false;
    //while(!completed){}
}
/*
 *
 *  INITIALIZATION FUNCTION
 *
 */
bool init() {
    // << is concatenation
    string dummy;
    cout << endl;
    //Player mag(dummy, 0);
    //Begin prologue!
    cout << locations[0].getLocationDescription() << endl;
    prompt(cont);
    getline(cin, dummy);
    cout << "???: Hello? Heellllooo? Can you hear me?\n\nHuh? Where is that voice coming from? This doesn't feel right..." << endl;
    prompt("acknowledge the disembodied voice>");
    cout << "???: Good. You're awake. About time! I was getting sooooo bored of just watching you sleep!\n\nDoesn't feel right isn't enough to describe this. What is going on here??" << endl;
    prompt(cont);
    cout << "???: You look confused! Do you remember your name? Ya know, that thing people call you? Yeah. That!\n\n<Enter your name>\n";
    cin >> dummy;
    //TODO: Fun with names ;)
    cout << "???: " << dummy << "? Let's see... gotcha. Your cognitive abilities don't seem to be compromised...  I sense that you want answers. I get it, but I must follow 'protocols.' "
                                " Ethics. Bleeeeh. Boring, really, but hey, it's a living. Let's just test your sense of orientation. Then we'll talk." << endl;
    prompt(cont);
    Player mag(dummy, 1);
    //Begin tutorial
    tutorial(mag);
    return copyright(mag.getScore(), true);

}

int main() {
    while(init());
    return 0;
}
bool dumm = copyright(0, false);