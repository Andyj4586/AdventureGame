#include <iostream>
#include "AdventureGame.hpp"
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

// ANSI escape codes for color
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_PINK "\x1b[35m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void slowPrint(std::string str, const char* color) {
    std::cout << color;
    for (int c = 0; c < str.length(); c++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(45));
        std::cout << str[c] << std::flush;
    }
    std::cout << ANSI_COLOR_RESET;
}

void slowPrint(std::string str){
    for (int c = 0; c < str.length(); c++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(45));
        std::cout << str[c] << std::flush;
    }
}

void start_game() {
    std::string start("Welcome to an Epic Adventure! Choose your character: Goblin or Princess (G/P)\n");
    slowPrint(start, ANSI_COLOR_RED);
    std::cin >> choice0;
    transform(choice0.begin(), choice0.end(), choice0.begin(), ::toupper);
    if (choice0 == "G") {
        std::string gob("You awaken in your dark and filthy cave to find you have been robbed by sneaky thieves. Do you Wake up and go look around, or go back to Sleep? (W/S)\n"); 
        slowPrint(gob, ANSI_COLOR_GREEN);
        std::cin >> choice1;
    } else if (choice0 == "P") {
        std::string pr("Greetings, m'lady! You find yourself in the majestic castle. Would you like to go to the ancient library, or take a stroll into the bustling village? (L/V)\n");
        slowPrint(pr, ANSI_COLOR_PINK);
        std::cin >> choice1;
    } else {
        std::cout << "\n";
    }
}

bool play_again() {
    std::string again("Would you like to embark on another thrilling adventure? (Y/N)\n");
    slowPrint(again, ANSI_COLOR_RED);
    std::cin >> cont;
    transform(cont.begin(), cont.end(), cont.begin(), ::toupper);
    while (cont != "Y" && cont != "N") {
        std::string que("Pardon me, but I didn't quite catch that. Would you like to play again? (Y/N)\n");
        slowPrint(que, ANSI_COLOR_RED);
        std::cin >> cont;
        transform(cont.begin(), cont.end(), cont.begin(), ::toupper);
    }
    if (cont == "Y") {
        return true;
    } else {
        return false;
    }
}

