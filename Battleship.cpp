#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

string pinput;
int player;
int counter;
int counters;
int shipscrushed = 0;


bool not_safe(int a, int b, int c, int s);
void allplaceship(int s, char alphabet);
char cpuboard[10][10]; // the ships are placed here
char playerboard[10][10]; // the board that the player sees

// resets the board to all underscores
void reset(char b[10][10]);
void dumbmethod(string pinput);

// displays board b with letter and numbers
void display(char b[10][10]);

void hitormissed();
//prototypes for all the ships we need


int main(){
   int s[5] = {5,4,3,3,2};//size of the five ships
   char alphabet[5] = {'A','B','C','S','D'};//letter for the five ships
   srand(time(0));// totally rand every time you run the program

   cout<<"Welcome to the game of 'Battleship' "<<endl;
   cout<<"Enter 1 to play the game."<<endl;
   cout<<"Enetr 2 to read the rules."<<endl;
   cout<<"Your input:";
   cin>>player;
   cout<<endl;
   cout<<"Choose your difficulty please:(if you're reading the rule ignore this)"<<endl;
   cout<<"(1) = Easy\n(2) = Medium \n(3) = Hard \n(4) = Impossible"<<endl;
   cin >> counters;
   if(counters == 1){
       counter = 72;
   }
   else if(counters == 2){
       counter = 60;
   }
   else if(counters == 3){
       counter = 48;
   }
   else if(counters == 4){
       counter = 22;
   }//for difficulties.

   reset(cpuboard);
   reset(playerboard);
   for(int i = 0; i < 5; i++){
       allplaceship(s[i],alphabet[i] );
   }//prints all the five ship to the cpuboard.



   switch(player){
       case 1:
           do{
               cout<<shipscrushed;
               cout<<endl;
               display(cpuboard);
               cout << endl;
               display(playerboard);

               cout<<"\n\nYou now got "<<counter<<" tries."<<endl;
               cout<<"\n\nPlease input a valid spot:(no capital letter)";
               cin >> pinput;
               dumbmethod(pinput);//plugging in the pinput into the placing + checking function
               counter--;

           }while(shipscrushed != 17 && counter != 0);//loop the game until you lose or until you win.

           if(shipscrushed == 17){
               cout<<"Congratz you won the game !!!"<<endl;
               display(cpuboard);
               display(playerboard);
           }
           else{
               cout<<"\n\nYou lost!!"<<endl;
               cout<<"\n\nThe final result:"<<endl;
               display(cpuboard);
               cout<<"\n\nHere's your guesses";
               display(playerboard);
           }
           break;
       case 2:
           cout<<"|------------------------------|"<<endl;
           cout<<"|Rules-------------------------|"<<endl;
           cout<<"|Destroy all the five ships----|"<<endl;
           cout<<"|Call for a shot from a-j/1-10-|"<<endl;
           cout<<"|If you hit it is a X----------|"<<endl;
           cout<<"|If you missed it's a O--------|"<<endl;
           cout<<"|------------------------------|"<<endl;
           cout<<endl;
           cout<<"Re-run the program and enter 1 to play"<<endl;
           cout<<"Enter anything to exit:"; cin>>player;//rules to play
   }
}

void reset(char b[10][10]){//set all values in the array to 0
   for(int r=0; r<10; r++){
       for(int c = 0; c<10; c++){
           b[r][c] = '_';
       }
   }
}

void display(char b[10][10]){//display the array
   cout << endl;
   for(int r=0; r<10; r++){
       if(r<9){
           cout <<" ";
       }
       cout << r+1 <<" ";
       for(int c = 0; c<10; c++){
           cout << b[r][c] << " ";
       }
       cout << endl;
   }

   cout << "   ";
   for(char letter = 'A'; letter < 'A' + 10; letter++){
       cout << letter << " ";
   }
}

void allplaceship(int s, char alphabet){//place the ship when no overlap occurs
   bool ship = false;
   do{
       int a = rand() % 10;
       int b = rand() % 10;
       int c = rand() % 2;
       if(c % 2 == 0){if(!not_safe(a, b, c, s)){
               for (int g = b; g < b+s; g++){
                   cpuboard[a][g] = alphabet;
                   ship = false;
               }
           }else{
               ship = true;
           }
       }
       else{if(!not_safe(a, b, c, s)){
               for (int h = a; h < a+s; h++){
                   cpuboard[h][b] = alphabet;
                   ship = false;
               }
           }else{
               ship = true;
           }
       }
   }while(ship);
}


bool not_safe(int a, int b, int c, int s){//this function make sure nothing overlaps(the hardest of this program)
   if(c % 2 == 0){if(b + s <= 9){
           for (int d = b; d < b+s; d++){
               if (cpuboard[a][d] != '_'){
                   return true;
               }
           }
           return false;
       }else{
           return true;
       }
   }else{
       if(a+s < 10){
           for (int e = a; e < a+s; e++){
               if (cpuboard[e][b] != '_'){
                   return true;
               }
           }
           return false;
       }else{
           return true;
       }
   }
}

