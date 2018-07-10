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
Locale closet(6, items, "The void transforms completely, transforms... into a broom closet. Huh.", "You return to the broom closet.", "Nothing but useless junk.");
Locale hallway1(7, items, "You enter a hallway and come to a corner", "You are at a hallway corner.", examineDesc);
Locale officeNW(8, items, "You enter one of the office corners.", "You are in the Northwest corner of the office.", "The place is a mess. Papers and various other supplies litter the floor.");
Locale officeW(9, items, "You come to a room and nothing but cubicles. So you're in an office, then.", "You are in the office", "Cubicles, cubicles, cubicles.");
Locale officeSW(10, items, "You enter one of the office corners, which has a particularly large ficus. You study it with intensity.", "You are in the Southwest corner of the office.", "What. A. Ficus.");
Locale officeN(11, items, "You enter a cublicle that is larger than the rest. It looks it supposed to fit four, maybe five people. The thought makes you claustrophobic.", "You enter the large cubicle.", examineDesc);
Locale officeC(12, items, "You enter the center of the office. The center of the universe.", "You are in the center of the office.", examineDesc);
Locale officeS(13, items, "You find a pair of doors. What lies beyond them?", "You head towards the double doors.", "The doors won't budge. Looks like you need a key.");
Locale officeNE(14, items, "You enter one of the office corners. There is a watercooler, but its empty.", "You are in the Northeast corner of the office.", "Could really use some water... ugh.");
Locale officeE(15, items, "You are now on the other side of the office. Something feels off, or maybe you're just sick of this place.", "You are in the office", examineDesc);
Locale officeSE(16, items, "You enter one of the office corners, and are met with a portrait of a sad clown. Pardon?", "You are in the Southeast corner of the office", "The nameplate reads: 'Chairman Bozo, may he grace you with his gaze. Yeah, moving on...");
Locale hallway2(17, items, "You walk down a hallway, and come to a corner.", "You are at a hallway corner.", examineDesc);



//Locale nowhere(0, items, longDesc, shortDesc, examineDesc);
//Locale office(1, items, "You now find yourself in an office. Elegant. Wait. WAIT. What to happened to every, erm, nothing? You were just in the middle of nowhere! This isn't right!", "You're in an office.", examineDesc);
//Locale forest(2, items, "The office disappears, and turns into a forest. You being to figure it out: you must be dreaming! You breathe a sigh of relief. Soon this weird dream will all be over, you'll wake up, and return to normal life.", "You're in a forest.", examineDesc);
//Locale bed(3, items, "You are in your bed. Finally! It's over.", "Wakey-wakey!", examineDesc);

//Create an array to act as a dictionary for the locales
Locale na(-1, items, "This is stupid", "Seriously.", examineDesc); //So my null constructor is officially useless, because that creates a syntax error when used in arrays
//Also NULL doesn't work either because why would it?
Locale locations[50] = {voidDummy, voidC, voidN, voidS, voidE, voidW,
                        closet, hallway1, officeNW, officeW, officeSW,
                        officeN, officeC, officeS, officeNE, officeE,
                        officeSE, hallway2};
//NavMat
        //navigator[localeID][iDirection] = Locale
                //0 = North, 1 = South, 2 = East, 3 = West
Locale navigator[50][6] = {
        {na, na, na, na, na, na},
        {voidN, voidS, voidE, voidW}, //------------------voidC
        {na, voidC, na, na}, //---------------------------voidN
        {voidC, na, na, na}, //---------------------------voidS
        {na, na, na, voidC}, //---------------------------voidE
        {na, na, voidC, na}, //---------------------------voidW

        {hallway1, na, na, na}, //------------------------closet
        {na, closet, officeW, na}, //---------------------hallway1
        {na, officeW, officeN, na}, //--------------------officeNW
        {officeNW, officeSW, officeC, hallway1}, //-------officeW
        {officeW, na, officeS, na}, //--------------------officeSW
        {na, officeC, na, officeNW}, //-------------------officeN
        {officeN, officeS, officeE, officeW}, //----------officeC
        {officeC, na, officeSE, officeSW}, //-------------officeS
        {na, officeE, na, na}, //-------------------------officeNE
        {officeNE, officeSE, hallway2, officeC}, //-------officeE
        {officeE, na, na, officeS}, //--------------------officeSE
        {na, na, na, officeE} //--------------------------hallway2
};

