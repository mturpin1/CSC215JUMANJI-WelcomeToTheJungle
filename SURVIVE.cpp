// SURVIVE.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Micah Turpin
// Email: micturpi@uat.edu
// Class: CSC215 C/C++ Programming I
// Assignment: JUMANJI: Welcome to the Jungle!
//

#include <iostream> //imports the iostream class, which handles basic user input and output
#include <string>   //imports the string class, which is used to handle the default char type and memory allocation for strings
#include <ctype.h>  //imports the ctype.h class, which enables string formatting (such as lowercasing/uppercasing)
#include "SURVIVE.h"
using namespace std; //tells the compiler to use the namspace std, which enables it to use specific commands that might be used under another namespace. Specifying the namespace ensures that the compiler uses the correct command

int main()
{
    int dtc = 100; //creates an integer variable, known as dtc (distance to civilization), set to the value of 100
    int hp = 100;  //creates an integer variable, known as hp (health points), set to the value of 100
    std::string player; //creates a string variable (using the string class that we imported above for char-type assignment and memory allocation) to keep track of the name of the player
    std::string option; //creates a string variable (using the string class that was imported above for char-type assignment and memory allocation) to keep track of user options

    cout << "Greetings and salutations! Welcome to the SURVIVAL game. Please enter your name below to continue. . ."; //outputs a greeting to the user, and requests that they input their name below
    cin >> player; //creates an input for the player to type their name
    std::string welcome = "Welcome, and glad you made it, " + player + "\n"; //creates a welcome string, and concantenates it with the name of the player
    cout << welcome; //prints the welcome string
    system("pause"); //pauses the program, to allow the user to decide whether they want to continue or not, by pressing a key to continue

    cout << "Hello, " << player << ". Your car ran out of gas in the desert, 100 miles from the nearest civilization.\nYou are now stranded.\nCurrent objective: SURVIVE\nGood luck. . ."; //introductory information and basic game instructions
    cout << "\nDistance to Civilization (dtc): " << dtc << "\nHealth Points (hp): " << hp; //outputs the names of the variables that are being kept track of throughout the game, as well as the abbreviations used and initial values
    std::string warning = "\n***hint: make sure you type your options correctly - not doing so will make you lose 5 hp!!***\n"; //warning to type correctly
    cout << warning; //prints the warning string
    system("pause"); //another system pause
    goto outOfWater; //tells the program to go to the function outOfWater, in order to start the game

outOfWater: //defines the name of the function
    cout << "\nYou are out of water. Do you decide to search for civilization(search) or find your own water(fyow)?"; //prints the game information that the player needs to know, and tells them the choices and abbreviations to type in order to choose a direction to go
    cin >> option; //gives the user an input box to type their selection
    
    if (option == "search") { //tests if the user input equals search
        goto searchForCivilization; //tells the program to go to the searchForCivilization function
    }
    else if (option == "fyow") { //checks user output
        goto findYourOwnWater; //to navigate to the function that the user chose
    }
    else if (hp <= 0) { //checks if the health points of the player have dropped below 0 (aka the player has died)
        goto yerDed; //navigates to a function that ends the game, with a losing result
    }
    else if (dtc <= 0) { //checks if the distance to civilization is below 0 (aka the player has arrived at civilization)
        goto madeItToCivilization; //navigates to a function that ends the game, with a winning result
    }
    else { //checks if user typed anything other than the strings defined above, and checks to see if any other condtions are met
        cout << "Looks like you messed something up. -5 hp."; //tells the user that they messed up their input
        hp -= 5; //subtracts 5 health points, to ensure that the player isn't constantly mistyping
        goto outOfWater; //restarts the function
    }

searchForCivilization: //same syntax/organization/navigation/conditional rules from the outOfWater function apply to the following 6 functions
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nYou come upon a town that has water, but also a deadly plague (dtc -25).\n Do you decide to go into the village(village) or move on(moveon)?";
    dtc -= 25;
    cin >> option;

    if (option == "village") {
        goto goIntoTheVillage;
    }
    else if (option == "moveon") {
        goto moveOn;
    }
    else if (hp <= 0) {
        goto yerDed;
    }
    else if (dtc <= 0) {
        goto madeItToCivilization;
    }
    else {
        cout << "Looks like you messed something up. -5 hp.";
        hp -= 5;
        goto searchForCivilization;
    }

findYourOwnWater:
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nYou know you have to dig to find water. -10 hp\nDo you devide to dig your own well(dig) or search for and enlarge an existing hole(enlarge)?";
    hp -= 10;
    cin >> option;

    if (option == "dig") {
        goto digYourOwnWell;
    }
    else if (option == "enlarge") {
        goto searchForAndEnlargeAnExistingHole;
    }
    else if (hp <= 0) {
        goto yerDed;
    }
    else if (dtc <= 0) {
        goto madeItToCivilization;
    }
    else {
        cout << "Looks like you messed something up. -5 hp.";
        hp -= 5;
        goto findYourOwnWater;
    }

goIntoTheVillage:
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nYou find water in the town, after several hours. -25 hp\nDo you decide to drink the water immediately, as you are almost dying of thirst (drink), or do you decide to boil it (boil)?";
    hp -= 25;
    cin >> option;

    if (option == "drink") {
        goto drinkTheWaterImmediately;
    }
    else if (option == "boil") {
        goto boilIt;
    }
    else if (hp <= 0) {
        goto yerDed;
    }
    else if (dtc <= 0) {
        goto madeItToCivilization;
    }
    else {
        cout << "Looks like you messed something up. -5 hp.";
        hp -= 5;
        goto goIntoTheVillage;
    }

moveOn:
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nYou decide to move on from the village, and come upon a broken-down truck on the side of the road\nDo you decide to keep moving(keepmoving) or do you decide to help the trucker(help)?";
    cin >> option;

    if (option == "keepmoving") {
        goto keepMoving;
    }
    else if (option == "help") {
        goto helpTheTrucker;
    }
    else if (hp <= 0) {
        goto yerDed;
    }
    else if (dtc <= 0) {
        goto madeItToCivilization;
    }
    else {
        cout << "Looks like you messed something up. -5 hp.";
        hp -= 5;
        goto moveOn;
    }

digYourOwnWell:
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nYou decide to dig your own well. -15 hp, +10 dtc\nDo you decide to dig a deep well(deep) or do you decide to dig a shallow hole covered with plastic(shallow)?";
    hp -= 15;
    dtc += 10;
    cin >> option;

    if (option == "deep") {
        goto digADeepWell;
    }
    else if (option == "shallow") {
        goto digAShallowHoleCoveredWithPlastic;
    }
    else if (hp <= 0) {
        goto yerDed;
    }
    else if (dtc <= 0) {
        goto madeItToCivilization;
    }
    else {
        cout << "Looks like you messed something up. -5 hp.";
        hp -= 5;
        goto digYourOwnWell;
    }

searchForAndEnlargeAnExistingHole:
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nYou have found an apparently empty snake burrow. +10 dtc\nDo you decide to dig right away(dignow) or do you decide to make sure it is cleared out first(clear)";
    cin >> option;

    if (option == "dignow") {
        goto digRightAway;
    }
    else if (option == "clear") {
        goto makeSureItIsClearedOutFirst;
    }
    else if (hp <= 0) {
        goto yerDed;
    }
    else if (dtc <= 0) {
        goto madeItToCivilization;
    }
    else {
        cout << "Looks like you messed something up. -5 hp.";
        hp -= 5;
        goto searchForAndEnlargeAnExistingHole;
    }

drinkTheWaterImmediately: //defines a function that is a final result of the survival game
    cout << "\nYou decided to find civilization, then you chose to go into the town with the plague.\nYou decided to drink the water right away without boiling it, and got the plague. hp - " << hp; //tells the player their choices throughout the game, as well as telling them what any hp/dtc changes are
    hp -= hp; //since this is a losing game choice, the program will subtract all of the player's hp, meaning that it reaches 0
    cout << "\ndtc: " << dtc << "\nhp: " << hp; //tells the player their remaining hp and dtc
    cout << "\nGAME OVER, " << player << ". You Died. Type 'restart' to play again, type anything else to exit. . ."; //game over message, telling the player what the outcome of the game was, and informing them how to restart the game
    cin >> option; //input window for user to either exit the game or restart the game

    if (option == "restart") { //checks if the user wants to restart the game
        goto outOfWater; //navigates to the first function at the beginning of the game
    }
    else { //for all other inputs. . .
        return 0; //exit the program with a return code of 0
    }

//syntax for the following 7 functions largely remains the same, except for the functions that calculate remaining hp/dtc

boilIt:
    cout << "\nYou decided to find civilization, then you chose to go into the town with the plague.\nYou decided to boil the water before drinking it, killing all the germs in the water.\nYou now have a reliable supply of water, which is able to tide you over until a rescue group comes looking for you. dtc - " << dtc;
    dtc -= dtc; //this is a winning game choice, and since the ultimate goal is to get to civilization, the dtc is reduced to 0
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You WIN!! Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they won
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

keepMoving:
    cout << "\nYou decided to find civilization, then you chose to move on from the village with the plague.\nYou move on from the broken down truck, ignoring the trucker.\nYou can't find anybody or anything else.\nYou die a lonely death sevearl days later, after wandering aimlessly around the desert, not realizing that you were only a couple miles away from your de4stination. hp - " << hp;
    hp -= hp; //since this is a losing game choice, the player's health points are reduced to 0
    dtc -= (dtc - 2); //since the player has gotten really close to getting back to civilization, the dtc is reduced to 2 miles away from civilization
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You Died. Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they lost
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

helpTheTrucker:
    cout << "\nYou decided to find civilization, then you chose to move on from the village with the plague.\nYou decide to help the driver of the broken down truck, and your mechanical knowledge helped you to fix his truck.\nGrateful, he gives you some food, water, and a quick hour-long ride back into civilization. hp + " << (100 - hp) << ", dtc - " << dtc;
    hp += (100-hp); //since this is a winning game choice, the player's hp will be increased to 100
    dtc -= dtc; //since this is a winning game choice, the player's dtc is reduced to 0
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You WIN!! Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they win
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

digADeepWell:
    cout << "\nYou decided to find your own water, and you chose to dig your own well.\nYou decide to dig a deep well, but you dig so deep, the only water that seeps up is too far down for you to reach.\nYou spend a long, cold, and lonely night in the desert, and die the next day, staring at the very fluid that could have given you life, if it weren't for your arrogance. hp - " << hp;
    hp -= hp; //since this is a losing game choice, the player's hp is reduced to 0
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You Died. Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they have lost
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

digAShallowHoleCoveredWithPlastic:
    cout << "\nYou decided to find your own water, and then chose to dig your own well.\nYou decide to dig a shallow well covered with plastic to catch condensation, which will then drip into your canteen, lying at the bottom of the hole.\nYour well is perfect, and you collect enough water over the night to dill up three canteens full of water. hp + " << (100 - hp) << ", dtc - " << dtc;
    hp += (100-hp); //since this is a winning game choice, the player's hp is increased to 100
    dtc -= dtc; //since this is a winning game choice, the player's dtc is reduced to 0
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You WIN!! Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they have won
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

digRightAway:
    cout << "\nYou decided to find your own water, and then chose to search for and enlarge an existing hole.\nYou decide to enlarge an old snake burrow, without checking for any other animals first. You failed to see the family of scorpions who had make the old burrow their nest.\nYou get stung multiple times, and die from the venom that flows through your veins. hp - " << hp << ", dtc + 10";
    hp -= hp; //since this is a losing game choice, the player's health is reduced all the way down to 0
    dtc += 10; //since this is a losing game choice, the player's distance from civilization is increased
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You Died. Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they have lost the game
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

makeSureItIsClearedOutFirst:
    cout << "\nYou decided to find your own water, and then chose to search for and enlarge an existing hole.\nYou decide to check for other animals first; you clear out the scorpion family that had taken up residence.\nYou are now able to dig yourself a small reserevoir, and retrieve as much water as you need for a safe trek back to civilization. hp + " << (100-hp) << ", dtc - " << dtc;
    hp += (100-hp); //since this is a winning game choice, the player's hp is increased to 100
    dtc -= dtc; //since this is a winning game choice, the player's dtc is reduced to 0
    cout << "\ndtc: " << dtc << "\nhp: " << hp;
    cout << "\nGAME OVER, " << player << ". You WIN!! Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they have won the game
        cin >> option;

    if (option == "restart") {
        goto outOfWater;
    }
    else {
        return 0;
    }

yerDed:
    cout << "\nYou typed incorrectly too many times, and are now dead.";
    hp = 0; //since a player typing incorrect choices very often would reduce their enjoyment of the game, implementing a reduction in hp that will eventually kill them if they continue is implemented in this function to ensure that the user is not mistyping too often
    cout << "\ndtc: " << dtc << "\nhp: " << hp; //displays the player's hp and dtc
    cout << "\nGAME OVER, " << player << ". You died. Type 'restart' to play again, type anything else to exit. . ."; //informs the player that their game is over, and they have lost
    cin >> option; //gives the player an input window to select whether they want to play again or quite the game

    if (option == "restart") { //checks if the player wants to restart
        goto outOfWater; //navigates to the first function, which restarts the game
    }
    else { //checks for any other cases
        return 0; //exits the program with a return code of 0
    }

madeItToCivilization:
    cout << "\nCongrats! You made it to civilization."; //informs the player that they have successfully reached civilization
    hp += (100 - hp); //since this is a winning game condition, the player's hp is increased to 100
    dtc = 0; //to insure that there aren't any negative numbers being dealt with, and to avoid any errors, the dtc is manually set to 0; I was having logical issues with other mathematical operations
    cout << "\ndtc: " << dtc << "\nhp: " << hp; //displays the player's hp and dtc
    cout << "\nGAME OVER, " << player << ". You WIN!! Type 'restart' to play again, type anything else to exit. . ."; //informs the player that they have reached civilization, thus winning the game
    cin >> option; //provides an input window for the user to select whether they want to restart or exit the game

    if (option == "restart") { //checks if the user wants to restart the game
        goto outOfWater; //navigates to the first function, restarting the game
    }
    else { //checks for any other logical conditions
        return 0; //exits the game with a return code of 0
    }
}
