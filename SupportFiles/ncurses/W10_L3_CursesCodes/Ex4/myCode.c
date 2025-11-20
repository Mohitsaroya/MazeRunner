#include<stdio.h>
#include<ncurses.h>

int main(void)
{
	
	initscr();
	noecho();
	cbreak();
	int y,x,yS,xS,yMax,xMax;

	mvprintw(1,1,"Hello\n");

	getyx(stdscr,y,x);
	getbegyx(stdscr,yS,xS);
	getmaxyx(stdscr,yMax,xMax);

	printw("%d %d\n",y,x);
	printw("%d %d\n",yS,xS);
	printw("%d %d\n",yMax,xMax);

	refresh();
	getch();
	endwin();
	return 0;

}

