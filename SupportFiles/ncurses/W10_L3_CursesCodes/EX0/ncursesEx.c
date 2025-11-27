#include<stdio.h>
#include<ncurses.h>
int main(void)
{
	char line[100];
	int x=10,y=5;
	printf("Hello printf! \n");
	scanf("%s",line);
	
	
	initscr();
	WINDOW *win=newwin(10,20,y,x);
	refresh();
	box(win,'*','*');
	wrefresh(win);
	//move(y,x);	
	//printw("Hello printw, entered string is %s\n",line);	
	getch();
	refresh();
	endwin();
	
	return 0;
}
