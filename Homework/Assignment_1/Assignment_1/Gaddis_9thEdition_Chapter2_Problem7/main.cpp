/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 3:34 PM
 * Purpose: Ocean Levels, Problem 7, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    
    //Declare Variables and Initialize Variable
    float inc = 1.5;
    
    //Display Outputs
    cout<<"The oceans level will be "<<inc*5<<"mm higher than it currently is in 5 years.\n";
    cout<<"The oceans level will be "<<inc*7<<"mm higher than it currently is in 7 years.\n";
    cout<<"The oceans level will be "<<inc*10<<"mm higher than it currently is in 10 years.\n";

    return 0;
}

