#include<stdio.h>
#include<ncurses.h>

int main(void)
{
	int h1,w1,s_y,s_x;
	h1=5;w1=10; s_y=2,s_x=2;

	initscr();
	WINDOW *win=newwin(h1,w1,s_y,s_x);
	refresh();
	char cx='-',cy='|';
	wborder(win, cy,cy,cx,cx,34,34,34,34);	
	wrefresh(win);
	mvwprintw(win,1,1,"Hello");
	wrefresh(win);	

	getch();
	endwin();
	return 0;

}



