/* 
 * File: main.cpp
 * Author: Josh McIntyre
 * Created on October 31, 2017, 11:50 AM
 * Purpose: Gaddis 8thEd, Ch6, Prob7 - Temperature Conversion
 */

//Function Prototypes
float degC(float);//Linear Conversion
float degC(float, float, float, float, float);//Interpolation


//Global Constants

//User Libraries

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    float degCent, degFahr,
            f1 = 32,  //Freezing Point of water 32 degrees Fahrenheit
            f2 = 212, //Boiling Point of water 212 degrees Fahrenheit
            c1 = 0,   //Freezing Point of water 0 degrees Centigrade
            c2 = 100; //Boiling Point of water 100 degrees Centigrade
    
    //Output the Temperature Table
    cout<<"The Temperate Conversion Table"<<endl;
    cout<<"Fahrenheit  Celsius 1   Celsius 2"<<endl;
    cout<<fixed<<setprecision(4)<<showpoint;
    for (int f=f1; f <= f2; f++) {
        cout<<setw(7)<<f
            <<setw(14)<<degC(f)
            <<setw(12)<<degC(f,f1,f2,c1,c2)<<endl;
    }
    
    //Exits Program
    return 0;
}

//Linear Conversion Function
float degC(float f) {
    return (f-32)*5/9;
}

//Interpolation Function
float degC(float f, float f1, float f2, float c1, float c2) {
    return c1+((c2-c1)*(f-f1)/(f2-f1));
}
