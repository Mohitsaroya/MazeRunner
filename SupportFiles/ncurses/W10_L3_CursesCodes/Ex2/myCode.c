#include<stdio.h>
#include<ncurses.h>

int main(void)
{
	/* A_NORMAL	A_STANDOUT	A_REVERSE
	 * A_BLINK	A_DIM		A_BOLD
	 * A_PROTECT	A_INVIS		A_ALTCHARSET
	 * A_CAHRTEXT
	*/
	
	initscr();
	
	int flag=has_colors();
	attron(A_REVERSE);
	mvprintw(1,1,"Hello\n");
	mvprintw(2,1,"The terminal has colors %d",flag);
	attroff(A_REVERSE);

	refresh();
	getch();
	endwin();
	return 0;

}