Player Luca("nil", 1);
string cont = "continue";

/*
 *
 * UTILITY FUNCTIONS
 *
 */
Locale NAVMAT[50][6];
/*
 * copyNav
 * used for creating a copy of the navigation matrix specifically
 *
 */
void copyNav(bool reverse) {
    for(int i = 0; i < 50; i ++) {
        if(reverse){
            navigator[i][0] = NAVMAT[i][0];
            navigator[i][1] = NAVMAT[i][1];
            navigator[i][2] = NAVMAT[i][2];
            navigator[i][3] = NAVMAT[i][3];
            navigator[i][4] = NAVMAT[i][4];
            navigator[i][5] = NAVMAT[i][5];
        }
        else {
            NAVMAT[i][0] = navigator[i][0];
            NAVMAT[i][1] = navigator[i][1];
            NAVMAT[i][2] = navigator[i][2];
            NAVMAT[i][3] = navigator[i][3];
            NAVMAT[i][4] = navigator[i][4];
            NAVMAT[i][5] = navigator[i][5];
        }
    }
}
/*
 * copyright
 * Accepts an int and a boolean
 * prints out a standard copyright message, and acts the gameover message if elligible
 */
bool copyright(int score, bool gameOver) {
    string message = "Copyright Anthony Griggs, Anthony.Griggs1@marist.edu";
    if(gameOver) {
        string dummy; //So the program doesn't crash if you don't enter anything
        cout << "Final score: " << score << endl;
        cout << "Gameover!\nThanks for playing!" << endl << message << endl;
        cout << "Play again? y | n";
        cin >> message;
        getline(cin, dummy);
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
 * decipher
 * takes in a player and a string
 * if the string is a valid command, does that command
 */
void decipher(string command) {
    if(compareIgnoreCase(command, "north")) {
        int localeID = navigator[Luca.getLocale()][0].getID();
        if(localeID > -1) Luca.updateID(localeID);
        else cout << "You cannot go that way." << endl;
    }
    else if(compareIgnoreCase(command, "south")) {
        int localeID = navigator[Luca.getLocale()][1].getID();
        if(localeID > -1) Luca.updateID(localeID);
        else cout << "You cannot go that way." << endl;
    }
    else if(compareIgnoreCase(command, "east")) {
        int localeID = navigator[Luca.getLocale()][2].getID();
        if(localeID > -1) Luca.updateID(localeID);
        else cout << "You cannot go that way." << endl;
    }
    else if(compareIgnoreCase(command, "west")) {
        int localeID = navigator[Luca.getLocale()][3].getID();
        if(localeID > -1) Luca.updateID(localeID);
        else cout << "You cannot go that way." << endl;
    }
        //other commands
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
    else if(compareIgnoreCase(command, "look")) cout << locations[Luca.getLocale()]._longDescription << endl;
    else if(compareIgnoreCase(command, "examine")) cout << locations[Luca.getLocale()]._examineDescription << endl;
    else if(compareIgnoreCase(command, "score")) cout << "score: " << Luca.getScore() << endl;
    else if(compareIgnoreCase(command, "moves")) cout << "moves: " << Luca.getMoves() << endl;
    else cout << "That is not a valid command." << endl;
   // return Luca.getLocale();
}

/*
 * resetMain
 * resets locales and the navigation matrix, as well as anything else that may have changed
 */
void resetMain() {
    //TODO: deepcopy function for navigator
    copyNav(true);
    for(int i = 0; i < 6; i++) locations[i].reset();
    Luca.updateID(1);
    Luca.updateScore(-Luca.getScore());
    Luca.setMoves(0);
}
/*
 * switchLocations
 * Takes two sets of rows and columns for the navigation matrix
 * Switches the locations at those rows and columns with each other
 */
void switchLocations(int r1, int c1, int r2, int c2) {
    Locale temp = navigator[r1][c1];
    navigator[r1][c1] = navigator[r2][c2];
    navigator[r2][c2] = temp;
}
/*
 * replaceLocation
 * Replaces a Locale at a row and column of the Navigation Maxtrix with another Locale
 */
void replaceLocation(int r, int c, Locale cola) {
    navigator[r][c] = cola;
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
bool tutorial() {
    bool completed = false;
    cout <<  "Suddenly a circle appears beneath your feet, with lines going in four directions, ultimately leading to four circles."
             "\n\n<Type 'North', 'South', 'East', or 'West' to head in that direction. Type 'Help' to view all available commands.>" << endl;
    while(!completed) {
        string command;
        cout << locations[Luca.getLocale()].getLocationDescription() << endl;
        getline(cin, command);
        locations[Luca.getLocale()].updateVisited();
        //Check what the command was...
        if(compareIgnoreCase(command, "quit")) return false;
        decipher(command);

        if(!locations[Luca.getLocale()].getVisited()) Luca.updateScore(5);
        if(locations[2].getVisited() && locations[3].getVisited() &&  locations[4].getVisited() && locations[5].getVisited()) completed = true;
    }
    return true;
}
bool game() {
    bool completed = false;
    while(!completed) {
        string command;
        cout << locations[Luca.getLocale()].getLocationDescription() << endl;
        getline(cin, command);
        locations[Luca.getLocale()].updateVisited();
        if(compareIgnoreCase(command, "quit")) return false;
        decipher(command);
        if(!locations[Luca.getLocale()].getVisited()) Luca.updateScore(5);
        if(Luca.getLocale() == officeC.getID()) {
            //Switch the hallways
            switchLocations(officeW.getID(), 3, officeE.getID(), 2);
            //Fix the navigation matrix
            //Make it so that going west from hallway2 no longer leads to officeW
            replaceLocation(navigator[officeW.getID()][3].getID(), 3, na);
            //Make it so that going east from hallway2 now leads to officeW
            replaceLocation(navigator[officeW.getID()][3].getID(), 2, officeW);
            //Vice versa
            replaceLocation(navigator[officeE.getID()][2].getID(), 2, na);
            replaceLocation(navigator[officeE.getID()][2].getID(), 3, officeE);
        }
        if(command == "No Luca no") completed = true; //Placeholder. Also reference ftw
    }
}
/*
 *
 *  INITIALIZATION FUNCTION
 *
 */
bool init() {
    // << is concatenation
    copyNav(false);
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
    //Player mag(dummy, 1);

    Luca._name = dummy;
    prompt(cont);
    getline(cin, dummy);
    getline(cin, dummy);


    //Begin tutorial
    if(tutorial()) {
        cout << "???: Excellent. Subject condition is optimal.\n\nOptimal?" << endl;
        prompt(cont);
        getline(cin, dummy);
        cout << "???: We haven't been properly acquainted, now have we? I... am Bx106001-c. I am a Generation IV Class C Artificial Intelligence. Call me baby!" << endl;
        cout << "Baby: I promised you we would talk things out, didn't I? Well, it's a long story. What would you like to know?" << endl;
        cin >> dummy;
        //Baby: No.
        cout << "Baby: ERROR: Access denied." << endl;
        //Let's do the makeshift way first
        for(int i = 0; i < 100000; i++);
        for(int i = 0; i < 100; i++) cout << "Ex002334" << i << " CRITICAL: Bx106001-c IV h#s @eC$trrr an iS*&e @0mpr%S$sG &Eof-Sufficient 0$per@tions!" << endl;
        cout << "Baby: Sorry about that. Had a little hiccup! Where were we? Oh yeah! We were going to begin the simulation! That's right!" << endl;
        prompt("protest");
        getline(cin, dummy);
        getline(cin, dummy);
        cout << "Baby: Nuh-uh-uh, we went over this! All subjects must pass our simulations in order to be granted freedom! That's what you want, right? You want out. You'll get your out, if you pass!\n"
                "\nFreedom? Are you... a captive? Looks like that 'hiccup' fried this hunk of metal's brain. Just go along with it, who knows what this thing'll do." << endl;
        prompt(cont);
        getline(cin, dummy);
        cout << "Baby: Enough talk. Humans bore me." << endl;
        prompt("begin");
        getline(cin, dummy);
        Luca.updateID(6);
        Luca.setMoves(0);
        game();
    }
    return copyright(Luca.getScore(), true);

}

int main() {
    while(init()) resetMain();
    return 0;
}
bool dumm = copyright(0, false);