std::string step_1() {
    transform(choice1.begin(), choice1.end(), choice1.begin(), ::toupper);
    if (choice1 == "L") {
        std::string pr("You venture into the ancient library, but to your dismay, the most treasured book of legends has vanished! Will you head to the village Bookstore to investigate further, or seek counsel from your wise father, the King? (B/K)\n");
        slowPrint(pr, ANSI_COLOR_PINK);
        std::cin >> choice2;
        return "P"; 
    } else if (choice1 == "V") {
        std::string pr("You stealthily sneak past the vigilant guards and venture into the lively village. Shall you visit the mysterious Bookstore or the enchanting Cafe? (B/C)\n");
        slowPrint(pr, ANSI_COLOR_PINK);
        std::cin >> choice2;
        return "P";
    } else if (choice1 == "W") {
        std::string gob("You step outside your cave to see an orc stumbling away with your belongings. Confront or Ignore? (C/I)\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
        std::cin >> choice2;
        return "G";
    } else if (choice1 == "S") {
        std::string gob("You roll over and fall back asleep like the lazy Goblin you are.\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
        return "N";
    } else {
        std::cout << "\n";
        return "N";
    }
}

std::string step_2G() {
    transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
    if (choice2 == "C") {
        std::string gob("The orc is willing to return your belongings if you can best him in an arm-wrestling match. Do you accept his offer? (Y/N)\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
        std::cin >> choice3;
        return "A";
    } else if (choice2 == "I") {
        std::string gob("With nothing of value to your name, you decide to wander the streets as a penniless, homeless Goblin.\nBut suddenly, you encounter a mysterious magician. He offers you magic beans that can grow into a new, luxurious home for you.\nBut there's a catch. They come at a price...\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
        sleep(3);
        std::string gob1("You must serve as the magician's apprentice for 5 years before planting the beans to make them work properly.\nDo you Accept the magician's offer, or Run away like a scared little baby goblin? (A/R)\n");
        slowPrint(gob1, ANSI_COLOR_GREEN);
        std::cin >> choice3;
        return "B";
    } else {
        std::cout << "\n";
        return "Q";
    }
}

void step_3G() {
    transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
    if (choice3 == "Y") {
        std::string gob("You courageously accept the orc's challenge, but he easily bests you and proceeds to tear your arm off as a painful lesson. Perhaps, think twice about your decisions next time, brave Goblin!\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
    } else if (choice3 == "N") {
        std::string gob("A wise decision indeed. It's better to be alive, even if it means starting over...\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
    } else if (choice3 == "A") {
        std::string gob("You begin working tirelessly for the magician, and continue to do so as per your 5-year contract.\nAt the end of a long, hard 5 years, you ask the magician if it is time to plant your beans.\nThe magician turns to you and laughs. After all this time, he confesses that magic isn't real.\nHow did you not figure that out over 5 years, silly Goblin?? Better luck next time...\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
    } else if (choice3 == "R") {
        std::string gob("You run away to the village crying. The local cobbler takes pity on you and offers you a home and apprenticeship.\nFinally, you have found a place where you can live a happy, peaceful, but not-so-smart Goblin life.\nTHE END\n");
        slowPrint(gob, ANSI_COLOR_GREEN);
    } else {
        std::cout << "\n";
    }
}

std::string step_2P() {
    transform(choice2.begin(), choice2.end(), choice2.begin(), ::toupper);
    if (choice2 == "B") { 
        std::string pr("On your way to the bookstore, you spot a magician trying to deceive a goblin. Do you stop to Help or Walk on by? (H/W)\n");
        slowPrint(pr, ANSI_COLOR_PINK);
        std::cin >> choice3;
        return "C";
    } else if (choice2 == "K") { 
        std::string pr("You go to speak with the King, but find that he has been called to lead the army against an invading tribe of orcs.\nWhat's more, the royal guards have declared a lockdown preventing you from leaving the castle.\nYou decide to make a run for it. After stealing a horse, you have a decision to make. Do you rush to the Village to buy a new book, or\nhead to the Battlefield to try and help your father? (V/B)\n");
        slowPrint(pr, ANSI_COLOR_PINK);
        std::cin >> choice3;
        return "D";
    } else if (choice2 == "C") {
        std::string pr("You arrive at the cafe. Do you order your Usual, or the Special? (U/S)\n");
        slowPrint(pr, ANSI_COLOR_PINK);
        std::cin >> choice3;
        return "E";
    } else {
        std::cout << "\n";
        return "H";
    }
}

void step_3P() {
    transform(choice3.begin(), choice3.end(), choice3.begin(), ::toupper);
    if (choice3 == "H") {
        std::string pr("You help the goblin avoid a terrible mistake. Being the kind princess you are, you escort the goblin to the village.\nAfter talking, you discover that you get along quite nicely, and decide to immediately take the goblin\nback to the castle as your personal servant.\nOver the years, the two of you go on many fun adventures, and live happily ever after.\nTHE END\n");
        slowPrint(pr, ANSI_COLOR_PINK);
    } else if (choice3 == "W") {
        std::string pr("You ignore the poor goblin and rush to the village. Just as you arrive, the orc army invades and attacks you.\nMaybe you should have been a little kinder to the goblin...\n");
        slowPrint(pr, ANSI_COLOR_PINK);
    } else if (choice3 == "V") {
        std::string pr("You rush to the village, paying no attention to anyone you pass by. The village has already been invaded by orcs,\nwho take you prisoner for the rest of your life. Maybe next time don't be in such a rush...\n");
        slowPrint(pr, ANSI_COLOR_PINK);
    } else if (choice3 == "B") {
        std::string pr("You arrive at the battlefield just in time to valiantly save your father's life. Together, you defeat the orc leader and\nusher in a new era of peace throughout your kingdom. The people adore you, and you live a long, happy life,\nserving as a fierce and effective Queen. On your deathbed, your only regret\nis not having a close friend to have shared your adventures with.\nTHE END\n"); 
        slowPrint(pr, ANSI_COLOR_PINK);
    } else if (choice3 == "U") {
        std::string pr("You drink your usual, and go on to the bookstore, where you run into Prince Charming.\nHe sees the coffee you ordered and looks disgusted.\nYou try to flirt with him, but you ruin it by being awkward, and he never talks to you again.\nMaybe you should have tried something new...\n");
        slowPrint(pr, ANSI_COLOR_PINK);
    } else if (choice3 == "S") {
        std::string pr("The special of the day is delicious and extra caffeinated. The extra boost jogs your memory,\nand you remember where your book is! You return to the castle and have a nice time re-reading it.\nMaybe one day you'll go on adventures like the ones in the book you like so much...\n");
        slowPrint(pr, ANSI_COLOR_PINK);
    } else {
        std::cout << "\n";
    }
}


int main() {
    while(keep_playing){
    start_game();
    ans1 = step_1();
    if(ans1 == "G") {
        ans2 = step_2G();
        if(ans2 == "A" || ans2 == "B"){
        step_3G();
        }
        else if(ans2 == "C" || ans2 == "D" || ans2 == "E"){
        step_3P();
        }
        else {
        std::cout << "That wasn't one of the options.\n";
        }
        
    }
    else if(ans1 == "P") {
        ans2 = step_2P();
        if(ans2 == "A" || ans2 == "B"){
        step_3G();
        } 
        else if(ans2 == "C" || ans2 == "D" || ans2 == "E"){
        step_3P();
        }
        else {
        std::cout << "That wasn't one of the options.\n";
        }
    }
    else {
        std::cout << "That wasn't one of the options.\n";
        }
    keep_playing = play_again();
    
    }
}