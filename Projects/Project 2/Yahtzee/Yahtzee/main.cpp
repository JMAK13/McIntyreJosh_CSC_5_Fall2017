/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 8, 2017, 6:25 PM
 * Purpose: Recreation of the popular card game Yahtzee
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

//Function Prototypes
void swapPl(int &);                                             //Switch player function
int roll();                                                     //Roll dice function
void displayBoard(int[2][13], const int &, string &, string &); //Display scoreboard function
void sort(int arr[], int size);                                 //Sorts arrays from values greatest to least

//Global Constants

//User Libraries

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int player=1,ones=0,twos=0,threes=0,fours=0,fives=0,sixes=0,score1=0,score2=0;                              //Player, score, and dice variables
    bool running=true;                                                                                          //Game loop variable
    int initial,sum1,sum2;                                                                                      //Initial roll variables
    const int ROW=2,COL=13,MAX=5,SCORES=10;                                                                     //Array constants
    int scores[ROW][COL]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};   //2D score-keeping array
    int rolls[MAX]={},scoreboard[SCORES]={};                                                                                //1D array for holding dice value
    string header1,header2;                                                                                     //Scoreboard headers
    int turns=0;                                                                                                //Turn counter variable
    ofstream outFile;                                                                                        //Output file stream object
    ifstream inFile;                                                                                         //Input file stream object
    
    //Validate Input
    do {
        //Prompt User to Exit/Start/See Rules
        cout<<"Hello and Welcome to Yahtzee by Josh McIntyre!"<<endl;
        cout<<"<---IMPORTANT--->: Make sure your output prompt is very large or else you may miss some content!"<<endl;
        cout<<"Press 0 to Exit"<<endl;
        cout<<"Press 1 to Start"<<endl;
        cout<<"Press 2 for Rules"<<endl;
        cout<<"Press 3 to view the Scoreboard"<<endl;
        cin>>initial;
    } while(initial!=0&&initial!=1&&initial!=2&&initial!=3);
    
    //If User Input 0 - Exit
    if (initial==0) {
        cout<<"Okay, hope to see you again soon!"<<endl;
        
        //Exit Program
        return 0;
    }
    
    //If User Input 2 - Rules
    if (initial==2) {
        //GAMEPLAY
        cout<<"GAMEPLAY:"<<endl;
        cout<<"The game begins with player the dice and add the rolls up, then player 2 will do the same. The player with\n";
        cout<<"the higher roll will go first. During turns players start by rolling all 5 dice, and can reroll up to 2\n";
        cout<<"times. The player chooses which dice they would like to set aside before each reroll. The dice are then\n";
        cout<<"scored in the player's desired box in the 13 box table. Each turn 1 box must be checked, even if the player\n";
        cout<<"must take a 0 in that box. At the end of the game the player with the higher score wins!\n\n";
        //SCORING
        cout<<"SCORING:"<<endl;
        cout<<"3 of a Kind - if there are 3 dice of the same value then the sum of all 5 dice can be scored in this box\n";
        cout<<"4 of a Kind - if there are 4 dice of the same value then the sum of all 5 dice can be scored in this box\n";
        cout<<"5 of a Kind - if there are 5 dice of the same value then 50 points can be scored in this box\n";
        cout<<"Full House - if there are 3 dice of the same value while the other 2 dice have the same value then 25 points\n";
        cout<<"             can be put in this box\n";
        cout<<"Small Straight - if there are 4 dice of consecutive value then 30 points can be put in this box\n";
        cout<<"Large Straight - if there are 5 dice of consecutive value then 40 points can be put in this box\n";
        cout<<"Chance - the sum of all 5 dice can be put in this box\n";
        cout<<"Ones - the sum of all ones can be put in this box\n";
        cout<<"Twos - the sum of all twos can be put in this box\n";
        cout<<"Threes - the sum of all threes can be put in this box\n";
        cout<<"Fours - the sum of all fours can be put in this box\n";
        cout<<"Fives - the sum of all fives can be put in this box\n";
        cout<<"Sixes - the sum of all sixes can be put in this box\n\n";
        //Validate Input
        do {
            //Prompt User to Exit/Start
            cout<<"Press 0 to Exit"<<endl;
            cout<<"Press 1 to Start"<<endl;
            cin>>initial;
        } while(initial!=0&&initial!=1);
    }
    
    //If User Input 3 - Show Scores
    if (initial==3) {
        int count=0;
        
        inFile.open("scores.txt");
        inFile>>scoreboard[0];
        inFile>>scoreboard[1];
        inFile>>scoreboard[2];
        inFile>>scoreboard[3];
        inFile>>scoreboard[4];
        inFile>>scoreboard[5];
        inFile>>scoreboard[6];
        inFile>>scoreboard[7];
        inFile>>scoreboard[8];
        inFile>>scoreboard[9];
        inFile.close();
        sort(scoreboard, SCORES);
        for (int i=0;i<SCORES;i++) {
            if (scoreboard[i]!=0) {
                count++;
                cout<<count<<") "<<scoreboard[i]<<endl;
            }
        }
    }
    
    //If User Input 0 - Exit
    if (initial==0) {
        cout<<"Okay, hope to see you again soon!"<<endl;
        
        //Exit Program
        return 0;
    }
    
    //If User Input 1 - Start
    if (initial==1) {
            
        //Prompt Both Players to Roll to Go First
        do {

            //Seed the Random Function
            unsigned seed=time(0);
            srand(seed);
            
            //Player 1
            cout<<"Both players will now roll the dice, add them up, and whoever rolled higher will go first."<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.ignore();
            cin.get();
            for (int i=0; i<MAX; i++) {
                rolls[i]=roll();
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl;
            sum1=rolls[0]+rolls[1]+rolls[2]+rolls[3]+rolls[4];
            cout<<"Sum: "<<sum1<<endl<<endl;

            //Swap Players
            swapPl(player);

            //Player 2
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.get();
            for (int i=0; i<MAX; i++) {
                rolls[i]=roll();
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl;
            sum2=rolls[0]+rolls[1]+rolls[2]+rolls[3]+rolls[4];
            cout<<"Sum: "<<sum2<<endl<<endl;

            if (sum1>sum2) {
                player=1;
                cout<<"Player "<<player<<" will go first!\n"<<endl;
            }
            if (sum1<sum2) {
                player=2;
                cout<<"Player "<<player<<" will go first!\n"<<endl;
            }
        } while(sum1==sum2);
        
        //Game Loop
        while (running) {
            
            int dec=0;
            header1="Box       |Pl 1 |Pl 2 ";
            header2="Box             |Pl 1 |Pl 2 ";
            
            //Display Score Board
            displayBoard(scores, COL, header1, header2);
            
            //First Player's Turn
            cout<<endl<<endl<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.ignore();
            cin.get();
            for (int i=0; i<MAX; i++) {
                rolls[i]=roll();
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl<<endl;
            
            //Second Rolls
            for (int i=1; i<=MAX; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[0]=roll();
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[1]=roll();
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[2]=roll();
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[3]=roll();
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[4]=roll();
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl<<endl;
            
            //Third Rolls
            for (int i=1; i<=MAX; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[0]=roll();
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[1]=roll();
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[2]=roll();
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[3]=roll();
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[4]=roll();
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl<<endl;
        
            //Count First Player's Dice
            for (int i=0; i<MAX; i++) {
                if (rolls[i]==1) ones++;
                if (rolls[i]==2) twos++;
                if (rolls[i]==3) threes++;
                if (rolls[i]==4) fours++;
                if (rolls[i]==5) fives++;
                if (rolls[i]==6) sixes++;
            }
            
            //Score First Player's Rolls
            bool invalid=true;
            do {
                //Prompt User to Select a Box to Score
                cout<<"Please input the number of the box you wish to score: ";
                cin>>dec;
                
                if (dec==1) {
                    if (scores[player-1][0]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones==1) scores[player-1][0]=1;
                        else if (ones==2) scores[player-1][0]=2;
                        else if (ones==3) scores[player-1][0]=3;
                        else if (ones==4) scores[player-1][0]=4;
                        else if (ones==5) scores[player-1][0]=5;
                        else if (ones==6) scores[player-1][0]=6;
                        else scores[player-1][0]=0;
                        score1+=scores[player-1][0];
                        invalid=false;
                    }
                }
                if (dec==2) {
                    if (scores[player-1][1]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (twos==1) scores[player-1][1]=2;
                        else if (twos==2) scores[player-1][1]=4;
                        else if (twos==3) scores[player-1][1]=6;
                        else if (twos==4) scores[player-1][1]=8;
                        else if (twos==5) scores[player-1][1]=10;
                        else if (twos==6) scores[player-1][1]=12;
                        else scores[player-1][1]=0;
                        score1+=scores[player-1][1];
                        invalid=false;
                    }
                }
                if (dec==3) {
                    if (scores[player-1][2]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (threes==1) scores[player-1][2]=3;
                        else if (threes==2) scores[player-1][2]=6;
                        else if (threes==3) scores[player-1][2]=9;
                        else if (threes==4) scores[player-1][2]=12;
                        else if (threes==5) scores[player-1][2]=15;
                        else if (threes==6) scores[player-1][2]=18;
                        else scores[player-1][2]=0;
                        score1+=scores[player-1][2];
                        invalid=false;
                    }
                }
                if (dec==4) {
                    if (scores[player-1][3]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fours==1) scores[player-1][3]=4;
                        else if (fours==2) scores[player-1][3]=8;
                        else if (fours==3) scores[player-1][3]=12;
                        else if (fours==4) scores[player-1][3]=16;
                        else if (fours==5) scores[player-1][3]=20;
                        else if (fours==6) scores[player-1][3]=24;
                        else scores[player-1][3]=0;
                        score1+=scores[player-1][3];
                        invalid=false;
                    }
                }
                if (dec==5) {
                    if (scores[player-1][4]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fives==1) scores[player-1][4]=5;
                        else if (fives==2) scores[player-1][4]=10;
                        else if (fives==3) scores[player-1][4]=15;
                        else if (fives==4) scores[player-1][4]=20;
                        else if (fives==5) scores[player-1][4]=25;
                        else if (fives==6) scores[player-1][4]=30;
                        else scores[player-1][4]=0;
                        score1+=scores[player-1][4];
                        invalid=false;
                    }
                }
                if (dec==6) {
                    if (scores[player-1][5]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (sixes==1) scores[player-1][5]=6;
                        else if (sixes==2) scores[player-1][5]=12;
                        else if (sixes==3) scores[player-1][5]=18;
                        else if (sixes==4) scores[player-1][5]=24;
                        else if (sixes==5) scores[player-1][5]=30;
                        else if (sixes==6) scores[player-1][5]=36;
                        else scores[player-1][5]=0;
                        score1+=scores[player-1][5];
                        invalid=false;
                    }
                }
                if (dec==7) {
                    if (scores[player-1][6]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==1&&twos==1&&threes==1&&fours==1)||(twos==1&&threes==1&&fours==1&&fives==1)
                                ||(ones==2&&twos==1&&threes==1&&fours==1)||(twos==2&&threes==1&&fours==1&&fives==1)
                                ||(ones==1&&twos==2&&threes==1&&fours==1)||(twos==1&&threes==2&&fours==1&&fives==1)
                                ||(ones==1&&twos==1&&threes==2&&fours==1)||(twos==1&&threes==1&&fours==2&&fives==1)
                                ||(ones==1&&twos==1&&threes==1&&fours==2)||(twos==1&&threes==1&&fours==1&&fives==2)) scores[player-1][6]=30;
                        else scores[player-1][6]=0;
                        score1+=scores[player-1][6];
                        invalid=false;
                    }
                }
                if (dec==8) {
                    if (scores[player-1][7]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==1&&twos==1&&threes==1&&fours==1&&fives==1)||(twos==1&&threes==1&&fours==1&&fives==1&&sixes==1)) scores[player-1][7]=40;
                        else scores[player-1][7]=0;
                        score1+=scores[player-1][7];
                        invalid=false;
                    }
                }
                if (dec==9) {
                    if (scores[player-1][8]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones==3) scores[player-1][8]=3;
                        else if (twos==3) scores[player-1][8]=6;
                        else if (threes==3) scores[player-1][8]=9;
                        else if (fours==3) scores[player-1][8]=12;
                        else if (fives==3) scores[player-1][8]=15;
                        else if (sixes==3) scores[player-1][8]=18;
                        else scores[player-1][8]=0;
                        score1+=scores[player-1][8];
                        invalid=false;
                    }
                }
                if (dec==10) {
                    if (scores[player-1][9]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones==4) scores[player-1][9]=4;
                        else if (twos==4) scores[player-1][9]=8;
                        else if (threes==4) scores[player-1][9]=12;
                        else if (fours==4) scores[player-1][9]=16;
                        else if (fives==4) scores[player-1][9]=20;
                        else if (sixes==4) scores[player-1][9]=24;
                        else scores[player-1][9]=0;
                        score1+=scores[player-1][9];
                        invalid=false;
                    }
                }
                if (dec==11) {
                    if (scores[player-1][10]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==5)||(twos==5)||(threes==5)||(fours==5)||(fives==5)||(sixes==5)) scores[player-1][10]=50;
                        else scores[player-1][10]=0;
                        score1+=scores[player-1][10];
                        invalid=false;
                    }
                }
                if (dec==12) {
                    if (scores[player-1][11]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==2&&(twos==3||threes==3||fours==3||fives==3||sixes==3))||(ones==3&&(twos==2||threes==2||fours==2||fives==2||sixes==2))
                                ||(twos==2&&(threes==3||fours==3||fives==3||sixes==3))||(twos==3&&(threes==2||fours==2||fives==2||sixes==2))
                                ||(threes==2&&(fours==3||fives==3||sixes==3))||(threes==3&&(fours==2||fives==2||sixes==2))
                                ||(fours==2&&(fives==3||sixes==3))||(fours==3&&(fives==2||sixes==2))
                                ||(fives==2&&sixes==3)||(fives==3&&sixes==2)) scores[player-1][11]=50;
                        else scores[player-1][11]=0;
                        score1+=scores[player-1][11];
                        invalid=false;
                    } 
                }
                if (dec==13) {
                    int sum=0;
                    if (scores[player-1][12]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        sum=(ones*1)+(twos*2)+(threes*3)+(fours*4)+(fives*5)+(sixes*6);
                        scores[player-1][12]=sum;
                        score1+=scores[player-1][12];
                       
                        invalid=false;
                    }  
                }
            } while(invalid);
            
            //Switch Players
            swapPl(player);
            ones=0;
            twos=0;
            threes=0;
            fours=0;
            fives=0;
            sixes=0;
            dec=0;
            
            //Display Score Board
            displayBoard(scores, COL, header1, header2);
            
            //Second Player's Turn
            cout<<endl<<endl<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.ignore();
            cin.get();
            for (int i=0; i<MAX; i++) {
                rolls[i]=roll();
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl<<endl;
            
            //Second Rolls
            for (int i=1; i<=MAX; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[0]=roll();
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[1]=roll();
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[2]=roll();
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[3]=roll();
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[4]=roll();
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl<<endl;
            
            //Third Rolls
            for (int i=1; i<=MAX; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[0]=roll();
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[1]=roll();
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[2]=roll();
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[3]=roll();
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll!=0&&reroll!=1);
                        if (reroll==0) {
                            rolls[4]=roll();
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<rolls[0]<<" | Roll 2: "<<rolls[1]<<" | Roll 3: "<<rolls[2]<<" | Roll 4: "<<rolls[3]<<" | Roll 5: "<<rolls[4]<<endl<<endl;
        
            //Count Second Player's Dice
            for (int i=0; i<MAX; i++) {
                if (rolls[i]==1) ones++;
                if (rolls[i]==2) twos++;
                if (rolls[i]==3) threes++;
                if (rolls[i]==4) fours++;
                if (rolls[i]==5) fives++;
                if (rolls[i]==6) sixes++;
            }
            
            //Score Second Player's Rolls
            invalid = true;
            do {
                //Prompt User to Select a Box
                cout<<"Please input the number of the box you wish to score: ";
                cin>>dec;
                
                if (dec==1) {
                    if (scores[player-1][0]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones==1) scores[player-1][0]=1;
                        else if (ones==2) scores[player-1][0]=2;
                        else if (ones==3) scores[player-1][0]=3;
                        else if (ones==4) scores[player-1][0]=4;
                        else if (ones==5) scores[player-1][0]=5;
                        else if (ones==6) scores[player-1][0]=6;
                        else scores[player-1][0]=0;
                        score2+=scores[player-1][0];
                        invalid=false;
                    }
                }
                if (dec==2) {
                    if (scores[player-1][1]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (twos==1) scores[player-1][1]=2;
                        else if (twos==2) scores[player-1][1]=4;
                        else if (twos==3) scores[player-1][1]=6;
                        else if (twos==4) scores[player-1][1]=8;
                        else if (twos==5) scores[player-1][1]=10;
                        else if (twos==6) scores[player-1][1]=12;
                        else scores[player-1][1]=0;
                        score2+=scores[player-1][1];
                        invalid=false;
                    }
                }
                if (dec==3) {
                    if (scores[player-1][2]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (threes==1) scores[player-1][2]=3;
                        else if (threes==2) scores[player-1][2]=6;
                        else if (threes==3) scores[player-1][2]=9;
                        else if (threes==4) scores[player-1][2]=12;
                        else if (threes==5) scores[player-1][2]=15;
                        else if (threes==6) scores[player-1][2]=18;
                        else scores[player-1][2]=0;
                        score2+=scores[player-1][2];
                        invalid=false;
                    }
                }
                if (dec==4) {
                    if (scores[player-1][3]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fours==1) scores[player-1][3]=4;
                        else if (fours==2) scores[player-1][3]=8;
                        else if (fours==3) scores[player-1][3]=12;
                        else if (fours==4) scores[player-1][3]=16;
                        else if (fours==5) scores[player-1][3]=20;
                        else if (fours==6) scores[player-1][3]=24;
                        else scores[player-1][3]=0;
                        score2+=scores[player-1][3];
                        invalid=false;
                    }
                }
                if (dec==5) {
                    if (scores[player-1][4]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fives==1) scores[player-1][4]=5;
                        else if (fives==2) scores[player-1][4]=10;
                        else if (fives==3) scores[player-1][4]=15;
                        else if (fives==4) scores[player-1][4]=20;
                        else if (fives==5) scores[player-1][4]=25;
                        else if (fives==6) scores[player-1][4]=30;
                        else scores[player-1][4]=0;
                        score2+=scores[player-1][4];
                        invalid=false;
                    }
                }
                if (dec==6) {
                    if (scores[player-1][5]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (sixes==1) scores[player-1][5]=6;
                        else if (sixes==2) scores[player-1][5]=12;
                        else if (sixes==3) scores[player-1][5]=18;
                        else if (sixes==4) scores[player-1][5]=24;
                        else if (sixes==5) scores[player-1][5]=30;
                        else if (sixes==6) scores[player-1][5]=36;
                        else scores[player-1][5]=0;
                        score2+=scores[player-1][5];
                        invalid=false;
                    }
                }
                if (dec==7) {
                    if (scores[player-1][6]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==1&&twos==1&&threes==1&&fours==1)||(twos==1&&threes==1&&fours==1&&fives==1)
                                ||(ones==2&&twos==1&&threes==1&&fours==1)||(twos==2&&threes==1&&fours==1&&fives==1)
                                ||(ones==1&&twos==2&&threes==1&&fours==1)||(twos==1&&threes==2&&fours==1&&fives==1)
                                ||(ones==1&&twos==1&&threes==2&&fours==1)||(twos==1&&threes==1&&fours==2&&fives==1)
                                ||(ones==1&&twos==1&&threes==1&&fours==2)||(twos==1&&threes==1&&fours==1&&fives==2)) scores[player-1][6]=30;
                        else scores[player-1][6]=0;
                        score2+=scores[player-1][6];
                        invalid=false;
                    }
                }
                if (dec==8) {
                    if (scores[player-1][7]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==1&&twos==1&&threes==1&&fours==1&&fives==1)||(twos==1&&threes==1&&fours==1&&fives==1&&sixes==1)) scores[player-1][7]=40;
                        else scores[player-1][7]=0;
                        score2+=scores[player-1][7];
                        invalid=false;
                    }
                }
                if (dec==9) {
                    if (scores[player-1][8]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones==3) scores[player-1][8]=3;
                        else if (twos==3) scores[player-1][8]=6;
                        else if (threes==3) scores[player-1][8]=9;
                        else if (fours==3) scores[player-1][8]=12;
                        else if (fives==3) scores[player-1][8]=15;
                        else if (sixes==3) scores[player-1][8]=18;
                        else scores[player-1][8]=0;
                        score2+=scores[player-1][8];
                        invalid=false;
                    }
                }
                if (dec==10) {
                    if (scores[player-1][9]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones==4) scores[player-1][9]=4;
                        else if (twos==4) scores[player-1][9]=8;
                        else if (threes==4) scores[player-1][9]=12;
                        else if (fours==4) scores[player-1][9]=16;
                        else if (fives==4) scores[player-1][9]=20;
                        else if (sixes==4) scores[player-1][9]=24;
                        else scores[player-1][9]=0;
                        score2+=scores[player-1][9];
                        invalid=false;
                    }
                }
                if (dec==11) {
                    if (scores[player-1][10]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==5)||(twos==5)||(threes==5)||(fours==5)||(fives==5)||(sixes==5)) scores[player-1][10]=50;
                        else scores[player-1][10]=0;
                        score2+=scores[player-1][10];
                        invalid=false;
                    }
                }
                if (dec==12) {
                    if (scores[player-1][11]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if ((ones==2&&(twos==3||threes==3||fours==3||fives==3||sixes==3))||(ones==3&&(twos==2||threes==2||fours==2||fives==2||sixes==2))
                                ||(twos==2&&(threes==3||fours==3||fives==3||sixes==3))||(twos==3&&(threes==2||fours==2||fives==2||sixes==2))
                                ||(threes==2&&(fours==3||fives==3||sixes==3))||(threes==3&&(fours==2||fives==2||sixes==2))
                                ||(fours==2&&(fives==3||sixes==3))||(fours==3&&(fives==2||sixes==2))
                                ||(fives==2&&sixes==3)||(fives==3&&sixes==2)) scores[player-1][11]=50;
                        else scores[player-1][11]=0;
                        score2+=scores[player-1][11];
                        invalid=false;
                    } 
                }
                if (dec==13) {
                    int sum=0;
                    if (scores[player-1][12]!=-1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        sum=(ones*1)+(twos*2)+(threes*3)+(fours*4)+(fives*5)+(sixes*6);
                        scores[player-1][12]=sum;
                        score2+=scores[player-1][12];
                       
                        invalid=false;
                    }  
                }
            } while(invalid);
            
            //Switch Players
            swapPl(player);
            ones=0;
            twos=0;
            threes=0;
            fours=0;
            fives=0;
            sixes=0;
            
            //Increment the Turns Variables
            turns++;
            
            //Display Scores
            cout<<"\n\n-----SCORES-----\n";
            if (player==1) {
                cout<<"Pl 1 Score: "<<score1<<" | Pl 2 Score: "<<score2<<endl;
            }else {
                cout<<"Pl 1 Score: "<<score2<<" | Pl 2 Score: "<<score1<<endl;

            }
            
            //Check for Winner
            if (turns==13) {
                if (score1>score2) {
                    if (player==1) {
                        cout<<"Player 1 is the WINNER!!!"<<endl;
                        
                        //Records scores in text file
                        outFile.open("scores.txt");
                        outFile<<score1<<endl;
                        outFile.close();
                    } else {
                        cout<<"Player 2 is the WINNER!!!"<<endl;
                        
                        //Records scores in text file
                        outFile.open("scores.txt");
                        outFile<<score2<<endl;
                        outFile.close();
                    }
                    
                    //Exit Program
                    return 0;
                }
                if (score1<score2) {
                    string name;
                    
                    if (player==1) {
                        cout<<"Player 2 is the WINNER!!!"<<endl;
                        
                        //Records scores in text file
                        outFile.open("scores.txt");
                        outFile<<score2<<endl;
                        outFile.close();
                    } else {
                        cout<<"Player 1 is the WINNER!!!"<<endl;
                        
                        //Records scores in text file
                        outFile.open("scores.txt");
                        outFile<<score1<<endl;
                        outFile.close();
                    }
                    
                    //Exit Program
                    return 0;
                }
                if (score1==score2) {
                    cout<<"Player 1 and Player 2 TIED!!!"<<endl;
                    cout<<"Your scores were not recorded as a result, sorry :("<<endl;
                    
                    //Exit Program
                    return 0;
                }
            }
        }
    }
    
    //Exits Program
    return 0;
}   //End Main Function

