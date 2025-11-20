#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main(){

	WINDOW *w;
	int current_x, current_y;
	//initialize ncurses
	initscr();
	
	//height, width, start_y, start_x
	w = newwin(30,80, 5, 5);
	
	//any window creation or  box plot must be followed by a refresh for changes
	//to take effect
	refresh();
	
	/*
                use wborder to specify:
                left, right, top, bottom borders
                top left, top right, bottom left, bottom right corners
        */
	
	wborder(w,'|','|','-','-','+','+','+','+');
	wrefresh(w);
	
	//Move the cursor to coordinate (x=10, y=15)
	move(15,10);

	//get current position of cursor on the screen
	getyx(stdscr, current_y, current_x);
	
	//print the current coordinates to the window
	printw("%d %d", current_x, current_y);
	//print a message to the window
	printw("Hello World");
	refresh();

	//halt normal terminal behaviour for 3 sec.
	sleep(3);
	
	//clear the screen
	clear();
	
	//add a vertical line at  x=10, y=5 and ending at y = 20
	mvvline(5,10, '*',20);
	refresh();

	getchar();
	endwin();


	return 0;
}
