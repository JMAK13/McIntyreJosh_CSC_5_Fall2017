/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 8, 2017, 6:25 PM
 * Purpose: Recreation of the popular card game Yahtzee
 */

//Function Prototypes

//Global Constants

//User Libraries

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    int player=1, ones=0, twos=0, threes=0, fours=0, fives=0, sixes=0, roll1, roll2, roll3, roll4, roll5, roll6, score1, score2;    //Declare All Necessary Pre-Game Variables
    bool running=true;      //Game Loop Expression Variable
    int initial;            //Initial Variable to Either Start or Exit the Game
    
    //Validate Input
    do {
        //Prompt User to Exit/Start/See Rules
        cout<<"Hello and Welcome to Yahtzee by Josh McIntyre!"<<endl;
        cout<<"Press 0 to exit"<<endl;
        cout<<"Press 1 to start"<<endl;
        cout<<"Press 2 for rules"<<endl;
        cin>>initial;
    } while(initial != 0 && initial != 1 && initial != 2);
    
    //If User Input 0
    if (initial == 0) {
        
    }
    
    //If User Input 1
    if (initial == 1) {
        while (running) {
            
        }  
    }
    
    //If User Input 2
    if (initial == 2) {
        
    }
    
    
    //Exits Program
    return 0;
}

