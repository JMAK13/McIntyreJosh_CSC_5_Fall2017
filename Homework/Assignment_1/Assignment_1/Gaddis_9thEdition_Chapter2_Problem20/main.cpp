/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 2:17 PM
 * Purpose: How Much Paint, Problem 20, Chapter 2, Gaddis-9th Edition 
 */

//System Libraries
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    //Declare Variables
    float length, width, area, ftPerGal, gallons;
    
    //Initialize Variables
    ftPerGal = 340;
    
    //Receive Input and Run Calculations
    cout<<"What is the length of the object being painted?  ";
    cin>>length;
    cout<<"What is the width of the object being painted?  ";
    cin>>width;
    cout<<endl;
    
    area=length*width;
    gallons=area/ftPerGal;
    
    if (gallons == 1) {
        cout<<"The area of the object is "<<area<<"ft^2 and to paint one side of the object would require "<<gallons<<" gallon of paint.\n";
    }else {
        cout<<"The area of the object is "<<area<<"ft^2 and to paint one side of the object would require "<<gallons<<" gallons of paint.\n";
    }
    
    if ((2*gallons) == 1) {
        cout<<"To paint both sides of the object it would require "<<2.0*gallons<<" gallon of paint.\n";
    } else {
    cout<<"To paint both sides of the object it would require "<<2.0*gallons<<" gallons of paint.\n";
    }
    
    //Exit
    return 0;
}

