#include<stdio.h>
#include<ncurses.h>

int main(void)
{
	
	initscr();
	noecho();
	cbreak();

	int yMax,xMax;
	getmaxyx(stdscr,yMax,xMax);

	WINDOW *inputWin=newwin(3,xMax-12,yMax-5,5);
	wborder(inputWin,'|','|','-','-','+','+','+','+');
	refresh();
	wrefresh(inputWin);
	keypad(inputWin,true);

	int c=wgetch(inputWin);
	if (c==KEY_UP)
	{mvwprintw(inputWin,1,1,"You pressed UP!");}
	else if(c==KEY_DOWN)
	{mvwprintw(inputWin,1,1,"You pressed DOWN!");}
	else{mvwprintw(inputWin,1,1,"Not a valid Entry!");}
	wrefresh(inputWin);

	getch();
	endwin();
	return 0;

}

