/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on October 17, 2017, 11:42 AM
 * Purpose: Weight Problem
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants
const float GRAVITY = 6.673e-8f;
const float CNVCMFT = 1/30.48f;
const float CNVMFT = 5280.0f;
const float CNVGKG = 1000.0f;
const float REARTH = 3959.0f;
const float MEARTH = 5.972e24f;

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    float myMass, myWgt, actWgt;
    
    //Initialize Variables
    myMass = 6.0f;
    
    //Input Data/Variables
    cout<<"This program converts your weight in pounds to"<<endl;
    cout<<"Your mass in slugs"<<endl;
    cout<<"Input your actual weight in pounds"<<endl;
    cin>>actWgt;
    
    //Perform Calculations
    float delta, tol=.01f, kGain = tol;
    do {
        myWgt = GRAVITY * CNVCMFT * CNVCMFT * CNVCMFT * MEARTH * CNVGKG * myMass /(REARTH * REARTH * CNVMFT * CNVMFT);
        delta = actWgt-myWgt;
        myMass += kGain*delta;
    } while (abs(delta) >= tol);
    
    //Display Output
    cout<<"Your weight = "<<myWgt<<" lbs"<<endl;
    cout<<"Your mass = "<<myMass<<" slugs"<<endl;
    
    //Terminates Program
    return 0;
}

