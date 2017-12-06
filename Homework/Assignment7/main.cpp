/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 28, 2017, 1:21 PM
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
int binarySearch(int[], int, int);
string binarySearch2(string[], int, string);
void selectionSort(int[], int);
void selectionSort(float[], int);
void selectionSort(string[], int);
void selectionSort2(string[], int);
void swap(int &, int &);
void swap(float &, float &);
void swap(string &, string &);

//Global Constants

//User Libraries

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int dec;
    
    //Prompt for and Validate Input
    do {
        cout<<"Please input the number of the problem that you would like to solve: "<<endl;
        cin>>dec;
    } while(dec < 1 || dec > 8);
    
    //Menu
    switch(dec) {
        
        //Problem 1
        case 1: {
            //Declare Variables
            int num;
            const int MAX=18;
            bool valid;
            int list[MAX]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                            1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
            
            //Prompt User for Input
            do {
                cout<<"Please enter the 7-digit charge account number: ";
                cin>>num;
            } while(num<0);
            
            //Display Output
            for (int i=0; i<MAX; i++) {
                if (list[i]==num) {valid=true; break;}
                else valid=false;
            }
            if (valid) cout<<endl<<"SUCCESS! That number is valid."<<endl;
            else cout<<endl<<"FAILED! Number is not valid."<<endl;
            
            //Exits Program
            return 0;
        }
        
        //Problem 2
        case 2: {
            //Declare Variables
            int num;
            const int MAX=10;
            bool valid;
            int list[MAX]={13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
            
            //Prompt User for Input
            do {
                cout<<"Please enter the 5-digit winning lottery number: ";
                cin>>num;
            } while(num<0);
            
            //Display Output
            for (int i=0; i<MAX; i++) {
                if (list[i]==num) {valid=true; break;}
                else valid=false;
            }
            if (valid) cout<<endl<<"SUCCESS! That number is a winner :)"<<endl;
            else cout<<endl<<"FAILED! Number is not a winner :("<<endl;
            
            //Exits Program
            return 0;
        }
        
        //Problem 3
        case 3: {
            //Declare Variables
            int num;
            const int MAX=10;
            int results;
            int list[MAX]={13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
            
            //Prompt User for Input
            do {
                cout<<"Please enter the 5-digit winning lottery number: ";
                cin>>num;
            } while(num<0);
            
            results = binarySearch(list, MAX, num);
            
            //Display Output
            if (results == -1) cout<<endl<<"FAILED! Number is not a winner :("<<endl;
            else cout<<endl<<"SUCCESS! The number "<<results<<" is a winner :)"<<endl;
            
            //Exits Program
            return 0;
        }
        
        //Problem 4 - Function At Bottom
        case 4: {
            //Declare Variables
            int num;
            const int MAX=18;
            int results;
            int list[MAX]={1005231, 1250255, 1302850, 3852085, 4520125, 4562555, 4581002, 5050552, 5552012, 5658845, 6545231, 7576651, 7825877, 7881200, 7895122, 8080152, 8451277, 8777541};
            
            //Prompt User for Input
            do {
                cout<<"Please enter the 7-digit charge account number: ";
                cin>>num;
            } while(num<0);
            
            results = binarySearch(list, MAX, num);
            
            //Display Output
            if (results == -1) cout<<endl<<"FAILED! Number is not valid"<<endl;
            else cout<<endl<<"SUCCESS! The number "<<results<<" is valid"<<endl;
            
            //Exits Program
            return 0;
        }
        
        //Problem 5
        case 5: {
            //Declare Variables
            const int SIZE = 12;
            float array[SIZE] = {};
            float total=0;
            
            //Prompt for Input
            for (int i=0; i<SIZE; i++) {
                do {
                    cout<<"\nPlease input the average rainfall(in) for month "<<i+1<<": ";
                    cin>>array[i];
                } while(array[i]<0);
                total+=array[i];
            }
            
            //Sort Array
            selectionSort(array, SIZE);
            
            //Declare Initial min/max Values
            float max=array[0],min=array[SIZE-1];
            
            //Display Output
            cout<<"Total Rainfall: "<<total<<"in"<<endl;
            cout<<"Min: "<<min<<"in"<<endl;
            cout<<"Max: "<<max<<"in"<<endl;
            for (int i=0; i<SIZE; i++) {
                cout<<"Month: "<<i+1<<" | Rainfall: "<<array[i]<<endl;
            }
            
            //Exits Program
            return 0;
        }
        
        //Problem 6
        case 6: {
            //Declare Variables
            const int SIZE=20;
            string array[SIZE]={"Collins, BILL","SMITH, BART","ALLEN, JIM","GRIFFIN, JIM","STAMEY, MARTY","ROSE, GARI",
                                "TAYLOR, TERRI","JOHNSON, JILL","ALLISON, JEFF","LOONEY, JOE","WOLFE, BILL","JAMES, JEAN",
                                "WEAVER, JIM","PORE, BOB","RUTHERFORD, GREG","JAVENS, RENEE","HARRISON, ROSE","SETZER, CATHY","PIKE, GORDON","HOLLAND, BETH"};
            
            //Sort Array
            selectionSort(array, SIZE);
            
            //Display Output
            for (int i=0; i<SIZE; i++) {
                cout<<"Index: "<<i+1<<" | Name: "<<array[i]<<endl;
            }
            
            //Exits Program
            return 0;
        }
        
        //Problem 7
        case 7: {
            //Declare Variables
            string name;
            const int SIZE=20;
            string results;
            string array[SIZE]={"COLLINS, BILL","SMITH, BART","ALLEN, JIM","GRIFFIN, JIM","STAMEY, MARTY","ROSE, GARI",
                                "TAYLOR, TERRI","JOHNSON, JILL","ALLISON, JEFF","LOONEY, JOE","WOLFE, BILL","JAMES, JEAN",
                                "WEAVER, JIM","PORE, BOB","RUTHERFORD, GREG","JAVENS, RENEE","HARRISON, ROSE","SETZER, CATHY","PIKE, GORDON","HOLLAND, BETH"};
            
            //Prompts User for Input
            cout<<"Please input a name:";
            cin.ignore();
            getline(cin, name);
            
            //Sort Array
            selectionSort2(array, SIZE);
            
            //Search List
            results=binarySearch2(array, SIZE, name);
            
            for (int i=0;i<SIZE;i++) {
                cout<<"Index: "<<i+1<<" | Name: "<<array[i]<<endl;
            }
            
            cout<<"PROBLEM UNSOLVED !"<<endl;
            
            cout<<name<<endl;
            //Display Output
            if (results=="-1")
                cout<<name<<" is not in the list"<<endl;
            else 
                cout<<results<<" is in the list"<<endl;
            
            
            //Exits Program
            return 0;
        }
        
        //Problem 8
        case 8: {
            //Declare Variables
            int num,cnt1=0,cnt2=0,results;
            const int MAX=20;
            bool valid;
            int list[MAX]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
            int first=0,last=MAX-1,middle,count=0,position=-1;
            bool found=false;
    
            //Linear Search
            do {
                cout<<"Please enter the number to search for: ";
                cin>>num;
            } while(num<0);
            
            //Perform Calculations
            for (int i=0; i<MAX; i++) {
                if (list[i]==num) {valid=true; break;}
                else {valid=false; cnt1++;}
            }
            
            //Binary Search
            while (!found && first <= last) {
                middle = (first + last) / 2;
                if (list[middle] == num) {
                    found = true;
                    position = num;
                }
                else if (list[middle] > num) {
                    last = middle - 1;
                    cnt2++;
                }
                else {
                    first = middle + 1;
                    cnt2++;
                }
            }
            
            //Display Output
            cout<<"Linear Search Count: "<<cnt1<<endl;
            cout<<"Binary Search Count: "<<cnt2<<endl;
            //Exits Program
            return 0;
        }
    }
    
    //Exit Program
    return 0;
}


int binarySearch(int array[], int size, int value) {
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;
    
    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (array[middle] == value) {
            found = true;
            position = value;
        }
        else if (array[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
        
        return position;
    }
}

string binarySearch2(string array[], int size, string value) {
    int first = 0,
        last = size - 1,
        middle;
    string position = "-1";
    bool found = false;
    
    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (array[middle] == value) {
            found = true;
            position = value;
        }
        else if (array[middle] > value)
            last = middle - 1;
        else
            first = middle + 1;
        
        return position;
    }
}

void selectionSort(int array[], int size) {
    int maxIndex, maxValue;
    
    for (int start=0; start<(size-1); start++) {
        maxIndex=start;
        maxValue=array[start];
        for (int i=start+1; i<size; i++) {
            if (array[i]>maxValue) {
                maxValue=array[i];
                maxIndex=i;
            }
        }
        swap(array[maxIndex], array[start]);
    }
}

void selectionSort(float array[], int size) {
    int maxIndex;
    float maxValue;
    
    for (int start=0; start<(size-1); start++) {
        maxIndex=start;
        maxValue=array[start];
        for (int i=start+1; i<size; i++) {
            if (array[i]>maxValue) {
                maxValue=array[i];
                maxIndex=i;
            }
        }
        swap(array[maxIndex], array[start]);
    }
}

void selectionSort(string array[], int size) {
    int maxIndex;
    string maxValue;
    
    for (int start=0; start<(size-1); start++) {
        maxIndex=start;
        maxValue=array[start];
        for (int i=start+1; i<size; i++) {
            if (array[i]>maxValue) {
                maxValue=array[i];
                maxIndex=i;
            }
        }
        swap(array[maxIndex], array[start]);
    }
}

void selectionSort2(string array[], int size) {
    int minIndex;
    string minValue;
    
    for (int start=0; start<(size-1); start++) {
        minIndex=start;
        minValue=array[start];
        for (int i=start+1; i<size; i++) {
            if (array[i]<minValue) {
                minValue=array[i];
                minIndex=i;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

void swap(int &a, int &b) {
    int temp=a;
    a=b;
    b=temp;
}

void swap(float &a, float &b) {
    float temp=a;
    a=b;
    b=temp;
}

void swap(string &a, string &b) {
    string temp=a;
    a=b;
    b=temp;
}

