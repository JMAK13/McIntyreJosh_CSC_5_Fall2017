/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 25, 2017, 4:26 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    short ate, calories;
    
    //Prompt User for Inputs
    cout<<"Please input the number of cookies you ate: ";
    cin>>ate;
    
    //Performs Calculation
    calories = (300/(30/10))*ate;
    
    //Display Output
    cout<<"\nYou have consumed "<<calories<<" calories by eating "<<ate<<" cookies.";
    
    //Ends Program
    return 0;
}

