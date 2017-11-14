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

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int yrNow=2017, yrThen;
    float infRate, prNow, prThen;
    
    //Initialize Variables
    
    //Input Data/Variables
    cout<<"This program calculates inflation rate"<<endl;
    cout<<"Year and price of original item"<<endl;
    cout<<"As well as price today"<<endl;
    cin>>yrThen>>prThen>>prNow;
    
    //Perform Calculations
    float prCalc = prThen;
    for (int year = yrThen; year <= yrNow; year++) {
        prCalc *= (1+infRate);
    }
    
    //Display Output
    cout<<"In "<<yrThen<<" your price = $"<<prThen<<endl;
    cout<<"In "<<yrNow<<" then price = $"<<prNow<<endl;
    cout<<"The Price calculated = "<<prCalc<<endl;
    cout<<"The inflation rate = "<<infRate*100.0f<<"%"<<endl;
    
    //Terminates Program
    return 0;
}

