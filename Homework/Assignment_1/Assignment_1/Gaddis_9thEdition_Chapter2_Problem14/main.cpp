/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on September 12, 2017, 2:51 PM
 * Purpose: Personal Information, Problem 15, Chapter 2, Gaddis9th Edition
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char** argv) {
    
    //Declare Variables
    string name, address, city, state, major, zip, phoneNum;
    
    //Map Inputs to Variables
    cout<<"Please input your full name: ";
    getline(cin, name);
    cout<<"Please input your street address: ";
    getline(cin, address);
    cout<<"Please input the name of your city: ";
    getline(cin, city);
    cout<<"Please input the name of your state: ";
    getline(cin, state);
    cout<<"Please input your zip code: ";
    getline(cin, zip);
    cout<<"Please input your phone number with ONLY numbers: ";
    getline(cin, phoneNum);
    cout<<"Please input what your college major is: ";
    getline(cin, major);
    
    //Display Output in One Single Line as Requested
    cout<<"Your name is "<<name<<", your address is "<<address<<", your state is "<<state<<", your city is "<<city<<", your zip code is "<<zip<<
            ", your phone number is "<<phoneNum<<", and your major is "<<major<<".\n";

    return 0;
}

