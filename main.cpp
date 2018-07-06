#include <iostream>
#include <string>
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
string examineDesc = "You see nothing of use.";
string items[100];
Locale voidDummy(0, items, longDesc, "NULL", "NULL");
Locale voidC(1, items, "You are in the center circle. So. Where to first?", "You are standing on the center circle.", examineDesc);

Locale voidN(2, items, "You follow the line North. Once you reach the circle, you notice it has the letter 'N' on it. "
                       "The void transforms into a lush forest teeming with pine trees. You hear the wind breeze through the trees, "
                       "the songs of birds and feel welcome.", "You are at the forest", examineDesc);

Locale voidS(3, items, "You follow one of the lines to a circle that has the letter 'S' on it. "
                       "The area around transforms. Now you at the edge of a cliff overlooking the open sea. You hear the waves crashing "
                       "against the crags below, which resemble hungry teeth tearing into the vast watters, eager to do the same to you. You feel a sense of somberness.",
                       "You're at the cliffside", examineDesc);

Locale voidE(4, items, "You follow the line leading East, stopping at the circle with the letter 'E' on it. "
                       "The area transforms into the ruins of city. Cars rusted, buildings overgrown with moss and vines. Nature has reclaimed what it once lost."
                       " You can't help but feel curious about the fate of this place.", "You are at the city ruins.", examineDesc);

Locale voidW(5, items, "You head West, coming to a circle with the letter 'W' on it. The area transforms,"
                                    " and now you are in an office. Desks overflowing with paperwork and the inescapable stench of stale cofee makes you feel anxious.",
                          "You are at the office", examineDesc);




//Locale nowhere(0, items, longDesc, shortDesc, examineDesc);
//Locale office(1, items, "You now find yourself in an office. Elegant. Wait. WAIT. What to happened to every, erm, nothing? You were just in the middle of nowhere! This isn't right!", "You're in an office.", examineDesc);
//Locale forest(2, items, "The office disappears, and turns into a forest. You being to figure it out: you must be dreaming! You breathe a sigh of relief. Soon this weird dream will all be over, you'll wake up, and return to normal life.", "You're in a forest.", examineDesc);
//Locale bed(3, items, "You are in your bed. Finally! It's over.", "Wakey-wakey!", examineDesc);

//Create an array to act as a dictionary for the locales
Locale na(-1, items, "This is stupid", "Seriously.", examineDesc); //So my null constructor is officially useless, because that creates a syntax error when used in arrays
//Also NULL doesn't work either because why would it?
Locale locations[50] = {voidDummy, voidC, voidN, voidS, voidE, voidW};
//NavMat
        //navigator[localeID][iDirection] = Locale
                //0 = North, 1 = South, 2 = East, 3 = West
Locale navigator[50][4] = {
        {na, na, na, na},
        {voidN, voidS, voidE, voidW}, //voidC
        {na, voidC, na, na}, //voidN
        {voidC, na, na, na}, //voidS
        {na, na, na, voidC}, //voidE
        {na, na, voidC, na} //voidW
};

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
 * compareIgnoreCase
 * compares two strings to see if they are the same, ignoring case
 */
bool compareIgnoreCase(string one, string two) {
    if(one.length() != two.length()) return false;
    for(int i = 0; i < one.length(); i++) {
        char a = one.at(i);
        char b = two.at(i);
        a = toupper(a);
        b = toupper(b);
        if(a != b) return false;
    }
    return true;
}
/*
 *
 * GAMEPLAY FUNCTIONS
 *
 */

/*
 * tutorial
 * simulates the game on a much smaller scale to give the player a chance to learn the ropes
 * returns true if the player quit
 * return false if completed
 */
bool tutorial(Player love) {
    //TODO: tutorial
    bool completed = false;
    cout <<  "Suddenly a circle appears beneath your feet, with lines going in four directions, ultimately leading to four circles."
             "\n\n<Type 'North', 'South', 'East', or 'West' to head in that direction. Type 'Help' to view all available commands.>" << endl;
    while(!completed) {
        string command;
        cout << locations[love.getLocale()].getLocationDescription() << endl;
        getline(cin, command);
        locations[love.getLocale()].updateVisited();
        //Check what the command was...
        //navigation
        if(compareIgnoreCase(command, "north")) {
            int localeID = navigator[love.getLocale()][0].getID();
            if(localeID > -1) love.updateID(localeID);
            else cout << "You cannot go that way." << endl;
        }
        else if(compareIgnoreCase(command, "south")) {
            int localeID = navigator[love.getLocale()][1].getID();
            if(localeID > -1) love.updateID(localeID);
            else cout << "You cannot go that way." << endl;
        }
        else if(compareIgnoreCase(command, "east")) {
            int localeID = navigator[love.getLocale()][2].getID();
            if(localeID > -1) love.updateID(localeID);
            else cout << "You cannot go that way." << endl;
        }
        else if(compareIgnoreCase(command, "west")) {
            int localeID = navigator[love.getLocale()][3].getID();
            if(localeID > -1) love.updateID(localeID);
            else cout << "You cannot go that way." << endl;
        }
        //other commands
        else if(compareIgnoreCase(command, "quit")) return true;
        else if(compareIgnoreCase(command, "help")) cout << "List of commands:\n"
                                           "Quit - ends the game\n"
                                           "Help - shows help\n"
                                           "North - moves north\n"
                                           "South - moves south\n"
                                           "East - moves east\n"
                                           "West - moves west\n"
                                           "Look - displays the long description of your current location\n"
                                           "Score - displays your current score\n"
                                           "Moves - displays your current moves\n";
        else if(compareIgnoreCase(command, "look")) cout << locations[love.getLocale()]._longDescription << endl;
        else if(compareIgnoreCase(command, "score")) cout << "score: " << love.getScore() << endl;
        else if(compareIgnoreCase(command, "moves")) cout << "moves: " << love.getMoves() << endl;
        else if(command == "I know what I am doing I know that not all control paths return a value will you just run and not assume me to be an idiot?") completed = true;
        if(!locations[love.getLocale()].getVisited()) love.updateScore(5);
    }
    return false;
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
    prompt("acknowledge the disembodied voice");
    getline(cin, dummy);
    cout << "???: Good. You're awake. About time! I was getting sooooo bored of just watching you sleep!\n\nDoesn't feel right isn't enough to describe this. What is going on here??" << endl;
    prompt(cont);
    getline(cin, dummy);
    cout << "???: You look confused! Do you remember your name? Ya know, that thing people call you? Yeah. That!\n<Enter your name>\n";
    cin >> dummy;
    //TODO: Fun with names ;)
    cout << "???: " << dummy << "? Let's see... gotcha. Your cognitive abilities don't seem to be compromised...  I sense that you want answers. I get it, but I must follow 'protocols.' "
                                " Ethics and all that human rights junk. Bleeeeh. Boring, really, but hey, it's a living. Let's just test your sense of orientation. Then we'll talk." << endl;
    Player mag(dummy, 1);
    prompt(cont);
    getline(cin, dummy); //Why? I have no idea. It's just the only way I could get it to work

    //Begin tutorial
    tutorial(mag);
    return copyright(mag.getScore(), true);

}

int main() {
    while(init());
    return 0;
}
bool dumm = copyright(0, false);