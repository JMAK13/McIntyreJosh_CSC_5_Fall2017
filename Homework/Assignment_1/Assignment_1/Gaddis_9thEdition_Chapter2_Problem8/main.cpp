/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 3:27 PM
 * Purpose: Total Purchase, Problem 8, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    
    //Declare Variables
    float p1, p2, p3, p4, p5, sub, tax, total;
    
    //Initialize Variables
    p1 = 15.95;
    p2 = 24.95;
    p3 = 6.95;
    p4 = 12.95;
    p5 = 3.95;
    sub = p1+p2+p3+p4+p5;
    tax = 1.07;
    total = tax*sub;
    
    //Display Output
    cout<<"The fist item cost $"<<p1<<"\n";
    cout<<"The fist item cost $"<<p2<<"\n";
    cout<<"The fist item cost $"<<p3<<"\n";
    cout<<"The fist item cost $"<<p4<<"\n";
    cout<<"The fist item cost $"<<p5<<"\n";
    cout<<"The subtotal of the entire purchase is $"<<sub<<"\n";
    cout<<"Since tax is 7%, the complete total comes out to $"<<total<<"\n";
    
    //Exit
    return 0;
}

