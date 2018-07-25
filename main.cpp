#include <iostream>
#include <string>
#include "Player.h"

//Author: Anthony Griggs
//5-24-18
//Reality Text Adventure Game vC++
//Branch part5
//This branch will focus on win/loss conditions, finalizing everything

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
                       "You're at the cliffside.", examineDesc);

Locale voidE(4, "You follow the line leading East, stopping at the circle with the letter 'E' on it. "
                       "The area transforms into the ruins of city. Cars rusted, buildings overgrown with moss and vines. Nature has reclaimed what it once lost."
                       " You can't help but feel curious about the fate of this place.", "You are at the city ruins.", examineDesc);

Locale voidW(5, "You head West, coming to a circle with the letter 'W' on it. The area transforms,"
                                    " and now you are in an office. Desks overflowing with paperwork and the inescapable stench of stale coffee makes you feel anxious.",
                          "You are at the office", examineDesc);
Locale closet(6, "The void transforms completely, transforms... into a broom closet. Huh.", "You return to the broom closet.", "You rifle through the shelves");
Locale hallway1(7, "You enter a hallway and come to a corner", "You are at a hallway corner.", "There is a glass panel on the wall with what looks like a map of this place.\n"
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
Locale officeS(13, "You find a pair of doors. What lies beyond them?", "You head towards the double doors.", "The doors won't budge. Looks like you need a key."
                                                                                                             "\nYou notice a panel by the door. It reads:\n\n"
                                                                                                             "Beyond this pair lies another, beyond it lies the office of the clown, but only when west"
                                                                                                             "and east are 46");
Locale officeNE(14, "You enter one of the office corners. There is a watercooler, but its empty.", "You are in the Northeast corner of the office.", "Could really use some water... ugh.");
Locale officeE(15, "You are now on the other side of the office. Something feels off, or maybe you're just sick of this place.", "You are in the office", examineDesc);
Locale officeSE(16, "You enter one of the office corners, and are met with a portrait of a sad clown. Pardon?", "You are in the Southeast corner of the office", "The nameplate reads: 'Chairman Bozo, may he grace you with his gaze. Yeah, moving on...");
Locale hallway2(17, "You walk down a hallway, and come to a corner.", "You are at a hallway corner.", examineDesc);

Locale forest(18, "You pass through a pair of doors, and well... now you're in a forest. You look behind you, and the building you were just in has completely vanished. Well then.",
"You are in the forest.", "You can faintly hear what sounds like running water in the distance. A nearby notice board catches your attention. it reads:\n"
                         "\nNew Pena National Forest\n"
                         "========================\n\n"
                         "    e             \n"
                         "    |             \n"
                         "    g--f--h--i    \n"
                         "             |    \n"
                         "          j--k    \n"
                         "             |    \n"
                         "             l--m \n"
                         "\nYou are at: e   \n"
                         "\nExplore one of the many cave systems found within our beautiful forest! See the incantation circles where locals performed their rituals! Book your guided tour now!\n"
                         "WARNING: Cave spelunking can a dangerous activity, especially for the untrained! DO NOT EXPLORE UNAUTHORIZED AREAS ALONE OR WITHOUT A TRAINED PARK GUIDE!");
Locale river(19, "You continue down a dirt pathway, coming to a riverbank. You here what sounds like thunder in the distance.", "You are at the river", "Just a river.");
Locale lake(20, "You follow the river, eventually finding yourself at a large lake.", "You are at the lake.", "You walk along the shores, keeping an eye out for any interesting finds.");
Locale waterfall(21, "You follow the river to a waterfall. Looks pretty tall.", "You are at the waterfall.", "You take a look around the area.");
Locale caveE(22, "You go behind the waterfall, and the find the entrance to a cavern.", "You are behind the waterfall.", "You take a look around.");
Locale cave(23, "You enter the cave. It's pitch black.", "You are in the cavern.", "");
Locale deepCave(24, "You continue onward, inching slowly. You eventually come to an small chamber with a small opening to the surface, allowing you to see."
                    " You take notice of the many symbols drawn on the chamber floor in what could be chalk. Whatever it is, looks like it's for ritualistic purposes",
                "You are in a cave chamber.", "");
Locale ravine(25, "You take a step forward, unaware that there is no surface for you step on. You fall, tumbling down, down, down... You hit the bottom of a ravine,"
                  " hard. You can't see what's broken, but it doesn't feel good. You begin to slip out of consciousness.", "You're at the bottom of a ravine.", "");
Locale watertop(26, "Following the river's current, you come across the top of a waterfall. Looks pretty tall from here.", "It's the top of a waterfall. Again.", "");
Locale elevator(27, "You shuffle through the ravine, coming to well, an elevator. Now, up... or down?", "You are in an elevator", "Nothing or note. There is a panel with an up and a down button, though.");
Locale elevatorUp(28, "You press the up button. You feel your weight shift as the elevator makes it way upwards. It stops at a 'ding!' The doors slide open to reveal... a wall.", "You are in the elevator", "Where there's a wall, there's a room, right?");
Locale chairoff(29, "You open the double doors, revealing a large furnished office. On the other side of the office is a desk, and behind that desk of a very large portrait of Bobbo the Clown. This is happening.", "You are in the furnished office.", "");
Locale corridor1(30, "You open the double doors to reveal a long corridor, finding yourself at one of many intersections.", "You are at the north end of the corridor, standing at an intersection", "");
Locale corridor1E(31, "You head east in the intersection. You come to a door with a number on it", "You are in the east end of the intersection", "The number on the door is 50. There is a button with an arrow pointing north on it...");
Locale corridor1W(32, "You head west in the intersection. You come to a door with a number on it", "You are in the west end of the intersection", "The number on the door is 45. There is a button with an arrow pointing south on it...");
//Create an array to act as a dictionary for the locales
Locale na(-1, "This is stupid", "Seriously.", examineDesc); //So my null constructor is officially useless, because that creates a syntax error when used in arrays
//Also NULL doesn't work either because why would it?
Locale locations[50] = {voidDummy, voidC, voidN, voidS, voidE, voidW,
                        closet, hallway1, officeNW, officeW, officeSW,
                        officeN, officeC, officeS, officeNE, officeE,
                        officeSE, hallway2, forest, river, lake, waterfall,
                        caveE, cave, deepCave, ravine, watertop, elevator,
                        elevatorUp, chairoff, corridor1, corridor1E, corridor1W};
//NavMat
        //navigator[localeID][iDirection] = Locale
                //0 = North, 1 = South, 2 = East, 3 = West, 4 = Up, 5 = Down
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
        {na, forest, na, officeE}, //-------------------------hallway2
        {na, river, na, na}, //---------------------------forest
        {forest, na, waterfall, lake}, //-----------------river
        {na, na, river, na}, //---------------------------lake
        {na, na, na, river}, //---------------------------waterfall
        {na, cave, na, waterfall}, //----------------------caveE
        {caveE, ravine, na, deepCave}, //-----------------cave
        {na, na, cave, na}, //----------------------------deepCave
        {cave, na, elevator, na,}, //---------------------ravine
        {na, na, river, waterfall}, //--------------------watertop
        {na, na, na, na, elevatorUp, na}, //--------------elevator
        {na, na, na, na, na, elevator}, //----------------elevatorUp
        {na, na, na, na}, //-------------------------chairoff
        {officeS, na, corridor1E, corridor1W}, //----------corridor1
        {na, na, na, corridor1}, //------------------------corridor1E
        {na, na, corridor1, na} //-------------------------corridor1W

};
Player Luca("Lucas", 1);
string cont = "continue";
//bool usedItem[10] = {false, false, false, false, false, false, false, false, false, false};


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
//Since there aren't that many items, I'm going to use individual variables to determine if an item was used
bool usedBatteries = false;
bool usedFlashlight = false;
bool usedHammer = false;
bool usedKey = false;


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
            if(makeUpper(item) == "MAP" && !usedHammer) {
                cout << "It's behind the glass casing, of which there does not seem to be a way of opening.\n";
                return false;
            }
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
bool ravineKills = true;
string map = "   c1--C   c6     \n"
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
             "     = 46 =        ";

