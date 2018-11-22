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
    float score1, score2, score3, score4, score5, avg;
    
    //Prompt User for Inputs
    cout<<"Please input the first test score: ";
    cin>>score1;
    cout<<"\nPlease input the second test score: ";
    cin>>score2;
    cout<<"\nPlease input the third test score: ";
    cin>>score3;
    cout<<"\nPlease input the fourth test score: ";
    cin>>score4;
    cout<<"\nPlease input the fifth test score: ";
    cin>>score5;
    
    //Performs Calculation
    avg = (score1+score2+score3+score4+score5)/5;
    
    //Display Output
    cout<<setprecision(3)<<"\nThe overall test average was: "<<avg<<"%";

    //Ends Program
    return 0;
}

