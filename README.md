# Reality Text Adventure Game: C++ verison
The goal of this repository is record my progress in remaking my game(https://github.com/AGriggs1/Reality-Text-Adventure-Game) in C++ as a way to familiarize myself with the language.

# What is Reality?
Reality is a text adventure game created by me during my Fall 2017 semester at Marist College. The premise was that you, the player, were trapped in some sort of virtual reality by an artificial intelligence, with seemingly no means to escape: that is, no other way other than to do said AI's bidding and complete its gauntlet. The world around you could change without warning, key locations could be moved around or cease to exist in order to trick the player. This gave me the opportunity to be more creative in the game's level design. The game was originally programmed in Python; the version you are seeing here is a recreation of it in C++, which I did in order to help teach myself the language over the 2018 Summer break.

# What are the differences between this version and the Python version?
Both versions are virtually the same as that was my intention when creating this. There are some changes in text, but things like the objectives, items and locations are unchanged. There is one change I made to the corridor puzzle of the game: in the Python version, you would be teleported to the beginning of the corridor or to the forest if you tried to enter the chairman's office while the puzzle was still unsolved. I felt this to be tedious and nothing but a time-waster, and so I did not implement this mechanic into this version.

# So exactly how do I win?
In order to complete the game, you have to make it to a certain location within 75 moves (hint: it's somewhere accessible from the office). A 'move' is defined by the game as any action that causes the player to change their current location to another. The game can be completed in significantly less time than 75 moves, so this should give you plenty of time to fully explore all of the locations the game has to offer. Furthermore, if you are holding a certain item by the 75 moves limit, you will be allowed to continue the game to completion with no penalty. I highly recommend exploring and finding all of the items found in the office before moving onward, as the game will become unwinnable if you leave the area without some of them!

# Cheat codes, please!
Why not. I found these to be extremely helpful in quickly testing portions of the game, so here's the cheats I implemented into the game. To access them, when the game asks for your name, type the phrase "Boy from Nowhere" and type "end" when you are done entering cheats. 

Accessing the cheats will automatically skip the tutorial.

"all items": Typing this will give you every item in the game and remove them from the location they would normally be found in.

"goto": This allows you to go to any location in the game. You will be asked where you want to go after inputing this command. You need to type the ID of the location you want to go, that is, input a number from 0-41. If you do NOT input a number, the game will likely crash. You will be able to see the description of the location you are trying to go to in order to help ascertain that that is where you want to go. The IDs for all of the locations as follows:
0: Placeholder. I.E. not a location.
1: Center of void from the tutorial.
2: The North section of the tutorial.
3: The South section of the tutorial.
4: The East section of the tutorial.
5: The West section of the tutorial.
6: The broom closet.
7: The hallway west of the office.
8: The Northwest section of the office.
9: The West section of the office.
10: The Southwest section of the office.
11: The North section of the office.
12: The Center section of the office.
13: The South section of the office.
14: The Northeast section of the office.
15: The East section of the office.
16: The Southeast section of the office.
17: The hallway east of the office.
18: The forest.
19: The river.
20: The lake.
21: The waterfall.
22: The cave entrance.
23: Inside the cave.
24: The incantation circle.
25: The ravine (this might kill you if try to use this command to go there).
26: The top of the waterfall.
27: The elevator.
28: The elevator after going up.
29: The chairman's office.
30: The first intersection of the corridor.
31: The east end of the first corridor intersection.
32: The west end of the first corridor intersection.
33: The section before the second intersection of the corridor.
34: The second intersection of the corridor.
35: The east end of the second corridor intersection.
36: The west end of the second corridor intersection.
37: The section before the third intersection of the corridor.
38: The third intersection of the corridor.
39: The east end of the third corridor intersection.
40: The west end of the third corridor intersection.
41: The section of the corridor leading to the chairman's office.


Copyright Anthony Griggs, Anthony.Griggs1@marist.edu
