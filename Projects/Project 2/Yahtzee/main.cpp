/* 
 * File:   main.cpp
 * Author: Josh McIntyre
 * Created on November 8, 2017, 6:25 PM
 * Purpose: Recreation of the popular card game Yahtzee
 */

//Function Prototypes
void swapPl(int &);

//Global Constants

//User Libraries

//System Libraries
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//Execution Begins Here
int main(int argc, char** argv) {

    //Declare Variables
    int player=1, ones=0, twos=0, threes=0, fours=0, fives=0, sixes=0, roll1, roll2, roll3, roll4, roll5, score1, score2;               //Declare Necessary Pre-Game Variables
    int ones1=-1, ones2=-1, twos1=-1, twos2=-1, threes1=-1, threes2=-1, fours1=-1, fours2=-1, fives1=-1, fives2=-1, sixes1=-1, sixes2=-1;//The Upper Level Scoring Variables
    int fh1=-1, fh2=-1, ls1=-1, ls2=-1, ss1=-1, ss2=-1, threeK1=-1, threeK2=-1, fourK1=-1, fourK2=-1, fiveK1=-1, fiveK2=-1;             //The Lower Level Scoring Variables
    bool running=true;                                                                                                                  //Game Loop Expression Variable
    int initial, sum1, sum2;                                                                                                            //Initial Variable to Either Start or Exit the Game
    const int ROLLS = 5;                                                                                                                //The Variable to Hold Max Value for roll[]
    
    //Validate Input
    do {
        //Prompt User to Exit/Start/See Rules
        cout<<"Hello and Welcome to Yahtzee by Josh McIntyre!"<<endl;
        cout<<"Make sure your output prompt is very large or else you may miss some content!"<<endl;
        cout<<"Press 0 to Exit"<<endl;
        cout<<"Press 1 to Start"<<endl;
        cout<<"Press 2 for Rules"<<endl;
        cin>>initial;
    } while(initial != 0 && initial != 1 && initial != 2);
    
    //If User Input 0 - Exit
    if (initial == 0) {
        cout<<"Okay, hope to see you again soon!"<<endl;
        
        //Exit Program
        return 0;
    }
    
    //If User Input 2 - Rules
    if (initial == 2) {
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
        cout<<"Small Straight - if there are 4 dice of consective value then 30 points can be put in this box\n";
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
        } while(initial != 0 && initial != 1);
    }
    
    //If User Input 0 - Exit
    if (initial == 0) {
        cout<<"Okay, hope to see you again soon!"<<endl;
        
        //Exit Program
        return 0;
    }
    
    //If User Input 1 - Start
    if (initial == 1) {
            
        //Prompt Both Players to Roll to Go First
        do {

            //Seed the Random Function
            unsigned seed = time(0);
            srand(seed);
            
            //Player 1
            cout<<"Both players will now roll the dice, add them up, and whoever rolled higher will go first."<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.ignore();
            cin.get();
            roll1=(rand()%6)+1;
            roll2=(rand()%6)+1;
            roll3=(rand()%6)+1;
            roll4=(rand()%6)+1;
            roll5=(rand()%6)+1;
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl;
            sum1=roll1+roll2+roll3+roll4+roll5;
            cout<<"Sum: "<<sum1<<endl<<endl;

            //Swap Players
            swapPl(player);

            //Player 2
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.get();
            roll1=(rand()%6)+1;
            roll2=(rand()%6)+1;
            roll3=(rand()%6)+1;
            roll4=(rand()%6)+1;
            roll5=(rand()%6)+1;
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl;
            sum2=roll1+roll2+roll3+roll4+roll5;
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
            
            int dec = 0;
            
            //Display Score Board
            cout<<endl<<endl<<endl;
            cout<<"----UPPER SECTION----"<<endl;
            if (ones1 == -1 && ones2 == -1) cout<<"1) Ones  |     |     "<<endl;
            else if (ones1 == -1 && ones2 != -1) cout<<"1) Ones  |     |  "<<ones2<<endl;
            else if (ones1 != -1 && ones2 != -1) cout<<"1) Ones  |  "<<ones1<<"  |  "<<ones2<<endl;
            else if (ones1 != -1 && ones2 == -1) cout<<"1) Ones  |  "<<ones1<<"  |     "<<endl;
            if (twos1 == -1 && twos2 == -1) cout<<"2) Twos  |     |     "<<endl;
            else if (twos1 == -1 && twos2 != -1) cout<<"2) Twos  |     |  "<<twos2<<endl;
            else if (twos1 != -1 && twos2 != -1) cout<<"2) Twos  |  "<<twos1<<"  |  "<<twos2<<endl;
            else if (twos1 != -1 && twos2 == -1) cout<<"2) Twos  |  "<<twos1<<"  |     "<<endl;
            if (threes1 == -1 && threes2 == -1) cout<<"3) Threes|     |     "<<endl;
            else if (threes1 == -1 && threes2 != -1) cout<<"3) Threes|     |  "<<threes2<<endl;
            else if (threes1 != -1 && threes2 != -1) cout<<"3) Threes|  "<<threes1<<"  |  "<<threes2<<endl;
            else if (threes1 != -1 && threes2 == -1) cout<<"3) Threes|  "<<threes1<<"  |     "<<endl;
            if (fours1 == -1 && fours2 == -1) cout<<"4) Fours |     |     "<<endl;
            else if (fours1 == -1 && fours2 != -1) cout<<"4) Fours |     |  "<<fours2<<endl;
            else if (fours1 != -1 && fours2 != -1) cout<<"4) Fours |  "<<fours1<<"  |  "<<fours2<<endl;
            else if (fours1 != -1 && fours2 == -1) cout<<"4) Fours |  "<<fours1<<"  |     "<<endl;
            if (fives1 == -1 && fives2 == -1) cout<<"5) Fives |     |     "<<endl;
            else if (fives1 == -1 && fives2 != -1) cout<<"5) Fives |     |  "<<fives2<<endl;
            else if (fives1 != -1 && fives2 != -1) cout<<"5) Fives |  "<<fives1<<"  |  "<<fives2<<endl;
            else if (fives1 != -1 && fives2 == -1) cout<<"5) Fives |  "<<fives1<<"  |     "<<endl;
            if (sixes1 == -1 && sixes2 == -1) cout<<"6) Sixes |     |     "<<endl;
            else if (sixes1 == -1 && sixes2 != -1) cout<<"6) Sixes |     |  "<<sixes2<<endl;
            else if (sixes1 != -1 && sixes2 != -1) cout<<"6) Sixes |  "<<sixes1<<"  |  "<<sixes2<<endl;
            else if (sixes1 != -1 && sixes2 == -1) cout<<"6) Sixes |  "<<sixes1<<"  |     "<<endl;
            cout<<"----LOWER SECTION----"<<endl;
            cout<<setw(8)<<"7) 3 of Kind|"<<endl;
            cout<<setw(8)<<"8) 4 of Kind|"<<endl;
            cout<<setw(8)<<"9) Full House|"<<endl;
            cout<<setw(8)<<"10) Small Straight|"<<endl;
            cout<<setw(8)<<"11) Large Straight|"<<endl;
            cout<<setw(8)<<"12) 5 of Kind|"<<endl;
            cout<<setw(8)<<"13) CHANCE|"<<endl;
            
            //First Player's Turn
            cout<<endl<<endl<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.ignore();
            cin.get();
            roll1=(rand()%6)+1;
            roll2=(rand()%6)+1;
            roll3=(rand()%6)+1;
            roll4=(rand()%6)+1;
            roll5=(rand()%6)+1;
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl<<endl;
            
            //Second Rolls
            for (int i = 1; i <= 5; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll1=(rand()%6)+1;
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll2=(rand()%6)+1;
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll3=(rand()%6)+1;
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll4=(rand()%6)+1;
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll5=(rand()%6)+1;
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl<<endl;
            
            //Third Rolls
            for (int i = 1; i <= 5; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll1=(rand()%6)+1;
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll2=(rand()%6)+1;
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll3=(rand()%6)+1;
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll4=(rand()%6)+1;
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll5=(rand()%6)+1;
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl<<endl;
            
            //Map First Player's Rolls to Array
            int rolls[ROLLS] = {roll1, roll2, roll3, roll4, roll5};
        
            //Count First Player's Dice
            for (int i = 0; i < ROLLS; i++) {
                if (rolls[i] == 1) ones++;
                if (rolls[i] == 2) twos++;
                if (rolls[i] == 3) threes++;
                if (rolls[i] == 4) fours++;
                if (rolls[i] == 5) fives++;
                if (rolls[i] == 6) sixes++;
            }
            
            //Score First Player's Rolls
            bool invalid = true;
            do {
                //Prompt User to Select a Box
                cout<<"Please input the number of the box you wish to score: ";
                cin>>dec;
                
                if (dec == 1) {
                    if (ones1 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones == 1) ones1=1;
                        if (ones == 2) ones1=2;
                        if (ones == 3) ones1=3;
                        if (ones == 4) ones1=4;
                        if (ones == 5) ones1=5;
                        if (ones == 6) ones1=6;
                        score1+=ones1;
                        invalid=false;
                    }
                }
                if (dec == 2) {
                    if (twos1 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (twos == 1) twos1=2;
                        if (twos == 2) twos1=4;
                        if (twos == 3) twos1=6;
                        if (twos == 4) twos1=8;
                        if (twos == 5) twos1=10;
                        if (twos == 6) twos1=12;
                        score1+=twos1;
                        invalid=false;
                    }
                }
                if (dec == 3) {
                    if (threes1 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (threes == 1) threes1=3;
                        if (threes == 2) threes1=6;
                        if (threes == 3) threes1=9;
                        if (threes == 4) threes1=12;
                        if (threes == 5) threes1=15;
                        if (threes == 6) threes1=18;
                        score1+=threes1;
                        invalid=false;
                    }
                }
                if (dec == 4) {
                    if (fours1 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fours == 1) fours1=4;
                        if (fours == 2) fours1=8;
                        if (fours == 3) fours1=12;
                        if (fours == 4) fours1=16;
                        if (fours == 5) fours1=20;
                        if (fours == 6) fours1=24;
                        score1+=fours1;
                        invalid=false;
                    }
                }
                if (dec == 5) {
                    if (fives1 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fives == 1) fives1=5;
                        if (fives == 2) fives1=10;
                        if (fives == 3) fives1=15;
                        if (fives == 4) fives1=20;
                        if (fives == 5) fives1=25;
                        if (fives == 6) fives1=30;
                        score1+=fives1;
                        invalid=false;
                    }
                }
                if (dec == 6) {
                    if (sixes1 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (sixes == 1) sixes1=6;
                        if (sixes == 2) sixes1=12;
                        if (sixes == 3) sixes1=18;
                        if (sixes == 4) sixes1=24;
                        if (sixes == 5) sixes1=30;
                        if (sixes == 6) sixes1=36;
                        score1+=sixes1;
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
            
            //Display Score Board
            cout<<endl<<endl<<endl;
            cout<<"----UPPER SECTION----"<<endl;
            if (ones1 == -1 && ones2 == -1) cout<<"1) Ones  |     |     "<<endl;
            else if (ones1 == -1 && ones2 != -1) cout<<"1) Ones  |     |  "<<ones2<<endl;
            else if (ones1 != -1 && ones2 != -1) cout<<"1) Ones  |  "<<ones1<<"  |  "<<ones2<<endl;
            else if (ones1 != -1 && ones2 == -1) cout<<"1) Ones  |  "<<ones1<<"  |     "<<endl;
            if (twos1 == -1 && twos2 == -1) cout<<"2) Twos  |     |     "<<endl;
            else if (twos1 == -1 && twos2 != -1) cout<<"2) Twos  |     |  "<<twos2<<endl;
            else if (twos1 != -1 && twos2 != -1) cout<<"2) Twos  |  "<<twos1<<"  |  "<<twos2<<endl;
            else if (twos1 != -1 && twos2 == -1) cout<<"2) Twos  |  "<<twos1<<"  |     "<<endl;
            if (threes1 == -1 && threes2 == -1) cout<<"3) Threes|     |     "<<endl;
            else if (threes1 == -1 && threes2 != -1) cout<<"3) Threes|     |  "<<threes2<<endl;
            else if (threes1 != -1 && threes2 != -1) cout<<"3) Threes|  "<<threes1<<"  |  "<<threes2<<endl;
            else if (threes1 != -1 && threes2 == -1) cout<<"3) Threes|  "<<threes1<<"  |     "<<endl;
            if (fours1 == -1 && fours2 == -1) cout<<"4) Fours |     |     "<<endl;
            else if (fours1 == -1 && fours2 != -1) cout<<"4) Fours |     |  "<<fours2<<endl;
            else if (fours1 != -1 && fours2 != -1) cout<<"4) Fours |  "<<fours1<<"  |  "<<fours2<<endl;
            else if (fours1 != -1 && fours2 == -1) cout<<"4) Fours |  "<<fours1<<"  |     "<<endl;
            if (fives1 == -1 && fives2 == -1) cout<<"5) Fives |     |     "<<endl;
            else if (fives1 == -1 && fives2 != -1) cout<<"5) Fives |     |  "<<fives2<<endl;
            else if (fives1 != -1 && fives2 != -1) cout<<"5) Fives |  "<<fives1<<"  |  "<<fives2<<endl;
            else if (fives1 != -1 && fives2 == -1) cout<<"5) Fives |  "<<fives1<<"  |     "<<endl;
            if (sixes1 == -1 && sixes2 == -1) cout<<"6) Sixes |     |     "<<endl;
            else if (sixes1 == -1 && sixes2 != -1) cout<<"6) Sixes |     |  "<<sixes2<<endl;
            else if (sixes1 != -1 && sixes2 != -1) cout<<"6) Sixes |  "<<sixes1<<"  |  "<<sixes2<<endl;
            else if (sixes1 != -1 && sixes2 == -1) cout<<"6) Sixes |  "<<sixes1<<"  |     "<<endl;
            cout<<"----LOWER SECTION----"<<endl;
            cout<<setw(8)<<"7) 3 of Kind|"<<endl;
            cout<<setw(8)<<"8) 4 of Kind|"<<endl;
            cout<<setw(8)<<"9) Full House|"<<endl;
            cout<<setw(8)<<"10) Small Straight|"<<endl;
            cout<<setw(8)<<"11) Large Straight|"<<endl;
            cout<<setw(8)<<"12) 5 of Kind|"<<endl;
            cout<<setw(8)<<"13) CHANCE|"<<endl;
            
            //Second Player's Turn
            cout<<endl<<endl<<endl;
            cout<<"Player "<<player<<": Please press enter to roll the dice";
            cin.ignore();
            cin.get();
            roll1=(rand()%6)+1;
            roll2=(rand()%6)+1;
            roll3=(rand()%6)+1;
            roll4=(rand()%6)+1;
            roll5=(rand()%6)+1;
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl<<endl;
            
            //Second Rolls
            for (int i = 1; i <= 5; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll1=(rand()%6)+1;
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll2=(rand()%6)+1;
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll3=(rand()%6)+1;
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll4=(rand()%6)+1;
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll5=(rand()%6)+1;
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl<<endl;
            
            //Third Rolls
            for (int i = 1; i <= 5; i++) {
                switch (i) {
                    case 1: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll1=(rand()%6)+1;
                        }
                        break;
                    }
                    case 2: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll2=(rand()%6)+1;
                        }
                        break;
                    }
                    case 3: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll3=(rand()%6)+1;
                        }
                        break;
                    }
                    case 4: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll4=(rand()%6)+1;
                        }
                        break;
                    }
                    case 5: {
                        int reroll;
                        do {
                            cout<<"Press 0 to re-roll Roll "<<i<<" or 1 to keep it as is: ";
                            cin>>reroll;
                        } while(reroll != 0 && reroll != 1);
                        if (reroll==0) {
                            roll5=(rand()%6)+1;
                        }
                        break;
                    }
                }
            }
            cout<<"Roll 1: "<<roll1<<" | Roll 2: "<<roll2<<" | Roll 3: "<<roll3<<" | Roll 4: "<<roll4<<" | Roll 5: "<<roll5<<endl<<endl;
            
            //Map Second Player's Rolls to Array
            int rolls2[ROLLS] = {roll1, roll2, roll3, roll4, roll5};
        
            //Count First Player's Dice
            for (int i = 0; i < ROLLS; i++) {
                if (rolls2[i] == 1) ones++;
                if (rolls2[i] == 2) twos++;
                if (rolls2[i] == 3) threes++;
                if (rolls2[i] == 4) fours++;
                if (rolls2[i] == 5) fives++;
                if (rolls2[i] == 6) sixes++;
            }
            
            //Score Second Player's Rolls
            invalid = true;
            do {
                //Prompt User to Select a Box
                cout<<"Please input the number of the box you wish to score: ";
                cin>>dec;
                
                if (dec == 1) {
                    if (ones2 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (ones == 1) ones2=1;
                        if (ones == 2) ones2=2;
                        if (ones == 3) ones2=3;
                        if (ones == 4) ones2=4;
                        if (ones == 5) ones2=5;
                        if (ones == 6) ones2=6;
                        score2+=ones2;
                        invalid=false;
                    }
                }
                if (dec == 2) {
                    if (twos2 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (twos == 1) twos2=2;
                        if (twos == 2) twos2=4;
                        if (twos == 3) twos2=6;
                        if (twos == 4) twos2=8;
                        if (twos == 5) twos2=10;
                        if (twos == 6) twos2=12;
                        score2+=twos2;
                        invalid=false;
                    }
                }
                if (dec == 3) {
                    if (threes2 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (threes == 1) threes2=3;
                        if (threes == 2) threes2=6;
                        if (threes == 3) threes2=9;
                        if (threes == 4) threes2=12;
                        if (threes == 5) threes2=15;
                        if (threes == 6) threes2=18;
                        score2+=threes2;
                        invalid=false;
                    }
                }
                if (dec == 4) {
                    if (fours2 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fours == 1) fours2=4;
                        if (fours == 2) fours2=8;
                        if (fours == 3) fours2=12;
                        if (fours == 4) fours2=16;
                        if (fours == 5) fours2=20;
                        if (fours == 6) fours2=24;
                        score2+=fours2;
                        invalid=false;
                    }
                }
                if (dec == 5) {
                    if (fives2 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (fives == 1) fives2=5;
                        if (fives == 2) fives2=10;
                        if (fives == 3) fives2=15;
                        if (fives == 4) fives2=20;
                        if (fives == 5) fives2=25;
                        if (fives == 6) fives2=30;
                        score2+=fives2;
                        invalid=false;
                    }
                }
                if (dec == 6) {
                    if (sixes2 != -1) {cout<<"You have already marked that box!"<<endl; invalid=true;}
                    else {
                        if (sixes == 1) sixes2=6;
                        if (sixes == 2) sixes2=12;
                        if (sixes == 3) sixes2=18;
                        if (sixes == 4) sixes2=24;
                        if (sixes == 5) sixes2=30;
                        if (sixes == 6) sixes2=36;
                        score2+=sixes2;
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
        }
    }
    
    //Exits Program
    return 0;
}   //End Main Function

//Swap Player Function
void swapPl(int &player) {
    if (player == 1) player = 2;
    else player = 1;
}