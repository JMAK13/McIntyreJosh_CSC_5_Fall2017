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
    string mon1, mon2, mon3;
    float amt1, amt2, amt3, avg;
    
    //Prompt User for Inputs
    cout<<"Please input the name of the first month: ";
    cin>>mon1;
    cout<<"\nPlease input "<<mon1<<"'s amount of rain in inches: ";
    cin>>amt1;
    cout<<"Please input the name of the second month: ";
    cin>>mon2;
    cout<<"\nPlease input "<<mon2<<"'s amount of rain in inches: ";
    cin>>amt2;
    cout<<"Please input the name of the third month: ";
    cin>>mon3;
    cout<<"\nPlease input "<<mon3<<"'s amount of rain in inches: ";
    cin>>amt3;
    
    //Performs Calculation
    avg = (amt1+amt2+amt3)/3;
    
    //Display Output
    cout<<setprecision(3)<<"\nThe average rainfall for "<<mon1<<", "<<mon2<<", and "<<mon3<<" is "<<avg<<" inches.";

    //Ends Program
    return 0;
}

