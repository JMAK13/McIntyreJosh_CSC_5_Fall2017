/* 
 * File:   main.cpp
 * Author: joshr
 *
 * Created on November 16, 2017, 11:34 AM
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
    int dec;
    
    //Prompt User for Input and Validate It
    do {
        cout<<"Please input the number of the version of the problem you would like to solve: "<<endl;
        cout<<"1) Computations"<<endl;
        cout<<"2) Arrays"<<endl;
        cout<<"3) MVC";
        cout<<"4) Functions";
        cin>>dec;
    } while(dec < 1 || dec > 4);
    
    
    //Menu
    switch (dec) {
        
        //Computations Version
        case 1: {
            //Declare Variables
            float pPrice, pDown, loanAmt, intRate, mnPmnt, blnPmnt, lstPmnt, totalL, totalC, accrued;
            
            //Initialize Variables
            pPrice = 10000.0f;
            pDown = 0.0f;
            loanAmt = pPrice*(1-pDown);
            intRate = .05f;
            mnPmnt = 299.71f;
            
            cout<<"Loan Amount(Start) | Interest Accrued(End) | Monthly Payment(End)"<<endl;
            for (int i = 0; i <= 35; i++) {
                accrued = loanAmt*intRate/12;
                cout<<fixed<<showpoint<<setprecision(2)<<setw(16)<<loanAmt<<setw(14)<<accrued<<setw(24)<<mnPmnt<<endl;
                loanAmt = loanAmt + accrued - mnPmnt;
            }
            
            accrued = loanAmt*intRate/12;
            loanAmt = loanAmt + accrued - mnPmnt;
            blnPmnt = mnPmnt + loanAmt;
            lstPmnt = mnPmnt + blnPmnt;
            totalL = mnPmnt * 35 + lstPmnt;
            totalC = totalL + pPrice*pDown;
            cout<<fixed<<showpoint<<setprecision(2);
            cout<<"Balloon Payment     = $"<<blnPmnt<<endl;
            cout<<"Last Payment        = $"<<lstPmnt<<endl;
            cout<<"Total Paid for Loan = $"<<totalL<<endl;
            cout<<"Total Paid for Car  = $"<<totalC<<endl;
            
        }
        
        //Arrays Version
        case 2: {
            //Declare Variables
            const int SIZE = 37;
            int byMonth[SIZE]={};
            float loanAmt[SIZE+1]={}, accrued[SIZE]={};
            float pPrice, pDown, intRate, mnPmnt;
            
            //Initialize Variables
            pPrice = 10000.0f;
            pDown = 0.0f;
            intRate = 0.05f;
            mnPmnt = 299.71f;
            loanAmt[0] = pPrice*(1-pDown);
            
            cout<<fixed<<setprecision(2)<<showpoint;
            cout<<"Car Payment Table"<<endl;
            cout<<"Monthly Payment = $ "<<mnPmnt<<endl;
            cout<<"Interest Rate   =  "<<intRate*100.0f<<"%"<<endl;
            cout<<"Price of Car    = $"<<pPrice<<endl;
            cout<<"Down Payment    = $  "<<pDown<<endl<<endl;
            cout<<"Month         Loan Amount        Accrued         Payment"<<endl;
            for(int indx=0;indx<SIZE;indx++) {
                accrued[indx]=loanAmt[indx]*intRate/12;
                cout<<setw(4)<<byMonth[indx]<<setw(18)<<loanAmt[indx]<<setw(17)<<accrued[indx]<<setw(17)<<mnPmnt<<endl;
                loanAmt[indx+1]=loanAmt[indx]+(accrued[indx]-mnPmnt);
            }
            
        }
        
        //MVS Version
        case 3: {
            cout<<"Not yet implemented..."<<endl;
        }
        
        //Functions Version
        case 4: {
            cout<<"Not yet implemented..."<<endl;
        }
    }
    //Exits
    return 0;
}

