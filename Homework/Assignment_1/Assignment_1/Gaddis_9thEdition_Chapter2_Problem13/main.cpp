/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 3:09 PM
 * Purpose: Circuit Board Price, Problem 13, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    float prcProf, cost;
    
    //Initialize Variables
    prcProf = .35;
    
    //Map Inputs to the Variables
    cout<<"Please input the price of the circuit board: ";
    cin>>cost;
    
    //Displays Output
    cout<<"The selling price for the circuit board is $"<<cost-(prcProf*cost)<<".\n";

    //Exit
    return 0;
}

