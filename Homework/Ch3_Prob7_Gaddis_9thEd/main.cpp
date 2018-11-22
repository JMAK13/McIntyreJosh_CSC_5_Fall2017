/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 25, 2017, 4:26 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    string movie;
    short adults, children;
    float sum1, sum2, gross, net, paid;
    
    //Prompt User for Inputs
    cout<<"Please input the name of the movie: ";
    getline(cin, movie);
    cout<<"\nPlease input how many adult tickets were sold: ";
    cin>>adults;
    cout<<"\nPlease input how many child tickets were sold: ";
    cin>>children;
    
    //Performs Calculation
    sum1 = static_cast<float>(adults)*10.00f;
    sum2 = static_cast<float>(children)*6.00f;
    gross = sum1+sum2;
    net = gross*0.2f;
    paid = gross-paid;
    
    //Display Output
    cout<<"\nMovie Name: \""<<movie<<"\"";
    cout<<"\nAdult Tickets Sold: "<<adults;
    cout<<"\nChild Tickets Sold: "<<children;
    cout<<"\nGross Box Office Profit: $"<<setprecision(2)<<fixed<<showpoint<<gross;
    cout<<"\nNet Box Office Profit: $"<<setprecision(2)<<fixed<<showpoint<<net;
    cout<<"\nAmount Paid to Distributer: $"<<setprecision(2)<<fixed<<showpoint<<paid;
    
    //Ends Program
    return 0;
}

