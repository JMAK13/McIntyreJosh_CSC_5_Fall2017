/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 3:38 PM
 * Purpose: Annual Pay, Problem 6, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    
    //Declare Variables
    float payAmount = 2200, payPeriods = 26, annualPay;
    
    //Calculate and Initialize annualPay Variable
    annualPay = 2200*26;
    
    //Display Output
    cout<<"The employee's annual pay after "<<payPeriods<<" pay periods and getting payed $"<<payAmount<<".00 each time is $"<<annualPay<<".00\n";
    
    //Exit
    return 0;
}

