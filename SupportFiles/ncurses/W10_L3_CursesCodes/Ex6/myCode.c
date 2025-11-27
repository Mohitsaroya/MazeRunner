#include<stdio.h>
#include<ncurses.h>
int main(void)
{
	initscr();noecho();cbreak();

	int yMax,xMax;
	getmaxyx(stdscr,yMax,xMax);

	WINDOW *inputWin=newwin(6,xMax-50,yMax-30,5);
	wborder(inputWin,'|','|','-','-','+','+','+','+');
	refresh();
	wrefresh(inputWin);
	keypad(inputWin,true);

	char str[][8]={"Choice1", "Opt2","No3"};
	int highlight=0;
	int readKey=0;
	while(readKey!='\n')
	{
		for(int i=0;i<3;i++)    // this For loop to print the choices 
		{if(i==highlight) wattron(inputWin,A_REVERSE);// highlight the choice we are at	
		mvwprintw(inputWin,i+1,1,"%s",str[i]);
		wattroff(inputWin,A_REVERSE);} 

		wrefresh(inputWin);
		readKey=wgetch(inputWin);    // read UP or DOWN form the user
		if((readKey==KEY_UP)&&(highlight!=0)) highlight--; // change the highlghted choice
		else if ((readKey==KEY_DOWN)&&(highlight!=2)) highlight++; // change the highlighted choice
	}

	mvwprintw(stdscr,2,2,"You selected: %s ",str[highlight]);
	refresh();
	getch();
	endwin();
	return 0;
}

