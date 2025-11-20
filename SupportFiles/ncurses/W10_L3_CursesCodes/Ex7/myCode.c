#include<stdio.h>
#include<ncurses.h>
int main(void)
{
	initscr();noecho();cbreak();
	
	//int snakeL=10;
	//char *snakeBody;
	//snakeBody=malloc(snakeL*sizeof(int));
	//for (int i=0;i<snakeL;i++)*(snakeBody+i)='x';

	WINDOW *gameWin=newwin(15,30,10,10);
	wborder(gameWin,'|','|','-','-','+','+','+','+');
	refresh();
	wrefresh(gameWin);
	keypad(gameWin,true);
	mvwprintw(gameWin,1,1,"We print here");
	wrefresh(gameWin);
	//int readKey=0;

	refresh();
	getch();
	endwin();
	return 0;
}

