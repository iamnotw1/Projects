#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
using namespace std;

//prototyping
string getUnderscores(string s);
void display(string s);

int randnum;


int main(){

    int misscounter = 0;    // counts the missed letters
    bool foundLetter;       // boolean variable to determine if letter is in puzzle
    bool is_duplicateguess; // boolean variable to determine if letter has been guessed
    bool win = false;       // boolean variable if the game is won



    // Puzzle array and hints
    string answer[5] = {"The Matrix: Reloaded", "Star Wars: The Empire Strikes Back","Frozen 2", "Paw Patrol: The Movie", "Dude, Where's My Car?"};
    string hint[5] = {"The main character is Neo", "The Best One", "Disney printing money", "THE WORST KID'S SHOW EVER!!!~~","Bill and Ted's Other adventure"};

    // string of underscores
    string answerUND;

    // User's guessed letter
    char letter;
    //USERS GUESSED LETTER FOR VOWELS
    char leter;
    //YOU LOSE A TURN IN THE WHEEL
    int misses = misscounter + 1;
    // user's entered solved solution
    string usersolution;

    // user's input string (for the letter)
    string input_ans; // user input as string
    // USERS INPUT FOR VOWEL
    string vowels_guess;
    // USERS INPUT FOR CONSONANT
    string constant_guess;

    // list of alphabet and missed letters
    string        constant =" bcd fgh jklmn pqrst vwxyz";
    string guessed_constant="                          ";

    // list of vowels and vowels that's being guessed
    string vowels ="a e i o u";
    string guessed_vowels ="          ";

    // selecting a random number between 0 and however many puzzles there are
    int r = rand() % 5;




    // a variable for the keeps track of money.
    int money = 0;
    // SET MONEY TO ZERO AND YOU LOSE A TURN
    int bank_rupt = money * 0 && misscounter++;

    // A VARIABLE IN THE USE FOR SWITCH CASE. THE USER'S CHOICE WHETHER THE USER WANTS TO SPIN THE WHEEL OR BUY A VOWEL.
    int choice;
    // a variable that stores the players name for after.
    string pname;
    // converts puzzle into underscores as new string
    answerUND = getUnderscores(answer[r]);


    //ARRAY FOR THE WHEEL
    int wheel[20]={250,200,300,400,350,450,500,misses,550,600,1000,2000,1000,bank_rupt,1000,550,bank_rupt,100,300,450};


    //WELCOEM PLAYERS TO THE GAME
    cout<<"Welcome to Wheel Of Fortune, what is your name?"<<endl;
    cin>> pname;//ASK FOR INPUT FOR USERS NAME
    cout<<"Hello "<<pname<<" you start the game with $"<<money<<endl;
// Start the game as a do-while loop
    do{
        int s = rand() % 20;//RANDOMLY CHOOSE FROM 0 - 19
        srand(time(NULL));//SRAND(TIME(0)) SO THAT THE SRAND WORKS.


        foundLetter = false;    // assume letter is not found.

        cout<<"You now have $"<<money<<endl;//KEEPS TRACK OF HOW MUCH MONEY YOU HAVE RIGHT NOW.

        cout<<"Enter 1 to spin the wheel:"<<endl;
        cout<<"Enter 2 to buy a vowel: "<<endl;
        cin>>choice;//USRE DECIDE WHAT TO DO.

        //AFTER USERS INPUT FOR CHOICE IT RUNS THE ONE USER CHOOSE.
        switch(choice){
            case 1:
                cout<<"You landed on $"<<wheel[s]<<endl;//RANDOMLY GENERATE A NUMBER FROM 0 -19 IN THE WHEEL AND PRINTS IT OUT.


                display(answerUND);         //displays underscore string
                cout<<"You now have $"<<money<<endl;//TELL THE USER HOW MUCH MONEY THE USER HAVE
                cout <<"Hint: "<< hint[r]<<endl;   // displays hint of puzzle
                cout<< "Missed: " <<misscounter<<endl;  //displays number of misses

                cout <<"Consonants available: "<< constant<<endl;  // shows alphabet
                cout <<"Guessed consonants:   "<< guessed_constant<<endl; // shows guessed letters

                cout<<"Guess a consonant: ";//USER INPUT (ONLY CONSONANT)
                cin>>input_ans;//ASK FOR INPUT
                letter = input_ans[0];//FIRST LETTER OF THE INPUT EQUALS TO LETTER
                break;

            case 2:cout<<"You bought a vowel choose letters from (a e i o u):"<<endl;
                display(answerUND);         //displays underscore string
                cout<<"You now have $"<<money<<endl;//KEEP TRACK OF HOW MUCH MONEY USER HAVE.
                cout << "Hint: "<< hint[r]<<endl;   // displays hint of puzzle
                cout<< "Missed: " <<misscounter<<endl;  //displays number of misses
                cout<<"Vowels available: "<<vowels<<endl;//shows vowels left
                cout<<"Guessed vowels: "<<guessed_vowels<<endl;//shows guessed vowels//
                money = money - 250;//-250 DOLLARS IF USER BUY VOWEL
                cin>>vowels_guess;//ASK FOR VOWEL AS A INPUT
                leter = vowels_guess[0];//FIRST LETTER OF THE INPUT ABOVE EQUALS TO LETER.
                break;


        }

        if(input_ans == "a" || input_ans == "e"||input_ans =="i" || input_ans == "o"||input_ans == "u"){
            cout <<"Your input must be a consonant !"<<endl;
            misscounter++;
        }// THIS WHOLE IF STATEMENT IS TO SEE IF USER'S INPUT FOR CONSONANT IS CONSONANT OR NOT IF NOT MISSCOUNTER ++.
        if (wheel[s] == 1){
            misscounter++;
        }//THIS IS FOR LOSE A TURN IN THE WHEEL
        if(wheel[s] == 2){
            money = money * 0;
        }//THIS IS FOR BANKRUPT IN THE WHEEL.
        if(isalpha(letter)) {

            //looking for the letter in alphabet; change it to space
            // Assume the letter is a dupe guess
            is_duplicateguess = true;
            for (int i = 0; i < constant.length(); i++) {
                if (tolower(letter) == constant[i]) {
                    constant[i] = ' ';
                    guessed_constant[i] = letter;
                    is_duplicateguess = false; //proven it is NOT a dupe guess
                }
            }


            //Looking for the letters as vowel and change it to space
            //if user's input matches the string.
            for (int i = 0; i < vowels.length(); i++) {
                if (tolower(letter) == vowels[i]) {
                    vowels[i] = ' ';
                    guessed_vowels[i] = letter;
                    is_duplicateguess = false; //proven it is NOT a dupe guess
                }
            }

            //Looking for the leter in the puzzle.....
            for (int i = 0; i < answer[r].length(); i++) {
                if (toupper(answer[r][i]) == toupper(leter)) {
                    answerUND[i] = answer[r][i];
                    foundLetter = true;
                }
            }

            //LOOKING FOR LETTER IN THE PUZZLE
            for (int i = 0; i < answer[r].length(); i++) {
                if (toupper(answer[r][i]) == toupper(letter)) {
                    answerUND[i] = answer[r][i];
                    foundLetter = true;
                    money = money + wheel[s];
                }
            }


            // if the letter is not found or a dupe; increase miss counter
            if (!foundLetter || is_duplicateguess)
                misscounter++;
            cout << endl;
        } // end of if()
    }while((answerUND != answer[r] && misscounter != 3) && !win);
    // end of do-while

    if(win || answerUND == answer[r]){
        cout <<"Congrats!"<<endl;
    }
    else{
        cout << "Sorry. Game Over!"<<endl;
    }

    cout << "The answer was: " << answer[r];
}




string getUnderscores(string s){
    string temp = "";
    for(int i=0; i < s.length(); i++){
        if(isalpha(s[i])){
            temp = temp + '_';
        }
        else
            temp += s[i];
    }
    return temp;
}
void display(string s) {
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}