void dumbmethod(string pinput){// this function places user's input into the graph and checks if it hits or missed.

   if(pinput == "a1" && cpuboard[0][0] == 'A' ||pinput == "a1" && cpuboard[0][0] == 'B'||pinput == "a1" && cpuboard[0][0] == 'C'
   ||pinput == "a1" && cpuboard[0][0] == 'D'||pinput == "a1" && cpuboard[0][0] == 'S'){
       playerboard[0][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a1" && cpuboard[0][0] == '_'){
       playerboard[0][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a2" && cpuboard[1][0] == 'A' ||pinput == "a2" && cpuboard[1][0] == 'B'||pinput == "a2" && cpuboard[1][0] == 'C'
      ||pinput == "a2" && cpuboard[1][0] == 'D'||pinput == "a2" && cpuboard[1][0] == 'S'){
       playerboard[1][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a2" && cpuboard[1][0] == '_'){
       playerboard[1][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

       else if(pinput == "a3" && cpuboard[2][0] == 'A' ||pinput == "a3" && cpuboard[2][0] == 'B'||pinput == "a3" && cpuboard[2][0] == 'C'
               ||pinput == "a3" && cpuboard[2][0] == 'D'||pinput == "a3" && cpuboard[2][0] == 'S'){
           playerboard[2][0] = 'O';
           cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
            shipscrushed++;
       }else if(pinput == "a3" && cpuboard[2][0] == '_'){
           playerboard[2][0] = 'X';
           cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a4" && cpuboard[3][0] == 'A' ||pinput == "a4" && cpuboard[3][0] == 'B'||pinput == "a4" && cpuboard[3][0] == 'C'
           ||pinput == "a4" && cpuboard[3][0] == 'D'||pinput == "a4" && cpuboard[3][0] == 'S'){
       playerboard[3][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a4" && cpuboard[3][0] == '_'){
       playerboard[3][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a5" && cpuboard[4][0] == 'A' ||pinput == "a5" && cpuboard[4][0] == 'B'||pinput == "a5" && cpuboard[4][0] == 'C'
           ||pinput == "a5" && cpuboard[4][0] == 'D'||pinput == "a5" && cpuboard[4][0] == 'S'){
       playerboard[4][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a5" && cpuboard[4][0] == '_'){
       playerboard[4][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a6" && cpuboard[5][0] == 'A' ||pinput == "a6" && cpuboard[5][0] == 'B'||pinput == "a6" && cpuboard[5][0] == 'C'
           ||pinput == "a6" && cpuboard[5][0] == 'D'||pinput == "a6" && cpuboard[5][0] == 'S'){
       playerboard[5][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a6" && cpuboard[5][0] == '_'){
       playerboard[5][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a7" && cpuboard[6][0] == 'A' ||pinput == "a7" && cpuboard[6][0] == 'B'||pinput == "a7" && cpuboard[6][0] == 'C'
           ||pinput == "a7" && cpuboard[6][0] == 'D'||pinput == "a7" && cpuboard[6][0] == 'S'){
       playerboard[6][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a7" && cpuboard[6][0] == '_'){
       playerboard[6][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a8" && cpuboard[7][0] == 'A' ||pinput == "a8" && cpuboard[7][0] == 'B'||pinput == "a8" && cpuboard[7][0] == 'C'
           ||pinput == "a8" && cpuboard[7][0] == 'D'||pinput == "a8" && cpuboard[7][0] == 'S'){
       playerboard[7][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a8" && cpuboard[7][0] == '_'){
       playerboard[7][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a9" && cpuboard[8][0] == 'A' ||pinput == "a9" && cpuboard[8][0] == 'B'||pinput == "a9" && cpuboard[8][0] == 'C'
           ||pinput == "a9" && cpuboard[8][0] == 'D'||pinput == "a9" && cpuboard[8][0] == 'S'){
       playerboard[8][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a9" && cpuboard[8][0] == '_'){
       playerboard[8][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "a10" && cpuboard[9][0] == 'A' ||pinput == "a10" && cpuboard[9][0] == 'B'||pinput == "a10" && cpuboard[9][0] == 'C'
           ||pinput == "a10" && cpuboard[9][0] == 'D'||pinput == "a10" && cpuboard[9][0] == 'S'){
       playerboard[9][0] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "a10" && cpuboard[9][0] == '_'){
       playerboard[9][0] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }


   else if(pinput == "b1" && cpuboard[0][1] == 'A' ||pinput == "b1" && cpuboard[0][1] == 'B'||pinput == "b1" && cpuboard[0][1] == 'C'
      ||pinput == "b1" && cpuboard[0][1] == 'D'||pinput == "b1" && cpuboard[0][1] == 'S'){
       playerboard[0][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b1" && cpuboard[0][1] == '_'){
       playerboard[0][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b2" && cpuboard[1][1] == 'A' ||pinput == "b2" && cpuboard[1][1] == 'B'||pinput == "b2" && cpuboard[1][1] == 'C'
           ||pinput == "b2" && cpuboard[1][1] == 'D'||pinput == "b2" && cpuboard[1][1] == 'S'){
       playerboard[1][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b2" && cpuboard[1][1] == '_'){
       playerboard[1][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b3" && cpuboard[2][1] == 'A' ||pinput == "b3" && cpuboard[2][1] == 'B'||pinput == "b3" && cpuboard[2][1] == 'C'
           ||pinput == "b3" && cpuboard[2][1] == 'D'||pinput == "b3" && cpuboard[2][1] == 'S'){
       playerboard[2][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b3" && cpuboard[2][1] == '_'){
       playerboard[2][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b4" && cpuboard[3][1] == 'A' ||pinput == "b4" && cpuboard[3][1] == 'B'||pinput == "b4" && cpuboard[3][1] == 'C'
           ||pinput == "b4" && cpuboard[3][1] == 'D'||pinput == "b4" && cpuboard[3][1] == 'S'){
       playerboard[3][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b4" && cpuboard[3][1] == '_'){
       playerboard[3][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b5" && cpuboard[4][1] == 'A' ||pinput == "b5" && cpuboard[4][1] == 'B'||pinput == "b5" && cpuboard[4][1] == 'C'
           ||pinput == "b5" && cpuboard[4][1] == 'D'||pinput == "b5" && cpuboard[4][1] == 'S'){
       playerboard[4][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b5" && cpuboard[4][1] == '_'){
       playerboard[4][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b6" && cpuboard[5][1] == 'A' ||pinput == "b6" && cpuboard[5][1] == 'B'||pinput == "b6" && cpuboard[5][1] == 'C'
           ||pinput == "b6" && cpuboard[5][1] == 'D'||pinput == "b6" && cpuboard[5][1] == 'S'){
       playerboard[5][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b6" && cpuboard[5][1] == '_'){
       playerboard[5][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b7" && cpuboard[6][1] == 'A' ||pinput == "b7" && cpuboard[6][1] == 'B'||pinput == "b7" && cpuboard[6][1] == 'C'
           ||pinput == "b7" && cpuboard[6][1] == 'D'||pinput == "b7" && cpuboard[6][1] == 'S'){
       playerboard[6][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b7" && cpuboard[6][1] == '_'){
       playerboard[6][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b8" && cpuboard[7][1] == 'A' ||pinput == "b8" && cpuboard[7][1] == 'B'||pinput == "b8" && cpuboard[7][1] == 'C'
           ||pinput == "b8" && cpuboard[7][1] == 'D'||pinput == "b8" && cpuboard[7][1] == 'S'){
       playerboard[7][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b8" && cpuboard[7][1] == '_'){
       playerboard[7][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b9" && cpuboard[8][1] == 'A' ||pinput == "b9" && cpuboard[8][1] == 'B'||pinput == "b9" && cpuboard[8][1] == 'C'
           ||pinput == "b9" && cpuboard[8][1] == 'D'||pinput == "b9" && cpuboard[8][1] == 'S'){
       playerboard[8][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b9" && cpuboard[8][1] == '_'){
       playerboard[8][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "b10" && cpuboard[9][1] == 'A' ||pinput == "b10" && cpuboard[9][1] == 'B'||pinput == "b10" && cpuboard[9][1] == 'C'
           ||pinput == "b10" && cpuboard[9][1] == 'D'||pinput == "b10" && cpuboard[9][1] == 'S'){
       playerboard[9][1] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "b10" && cpuboard[9][1] == '_'){
       playerboard[9][1] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }


   else if(pinput == "c1" && cpuboard[0][2] == 'A' ||pinput == "c1" && cpuboard[0][2] == 'B'||pinput == "c1" && cpuboard[0][2] == 'C'
           ||pinput == "c1" && cpuboard[0][2] == 'D'||pinput == "c1" && cpuboard[0][2] == 'S'){
       playerboard[0][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c1" && cpuboard[0][2] == '_'){
       playerboard[0][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c2" && cpuboard[1][2] == 'A' ||pinput == "c2" && cpuboard[1][2] == 'B'||pinput == "c2" && cpuboard[1][2] == 'C'
           ||pinput == "c2" && cpuboard[1][2] == 'D'||pinput == "c2" && cpuboard[1][2] == 'S'){
       playerboard[1][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c2" && cpuboard[1][2] == '_'){
       playerboard[1][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c3" && cpuboard[2][2] == 'A' ||pinput == "c3" && cpuboard[2][2] == 'B'||pinput == "c3" && cpuboard[2][2] == 'C'
           ||pinput == "c3" && cpuboard[2][2] == 'D'||pinput == "c3" && cpuboard[2][2] == 'S'){
       playerboard[2][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c3" && cpuboard[2][2] == '_'){
       playerboard[2][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c4" && cpuboard[3][2] == 'A' ||pinput == "c4" && cpuboard[3][2] == 'B'||pinput == "c4" && cpuboard[3][2] == 'C'
           ||pinput == "c4" && cpuboard[3][2] == 'D'||pinput == "c4" && cpuboard[3][2] == 'S'){
       playerboard[3][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c4" && cpuboard[3][2] == '_'){
       playerboard[3][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c5" && cpuboard[4][2] == 'A' ||pinput == "c5" && cpuboard[4][2] == 'B'||pinput == "c5" && cpuboard[4][2] == 'C'
           ||pinput == "c5" && cpuboard[4][2] == 'D'||pinput == "c5" && cpuboard[4][2] == 'S'){
       playerboard[4][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c5" && cpuboard[4][2] == '_'){
       playerboard[4][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c6" && cpuboard[5][2] == 'A' ||pinput == "c6" && cpuboard[5][2] == 'B'||pinput == "c6" && cpuboard[5][2] == 'C'
           ||pinput == "c6" && cpuboard[5][2] == 'D'||pinput == "c6" && cpuboard[5][2] == 'S'){
       playerboard[5][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c6" && cpuboard[5][2] == '_'){
       playerboard[5][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c7" && cpuboard[6][2] == 'A' ||pinput == "c7" && cpuboard[6][2] == 'B'||pinput == "c7" && cpuboard[6][2] == 'C'
           ||pinput == "c7" && cpuboard[6][2] == 'D'||pinput == "c7" && cpuboard[6][2] == 'S'){
       playerboard[6][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c7" && cpuboard[6][2] == '_'){
       playerboard[6][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c8" && cpuboard[7][2] == 'A' ||pinput == "c8" && cpuboard[7][2] == 'B'||pinput == "c8" && cpuboard[7][2] == 'C'
           ||pinput == "c8" && cpuboard[7][2] == 'D'||pinput == "c8" && cpuboard[7][2] == 'S'){
       playerboard[7][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c8" && cpuboard[7][2] == '_'){
       playerboard[7][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c9" && cpuboard[8][2] == 'A' ||pinput == "c9" && cpuboard[8][2] == 'B'||pinput == "c9" && cpuboard[8][2] == 'C'
           ||pinput == "c9" && cpuboard[8][2] == 'D'||pinput == "c9" && cpuboard[8][2] == 'S'){
       playerboard[8][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c9" && cpuboard[8][2] == '_'){
       playerboard[8][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "c10" && cpuboard[9][2] == 'A' ||pinput == "c10" && cpuboard[9][2] == 'B'||pinput == "c10" && cpuboard[9][2] == 'C'
           ||pinput == "c10" && cpuboard[9][2] == 'D'||pinput == "c10" && cpuboard[9][2] == 'S'){
       playerboard[9][2] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "c10" && cpuboard[9][2] == '_'){
       playerboard[9][2] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }



   else if(pinput == "d1" && cpuboard[0][3] == 'A' ||pinput == "d1" && cpuboard[0][3] == 'B'||pinput == "d1" && cpuboard[0][3] == 'C'
           ||pinput == "d1" && cpuboard[0][3] == 'D'||pinput == "d1" && cpuboard[0][3] == 'S'){
       playerboard[0][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d1" && cpuboard[0][3] == '_'){
       playerboard[0][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d2" && cpuboard[1][3] == 'A' ||pinput == "d2" && cpuboard[1][3] == 'B'||pinput == "d2" && cpuboard[1][3] == 'C'
           ||pinput == "d2" && cpuboard[1][3] == 'D'||pinput == "d2" && cpuboard[1][3] == 'S'){
       playerboard[1][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d2" && cpuboard[1][3] == '_'){
       playerboard[1][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d3" && cpuboard[2][3] == 'A' ||pinput == "d3" && cpuboard[2][3] == 'B'||pinput == "d3" && cpuboard[2][3] == 'C'
           ||pinput == "d3" && cpuboard[2][3] == 'D'||pinput == "d3" && cpuboard[2][3] == 'S'){
       playerboard[2][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d3" && cpuboard[2][3] == '_'){
       playerboard[2][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d4" && cpuboard[3][3] == 'A' ||pinput == "d4" && cpuboard[3][3] == 'B'||pinput == "d4" && cpuboard[3][3] == 'C'
           ||pinput == "d4" && cpuboard[3][3] == 'D'||pinput == "d4" && cpuboard[3][3] == 'S'){
       playerboard[3][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d4" && cpuboard[3][3] == '_'){
       playerboard[3][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d5" && cpuboard[4][3] == 'A' ||pinput == "d5" && cpuboard[4][3] == 'B'||pinput == "d5" && cpuboard[4][3] == 'C'
           ||pinput == "d5" && cpuboard[4][3] == 'D'||pinput == "d5" && cpuboard[4][3] == 'S'){
       playerboard[4][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d5" && cpuboard[4][3] == '_'){
       playerboard[4][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d6" && cpuboard[5][3] == 'A' ||pinput == "d6" && cpuboard[5][3] == 'B'||pinput == "d6" && cpuboard[5][3] == 'C'
           ||pinput == "d6" && cpuboard[5][3] == 'D'||pinput == "d6" && cpuboard[5][3] == 'S'){
       playerboard[5][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d6" && cpuboard[5][3] == '_'){
       playerboard[5][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d7" && cpuboard[6][3] == 'A' ||pinput == "d7" && cpuboard[6][3] == 'B'||pinput == "d7" && cpuboard[6][3] == 'C'
           ||pinput == "d7" && cpuboard[6][3] == 'D'||pinput == "d7" && cpuboard[6][3] == 'S'){
       playerboard[6][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d7" && cpuboard[6][3] == '_'){
       playerboard[6][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d8" && cpuboard[7][3] == 'A' ||pinput == "d8" && cpuboard[7][3] == 'B'||pinput == "d8" && cpuboard[7][3] == 'C'
           ||pinput == "d8" && cpuboard[7][3] == 'D'||pinput == "d8" && cpuboard[7][3] == 'S'){
       playerboard[7][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d8" && cpuboard[7][3] == '_'){
       playerboard[7][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d9" && cpuboard[8][3] == 'A' ||pinput == "d9" && cpuboard[8][3] == 'B'||pinput == "d9" && cpuboard[8][3] == 'C'
           ||pinput == "d9" && cpuboard[8][3] == 'D'||pinput == "d9" && cpuboard[8][3] == 'S'){
       playerboard[8][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d9" && cpuboard[8][3] == '_'){
       playerboard[8][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "d10" && cpuboard[9][3] == 'A' ||pinput == "d10" && cpuboard[9][3] == 'B'||pinput == "d10" && cpuboard[9][3] == 'C'
           ||pinput == "d10" && cpuboard[9][3] == 'D'||pinput == "d10" && cpuboard[9][3] == 'S'){
       playerboard[9][3] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "d10" && cpuboard[9][3] == '_'){
       playerboard[9][3] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }


   else if(pinput == "e1" && cpuboard[0][4] == 'A' ||pinput == "e1" && cpuboard[0][4] == 'B'||pinput == "e1" && cpuboard[0][4] == 'C'
           ||pinput == "e1" && cpuboard[0][4] == 'D'||pinput == "e1" && cpuboard[0][4] == 'S'){
       playerboard[0][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e1" && cpuboard[0][4] == '_'){
       playerboard[0][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e2" && cpuboard[1][4] == 'A' ||pinput == "e2" && cpuboard[1][4] == 'B'||pinput == "e2" && cpuboard[1][4] == 'C'
           ||pinput == "e2" && cpuboard[1][4] == 'D'||pinput == "e2" && cpuboard[1][4] == 'S'){
       playerboard[1][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e2" && cpuboard[1][4] == '_'){
       playerboard[1][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e3" && cpuboard[2][4] == 'A' ||pinput == "e3" && cpuboard[2][4] == 'B'||pinput == "e3" && cpuboard[2][4] == 'C'
           ||pinput == "e3" && cpuboard[2][4] == 'D'||pinput == "e3" && cpuboard[2][4] == 'S'){
       playerboard[2][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e3" && cpuboard[2][4] == '_'){
       playerboard[2][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e4" && cpuboard[3][4] == 'A' ||pinput == "e4" && cpuboard[3][4] == 'B'||pinput == "e4" && cpuboard[3][4] == 'C'
           ||pinput == "e4" && cpuboard[3][4] == 'D'||pinput == "e4" && cpuboard[3][4] == 'S'){
       playerboard[3][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e4" && cpuboard[3][4] == '_'){
       playerboard[3][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e5" && cpuboard[4][4] == 'A' ||pinput == "e5" && cpuboard[4][4] == 'B'||pinput == "e5" && cpuboard[4][4] == 'C'
           ||pinput == "e5" && cpuboard[4][4] == 'D'||pinput == "e5" && cpuboard[4][4] == 'S'){
       playerboard[4][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e5" && cpuboard[4][4] == '_'){
       playerboard[4][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e6" && cpuboard[5][4] == 'A' ||pinput == "e6" && cpuboard[5][4] == 'B'||pinput == "e6" && cpuboard[5][4] == 'C'
           ||pinput == "e6" && cpuboard[5][4] == 'D'||pinput == "e6" && cpuboard[5][4] == 'S'){
       playerboard[5][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e6" && cpuboard[5][4] == '_'){
       playerboard[5][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e7" && cpuboard[6][4] == 'A' ||pinput == "e7" && cpuboard[6][4] == 'B'||pinput == "e7" && cpuboard[6][4] == 'C'
           ||pinput == "e7" && cpuboard[6][4] == 'D'||pinput == "e7" && cpuboard[6][4] == 'S'){
       playerboard[6][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e7" && cpuboard[6][4] == '_'){
       playerboard[6][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e8" && cpuboard[7][4] == 'A' ||pinput == "e8" && cpuboard[7][4] == 'B'||pinput == "e8" && cpuboard[7][4] == 'C'
           ||pinput == "e8" && cpuboard[7][4] == 'D'||pinput == "e8" && cpuboard[7][4] == 'S'){
       playerboard[7][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e8" && cpuboard[7][4] == '_'){
       playerboard[7][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e9" && cpuboard[8][4] == 'A' ||pinput == "e9" && cpuboard[8][4] == 'B'||pinput == "e9" && cpuboard[8][4] == 'C'
           ||pinput == "e9" && cpuboard[8][4] == 'D'||pinput == "e9" && cpuboard[8][4] == 'S'){
       playerboard[8][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e9" && cpuboard[8][4] == '_'){
       playerboard[8][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "e10" && cpuboard[9][4] == 'A' ||pinput == "e10" && cpuboard[9][4] == 'B'||pinput == "e10" && cpuboard[9][4] == 'C'
           ||pinput == "e10" && cpuboard[9][4] == 'D'||pinput == "e10" && cpuboard[9][4] == 'S'){
       playerboard[9][4] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "e10" && cpuboard[9][4] == '_'){
       playerboard[9][4] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }



   else if(pinput == "f1" && cpuboard[0][5] == 'A' ||pinput == "f1" && cpuboard[0][5] == 'B'||pinput == "f1" && cpuboard[0][5] == 'C'
           ||pinput == "f1" && cpuboard[0][5] == 'D'||pinput == "f1" && cpuboard[0][5] == 'S'){
       playerboard[0][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f1" && cpuboard[0][5] == '_'){
       playerboard[0][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f2" && cpuboard[1][5] == 'A' ||pinput == "f2" && cpuboard[1][5] == 'B'||pinput == "f2" && cpuboard[1][5] == 'C'
           ||pinput == "f2" && cpuboard[1][5] == 'D'||pinput == "f2" && cpuboard[1][5] == 'S'){
       playerboard[1][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f2" && cpuboard[1][5] == '_'){
       playerboard[1][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f3" && cpuboard[2][5] == 'A' ||pinput == "f3" && cpuboard[2][5] == 'B'||pinput == "f3" && cpuboard[2][5] == 'C'
           ||pinput == "f3" && cpuboard[2][5] == 'D'||pinput == "f3" && cpuboard[2][5] == 'S'){
       playerboard[2][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f3" && cpuboard[2][5] == '_'){
       playerboard[2][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f4" && cpuboard[3][5] == 'A' ||pinput == "f4" && cpuboard[3][5] == 'B'||pinput == "f4" && cpuboard[3][5] == 'C'
           ||pinput == "f4" && cpuboard[3][5] == 'D'||pinput == "f4" && cpuboard[3][5] == 'S'){
       playerboard[3][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f4" && cpuboard[3][5] == '_'){
       playerboard[3][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f5" && cpuboard[4][5] == 'A' ||pinput == "f5" && cpuboard[4][5] == 'B'||pinput == "f5" && cpuboard[4][5] == 'C'
           ||pinput == "f5" && cpuboard[4][5] == 'D'||pinput == "f5" && cpuboard[4][5] == 'S'){
       playerboard[4][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f5" && cpuboard[4][5] == '_'){
       playerboard[4][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f6" && cpuboard[5][5] == 'A' ||pinput == "f6" && cpuboard[5][5] == 'B'||pinput == "f6" && cpuboard[5][5] == 'C'
           ||pinput == "f6" && cpuboard[5][5] == 'D'||pinput == "f6" && cpuboard[5][5] == 'S'){
       playerboard[5][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f6" && cpuboard[5][5] == '_'){
       playerboard[5][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f7" && cpuboard[6][5] == 'A' ||pinput == "f7" && cpuboard[6][5] == 'B'||pinput == "f7" && cpuboard[6][5] == 'C'
           ||pinput == "f7" && cpuboard[6][5] == 'D'||pinput == "f7" && cpuboard[6][5] == 'S'){
       playerboard[6][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f7" && cpuboard[6][5] == '_'){
       playerboard[6][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f8" && cpuboard[7][5] == 'A' ||pinput == "f8" && cpuboard[7][5] == 'B'||pinput == "f8" && cpuboard[7][5] == 'C'
           ||pinput == "f8" && cpuboard[7][5] == 'D'||pinput == "f8" && cpuboard[7][5] == 'S'){
       playerboard[7][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f8" && cpuboard[7][5] == '_'){
       playerboard[7][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f9" && cpuboard[8][5] == 'A' ||pinput == "f9" && cpuboard[8][5] == 'B'||pinput == "f9" && cpuboard[8][5] == 'C'
           ||pinput == "f9" && cpuboard[8][5] == 'D'||pinput == "f9" && cpuboard[8][5] == 'S'){
       playerboard[8][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f9" && cpuboard[8][5] == '_'){
       playerboard[8][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "f10" && cpuboard[9][5] == 'A' ||pinput == "f10" && cpuboard[9][5] == 'B'||pinput == "f10" && cpuboard[9][5] == 'C'
           ||pinput == "f10" && cpuboard[9][5] == 'D'||pinput == "f10" && cpuboard[9][5] == 'S'){
       playerboard[9][5] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "f10" && cpuboard[9][5] == '_'){
       playerboard[9][5] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }


   else if(pinput == "g1" && cpuboard[0][6] == 'A' ||pinput == "g1" && cpuboard[0][6] == 'B'||pinput == "g1" && cpuboard[0][6] == 'C'
           ||pinput == "g1" && cpuboard[0][6] == 'D'||pinput == "g1" && cpuboard[0][6] == 'S'){
       playerboard[0][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g1" && cpuboard[0][6] == '_'){
       playerboard[0][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g2" && cpuboard[1][6] == 'A' ||pinput == "g2" && cpuboard[1][6] == 'B'||pinput == "g2" && cpuboard[1][6] == 'C'
           ||pinput == "g2" && cpuboard[1][6] == 'D'||pinput == "g2" && cpuboard[1][6] == 'S'){
       playerboard[1][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g2" && cpuboard[1][6] == '_'){
       playerboard[1][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g3" && cpuboard[2][6] == 'A' ||pinput == "g3" && cpuboard[2][6] == 'B'||pinput == "g3" && cpuboard[2][6] == 'C'
           ||pinput == "g3" && cpuboard[2][6] == 'D'||pinput == "g3" && cpuboard[2][6] == 'S'){
       playerboard[2][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g3" && cpuboard[2][6] == '_'){
       playerboard[2][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g4" && cpuboard[3][6] == 'A' ||pinput == "g4" && cpuboard[3][6] == 'B'||pinput == "g4" && cpuboard[3][6] == 'C'
           ||pinput == "g4" && cpuboard[3][6] == 'D'||pinput == "g4" && cpuboard[3][6] == 'S'){
       playerboard[3][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g4" && cpuboard[3][6] == '_'){
       playerboard[3][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g5" && cpuboard[4][6] == 'A' ||pinput == "g5" && cpuboard[4][6] == 'B'||pinput == "g5" && cpuboard[4][6] == 'C'
           ||pinput == "g5" && cpuboard[4][6] == 'D'||pinput == "g5" && cpuboard[4][6] == 'S'){
       playerboard[4][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g5" && cpuboard[4][6] == '_'){
       playerboard[4][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g6" && cpuboard[5][6] == 'A' ||pinput == "g6" && cpuboard[5][6] == 'B'||pinput == "g6" && cpuboard[5][6] == 'C'
           ||pinput == "g6" && cpuboard[5][6] == 'D'||pinput == "g6" && cpuboard[5][6] == 'S'){
       playerboard[5][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g6" && cpuboard[5][6] == '_'){
       playerboard[5][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g7" && cpuboard[6][6] == 'A' ||pinput == "g7" && cpuboard[6][6] == 'B'||pinput == "g7" && cpuboard[6][6] == 'C'
           ||pinput == "g7" && cpuboard[6][6] == 'D'||pinput == "g7" && cpuboard[6][6] == 'S'){
       playerboard[6][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g7" && cpuboard[6][6] == '_'){
       playerboard[6][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g8" && cpuboard[7][6] == 'A' ||pinput == "g8" && cpuboard[7][6] == 'B'||pinput == "g8" && cpuboard[7][6] == 'C'
           ||pinput == "g8" && cpuboard[7][6] == 'D'||pinput == "g8" && cpuboard[7][6] == 'S'){
       playerboard[7][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g8" && cpuboard[7][6] == '_'){
       playerboard[7][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g9" && cpuboard[8][6] == 'A' ||pinput == "g9" && cpuboard[8][6] == 'B'||pinput == "g9" && cpuboard[8][6] == 'C'
           ||pinput == "g9" && cpuboard[8][6] == 'D'||pinput == "g9" && cpuboard[8][6] == 'S'){
       playerboard[8][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g9" && cpuboard[8][6] == '_'){
       playerboard[8][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "g10" && cpuboard[9][6] == 'A' ||pinput == "g10" && cpuboard[9][6] == 'B'||pinput == "g10" && cpuboard[9][6] == 'C'
           ||pinput == "g10" && cpuboard[9][6] == 'D'||pinput == "g10" && cpuboard[9][6] == 'S'){
       playerboard[9][6] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "g10" && cpuboard[9][6] == '_'){
       playerboard[9][6] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }




   else if(pinput == "h1" && cpuboard[0][7] == 'A' ||pinput == "h1" && cpuboard[0][7] == 'B'||pinput == "h1" && cpuboard[0][7] == 'C'
           ||pinput == "h1" && cpuboard[0][7] == 'D'||pinput == "h1" && cpuboard[0][7] == 'S'){
       playerboard[0][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h1" && cpuboard[0][7] == '_'){
       playerboard[0][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h2" && cpuboard[1][7] == 'A' ||pinput == "h2" && cpuboard[1][7] == 'B'||pinput == "h2" && cpuboard[1][7] == 'C'
           ||pinput == "h2" && cpuboard[1][7] == 'D'||pinput == "h2" && cpuboard[1][7] == 'S'){
       playerboard[1][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h2" && cpuboard[1][7] == '_'){
       playerboard[1][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h3" && cpuboard[2][7] == 'A' ||pinput == "h3" && cpuboard[2][7] == 'B'||pinput == "h3" && cpuboard[2][7] == 'C'
           ||pinput == "h3" && cpuboard[2][7] == 'D'||pinput == "h3" && cpuboard[2][7] == 'S'){
       playerboard[2][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h3" && cpuboard[2][7] == '_'){
       playerboard[2][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h4" && cpuboard[3][7] == 'A' ||pinput == "h4" && cpuboard[3][7] == 'B'||pinput == "h4" && cpuboard[3][7] == 'C'
           ||pinput == "h4" && cpuboard[3][7] == 'D'||pinput == "h4" && cpuboard[3][7] == 'S'){
       playerboard[3][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h4" && cpuboard[3][7] == '_'){
       playerboard[3][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h5" && cpuboard[4][7] == 'A' ||pinput == "h5" && cpuboard[4][7] == 'B'||pinput == "h5" && cpuboard[4][7] == 'C'
           ||pinput == "h5" && cpuboard[4][7] == 'D'||pinput == "h5" && cpuboard[4][7] == 'S'){
       playerboard[4][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h5" && cpuboard[4][7] == '_'){
       playerboard[4][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h6" && cpuboard[5][7] == 'A' ||pinput == "h6" && cpuboard[5][7] == 'B'||pinput == "h6" && cpuboard[5][7] == 'C'
           ||pinput == "h6" && cpuboard[5][7] == 'D'||pinput == "h6" && cpuboard[5][7] == 'S'){
       playerboard[5][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h6" && cpuboard[5][7] == '_'){
       playerboard[5][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h7" && cpuboard[6][7] == 'A' ||pinput == "h7" && cpuboard[6][7] == 'B'||pinput == "h7" && cpuboard[6][7] == 'C'
           ||pinput == "h7" && cpuboard[6][7] == 'D'||pinput == "h7" && cpuboard[6][7] == 'S'){
       playerboard[6][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h7" && cpuboard[6][7] == '_'){
       playerboard[6][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h8" && cpuboard[7][7] == 'A' ||pinput == "h8" && cpuboard[7][7] == 'B'||pinput == "h8" && cpuboard[7][7] == 'C'
           ||pinput == "h8" && cpuboard[7][7] == 'D'||pinput == "h8" && cpuboard[7][7] == 'S'){
       playerboard[7][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h8" && cpuboard[7][7] == '_'){
       playerboard[7][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h9" && cpuboard[8][7] == 'A' ||pinput == "h9" && cpuboard[8][7] == 'B'||pinput == "h9" && cpuboard[8][7] == 'C'
           ||pinput == "h9" && cpuboard[8][7] == 'D'||pinput == "h9" && cpuboard[8][7] == 'S'){
       playerboard[8][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h9" && cpuboard[8][7] == '_'){
       playerboard[8][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "h10" && cpuboard[9][7] == 'A' ||pinput == "h10" && cpuboard[9][7] == 'B'||pinput == "h10" && cpuboard[9][7] == 'C'
           ||pinput == "h10" && cpuboard[9][7] == 'D'||pinput == "h10" && cpuboard[9][7] == 'S'){
       playerboard[9][7] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "h10" && cpuboard[9][7] == '_'){
       playerboard[9][7] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }





   else if(pinput == "i1" && cpuboard[0][8] == 'A' ||pinput == "i1" && cpuboard[0][8] == 'B'||pinput == "i1" && cpuboard[0][8] == 'C'
           ||pinput == "i1" && cpuboard[0][8] == 'D'||pinput == "i1" && cpuboard[0][8] == 'S'){
       playerboard[0][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i1" && cpuboard[0][8] == '_'){
       playerboard[0][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i2" && cpuboard[1][8] == 'A' ||pinput == "i2" && cpuboard[1][8] == 'B'||pinput == "i2" && cpuboard[1][8] == 'C'
           ||pinput == "i2" && cpuboard[1][8] == 'D'||pinput == "i2" && cpuboard[1][8] == 'S'){
       playerboard[1][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i2" && cpuboard[1][8] == '_'){
       playerboard[1][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i3" && cpuboard[2][8] == 'A' ||pinput == "i3" && cpuboard[2][8] == 'B'||pinput == "i3" && cpuboard[2][8] == 'C'
           ||pinput == "i3" && cpuboard[2][8] == 'D'||pinput == "i3" && cpuboard[2][8] == 'S'){
       playerboard[2][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i3" && cpuboard[2][8] == '_'){
       playerboard[2][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i4" && cpuboard[3][8] == 'A' ||pinput == "i4" && cpuboard[3][8] == 'B'||pinput == "i4" && cpuboard[3][8] == 'C'
           ||pinput == "i4" && cpuboard[3][8] == 'D'||pinput == "i4" && cpuboard[3][8] == 'S'){
       playerboard[3][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i4" && cpuboard[3][8] == '_'){
       playerboard[3][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i5" && cpuboard[4][8] == 'A' ||pinput == "i5" && cpuboard[4][8] == 'B'||pinput == "i5" && cpuboard[4][8] == 'C'
           ||pinput == "i5" && cpuboard[4][8] == 'D'||pinput == "i5" && cpuboard[4][8] == 'S'){
       playerboard[4][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i5" && cpuboard[4][8] == '_'){
       playerboard[4][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i6" && cpuboard[5][8] == 'A' ||pinput == "i6" && cpuboard[5][8] == 'B'||pinput == "i6" && cpuboard[5][8] == 'C'
           ||pinput == "i6" && cpuboard[5][8] == 'D'||pinput == "i6" && cpuboard[5][8] == 'S'){
       playerboard[5][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i6" && cpuboard[5][8] == '_'){
       playerboard[5][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i7" && cpuboard[6][8] == 'A' ||pinput == "i7" && cpuboard[6][8] == 'B'||pinput == "i7" && cpuboard[6][8] == 'C'
           ||pinput == "i7" && cpuboard[6][8] == 'D'||pinput == "i7" && cpuboard[6][8] == 'S'){
       playerboard[6][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i7" && cpuboard[6][8] == '_'){
       playerboard[6][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i8" && cpuboard[7][8] == 'A' ||pinput == "i8" && cpuboard[7][8] == 'B'||pinput == "i8" && cpuboard[7][8] == 'C'
           ||pinput == "i8" && cpuboard[7][8] == 'D'||pinput == "i8" && cpuboard[7][8] == 'S'){
       playerboard[7][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i8" && cpuboard[7][8] == '_'){
       playerboard[7][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i9" && cpuboard[8][8] == 'A' ||pinput == "i9" && cpuboard[8][8] == 'B'||pinput == "i9" && cpuboard[8][8] == 'C'
           ||pinput == "i9" && cpuboard[8][8] == 'D'||pinput == "i9" && cpuboard[8][8] == 'S'){
       playerboard[8][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i9" && cpuboard[8][8] == '_'){
       playerboard[8][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "i10" && cpuboard[9][8] == 'A' ||pinput == "i10" && cpuboard[9][8] == 'B'||pinput == "i10" && cpuboard[9][8] == 'C'
           ||pinput == "i10" && cpuboard[9][8] == 'D'||pinput == "i10" && cpuboard[9][8] == 'S'){
       playerboard[9][8] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "i10" && cpuboard[9][8] == '_'){
       playerboard[9][8] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }




   else if(pinput == "j1" && cpuboard[0][9] == 'A' ||pinput == "j1" && cpuboard[0][9] == 'B'||pinput == "j1" && cpuboard[0][9] == 'C'
           ||pinput == "j1" && cpuboard[0][9] == 'D'||pinput == "j1" && cpuboard[0][9] == 'S'){
       playerboard[0][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j1" && cpuboard[0][9] == '_'){
       playerboard[0][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j2" && cpuboard[1][9] == 'A' ||pinput == "j2" && cpuboard[1][9] == 'B'||pinput == "j2" && cpuboard[1][9] == 'C'
           ||pinput == "j2" && cpuboard[1][9] == 'D'||pinput == "j2" && cpuboard[1][9] == 'S'){
       playerboard[1][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j2" && cpuboard[1][9] == '_'){
       playerboard[1][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j3" && cpuboard[2][9] == 'A' ||pinput == "j3" && cpuboard[2][9] == 'B'||pinput == "j3" && cpuboard[2][9] == 'C'
           ||pinput == "j3" && cpuboard[2][9] == 'D'||pinput == "j3" && cpuboard[2][9] == 'S'){
       playerboard[2][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j3" && cpuboard[2][9] == '_'){
       playerboard[2][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j4" && cpuboard[3][9] == 'A' ||pinput == "j4" && cpuboard[3][9] == 'B'||pinput == "j4" && cpuboard[3][9] == 'C'
           ||pinput == "j4" && cpuboard[3][9] == 'D'||pinput == "j4" && cpuboard[3][9] == 'S'){
       playerboard[3][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j4" && cpuboard[3][9] == '_'){
       playerboard[3][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j5" && cpuboard[4][9] == 'A' ||pinput == "j5" && cpuboard[4][9] == 'B'||pinput == "j5" && cpuboard[4][9] == 'C'
           ||pinput == "j5" && cpuboard[4][9] == 'D'||pinput == "j5" && cpuboard[4][9] == 'S'){
       playerboard[4][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j5" && cpuboard[4][9] == '_'){
       playerboard[4][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j6" && cpuboard[5][9] == 'A' ||pinput == "j6" && cpuboard[5][9] == 'B'||pinput == "j6" && cpuboard[5][9] == 'C'
           ||pinput == "j6" && cpuboard[5][9] == 'D'||pinput == "j6" && cpuboard[5][9] == 'S'){
       playerboard[5][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j6" && cpuboard[5][9] == '_'){
       playerboard[5][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j7" && cpuboard[6][9] == 'A' ||pinput == "j7" && cpuboard[6][9] == 'B'||pinput == "j7" && cpuboard[6][9] == 'C'
           ||pinput == "j7" && cpuboard[6][9] == 'D'||pinput == "j7" && cpuboard[6][9] == 'S'){
       playerboard[6][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j7" && cpuboard[6][9] == '_'){
       playerboard[6][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j8" && cpuboard[7][9] == 'A' ||pinput == "j8" && cpuboard[7][9] == 'B'||pinput == "j8" && cpuboard[7][9] == 'C'
           ||pinput == "j8" && cpuboard[7][9] == 'D'||pinput == "j8" && cpuboard[7][9] == 'S'){
       playerboard[7][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j8" && cpuboard[7][9] == '_'){
       playerboard[7][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j9" && cpuboard[8][9] == 'A' ||pinput == "j9" && cpuboard[8][9] == 'B'||pinput == "j9" && cpuboard[8][9] == 'C'
           ||pinput == "j9" && cpuboard[8][9] == 'D'||pinput == "j9" && cpuboard[8][9] == 'S'){
       playerboard[8][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j9" && cpuboard[8][9] == '_'){
       playerboard[8][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }

   else if(pinput == "j10" && cpuboard[9][9] == 'A' ||pinput == "j10" && cpuboard[9][9] == 'B'||pinput == "j10" && cpuboard[9][9] == 'C'
           ||pinput == "j10" && cpuboard[9][9] == 'D'||pinput == "j10" && cpuboard[9][9] == 'S'){
       playerboard[9][9] = 'O';
       cout<<"\n\n\n\n\n\nYou hit a ship!\n\n\n\n\n\n";
       shipscrushed++;
   }else if(pinput == "j10" && cpuboard[9][9] == '_'){
       playerboard[9][9] = 'X';
       cout<<"\n\n\n\n\n\nYou missed\n\n\n\n\n\n";
   }
}


