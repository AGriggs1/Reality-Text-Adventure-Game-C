#include <iostream>
#include <string>
#include "Player.h"

//Author: Anthony Griggs
//5-24-18
//Reality Text Adventure Game vC++
//Branch part4
//This branch will focus on implementing items.

using namespace std; //used so we don't have to type std::cout

/*
 * Define Locales
 */
                //It would seem that it is only possible to pass empty strings to an object, making passing them at all pointless
                // We'll to do it manually.
                // Story of my life.                                                                                                                                                                        string blockN = "N-block";
string blockS = "S-block";
string blockE = "E-block";
string blockW = "W-block";
string longDesc = "You find yourself in an empty, white space. A void. How? Why? Where? Who? Many thoughts race through your head, with no definitive answer manifesting...";
string examineDesc = "";
string items[100];
Locale voidDummy(0, longDesc, "NULL", "NULL");
Locale voidC(1, "You are in the center circle. So. Where to first?", "You are standing on the center circle.", examineDesc);


Locale voidN(2, "You follow the line North. Once you reach the circle, you notice it has the letter 'N' on it. "
                       "The void transforms into a lush forest teeming with pine trees. You hear the wind breeze through the trees, "
                       "the songs of birds and feel welcome.", "You are at the forest", examineDesc);

Locale voidS(3, "You follow one of the lines to a circle that has the letter 'S' on it. "
                       "The area around transforms. Now you at the edge of a cliff overlooking the open sea. You hear the waves crashing "
                       "against the crags below, which resemble hungry teeth tearing into the vast watters, eager to do the same to you. You feel a sense of somberness.",
                       "You're at the cliffside", examineDesc);

Locale voidE(4, "You follow the line leading East, stopping at the circle with the letter 'E' on it. "
                       "The area transforms into the ruins of city. Cars rusted, buildings overgrown with moss and vines. Nature has reclaimed what it once lost."
                       " You can't help but feel curious about the fate of this place.", "You are at the city ruins.", examineDesc);

Locale voidW(5, "You head West, coming to a circle with the letter 'W' on it. The area transforms,"
                                    " and now you are in an office. Desks overflowing with paperwork and the inescapable stench of stale coffee makes you feel anxious.",
                          "You are at the office", examineDesc);
Locale closet(6, "The void transforms completely, transforms... into a broom closet. Huh.", "You return to the broom closet.", "You rifle through the shelves");
Locale hallway1(7, "You enter a hallway and come to a corner", "You are at a hallway corner.", "There is a glass panel on the wall with what looks a map of this place.\n"
                                                                                               "   c1--C   c6     \n"
                                                                                               "   |   |   |      \n"
                                                                                               "b--c2--c4--c7--d  \n"
                                                                                               "|  |   |   |   |  \n"
                                                                                               "a  c3--c5--c8  e  \n"
                                                                                               "       |          \n"
                                                                                               "       |          \n"
                                                                                               "   51--n1--40     \n"
                                                                                               "     - |  +      \n"
                                                                                               "   50--n2--48     \n"
                                                                                               "     + |  -      \n"
                                                                                               "   45--n3--42     \n"
                                                                                               "     = |  =      \n"
                                                                                               "     = 46 =       \n "
                                                                                               "You are at: b");
Locale officeNW(8, "You enter one of the office corners.", "You are in the Northwest corner of the office.", "The place is a mess. Papers and various other supplies litter the floor.");
Locale officeW(9, "You come to a room and nothing but cubicles. So you're in an office, then.", "You are in the office", "Cubicles, cubicles, cubicles.");
Locale officeSW(10, "You enter one of the office corners, which has a particularly large ficus. You study it with intensity.", "You are in the Southwest corner of the office.", "What. A. Ficus.");
Locale officeN(11, "You enter a cubicle that is larger than the rest. It looks it supposed to fit four, maybe five people. The thought makes you claustrophobic.", "You enter the large cubicle.", "You try one of the computers."
                                                                                                                                                                                                   "It boots up to reveal a text document, which reads:\n"
                                                                                                                                                                                                   "'The running water chases the setting sun. Where they meet,"
                                                                                                                                                                                                   "reveals the secret of their origin.'");
Locale officeC(12, "You enter the center of the office. The center of the universe.", "You are in the center of the office.", examineDesc);
Locale officeS(13, "You find a pair of doors. What lies beyond them?", "You head towards the double doors.", "The doors won't budge. Looks like you need a key.");
Locale officeNE(14, "You enter one of the office corners. There is a watercooler, but its empty.", "You are in the Northeast corner of the office.", "Could really use some water... ugh.");
Locale officeE(15, "You are now on the other side of the office. Something feels off, or maybe you're just sick of this place.", "You are in the office", examineDesc);
Locale officeSE(16, "You enter one of the office corners, and are met with a portrait of a sad clown. Pardon?", "You are in the Southeast corner of the office", "The nameplate reads: 'Chairman Bozo, may he grace you with his gaze. Yeah, moving on...");
Locale hallway2(17, "You walk down a hallway, and come to a corner.", "You are at a hallway corner.", examineDesc);

