/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 14, 2017, 11:14 PM
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
    float pPrice, pDown, loanAmt, intRate, mnPmt;
    
    //Initialize Variables
    pPrice=350000.00f;                   //Purchase Price = $350k
    pDown=0.20f;                         //Percentage Down = 5%
    loanAmt=pPrice*(1-pDown);            //Required loan amount in $'s
    intRate=0.05;                        //Interest Rate per year
    mnPmt=1503.11f;                      //Initialize the retirement account
    
    //Process or Map the Inputs to the Outputs
    cout<<"Home Amortization Table"<<endl<<endl;
    cout<<"Purchase Price  = $"<<pPrice<<endl;
    cout<<"Percent Down    = "<<pDown*100<<"%"<<endl;
    cout<<"Loan Amount     = $"<<loanAmt<<endl;
    cout<<"Interest Rate   = "<<intRate*100<<"%"<<endl;
    cout<<"Monthly Payment = $"<<mnPmt<<endl<<endl;
    cout<<"Month  |  Loan Amount | Interest Payed | Monthly Payment"<<endl;
    for (int month=0; month<=359; month++) {
        float intAccum=intRate/12*loanAmt;  //Interest accumulated per month
        cout<<showpoint<<fixed<<setprecision(2)<<setw(4)<<month<<setw(16)<<loanAmt<<setw(14)<<intAccum<<setw(16)<<mnPmt<<endl;
        loanAmt+=(intAccum-mnPmt);
    }
    
    cout<<endl;
    cout<<"Last Payment = $"<<mnPmt+loanAmt<<endl;
    cout<<"Total Paid for Loan = $"<<360*mnPmt+loanAmt<<endl;
    cout<<"Total Paid for House = $"<<pPrice*pDown+360*mnPmt+loanAmt<<endl;
    
    //Exits Program
    return 0;
}

