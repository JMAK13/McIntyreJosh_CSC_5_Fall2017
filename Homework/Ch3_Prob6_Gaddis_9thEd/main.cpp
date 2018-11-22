/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 25, 2017, 4:26 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    float sugar, butter, flour, cookies;
    
    //Prompt User for Inputs
    cout<<"Please input how many cookies you would like to make: ";
    cin>>cookies;
    
    //Performs Calculation
    sugar = cookies/48*1.5;
    butter = cookies/48*1;
    flour = cookies/48*2.75;
    
    //Display Output
    cout<<"\nYou need "<<sugar<<" cups of sugar, "<<butter<<" cups of butter, and "<<flour<<" cups of flour in order to make "<<cookies<<" cookies.\n";

    //Ends Program
    return 0;
}