Locale forest(18, "You pass through a pair of doors, and well... now you're in a forest. You look behind you, and the building you were just in has completely vanished. Well then.",
"You are in the forest.", "You can faintly hear what sounds like running water in the distance. A nearby notice board catches your attention. it reads:\n"
                         "New Pena National Forest\n"
                         "e             \n"
                         "|             \n"
                         "g--f--h--i    \n"
                         "         |    \n"
                         "      j--k    \n"
                         "         |    \n"
                         "         l--m \n"
                         "\nExplore one of the many cave systems found within our beautiful forest! See the incantation circles where locals performed their rituals! Book your guided tour now!\n"
                         "WARNING: Cave spelunking can a dangerous activity, especially for the untrained! DO NOT EXPLORE UNAUTHORIZED AREAS ALONE OR WITHOUT A TRAINED PARK GUIDE!");
Locale river(19, "You continue down a dirt pathway, coming to a riverbank. You here what sounds like thunder in the distance", "You are at the river", "Just a river.");
Locale lake(20, "You follow the river, eventually finding yourself at a large lake.", "You are at the lake.", "You walk along the shores, keeping an eye out for any interesting finds.");
Locale waterfall(21, "You follow the river to a watefall. Looks pretty tall.", "You are at the waterfall.", "You take a look around the area.");
Locale caveE(22, "You go behind the waterfall, and the find the entrance to a cavern.", "You are behind the waterfall.", "You take a look around.");
Locale cave(23, "You enter the cave. It's pitch black.", "You are in the cavern.", "");
Locale deepCave(24, "You continue onward, inching slowly. You eventually come to an small chamber with a small opening to the surface, allowing you to see."
                    "You take notice of the many symbols drawn on the chamber floor in what could be chalk. Whatever it is, looks like it's for ritualistic purposes",
                "You are in a cave chamber.", "");
Locale ravine(25, "You take a step foward, unaware that there is no surface for you step on. You fall, tumbling down, down, down... You hit the bottom of a ravine,"
                  "hard. You can't see what's broken, but it doesn't feel good. You begin to slip out of consciousness.", "You're at the bottom of a ravine.", "");
Locale watertop(26, "Following the river's current, you come across the top of a waterfall. Looks pretty tall from here.", "It's the top of a waterfall. Again.", "");
//Create an array to act as a dictionary for the locales
Locale na(-1, "This is stupid", "Seriously.", examineDesc); //So my null constructor is officially useless, because that creates a syntax error when used in arrays
//Also NULL doesn't work either because why would it?
Locale locations[50] = {voidDummy, voidC, voidN, voidS, voidE, voidW,
                        closet, hallway1, officeNW, officeW, officeSW,
                        officeN, officeC, officeS, officeNE, officeE,
                        officeSE, hallway2, forest, river, lake, waterfall,
                        caveE};
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
        {na, na, na, officeE}, //-------------------------hallway2
        {na, river, na, na}, //---------------------------forest
        {forest, na, waterfall, lake}, //-----------------river
        {na, na, river, na}, //---------------------------lake
        {na, na, caveE, river}, //------------------------waterfall
        {na,cave, na, waterfall}, //----------------------caveE
        {caveE, ravine, na, deepCave}, //-----------------cave
        {na, na, cave, na}, //----------------------------deepCave
        {cave, na, na, na,}, //---------------------------ravine
        {na, na, river, waterfall} //---------------------watertop
};
//Define Items
bool canTakeItem[100] = {};
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
 * makeUpper
 * Takes in a string and converts all characters to be in upppercase
 */
