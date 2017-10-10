/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on October 1, 2017, 1:22 PM
 * Purpose: Gaddis 9th Edition Chapter 4 Questions 1-9
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Declare Variables
    int problem;
    bool valid = true;
    
    //Loops until user enters a valid problem number
    while (valid) {
    cout<<"Please input the number of the problem you wish to solve: ";
    cin>>problem;
        if (problem <= 0 || problem > 9) {
         cout<<"\nInvalid problem number.\n";
         valid = true;  //Keeps loop going
        } else valid = false;   //Exits loop
    }
    
    //Decides which problem is to be solves based on user input
    switch (problem) {
        
        //Problem 1
        case 1: {
            
            //Declare Variables
            float num1, num2, min, max;
            
            //Prompt User for Input
            cout<<"Please input the first number: ";
            cin>>num1;
            cout<<"\nPlease input the second number: ";
            cin>>num2;
            
            //Performs Calculations
            if (num1<num2) min = num1, max = num2;
            else min = num2, max = num1;
            
            //Display Output
            cout<<"The larger number is "<<max<<", and the smaller number is "<<min<<"\n";
            break;
        }
        
        //Problem 2
        case 2: {
            
            //Declare variables
            int number;
            bool valid = true;
            
            //Prompt User for Input
            while (valid) {
            cout<<"Please input a number between 1 and 10: ";
            cin>>number;
                if (number<=0 || number>10) {
                    cout<<"\nInvalid number! ";
                    valid = true;   //Keeps loop going
                } else valid = false;   //Exits loop
            }
            
            //Display Output
            switch (number) {
                case 1: {
                    cout<<number<<" is I in Roman Numerals."<<endl;
                    break;
                }
                
                case 2: {
                    cout<<number<<" is II in Roman Numerals."<<endl;
                    break;
                }
                
                case 3: {
                    cout<<number<<" is III in Roman Numerals."<<endl;
                    break;
                }
                
                case 4: {
                    cout<<number<<" is IV in Roman Numerals."<<endl;
                    break;
                }
                
                case 5: {
                    cout<<number<<" is V in Roman Numerals."<<endl;
                    break;
                }
                
                case 6: {
                    cout<<number<<" is VI in Roman Numerals."<<endl;
                    break;
                }
                
                case 7: {
                    cout<<number<<" is VII in Roman Numerals."<<endl;
                    break;
                }
                
                case 8: {
                    cout<<number<<" is VIII in Roman Numerals."<<endl;
                    break;
                }
                
                case 9: {
                    cout<<number<<" is IX in Roman Numerals."<<endl;
                    break;
                }
                
                case 10: {
                    cout<<number<<" is X in Roman Numerals."<<endl;
                    break;
                }
            }
            break;
        }
        
        //Problem 3
        case 3: {
            
            //Declare Variables
            int month, day, year;
            
            //Prompt User for Input
            cout<<"Please input the month: ";
            cin>>month;
            cout<<"\nPlease input the day: ";
            cin>>day;
            cout<<"\nPlease input the two digit year: ";
            cin>>year;
            
            //Display Output
            if (month*day == year) {
                cout<<"\nThe date "<<month<<"/"<<day<<"/"<<year<<" is magic.";
            } else {
                cout<<"\nThe date is not magic.";
            }
            break;
        }
        
        //Problem 4
        case 4: {
            
            //Declare Variables
            int len1, len2, wid1, wid2, area1, area2;
            
            //Prompt User for Inputs
            cout<<"Please input the length of the first rectangle: ";
            cin>>len1;
            cout<<"\nPlease input the width of the first rectangle: ";
            cin>>wid1;
            cout<<"\nPlease input the length of the second rectangle: ";
            cin>>len2;
            cout<<"\nPlease input the width of the second rectangle: ";
            cin>>wid2;
            
            //Perform Calculations
            area1 = len1*wid1;
            area2 = len2*wid2;
            
            //Display Output
            if (area1>area2) {
                cout<<"\nThe area of rectangle 1 is larger than the area of rectangle 2.";
            }
            if (area1<area2) {
                cout<<"\nThe area of rectangle 1 is smaller than the area of rectangle 2.";
            }
            if (area1==area2) {
                cout<<"\nThe area of rectangle 1 is the same as the area of rectangle 2.";
            }
            break;
        }
        
        //Problem 5
        case 5: {
            
            //Declare Variables
            float BMI, weight, height;
            
            //Prompt User for Inputs
            cout<<"\nPlease input your weight in pounds: ";
            cin>>weight;
            cout<<"\nPlease input your height in inches: ";
            cin>>height;
            
            //Perform Calculations
            BMI = weight * 703.0f / pow(height, 2);
            
            //Display Output
            if (BMI >= 18.5 && BMI <= 25) {
                cout<<"\nYour BMI is "<<BMI<<" which is optimal.";
            }
            if (BMI < 18.5) {
                cout<<"\nYour BMI is "<<BMI<<" which is underweight.";
            }
            if (BMI > 25) {
                cout<<"\nYour BMI is "<<BMI<<" which is overweight.";
            }
            break;
        }
  
        //Problem 6
        case 6: {
            
            //Declare Variables
            float mass;
            bool valid = true;
            
            //Prompt User for Input
            while (valid) {
                cout<<"\nPlease input the object's mass in kilograms: ";
                cin>>mass;
                if (mass < 10 || mass >1000) {
                    cout<<"\nInvalid mass!";
                } else valid = false;   //Exits loop
            }
            
            //Displays Output
            cout<<"\nThe weight of the object is "<<mass*9.8<<"N"<<endl;
            break;
        }
     
        //Problem 7
        case 7: {
            
            //Declare Variables
            int sec, min = 0, hour = 0, day = 0;
            
            //Prompts User for Input
            cout<<"Please input the number of seconds: ";
            cin>>sec;
            
            //Performs Calculations
            if (sec >= 60) {
                min = sec/60;
                if (sec >= 3600) {
                    hour = sec/3600;
                    if (sec >= 86400) {
                        day = sec/86400;
                    }
                }
            }
            
            //Displays Output
            cout<<"Seconds: "<<sec<<" | Minutes: "<<min<<" | Hours: "<<hour<<" | Days: "<<day;
            break;
        }
        
        //Problem 8
        case 8: {
            
            //Declare Variables
            bool valid1=true, valid2=true;
            string prim1, prim2;
            
            while (valid1) {
                cout<<"\nPlease input the first primary color: ";
                cin>>prim1;
                if (prim1 != "red" && prim1 != "blue" && prim1 != "yellow") {
                    cout<<"\nInvalid color!";
                    valid1 = true;  //Keeps loop going
                } else valid1 = false;  //Exits loop
            }
            
            while (valid2) {
                cout<<"\nPlease input the second primary color: ";
                cin>>prim2;
                if (prim2 != "red" && prim2 != "blue" && prim2 != "yellow") {
                    cout<<"\nInvalid color!";
                    valid2 = true;  //Keeps loop going
                } else valid2 = false;  //Exits loop
            }
            
            if ((prim1 == "red" && prim2 == "yellow") || (prim2 == "red" && prim1 == "yellow")) {
                cout<<"The color created by the mix of "<<prim1<<" and "<<prim2<<" is orange.";
            }
            if ((prim1 == "red" && prim2 == "blue") || (prim2 == "red" && prim1 == "blue")) {
                cout<<"The color created by the mix of "<<prim1<<" and "<<prim2<<" is purple.";
            }
            if ((prim1 == "yellow" && prim2 == "blue") || (prim2 == "yellow" && prim1 == "blue")) {
                cout<<"The color created by the mix of "<<prim1<<" and "<<prim2<<" is green.";
            }
            break;
        }
        
        //Problem 9
        case 9: {
            
            //Declare Variables
            bool val1 = true, val2 = true, val3 = true;
            int pennies, dimes, quarters;
            float total;
            
            //Prompts User for Inputs
            while (val1) {
                cout<<"\nPlease input the number of pennies: ";
                cin>>pennies;
                if (pennies < 0) {
                    cout<<"\nInvalid amount!";
                    val1 = true;  //Keeps loop going
                } else val1 = false;  //Exits loop
            }
            
            while (val2) {
                cout<<"\nPlease input the number of dimes: ";
                cin>>dimes;
                if (dimes < 0) {
                    cout<<"\nInvalid amount!";
                    val2 = true;  //Keeps loop going
                } else val2 = false;  //Exits loop
            }
            
            while (val3) {
                cout<<"\nPlease input the number of quarters: ";
                cin>>quarters;
                if (quarters < 0) {
                    cout<<"\nInvalid amount!";
                    val3 = true;  //Keeps loop going
                } else val3 = false;  //Exits loop
            }
            
            //Performs Calculations
            total = (pennies * .01) + (dimes*0.1) + (quarters*.25);
            
            //Displays Outputs
            if (total > 1) {
                cout<<"\nYou lost the game!  $"<<total<<" is greater than $1.00";
            }
            if (total < 1) {
                cout<<"\nYou lost the game!  $"<<total<<" is less than $1.00";
            }
            if (total == 1) {
                cout<<"\nYou won the game!  Your total was $1.00 exactly!";
            }
            break;
        }
    }

    //Exits Execution
    return 0;
}

