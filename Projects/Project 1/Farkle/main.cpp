/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on October 19, 2017, 12:12 PM
 * Purpose: Simple recreation of Farkle
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int s1=0, s2=0, d1, d2, d3, d4, d5, d6, player = 1, i1, i2;     //Score, Dice, and Player Variables
    bool running = true;                                        //Game Loop Expression
    int dec;                                                    //Decision Variable
    
    //Prompts User to Start/Exit
    do {
        cout<<"Welcome to Farkle by Josh McIntyre!"<<endl;
        cout<<"Enter 1 to Start or 0 to Exit: ";
        cin>>dec;
        
        //Sends Invalid Decision Message
        if (dec != 0 && dec != 1) {
            cout<<"\nPlease enter a valid decision!\n\n";
        }
    } while(dec != 0 && dec != 1);
    
    //Exits Game Based on User's Decision
    if (dec == 0) {
        cout<<"Thanks for playing, hope to see you again soon!"<<endl;
        return 0;
    }
    
    //Seeds for Random Function Using time
    unsigned seed = time(0);
    srand(seed);
    
    //Prompts Users to Each Roll a Die - Higher Roll Goes First
    cout<<"Both players will now roll 1 dice each, whoever gets the higher roll will go first"<<endl;
    
    //Keeps Players Rolling to Go First Until One Gets a Roll Higher than the Other
    do {
        //Player 1
        cout<<"Player "<<player<<": Press enter to roll the dice"<<endl;
        cin.ignore();
        cin.get();
        i1 = (rand() % 6) + 1;
        cout<<"You rolled a "<<i1<<endl;
        player++;

        //Player 2
        cout<<"Player "<<player<<": Press enter to roll the dice"<<endl;
        cin.get();
        i2 = (rand() % 6) + 1;
        cout<<"You rolled a "<<i2<<endl;
        player--;

        //Calculates Which Roll was Higher
        if (i1 > i2) {
            player = 1;
            cout<<"Player "<<player<<" will go first."<<endl;
        }
        if (i2 > i1) {
            player = 2;
            cout<<"Player "<<player<<" will go first."<<endl;
        }
    } while (i1 == i2);
    
    //Game Loop
    while (running) {
        
        int ones1=0, twos1=0, threes1=0, fours1=0, fives1=0, sixes1=0, ones2=0, twos2=0, threes2=0, fours2=0, fives2=0, sixes2=0;
        int temps1 = s1, temps2 = s2;
        
        //Player 1's Turn
        cout<<"Player "<<player<<": Press enter to roll the dice"<<endl;
        cin.get();
        d1 = (rand() % 6) + 1;
        d2 = (rand() % 6) + 1;
        d3 = (rand() % 6) + 1;
        d4 = (rand() % 6) + 1;
        d5 = (rand() % 6) + 1;
        d6 = (rand() % 6) + 1;
        
        //Map Rolls to Array
        int rolls1[6] = {d1, d2, d3, d4, d5, d6};
        
        //Count the Dice
        for (int i = 0; i <= 5; i++) {
            if (rolls1[i] == 1) ones1++;
            if (rolls1[i] == 2) twos1++;
            if (rolls1[i] == 3) threes1++;
            if (rolls1[i] == 4) fours1++;
            if (rolls1[i] == 5) fives1++;
            if (rolls1[i] == 6) sixes1++;
        }
        
        //Score Player 1's Rolls
        if (ones1 == 6 || twos1 == 6 || threes1 == 6 || fours1 == 6 || fives1 == 6 || sixes1 == 6) s1 += 3000;
        if (ones1 == 5 || twos1 == 5 || threes1 == 5 || fours1 == 5 || fives1 == 5 || sixes1 == 5) s1 += 2000;
        if (ones1 == 4 || twos1 == 4 || threes1 == 4 || fours1 == 4 || fives1 == 4 || sixes1 == 4) s1 += 1000;
        if (ones1 == 3) s1 += 300;
        if (twos1 == 3) s1 += 200;
        if (threes1 == 3) s1 += 300;
        if (fours1 == 3) s1 += 400;
        if (fives1 == 3) s1 += 500;
        if (sixes1 == 3) s1 += 600;
        if (ones1 == 2) s1 += 200;
        if (fives1 == 2) s1 += 100;
        if (ones1 == 1) s1 += 100;
        if (fives1 == 1) s1 += 50;
        if (temps1 == s1) s1 = 0;
        
        //Display Player 1's Rolls/Score
        cout<<"Roll 1: "<<d1<<" | Roll 2: "<<d2<<" | Roll 3: "<<d3<<" | Roll 4: "<<d4<<" | Roll 5: "<<d5<<" | Roll 6: "<<d6<<endl;
        cout<<"Player "<<player<<"'s Score: "<<s1<<endl;
        
        //Checks for Winner
        if (s1 >= 10000) {
            cout<<"Player "<<player<<" Wins!\n";
            running = false;
            return 0;
        }
        
        //Switch Players
        if (player == 1) player = 2;
        else player = 1;
        
        //Player 2's Turn
        cout<<"Player "<<player<<": Press enter to roll the dice"<<endl;
        cin.get();
        d1 = (rand() % 6) + 1;
        d2 = (rand() % 6) + 1;
        d3 = (rand() % 6) + 1;
        d4 = (rand() % 6) + 1;
        d5 = (rand() % 6) + 1;
        d6 = (rand() % 6) + 1;
        
        //Map Rolls to Array
        int rolls2[6] = {d1, d2, d3, d4, d5, d6};
        
        //Count the Dice
        for (int i = 0; i <= 5; i++) {
            if (rolls2[i] == 1) ones2++;
            if (rolls2[i] == 2) twos2++;
            if (rolls2[i] == 3) threes2++;
            if (rolls2[i] == 4) fours2++;
            if (rolls2[i] == 5) fives2++;
            if (rolls2[i] == 6) sixes2++;
        }
        
        //Score Player 2's Rolls
        if (ones2 == 6 || twos2 == 6 || threes2 == 6 || fours2 == 6 || fives2 == 6 || sixes2 == 6) s2 += 3000;
        if (ones2 == 5 || twos2 == 5 || threes2 == 5 || fours2 == 5 || fives2 == 5 || sixes2 == 5) s2 += 2000;
        if (ones2 == 4 || twos2 == 4 || threes2 == 4 || fours2 == 4 || fives2 == 4 || sixes2 == 4) s2 += 1000;
        if (ones2 == 3) s2 += 300;
        if (twos2 == 3) s2 += 200;
        if (threes2 == 3) s2 += 300;
        if (fours2 == 3) s2 += 400;
        if (fives2 == 3) s2 += 500;
        if (sixes2 == 3) s2 += 600;
        if (ones2 == 2) s2 += 200;
        if (fives2 == 2) s2 += 100;
        if (ones2 == 1) s2 += 100;
        if (fives2 == 1) s2 += 50;
        if (temps2 == s2) s2 = 0;
        
        //Display Player 2's Rolls/Score
        cout<<"Roll 1: "<<d1<<" | Roll 2: "<<d2<<" | Roll 3: "<<d3<<" | Roll 4: "<<d4<<" | Roll 5: "<<d5<<" | Roll 6: "<<d6<<endl;
        cout<<"Player "<<player<<"'s Score: "<<s2<<endl;
        
        //Checks for Winner
        if (s2 >= 10000) {
            cout<<"Player "<<player<<" Wins!\n";
            running = false;
            return 0;
        }
        
        //Switch Players
        if (player == 1) player = 2;
        else player = 1;
    }
    
    //Exits Program
    return 0;
}

