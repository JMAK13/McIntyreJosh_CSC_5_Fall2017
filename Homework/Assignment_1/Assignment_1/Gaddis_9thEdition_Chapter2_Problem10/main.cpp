/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 3:21 PM
 * Purpose: Miles per Gallon, Problem 10, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    unsigned short miles, gallons, mpg;
    
    //Initialize Variables
    gallons = 15;
    miles = 375;
    mpg = miles/gallons;
    
    //Display Output and Calculation
    cout<<"A car that can hold "<<gallons<<" gallons of gas that can go "<<miles<<" miles before refueling get "<<mpg<<" miles per gallon.\n";

    //Exit
    return 0;
}

