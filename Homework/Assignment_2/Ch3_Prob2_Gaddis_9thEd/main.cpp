/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 25, 2017, 4:26 AM
 */

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    int a, b, c, revenue;
    
    //Prompt User to Input Values
    cout<<"Please input the number of Class A tickets sold: ";
    cin>>a;
    cout<<"\nPlease input the number of Class B tickets sold: ";
    cin>>b;
    cout<<"\nPlease input the number of Class C tickets sold: ";
    cin>>c;
    
    //Perform Calculations
    revenue = (a*15) + (b*12) + (c*9);
    
    //Display Output
    cout<<"\nThe income generated from ticket sales was $"<<revenue<<".00";

    //Ends Program
    return 0;
}

