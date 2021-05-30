#include <iostream>
#include "AdventureGame.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

void slowPrint(std::string str)
{
  for (int c; c<= str.length(); c++){
    std::this_thread::sleep_for(std::chrono::milliseconds(45));
    std::cout << str[c] << std::flush;
  }
}

void start_game(){
    std::string start("Choose your character: Goblin or Princess (G/P)\n");
    slowPrint(start);
    std::cin >> choice0;
    transform(choice0.begin(), choice0.end(), choice0.begin(), ::toupper);
    if(choice0 == "G") {
        std::string gob("You awaken in your disgusting cave to find you have been robbed. Do you Wake up and go look around, or go back to Sleep? (W/S)\n"); 
        slowPrint(gob);
        std::cin >> choice1;
        }
    else if (choice0 == "P") {
        std::string pr("Hello, m'lady. Would you like to go to the castle's library, or take a stroll into the village? (L/V)\n");
        slowPrint(pr);
         std::cin >> choice1;
    }
    else {
        std::cout << "\n";
    }
}

bool play_again() {
    std::string again("Play again? (Y/N)\n");
    slowPrint(again);
    std::cin >> cont;
    transform(cont.begin(), cont.end(), cont.begin(), ::toupper);
    while(cont != "Y" && cont != "N") {
        std::string que("What? Play again? (Y/N)\n");
        slowPrint(que);
        std::cin >> cont;
        transform(cont.begin(), cont.end(), cont.begin(), ::toupper);
        }
    if(cont == "Y") {return true;}
    else {return false;}
        
    }
   


std::string step_1() {
    transform(choice1.begin(), choice1.end(), choice1.begin(), ::toupper);
    if(choice1 == "L") {
        std::string gob("You go to the library to discover your favorite book is missing. Head to village Bookstore or talk to your father the King? (B/K)\n");
        slowPrint(gob);
        std::cin >> choice2;
        return "P"; 
    }
    else if(choice1 == "V") {
        std::string gob("You sneak past the guards and head to the village. Shall you visit the Bookstore of the Cafe? (B/C)\n");
        slowPrint(gob);
        std::cin >> choice2;
        return "P";
    }
    else if(choice1 == "W") {
        std::string gob("You step outside your cave to see an orc stumbling away with your belongings. Confront or Ignore? (C/I)\n");
        slowPrint(gob);
        std::cin >> choice2;
        return "G";
    }
    else if(choice1 == "S") {
        std::string gob("You roll over and fall back asleep like the lazy Goblin you are.\n");
        slowPrint(gob);
        return "N";
    }
    else {
        std::cout << "\n";
        return "N";
    }
}
std::string step_2G() {
    transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
    if(choice2 == "C") {
        std::string gob("The orc is willing to return your belongings if you can best him in an armwrestling match. Do you accept his offer? (Y/N)\n");
        slowPrint(gob);
        std::cin >> choice3;
        return "A";
    }
    else if(choice2 == "I") {
        std::string gob("With nothing of value to your name, you decide to wander the streets as a useless, homeless Goblin.\nYou encounter a magician. He offers you some magic beans that could grow into a new, luxurious home for you.\nBut there's a catch. They come at a price...\n");
        slowPrint(gob);
        sleep(5);
        std::string gob1("You must serve as the magician's slave for 5 years before planting the beans in order for them to work properly.\nDo you Accept the magician's offer, or Run away like a coward goblin? (A/R)\n");
        slowPrint(gob1);
        std::cin >> choice3;
        return "B";
    }
    else {
        return "Q";}
    
}

