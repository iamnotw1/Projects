#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;


bool gameOver;
const int width = 20;
const int height = 20;

int x,y,fruitX,fruitY,score;
int tailX[width*height], tailY[width*height];
int nTail;
enum eDirection{STOP = 0, LEFT,RIGHT,UP,DOWN};
eDirection dir;

//setting up the game conditions, random fruit, score, no direction, game not over.
void Setup(){
	srand(time(0));
	gameOver = false;
	dir = STOP;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

//takes the cursor to the coordinate given then starts to overwrite the text.
void cursorToXY(int x, int y)
{
	COORD cursorPos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
}

//prints everything you need
void Draw(){
	cursorToXY(0, 0);
	
	for(int i = 0; i < width+2; i++){
		cout << "#";
	}
	cout<<endl;
	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width+2; j++){
			if(j == 0)
				cout<<"#";
			if(i == y && j == x)
				cout<<"O";
			else if(i == fruitY && j == fruitX)
				cout<<"A";
			else{
				bool print = false;
				for(int k = 0; k < nTail; k++){
					if(tailX[k] == j && tailY[k]==i){
						cout<<"o";
						print = true;
						}
					}
				if(!print)
				cout<<" ";	
			}
			if(j == width - 1)
				cout<<"#";
		}
		cout<<endl;	
	}

	for(int i = 0; i < width+2; i++){
		cout << "#";
	}
	
	cout<<"\n\nScore:"<< score;
	Sleep(50);		
}


//getting direction input and making sure it doesn't conflict with user's last input
void Input(){
	if(_kbhit()){
		switch(_getch()){
			  case 'a':
			  if (dir == RIGHT) 
			  break;           
			  dir = LEFT;
			  break;
			  
			  case 'd':
			  if (dir == LEFT)
			  break;       
			  dir = RIGHT;
			  break;
			  
			  case 'w':
			  if (dir == DOWN)
			  break;          
			  dir = UP;
			  break;
			  
			  case 's':
			  if (dir == UP) 
			  break;   
			  dir = DOWN;
			  break;
			  
			  case 'x':
			  gameOver = true;
			  break;
		}
	}

}

//logic of the game, including adding tail to the back of the last tail and the first tail is head, direction in terms of x and y coordinates, snake pass the wall will teleport from the other end, gameOver conditions, scoring.
void Logic()
{
 
int prevX = tailX[0];
int prevY = tailY[0];

for ( int i = nTail-1 ; i > 0 ; i-- )
{
    tailX[i] = tailX[i-1];
    tailY[i] = tailY[i-1];
}
tailX[0] = x;
tailY[0] = y;
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
 
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
 
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

//Snake Game
int main(){

Setup();

while(!gameOver){
	Draw();
	Input();
	Logic();
	
}
return 0;

}