string bigMap = "   c1--C   c6             \n"
                "   |   |   |              \n"
                "b--c2--c4--c7--d          \n"
                "|  |   |   |   |          \n"
                "a  c3--c5--c8  e          \n"
                "       |       |          \n"
                "       |    g--f--h--i    \n"
                "       |             |    \n"
                "   51--n1--40     j--k    \n"
                "       |             |    \n"
                "       n2            l--m \n"
                "       |                  \n"
                "   50--n3--48             \n"
                "       |                  \n"
                "       n4                 \n"
                "       |                  \n"
                "   45--n5--42             \n"
                "       |                  \n"
                "       46                   ";
//Used for telling the player where they are
string mapDiction[50] = {"", "", "", "", "", "", "a", "b", "c1", "c2", "c3", "C", "c4", "c5", "c6", "c7",
                        "c8", "d", "e", "g", "f", "h", "i", "k", "j", "l", "g", "m", "m", "46", "n1", "51",
                         "40", "n2", "n3", "50", "48", "n4", "n5", "45", "43", "46"};
/*
 * use
 * sees if the passed string is an item, and if it can be used
 * returns the message to be output
 */
string use(int localeID, string item) {
    //The player must have the item to use it, naturally
    string message = "You do not have any " + item;
    if(Luca.getItemByIndex(item) == -1) return message;
    message = "Cannot use the " + item + " here.";
    //Flashlight
    if(compareIgnoreCase(item, "flashlight")) {
        //The player must have used the batteries
        if(usedBatteries && !usedFlashlight) {
            //The player must be in the cave
            if(localeID == cave.getID()) {
                usedFlashlight = true;
                return "You turn on the flashlight. to reveal a sharp drop-off to your south. If only you had a way down...";
            }
            else return "It works, but no need to use it here.";
        }
        else if(!usedBatteries) return "Looks like it needs batteries.";
        else return "It works, but no need to use it here.";
    }
    //Hammer
    else if(compareIgnoreCase(item, "hammer")) {
        //Is the location hallway1?
        if(localeID == hallway1.getID() && locations[localeID]._searched && !usedHammer) {
            usedHammer = true;
            return "You take the hammer and smash the glass casing. You can now take the map.";
        }
        else if(localeID == elevatorUp.getID() && navigator[elevatorUp.getID()][0].getID() == -1) {
            replaceLocation(elevatorUp.getID(), 0, officeSE);
            return "You smash a hole in the wall. You look through to see a room. You continually do so until the opening is large enough for you to fit through. It's... the office. It looks you smashed through the portrait of Bobbo the clown, though.";
        }
        else return "No need for that here.";
    }
    //Rope
    else if(compareIgnoreCase(item, "Rope")) {
        if(localeID == cave.getID() && usedFlashlight) {
            Luca.removeItem(Luca.getItemByIndex(item));
            ravineKills = false;
            //update the ravine description
            locations[ravine.getID()]._longDescription = "You carefully shimmy down the rope, eventually reaching the bottom of the ravine. Now what?";
            return "You secure the rope to the ledge and throw it down the ravine. Did it reach any bottom?";
         }
         else return "No need for that here";
    }
    //Matches
    else if(compareIgnoreCase(item, "Matches")) {
        int dollDex = locations[localeID].getItemByIndex("DOLL");
        if(localeID == deepCave.getID() && dollDex > -1) {
            locations[localeID].removeItem(dollDex);
            locations[localeID].addItem("KEY", false);
            Luca.removeItem(Luca.getItemByIndex(item));
            return "With the doll in the incantation circle, you light a match and set it ablaze. Eventually, the flames die down, leaving nothing but the ashen remains, and a key.";
        }
        else return "No need for that here.";
    }
    //Batteries
    else if(compareIgnoreCase(item, "Batteries")) {
        if(Luca.getItemByIndex("FLASHLIGHT") == -1) return "Nothing to use those with.";
        else {
            usedBatteries = true;
            Luca.removeItem(Luca.getItemByIndex(item));
            return "You put the batteries in the flashlight.";
        }
    }
    //Key
    else if(compareIgnoreCase(item, "Key")) {
        if(localeID == officeS.getID()) {

            replaceLocation(officeS.getID(), 1, corridor1);
            usedKey = true;
            return "Using the key, you unlock the double doors";
        }
    }
    //Map
    else if(compareIgnoreCase(item, "Map")) {
        if(locations[forest.getID()]._searched) return bigMap + "\nYou are at: " + mapDiction[localeID];
        return map + "\nYou are at: " + mapDiction[localeID];
    }
    //TODO: corridor buttons
    return "Could not find item " + item;
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
    else if(compareIgnoreCase(command, "up")) {
        int localeID = navigator[Luca.getLocale()][4].getID();
        if(localeID > -1) Luca.updateID(localeID);
        else cout << "You cannot go that way." << endl;
    }
    //NOT GOING TO IMPLEMENT DOWN IN THIS VERSION, IT NEVER GETS USED
    //take
    else if(compareIgnoreCase(command.substr(0, 4), "take")) {
        //See if this is a two-word command... try to take with what should be the second half...


        if(command.length() > 4) {
            string item = command.substr(5, command.length());
            if(take(Luca.getLocale(), item)) cout << "took the " << item << "." << endl;
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
                if(take(Luca.getLocale(), command)) cout << "took the " << command <<  "." << endl;
                else cout << "Could not find " << command << ".";
            }
        }
    }
    //drop
    else if(compareIgnoreCase(command.substr(0, 4), "drop")) {
        if(command.length() > 4) {
            string item = command.substr(5, command.length());
            if(drop(Luca.getLocale(), item)) cout << "dropped the " << item <<  "." << endl;
            else cout << "You do not have any " << item;
        }
        else {
            cout << "Drop what?\n";
            Luca.printItems();
            getline(cin, command);
            if(drop(Luca.getLocale(), command)) cout << "dropped the " << command << "." << endl;
        }
    }
    //use
    else if(compareIgnoreCase(command.substr(0, 3), "use")) {
        if(command.length() > 3) {
            cout << use(Luca.getLocale(), makeUpper(command.substr(4, command.length()))) << endl;
        }
        else {
            cout << "Use what?\n";
            Luca.printItems();
            getline(cin, command);
            cout << use(Luca.getLocale(), makeUpper(command)) << endl;
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
    usedBatteries = false;
    usedFlashlight = false;
    usedHammer = false;
    usedKey = false;
    ravineKills = true;
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
    cout << "???: If you 'examine' where you are, you'll see that I've left some blocks lying around. Do me a favor, can you 'take' them and 'drop' them where they belong?" << endl;
    cout << "???: Too on the nose for you?" << endl;
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
        /*
         * LOCATION MUTATORS
         */
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

        //Did the player go to the lake?
        else if(Luca.getLocale() == lake.getID()) {
            replaceLocation(waterfall.getID(), 2, caveE);
        }
        //Did the player visit the waterfall before the lake?
        else if(Luca.getLocale() == waterfall.getID() && !locations[lake.getID()].getVisited()) {
            replaceLocation(river.getID(), 3, watertop);
            cout << "Wait... isn't there supposed to be something east of here?" << endl;
        }
        //If the lake is blocked, unblock it
        else if(Luca.getLocale() == forest.getID() && navigator[river.getID()][3].getID() == watertop.getID()) {
            replaceLocation(river.getID(), 3, lake);
        }

        /*
         * Location specific events
         */
            //Did the player visit the broom closet after 5 moves?
        else if(Luca.getLocale() == closet.getID() && Luca.getMoves() > 4) {
            //Kill them
            cout << "Suddenly the door slams shut behind you. You attempt to open, only for the doorknob to fall off\nBaby: Did you get the Broom Closet Ending? The Broom Closet Ending is my favorite!" << endl;
            return false;
        }
        //Did the player go to the ravine without using the rope? Kill them
        else if(Luca.getLocale() == ravine.getID() && ravineKills) {
            cout << ravine._longDescription << endl << "Baby: D'awwwww, did somebody find their mortality?";
            return false;
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
    locations[10].addItem("BATTERIES", true);
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