//Swap Player Function
void swapPl(int &player) {
    if (player==1) player=2;
    else player=1;
}

//Roll Dice Function
int roll() {
    return (rand()%6)+1;
}

//Display Board Function
void displayBoard(int scores[2][13], const int &COL, string &header1, string &header2) {
    string box;
            cout<<endl<<endl<<endl;
            cout<<"----UPPER SECTION----"<<endl;
            cout<<header1<<endl;
            for (int j=0; j<(COL-7); j++) {
                switch (j) {
                    case 0: {
                        box="Ones  ";
                        break;
                    }
                    case 1: {
                        box="Twos  ";
                        break;
                    }
                    case 2: {
                        box="Threes";
                        break;
                    }
                    case 3: {
                        box="Fours ";
                        break;
                    }
                    case 4: {
                        box="Fives ";
                        break;
                    }
                    case 5: {
                        box="Sixes ";
                        break;
                    }
                }
                    if (scores[0][j]==-1&&scores[1][j]==-1)      cout<<j+1<<") "<<box<<" |     |     "<<endl;
                    else if (scores[0][j]==-1 && scores[1][j]!=-1) cout<<j+1<<") "<<box<<" |     |  "<<scores[1][j]<<endl;
                    else if (scores[0][j]!=-1 && scores[1][j]!=-1) cout<<j+1<<") "<<box<<" |  "<<scores[0][j]<<"  |  "<<scores[1][j]<<endl;
                    else if (scores[0][j]!=-1 && scores[1][j]==-1) cout<<j+1<<") "<<box<<" |  "<<scores[0][j]<<"  |     "<<endl;
            }
            cout<<"----LOWER SECTION----"<<endl;
            cout<<header2<<endl;
            for (int j=6; j<COL; j++) {
                switch (j) {
                    case 6: {
                        box="Small Str   ";
                        break;
                    }
                    case 7: {
                        box="Large Str   ";
                        break;
                    }
                    case 8: {
                        box="3 of a Kind ";
                        break;
                    }
                    case 9: {
                        box="4 of a Kind";
                        break;
                    }
                    case 10: {
                        box="5 of a Kind";
                        break;
                    }
                    case 11: {
                        box="Full House ";
                        break;
                    }
                    case 12: {
                        box="CHANCE     ";
                        break;
                    }
                }
                    if (scores[0][j]==-1 && scores[1][j]==-1)      cout<<j+1<<") "<<box<<" |     |     "<<endl;
                    else if (scores[0][j]==-1 && scores[1][j]!=-1) cout<<j+1<<") "<<box<<" |     |  "<<scores[1][j]<<endl;
                    else if (scores[0][j]!=-1 && scores[1][j]!=-1) cout<<j+1<<") "<<box<<" |  "<<scores[0][j]<<"  |  "<<scores[1][j]<<endl;
                    else if (scores[0][j]!=-1 && scores[1][j]==-1) cout<<j+1<<") "<<box<<" |  "<<scores[0][j]<<"  |     "<<endl;
            }
}

//Array Sorting Function (Greatest --> Least)
void sort(int array[], int size) {
    int startScan, maxIndex, maxValue;

    for (startScan=0;startScan<(size-1);startScan++) {
        maxIndex = startScan;
        maxValue = array[startScan];

        for(int index = startScan + 1; index < size; index++) {
            if (array[index] > maxValue) {
                maxValue = array[index];
                maxIndex = index;
                }
            }
        
        array[maxIndex] = array[startScan];
        array[startScan] = maxValue;
    }
}