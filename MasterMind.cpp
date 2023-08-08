#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
using namespace std;

//variable that counts for how many times the user input.
int counter = 0;
//for switch statement
int choice;
int fd =(rand() % 6) + 1;//sorry :)
int sd =(rand() % 6) + 1;
int td =(rand() % 6) + 1;
int frd =(rand() % 6) + 1;
int nums2[4];
//random number array(sorry I know its dumb)
int digits[4] ={fd,sd,td,frd};
int main() {


    //srand made random numbers possible
    srand(time(NULL));


    //welcome screen with rules

    cout << "Welcome to the Game of Mastermind !\n\n" << endl;
    cout <<"Enter(1) to play."<<endl;
    cout <<"Enter(2) for rules."<<endl;
    cin>> choice;


// after user choose what to do(rule or play)
    switch(choice) {
        case 1:

            do {
                int digit_ctr = 0;
                int spot_ctr = 0;
                int nums;


                cout<<"\n";
                cout<<"You are in try #"<<counter+1;
                cout<<"\n";
                cout << "Enter your guess:"<<endl;
                cin >> nums;

                //break the array down into single int.
                for (int k = 3; k >= 0 ; k--) {
                    nums2[3-k] = nums/int(pow(10,k));
                    nums = nums % int(pow(10,k));
                }

                //checks position and digits(took me so long)
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if(nums2[i] == digits[j]){
                            digit_ctr++;
                            if(nums2[i] == digits[i]){
                                spot_ctr++;
                            };
                        }
                }
                }

                digit_ctr = digit_ctr/2;
                spot_ctr = spot_ctr/2;

                //tells you how many digits and position you have correct
                cout << digit_ctr << " in digits correct" << endl;
                cout << spot_ctr<< " in correct spot(s)" << endl;
                counter++;

                //if all number matches end game and REVEAL the answer
                if(digit_ctr and spot_ctr == 4){
                    cout<<"\nYou win!!";
                    cout<<"The answer was ";
                    for (int i = 0; i < 4; i++) {
                        cout<<digits[i];
                    }
                    cout<<"  :)";
                    counter = 12;
                }
            } while (counter < 12);//run 12 times
            break;

        default:
            cout<<"The computer will randomly choose a 4 digit number from numbers 1-6(Numbers can be repeated)"<<endl;
            cout<<"You as the player have to guess the random 4 digit number from 1-6 that the computer generates."<<endl;
            cout<<"For example if the random set of number is 1652"<<endl;
            cout<<"And you enter 2315 the computer will tell you 3 in digits correct and 0 in correct spot."<<endl;
            cout<<"You have 12 attempts to guess GOOD LUCK!\n"<<endl;
            cout<<"RE-RUN THE PROGRAM AND CHOOSE 1 to start ."<<endl;
            break;
    //rules
    }
}
