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
    short widgets;
    float stackedW, palletW, widgetW;
    
    //Prompt User for Inputs
    cout<<"Please input how much the pallet weighs by itself in pounds: ";
    cin>>palletW;
    cout<<"\nPlease input how much the pallet weighs with the pallets on it in pounds: ";
    cin>>stackedW;
    
    //Performs Calculation
    widgetW = stackedW-palletW;
    widgets = widgetW/12.5;
    
    //Display Output
    cout<<"\nThere are "<<widgets<<" widgets stacked on that pallet.";
    
    //Ends Program
    return 0;
}

