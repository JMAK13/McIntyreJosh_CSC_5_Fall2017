/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 3:15 PM
 * Purpose: Land Calculation, Problem 12, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
    //Declare and Initialize Variable
    float conv = 43560;
    float land = 391876;
    float acres = land/conv;
    
    //Display Output
    if (acres == 1) {
        cout<<"In "<<land<<" sq/ft of land their are "<<acres<<" acre.\n";
    } else {
    cout<<"In "<<land<<" sq/ft of land their are "<<acres<<" acres.\n";
    }

    //Exit
    return 0;
}

