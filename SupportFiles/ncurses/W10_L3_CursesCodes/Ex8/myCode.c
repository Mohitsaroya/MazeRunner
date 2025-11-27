#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include"Fun.h"
int main(void)
{
	initscr();noecho();cbreak();
	
	int snakeL=6, yMax=15,xMax=30, readKey;

	WINDOW *gameWin=newwin(yMax,xMax,10,10);
	wborder(gameWin,'|','|','-','-','+','+','+','+');
	refresh();
	wrefresh(gameWin);
	
	char *snakeBody=malloc(snakeL*sizeof(char)); // assign a pointer to char to carry the body shape	
	int  *snakeYloc=malloc(snakeL*sizeof(int));
	int  *snakeXloc=malloc(snakeL*sizeof(int));  // and for each character location Y,X
	char snakedir='r';				// 
	
	for (int i=0;i<snakeL;i++)
	{	*(snakeBody+i)='x';     // all chars symbol are 'x'
		*(snakeYloc+i)=yMax/2; // the body will start horizontal 
	 	*(snakeXloc+i)=xMax/2-i;// all characters are successive in x location
	}	
	*(snakeBody+snakeL-1)=' ';     // add sapce at the tail to erease while moving
	
	printSnake(gameWin,snakeL,snakeBody,snakeYloc,snakeXloc);
	
	do{readKey=wgetch(gameWin);
	mvSnake(gameWin,snakeL,snakeBody,snakeYloc,snakeXloc,&snakedir,readKey);
	printSnake(gameWin,snakeL,snakeBody,snakeYloc,snakeXloc);
	}while (readKey!='\n');
	refresh();
	getch();
	endwin();
	return 0;
}

