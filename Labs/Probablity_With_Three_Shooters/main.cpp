/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 7, 2017, 11:31 AM
 * Purpose: Simple probability problem from Savitch, Ch5, Prob15
 */

//Function Prototypes
float pRand();
void shoot(bool, float, bool &, bool &);

//Global Constants

//User Libraries

//System Libraries
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed
    unsigned seed = time(0);
    srand(seed);

    //Declare Variables
    bool aliveA, aliveB, aliveC;
    float pKillA, pKillB, pKillC;
    char aliveSm;
    int nGames, nWinA, nWinB, nWinC;
    
    //Initialize Variables
    aliveA = true;
    aliveB = true;
    aliveC = true;
    pKillA = 1.0f/3;
    pKillB = 1.0f/2;
    pKillC = 1.0f;
    nGames = 10000;
    nWinA = 0;
    nWinB = 0;
    nWinC = 0;
    
    //Loops nGames Amount of Times
    for (int game = 1; game <= nGames; game++) {
        
        //Loops Until 1 Survivor
        do {
            //Perform Calculations
            shoot(aliveA, pKillA, aliveB, aliveC);

            shoot(aliveB, pKillB, aliveC, aliveA);

            shoot(aliveC, pKillC, aliveA, aliveB);

            aliveSm = aliveA+aliveB+aliveC;
        } while (aliveSm > 1);
        nWinA += aliveA;
        nWinB += aliveB;
        nWinC += aliveC;
        aliveA = true;
        aliveB = true;
        aliveC = true;
    }
    //Display Output
    cout<<"Number of Games = "<<nGames<<" = "<<nWinA+nWinB+nWinC<<endl;
    cout<<"Aaron   won "<<nWinA<<" times"<<endl;
    cout<<"Bob     won "<<nWinB<<" times"<<endl;
    cout<<"Charlie won "<<nWinC<<" time"<<endl;
    
    //Exits Program
    return 0;
}

float pRand() {
    int random;
    unsigned seed = time(0);
    srand(seed);
    random = (rand() % 0 + 1) + 1;
    return random;
}

void shoot(bool a, float pka, bool &b, bool &c) {
    if (a) {
            if (b) {
                if (pRand()<=pka) b = false;
            } else if (c) {
                if (pRand()<=pka) c = false;
            }
        }
}