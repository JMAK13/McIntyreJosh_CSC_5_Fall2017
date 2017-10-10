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
    float loan, insurance, gas, oil, tires, maint, totalM, totalY;
    
    //Prompt User for Inputs
    cout<<"Please input the amount you pay monthly for a car loan: ";
    cin>>loan;
    cout<<"\nPlease input the amount you pay monthly for gas: ";
    cin>>gas;
    cout<<"\nPlease input the amount you pay monthly for oil: ";
    cin>>oil;
    cout<<"\nPlease input the amount you pay monthly for tires: ";
    cin>>tires;
    cout<<"\nPlease input the amount you pay monthly for car maintenance: ";
    cin>>maint;
    
    //Performs Calculation
    totalM = loan+gas+oil+tires+maint;
    totalY = 12*(loan+gas+oil+tires+maint);
    
    //Display Output
    cout<<"\nThe total you pay monthly for car expenses is $"<<fixed<<showpoint<<setprecision(2)<<totalM;
    cout<<"\nThe total you pay yearly for car expenses is $"<<fixed<<showpoint<<setprecision(2)<<totalY;
    
    //Ends Program
    return 0;
}

