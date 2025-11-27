#include<stdio.h>
#include<ncurses.h>

int main(void)
{
	/* COLOR_PAIR(n)	COLOR_BLACK  0	COLOR_RED   1
	 * COLOR_GREEN   2	COLOR_YELLOW 3  COLOR_BLUE  4
	 * COLOR_MAGNETA 5	COLOR_CYAN   6  COLOR_WHITE 7	
	*/
	
	initscr();
	
	if(!has_colors())
	{
	mvprintw(0,0,"Terminal Does not have colors\n");
	}else{
		start_color();
		init_pair(1,COLOR_GREEN, COLOR_BLUE);
	}
	attron(COLOR_PAIR(1));
	mvprintw(1,1,"Hello\n");
	attroff(COLOR_PAIR(1));

	refresh();
	getch();
	endwin();
	return 0;

}

