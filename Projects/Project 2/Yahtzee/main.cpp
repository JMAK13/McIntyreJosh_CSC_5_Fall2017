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
#include <ctime>
#include <cstdlib>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int player=1, ones=0, twos=0, threes=0, fours=0, fives=0, sixes=0, roll1, roll2, roll3, roll4, roll5, roll6, score1, score2;    //Declare Necessary Pre-Game Variables
    int fh1=-1,fh2=-1,ls1=-1,ls2=-1,ss1=-1,ss2=-1,threeK1=-1,threeK2=-1,fourK1=-1,fourK2=-1,fiveK1=-1,fiveK2=-1;                    //The Upper Level Scoring Variables
    bool running=true;      //Game Loop Expression Variable
    int initial,sum1,sum2;            //Initial Variable to Either Start or Exit the Game
    
    //Validate Input
    do {
        //Prompt User to Exit/Start/See Rules
        cout<<"Hello and Welcome to Yahtzee by Josh McIntyre!"<<endl;
        cout<<"Make sure your output prompt is very large or else you may miss some content!"<<endl;
        cout<<"Press 0 to Exit"<<endl;
        cout<<"Press 1 to Start"<<endl;
        cout<<"Press 2 for Rules"<<endl;
        cin>>initial;
    } while(initial != 0 && initial != 1 && initial != 2);
    
    //If User Input 0 - Exit
    if (initial == 0) {
        cout<<"Okay, hope to see you again soon!"<<endl;
        
        //Exit Program
        return 0;
    }
    
    //If User Input 2 - Rules
    if (initial == 2) {
        //GAMEPLAY
        cout<<"GAMEPLAY:"<<endl;
        cout<<"The game begins with player the dice and add the rolls up, then player 2 will do the same. The player with\n";
        cout<<"the higher roll will go first. During turns players start by rolling all 5 dice, and can reroll up to 2\n";
        cout<<"times. The player chooses which dice they would like to set aside before each reroll. The dice are then\n";
        cout<<"scored in the player's desired box in the 13 box table. Each turn 1 box must be checked, even if the player\n";
        cout<<"must take a 0 in that box. At the end of the game the player with the higher score wins!\n\n";
        //SCORING
        cout<<"SCORING:"<<endl;
        cout<<"3 of a Kind - if there are 3 dice of the same value then the sum of all 5 dice can be scored in this box\n";
        cout<<"4 of a Kind - if there are 4 dice of the same value then the sum of all 5 dice can be scored in this box\n";
        cout<<"5 of a Kind - if there are 5 dice of the same value then 50 points can be scored in this box\n";
        cout<<"Full House - if there are 3 dice of the same value while the other 2 dice have the same value then 25 points\n";
        cout<<"             can be put in this box\n";
        cout<<"Small Straight - if there are 4 dice of consecutive value then 30 points can be put in this box\n";
        cout<<"Large Straight - if there are 5 dice of consecutive value then 40 points can be put in this box\n";
        cout<<"Small Straight - if there are 4 dice of consective value then 30 points can be put in this box\n";
        cout<<"Chance - the sum of all 5 dice can be put in this box\n";
        cout<<"Ones - the sum of all ones can be put in this box\n";
        cout<<"Twos - the sum of all twos can be put in this box\n";
        cout<<"Threes - the sum of all threes can be put in this box\n";
        cout<<"Fours - the sum of all fours can be put in this box\n";
        cout<<"Fives - the sum of all fives can be put in this box\n";
        cout<<"Sixes - the sum of all sixes can be put in this box\n\n";
        //Validate Input
        do {
            //Prompt User to Exit/Start
            cout<<"Press 0 to Exit"<<endl;
            cout<<"Press 1 to Start"<<endl;
            cin>>initial;
        } while(initial != 0 && initial != 1);
    }
    
    //If User Input 0 - Exit
    if (initial == 0) {
        cout<<"Okay, hope to see you again soon!"<<endl;
        
        //Exit Program
        return 0;
    }
    
    //If User Input 1 - Start
    if (initial == 1) {
            
        //Prompt Both Players to Roll to Go First
        do {

            //Seed the Random Function
            unsigned seed = time(0);
            srand(seed);
            
            //Player 1
            cout<<"Both players will now roll the dice, add them up, and whoever rolled higher will go first."<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice"<<endl;
            cin.ignore();
            cin.get();
            roll1=(rand()%6)+1;
            roll2=(rand()%6)+1;
            roll3=(rand()%6)+1;
            roll4=(rand()%6)+1;
            roll5=(rand()%6)+1;
            roll6=(rand()%6)+1;
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<" | Roll 6: "<<roll6<<endl;
            sum1=roll1+roll2+roll3+roll4+roll5+roll6;
            cout<<"Sum: "<<sum1<<endl;

            //Swap Players
            player+=1;

            //Player 2
            cout<<"Both players will now roll the dice, add them up, and whoever rolled higher will go first."<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice"<<endl;
            cin.get();
            roll1=(rand()%6)+1;
            roll2=(rand()%6)+1;
            roll3=(rand()%6)+1;
            roll4=(rand()%6)+1;
            roll5=(rand()%6)+1;
            roll6=(rand()%6)+1;
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<" | Roll 6: "<<roll6<<endl;
            sum2=roll1+roll2+roll3+roll4+roll5+roll6;
            cout<<"Sum: "<<sum2<<endl;

            if (sum1>sum2) {
                player=1;
                cout<<"Player "<<player<<" will go first!"<<endl;
            }
            if (sum1<sum2) {
                player=2;
                cout<<"Player "<<player<<" will go first!"<<endl;
            }
        } while(sum1==sum2);
        
        //Game Loop
        while (running) {
            
        }  
    }
    
    //Exits Program
    return 0;
}

