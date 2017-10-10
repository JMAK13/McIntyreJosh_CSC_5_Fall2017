/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 2:37 PM
 * Purpose: Annual High Temperature, Problem 19, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
    //Declare Variables
    float temp1, temp2, temp3, prcRise, avg;
    
    //Initialize Variables
    prcRise = 1.02;
    
    //Map Inputs to the Variables
    cout<<"Please input the first temperature: ";
    cin>>temp1;
    cout<<"Please input the second temperature: ";
    cin>>temp2;
    cout<<"Please input the third temperature: ";
    cin>>temp3;
    cout<<endl;
    
    temp1 = temp1*prcRise;
    temp2 = temp2*prcRise;
    temp3 = temp3*prcRise;
    
    //Display Outputs
    cout<<"The first new average temperature if it rose by 2% is "<<temp1<<"degrees Fahrenheit.\n";
    cout<<"The second new average temperature if it rose by 2% is "<<temp2<<"degrees Fahrenheit.\n";
    cout<<"The third new average temperature if it rose by 2% is "<<temp3<<"degrees Fahrenheit.\n";

    //Exit
    return 0;
}

