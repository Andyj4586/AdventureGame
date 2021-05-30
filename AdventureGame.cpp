// roleplaying game
#include <iostream>
#include "AG_other_header.hpp"
using namespace std;

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
        std::cout << "Learn to read, moron.\n";
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
        std::cout << "Learn to read, moron.\n";
        }
    }
    else {
        std::cout << "Learn to read, moron.\n";
        }
    keep_playing = play_again();
    
    }
    }
