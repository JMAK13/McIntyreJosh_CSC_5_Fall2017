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
    float males, females, malePerc, femPerc, total;
    
    //Prompt User for Inputs
    cout<<"Please input the number of males in the class: ";
    cin>>males;
    cout<<"\nPlease input the number of females in the class: ";
    cin>>females;
    
    //Performs Calculation
    total = males + females;
    malePerc = (males/total)*100.0f;
    femPerc = (females/total)*100.0f;
    
    //Display Output
    cout<<setprecision(3)<<"\nThe percentage of males in the class is: "<<malePerc<<"%\n";
    cout<<setprecision(3)<<"The percentage of females in the class is: "<<femPerc<<"%";

    //Ends Program
    return 0;
}

