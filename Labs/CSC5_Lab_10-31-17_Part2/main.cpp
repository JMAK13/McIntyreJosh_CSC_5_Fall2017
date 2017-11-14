/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on October 31, 2017, 12:15 PM
 * Purpose: Gaddis 8thEd, Ch6, Prob11
 */

//Function Prototypes
float getScore();
float getMin(float &);
float avg();

//Global Constants

//User Libraries

//System Libraries
#include <iostream>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    //Display Output
    cout<<"Average for highest scores = "<<avg()<<endl;
    
    //Exits Program
    return 0;
}

//Score Getter Function
float getScore() {
    static int count = 1;
    float score;
    cout<<"Type in Test Score "<<count++<<": ";
    cin>>score;
    return score;
}

//Min Score Getter Function
float getMin(float &sum) {
    sum = 0;
    float min = getScore();
    sum+=min;
    for (int i = 1; i <= 4; i++) {
        float add = getScore();
        if (add < min) min = add;
        sum+=add;
    }
    return min;
}

//Average Function
float avg() {
    float sum, min = getMin(sum);
    return (sum - min)/4;
}