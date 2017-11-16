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
    const int SIZE=360;
    int strtMn, byMonth[SIZE];
    float intAccm[SIZE]={}, loanAmt[SIZE]={};
    float pPrice, pDown, intRate, mnPmt;
    
    //Initialize Variables
    pPrice=350000.00f;                   //Purchase Price = $350k
    pDown=0.20;                          //Percentage Down = 5%
    loanAmt[0] = pPrice*(1-pDown);       //Initialize first loan amount
    intRate=0.05;                        //Interest Rate per year
    mnPmt=1503.11f;                      //Initialize the Monthly Payment
    strtMn = 0;
    
    //Process or Map the Inputs to the Outputs
    cout<<"Home Amortization Table"<<endl<<endl;
    cout<<"Purchase Price  = $"<<pPrice<<endl;
    cout<<"Percent Down    = "<<pDown*100<<"%"<<endl;
    cout<<"Loan Amount     = $"<<loanAmt<<endl;
    cout<<"Interest Rate   = "<<intRate*100<<"%"<<endl;
    cout<<"Monthly Payment = $"<<mnPmt<<endl<<endl;
    cout<<"Month  |  Loan Amount | Interest Payed | Monthly Payment"<<endl;
    for (int i = 0; i < SIZE; i++) {
        byMonth[i] = i + strtMn;
        intAccm[i] = intRate/12*loanAmt[i];
        cout<<showpoint<<fixed<<setprecision(2)<<setw(4)<<byMonth[i]<<setw(16)<<loanAmt[i]<<setw(14)<<intAccm[i]<<setw(16)<<mnPmt<<endl;
        loanAmt[i+1] = intAccm[i]-mnPmt;
        /*float intAccm=intRate/12*loanAmt;  //Interest accumulated per month
        cout<<showpoint<<fixed<<setprecision(2)<<setw(4)<<month<<setw(16)<<loanAmt<<setw(14)<<intAccm<<setw(16)<<mnPmt<<endl;
        loanAmt+=(intAccm-mnPmt);*/
    }
    
    cout<<endl;
    cout<<"Last Payment = $"<<mnPmt+loanAmt[360]<<endl;
    cout<<"Total Paid for Loan = $"<<360*mnPmt+loanAmt[360]<<endl;
    cout<<"Total Paid for House = $"<<pPrice*pDown+360*mnPmt+loanAmt[360]<<endl;
    
    //Exits Program
    return 0;
}

