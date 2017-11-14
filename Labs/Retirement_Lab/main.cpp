/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 9, 2017, 12:21 PM
 */

//Function Prototypes

//Global Constants

//User Libraries

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    float salary, deposit, invRate, savings, retAcct;
    
    //Initialize Variables
    salary=100000;                  //$100k
    invRate=0.05;                   //5%
    savings=salary/invRate;         //Required savings to retire $'s
    deposit=0.10;                   //10%/year
    retAcct=0;                      //Initialize the retirement account
    
    //Process or Map the Inputs to the Outputs
    cout<<"Retirement Table"<<endl;
    cout<<"Year  |  Savings | Interest Earned | Deposit"<<endl;
    for (int year=2022; year<=2072; year++) {
        float intErnd=invRate*retAcct;  //Interest earned by the year
        float depAmt=deposit*salary;    //Yearly deposit
        cout<<showpoint<<fixed<<setprecision(2)<<setw(4)<<year<<setw(13)<<retAcct<<setw(15)<<intErnd<<setw(13)<<depAmt<<endl;
        retAcct+=(intErnd+depAmt);
    }
    
    //Exits Program
    return 0;
}

