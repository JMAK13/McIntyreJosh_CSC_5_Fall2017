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
    float cost, insurance;
    
    //Prompt User for Inputs
    cout<<"Please inputs the replacement cost for the building: ";
    cin>>cost;
    
    //Performs Calculation
    insurance = cost*0.8f;
    
    //Display Output
    cout<<"\nThe minimum amount of insurance you should buy for the property is %"<<fixed<<showpoint<<setprecision(2)<<insurance;
    
    //Ends Program
    return 0;
}