string makeUpper(string cappy) {
    string CAPPY;
    for(int i = 0; i < cappy.length(); i++) {
        char a = cappy.at(i);
        a = toupper(a);
        CAPPY += a;
    }
    return CAPPY;
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
void examineLocation(int localeID) {
    cout << locations[localeID]._examineDescription << endl;
    cout << "You see a/an: " << endl;
    locations[localeID].printItems(false);
    locations[localeID]._searched = true;

}
/*
 * take
 * takes the item at the given locale, if possible
 */
bool take(int localeID, string item) {
    //First, check if the item is here
    int index = locations[localeID].getItemByIndex(makeUpper(item));
    if(index == -1) return false;
    //Has the player searched the location? If so, they are free to take the item
    if(locations[localeID]._searched) {
            Luca.addItem(locations[localeID].removeItem(index));
            return true;
    }
    //otherwise, see if the item was dropped here
    else if(locations[localeID]._canTake[index]){
        Luca.addItem(locations[localeID].removeItem(index));
        return true;
    }
    return false;
}
/*
 * drop
 * drops the given item at the given locale, if the player has it
 */
bool drop(int localeID, string item) {
    int index = Luca.getItemByIndex(makeUpper(item));
    if(index == -1) return false;
    locations[localeID].addItem(Luca.removeItem(index), false);
    return true;
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
    //take
    else if(compareIgnoreCase(command.substr(0, 4), "take")) {
        //See if this is a two-word command... try to take with what should be the second half...


        if(command.length() > 4) {
            string item = command.substr(5, command.length());
            if(take(Luca.getLocale(), item)) cout << "took the " << item << endl;
            else cout << "Could not find item " << item << endl;
        }
        //Otherwise, prompt for what item the player wants
        else {
            int numItems = 0;
            cout << "Take what?\n";
            for(int i = 0; i < 30; i++) {
                if(locations[Luca.getLocale()]._canTake[i] == true) numItems++;
            }
            if(numItems > 0 || locations[Luca.getLocale()]._searched) {
                locations[Luca.getLocale()].printItems(!locations[Luca.getLocale()]._searched);
                getline(cin, command);
                if(take(Luca.getLocale(), command)) cout << "took the" << command << endl;
                else cout << "Could not find " << command;
            }
        }
    }
    //drop
    else if(compareIgnoreCase(command.substr(0, 4), "drop")) {
        if(command.length() > 4) {
            string item = command.substr(5, command.length());
            if(drop(Luca.getLocale(), item)) cout << "dropped the " << item << endl;
            else cout << "You do not have any " << item;
        }
        else {
            cout << "Drop what?\n";
        }
    }
        //other commands
    else if(compareIgnoreCase(command, "help")) cout << "List of commands:\n"
                                                        "Quit - ends the game\n"
                                                        "Help - shows help\n"
                                                        "North - moves north\n"
                                                        "South - moves south\n"
                                                        "East - moves east\n"
                                                        "West - moves west\n"
                                                        "Take - pickup a specified item at your current location\n"
                                                        "Drop - put down a specified item at your current location\n"
                                                        "Use - use a specified item at your current location\n"
                                                        "Look - displays the long description of your current location\n"
                                                        "Score - displays your current score\n"
                                                        "Moves - displays your current moves\n"
                                                        "Inventory - displays what items you have\n";
    else if(compareIgnoreCase(command, "look")) cout << locations[Luca.getLocale()]._longDescription << endl;
    else if(compareIgnoreCase(command, "examine")) examineLocation(Luca.getLocale());
    else if(compareIgnoreCase(command, "score")) cout << "score: " << Luca.getScore() << endl;
    else if(compareIgnoreCase(command, "moves")) cout << "moves: " << Luca.getMoves() << endl;
    else if(compareIgnoreCase(command, "inventory")) Luca.printItems();
    else cout << "That is not a valid command." << endl;
   // return Luca.getLocale();
}

/*
 * resetMain
 * resets locales and the navigation matrix, as well as anything else that may have changed
 */
void resetMain() {
    copyNav(true);
    for(int i = 0; i < 26; i++) locations[i].reset();
    Luca.updateID(1);
    Luca.updateScore(-Luca.getScore());
    Luca.setMoves(0);
    Luca.clearInventory();
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
        else if(compareIgnoreCase(command, "skip")) return true;
        decipher(command);

        if(!locations[Luca.getLocale()].getVisited()) Luca.updateScore(5);

        //The player must find all blocks and place them in the right location to complete the tutorial
        if(locations[2].getItemByIndex("N-BLOCK") > -1 && locations[3].getItemByIndex("S-BLOCK") > -1 &&  locations[4].getItemByIndex("E-BLOCK") > -1 && locations[5].getItemByIndex("W-BLOCK") > -1) completed = true;
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
        //Did the player enter the center hallway?
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
        //Did the player visit the broom closet after 5 moves?
        else if(Luca.getLocale() == closet.getID() && Luca.getMoves() > 4) {
            //Kill them
            cout << "Suddenly the door slams shut behind you. You attempt to open, only for the doorknob to fall off\nBaby: Did you get the Broom Closet Ending? The Broom Closet Ending is my favorite!" << endl;
            return false;
        }
        //Did the player visit the lake?
       // else if(Luca.getLocale() == lake.getID()) {
        //    replaceLocation(waterfall.getID(), )
        //}
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
    //set all items as untakeable
    for(int i = 0; i < 20; i++) {
        canTakeItem[i] = false;
    }
    //place items
    //voidC
            //Lets make items be in upper case to make things easier
    locations[1].addItem("S-BLOCK", true);
    locations[1].addItem("W-BLOCK", true);
    //voidN
    locations[2].addItem("E-BLOCK", true);
    //voidS
    locations[3].addItem("N-BLOCK", true);
    //Closet
    locations[6].addItem("HAMMER", true);
    locations[6].addItem("FLASHLIGHT", true);
    locations[6].addItem("MATCHES", true);
    //Hallway1
    locations[7].addItem("MAP", true);
    //OfficeSW
    locations[8].addItem("BATTERIES", true);
    //Forest
    locations[18].addItem("ROPE", true);
    //Lake
    locations[20].addItem("DOLL", true);
    //There's supposed to be another map item at 18 too, but I'm going to change that in this version
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
