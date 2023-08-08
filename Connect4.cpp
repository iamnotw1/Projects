#include<iostream>
using namespace std;
void Display( char board[6][7] );
bool gamewon = false;
char board[6][7];//available for whole program
bool drop(int b, char board[6][7],char xoro);
int choice;
int temp1 = 5;
int temp2 = 5;
int temp3 = 5;
int temp4 = 5;
int temp5 = 5;
int temp6 = 5;
int temp7 = 5;
char xoro;
int counter = 1;
int a;
int b;



int main(){
    //sets the grid
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = '_';
        }
    }
    // welcome titlescreen
    cout<<"Welcome to the Game of Connect 4!"<<endl;
    cout<<"Enter (1) to play."<<endl;
    cout<<"Enter (2) for rules."<<endl;
    cin >> choice;//get input from user
    switch(choice){
        case 1:


            do{

                Display(board);//displays the board
                cout<<"Player 1 makes a move(0-6)"<<endl;
                cin>>a;//get input from player 1

                if(counter % 2 == 1){//this checks if it's player 1 or player 2
                    xoro = 'x';// odd = player1, even = player2
                    counter++;
                }else{
                    xoro = 'o';
                    counter++;
                }


                if (a == 0 ){//this appears because my i-- seems to be unreachable and I don't know how to solve
                    board[temp1][a] = xoro;
                    temp1--;
                }
                else if(a == 1){
                    board[temp2][a] = xoro;
                    temp2--;
                }
                else if(a == 2){
                    board[temp3][a] = xoro;
                    temp3--;
                }
                else if(a == 3){
                    board[temp4][a] = xoro;
                    temp4--;
                }
                else if(a == 4){
                    board[temp5][a] = xoro;
                    temp5--;
                }
                else if(a == 5){
                    board[temp6][a] = xoro;
                    temp6--;
                }
                else if(a == 6){
                    board[temp7][a] = xoro;
                    temp7--;
                }

                drop(a,board,xoro);//dropping input into the grid

                for (int i = 6; i > 0 ; i--) {//checks the if player one wins, this is vertical
                    if((board[1][a] == 'x' && board[2][a] =='x' && board[3][a] == 'x' && board[4][a] == 'x')||
                       (board[5][a] == 'x' && board[2][a] == 'x' &&board[3][a] == 'x' &&board[4][a] == 'x') ||
                       (board[5][a] == 'x' &&board[6][a] == 'x' &&board[3][a] == 'x' &&board[4][a] == 'x') ||
                       (board[5][a] == 'x' &&board[6][a] == 'x' &&board[7][a] == 'x' &&board[4][a] == 'x' )) {
                        cout << "Player one wins!" << endl;
                        gamewon = true;
                    }
                }
                for (int i = 6; i > 0 ; i--) {//checks if player 2 wins, this is vertical
                    if((board[1][b] == 'o' && board[2][b] =='o' && board[3][b] == 'o' && board[4][b] == 'o')||
                       (board[5][b] == 'o' && board[2][b] == 'o' &&board[3][b] == 'o' &&board[4][b] == 'o') ||
                       (board[5][b] == 'o' &&board[6][b] == 'o' &&board[3][b] == 'o' &&board[4][b] == 'o') ||
                       (board[5][b] == 'o' &&board[6][b] == 'o' &&board[7][b] == 'o' &&board[4][b] == 'o' )){
                        cout<<"Player two wins!"<<endl;
                        gamewon = true;
                    }
                }
                cout<<endl;


                Display(board);//displays the board
                cout<<"Player 2 makes a move(1 - 7)"<<endl;
                cin >> b;//player 2 input

                if(counter % 2 == 1){//same thing checks if to use x or o player1 is odd which is x
                    //and player 2 is even which is o
                    xoro = 'x';
                    counter++;
                }else{
                    xoro = 'o';
                    counter++;
                }

                if (b == 0 ){//same thing just repeating(I find it easier to do it this way sry)
                    board[temp1][b] = xoro;
                    temp1--;
                }
                else if(b == 1){
                    board[temp2][b] = xoro;
                    temp2--;
                }
                else if(b == 2){
                    board[temp3][b] = xoro;
                    temp3--;
                }
                else if(b == 3){
                    board[temp4][b] = xoro;
                    temp4--;
                }
                else if(b == 4){
                    board[temp5][b] = xoro;
                    temp5--;
                }
                else if(b == 5){
                    board[temp6][b] = xoro;
                    temp6--;
                }
                else if(b == 6){
                    board[temp7][b] = xoro;
                    temp7--;
                }

                drop(b,board,xoro);//dropping o which is player 2's input
                for (int i = 6; i > 0 ; i--) {//check player 1 vertical
                    if((board[1][a] == 'x' && board[2][a] =='x' && board[3][a] == 'x' && board[4][a] == 'x')||
                       (board[5][a] == 'x' && board[2][a] == 'x' &&board[3][a] == 'x' &&board[4][a] == 'x') ||
                       (board[5][a] == 'x' &&board[6][a] == 'x' &&board[3][a] == 'x' &&board[4][a] == 'x') ||
                       (board[5][a] == 'x' &&board[6][a] == 'x' &&board[7][a] == 'x' &&board[4][a] == 'x' )) {
                        cout << "Player one wins!" << endl;
                        gamewon = true;
                    }
                }
                for (int i = 6; i > 0 ; i--) {//check player 2 vertical
                    if((board[1][b] == 'o' && board[2][b] =='o' && board[3][b] == 'o' && board[4][b] == 'o')||
                       (board[5][b] == 'o' && board[2][b] == 'o' &&board[3][b] == 'o' &&board[4][b] == 'o') ||
                       (board[5][b] == 'o' &&board[6][b] == 'o' &&board[3][b] == 'o' &&board[4][b] == 'o') ||
                       (board[5][b] == 'o' &&board[6][b] == 'o' &&board[7][b] == 'o' &&board[4][b] == 'o' )){
                        cout<<"Player two wins!"<<endl;
                        gamewon = true;}
                }
                cout<<endl<<endl;

            }while (!gamewon);//keep running until game won
            break;

        case 2:
            cout<<"How to play the Game of Connect 4???\n\n"<<endl;
            cout<<"The first player to get four of your input(x or o) in a row \neither horizontally, vertically or diagonally wins."<<endl;
            cout<<"Re-run for play";
            break;//rules
    }


}

// function I use for drop
bool drop(int b, char board[6][7],char xoro){
    for (int i = 5; i <= 0;i--){
        if(board[i][b] == '_'){
            board[i][b] =  xoro;
            return true;
        }
        else{
            return false;
        }


    }

}

// stores the input
void Display(char board[6][7]) {
    cout << " 0 1 2 3 4 5 6 " << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                cout << " ";
                cout << board[i][j];
            }
        }cout << endl;
    }
}