void step_3G() {
    transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
    if(choice3 == "Y"){
        std::cout << "The orc easily bests you, and proceeds to tear your arm off to teach you a lesson. Maybe you'll think harder about your decisions\n";
        std::cout << "next time, ugly Goblin.\n";
    }
    else if(choice3 == "N"){
        std::cout << "A wise decision indeed. Better off alive, even if it means starting over...\n";
    }
    else if(choice3 == "A"){
        std::cout << "You begin working tirelessly for the magician, and continue to do so as per your 5-year contract.\n";
        std::cout << "At the end of a long, hard 5 years, you ask the magician if it is time to plant your beans.\n";
        std::cout << "The magician turns to you and laughs. After all this time, he confesses that magic isn't real.\n";
        std::cout << "How did you not figure that out over 5 years, silly Goblin?? Better luck next time...\n";
    }
    else if(choice3 == "R"){
        std::cout << "You run away to the village crying. The local cobbler takes pity on you and offers you a home and apprenticeship.\n";
        std::cout << "Finally, you have found a place where you can live a happy, peaceful, stupid Goblin life.\n";
        std::cout << "THE END\n";
    }
    else {
        std::cout << "\n";
    }
}

std::string step_2P() {
    transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
    if(choice2 == "B") { 
        std::cout << "On your way to the bookstore, you see a magician trying to con a goblin. Do you stop to Help or Walk on by? (H/W)\n";
        std::cin >> choice3;
        return "C";
    }
    else if(choice2 == "K") { 
        std::cout << "You go to speak with the King, but find that he has been called to lead the army against an invading tribe of orcs.\n";
        sleep(2);
        std::cout << "What's more, the royal guards have declared a lockdown preventing you from leaving the castle.\n";
        std::cout << "You decide to make a run for it. After stealing a horse, you have a decision to make. Do you rush to the Village to buy a new book, or\n";
        std::cout << "to the Battlefield to try and help your father? (V/B)\n";
        std::cin >> choice3;
        return "D";
    }
    else if(choice2 == "C") {
        std::cout << "You arrive at the cafe. Do you order your Usual, or the Special? (U/S)\n";
        std::cin >> choice3;
        return "E";
    }
    else {
        return "H";
    }
}
void step_3P() {
    transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
    if(choice3 == "H"){
        std::cout << "You help the goblin avoid a terrible mistake. Being the kind princess you are, you walk the goblin to the village.\n";
        std::cout << "After talking, you discover that you get along quite nicely, and decide to immediately take the goblin";
        std::cout << "back to the castle as your personal servant.\n";
        std::cout << "Over the years, the two of you go on many fun adventures, and live happily ever after.\n";
        std::cout << "THE END\n";
    }
    else if(choice3 == "W"){
        std::cout << "You ignore the poor goblin and rush to the village. Just as you arrive, the orc army invades and murders you.\n";
        std::cout << "Maybe you should have been a little nicer to the goblin...\n";
    }
    else if(choice3 == "V"){
        std::cout << "You rush to the village, paying no attention to anyone you pass by. The village has already been invaded by orcs,\n";
        std::cout << "who take you prisoner for the rest of your life. Maybe next time don't be in such a rush...\n";
    }
    else if(choice3 == "B"){
        std::cout << "You arrive at the battlefield just in time to valiantly save your father's life. Together, you defeat the orc leader and\n";
        std::cout << "usher in a new era of peace throughout your kingdom. The people adore you, and you live a long, happy life,\n";
        std::cout << "serving as a fierce and effective Queen. On your deathbed, your only regret\n";
        std::cout << "is not having a close friend to have shared your adventures with.\n";
        std::cout << "THE END\n"; 
    }
    else if(choice3 == "U"){
        std::cout << "You drink your usual, and go on to the bookstore, where you run into Prince Charming.\n";
        std::cout << "He sees the coffee you ordered and looks disgusted.\n";
        std::cout << "You try to flirt with him, but you ruin it by being awkward, and he never talks to you again.\n";
        std::cout << "Maybe you should have tried something new...\n";
    }
    else if(choice3 == "S"){
        std::cout << "The special of the day is delicious and extra caffeinated. The extra boost jogs your memory,\n";
        std::cout << "and you remember where your book is! You return to the castle and have a nice time re-reading it.\n";
        std::cout << "Maybe one day you'll go on adventures like the ones in the book you like so much...\n";
    }
    else {
        std::cout << "\n";
    }
}