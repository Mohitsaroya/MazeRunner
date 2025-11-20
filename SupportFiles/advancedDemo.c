#include <stdio.h>
#include <curses.h>
#include <unistd.h>

/* struct representing each part of the player*/
typedef struct{
	int x;
	int y;
	char symbol;
}Part;

/* struct representing a player which is a combination of Part*/
typedef struct{
	Part eyebrow1, eyebrow2, eye1, eye2, nose;
	int x;
	int y;
}Player;

/* Create a player and set starting position at (10, 25)*/
Player createPlayer(){
	Player p;

	p.x = 10;
	p.y = 25;

	p.eyebrow1.x = p.x;
	p.eyebrow1.y= p.y;
	p.eyebrow1.symbol = '^';
	
	p.eyebrow2.x = p.x+2; 
    p.eyebrow2.y= p.y; 
    p.eyebrow2.symbol = '^';

	p.eye1.x = p.x; 
	p.eye1.y = p.y+1;
	p.eye1.symbol = '.';
	
	p.eye2.x = p.x+2; 
    p.eye2.y = p.y+1;
    p.eye2.symbol = '.';

	p.nose.x = p.x+1;
	p.nose.y = p.y+2;
	p.nose.symbol = '_';
	
	return p;
}

/* Draw a player on the screen */
void drawPlayer(Player p){
	mvaddch(p.eyebrow1.y, p.eyebrow1.x, p.eyebrow1.symbol);
	mvaddch(p.eyebrow2.y, p.eyebrow2.x, p.eyebrow2.symbol);

	mvaddch(p.eye1.y, p.eye1.x, p.eye1.symbol);
	mvaddch(p.eye2.y, p.eye2.x, p.eye2.symbol);

	mvaddch(p.nose.y, p.nose.x, p.nose.symbol);
	refresh();
}

/* Function that takes care of the player moving right*/
/* Moving consists of undrawing the player at current
   position (undrawing meaning setting those positions
   to a space) and redrawing the player at the next 
   position.
*/
Player movePlayerRight(Player p){
	mvaddch(p.eyebrow1.y,p.eyebrow1.x,' ');
    mvaddch(p.eyebrow1.y,p.eyebrow1.x+1,p.eyebrow1.symbol);
        
    mvaddch(p.eyebrow2.y,p.eyebrow2.x,' ');
    mvaddch(p.eyebrow2.y,p.eyebrow2.x+1,p.eyebrow2.symbol);

    mvaddch(p.eye1.y,p.eye1.x,' ');
    mvaddch(p.eye1.y,p.eye1.x+1,p.eye1.symbol);

    mvaddch(p.eye2.y,p.eye2.x,' ');
    mvaddch(p.eye2.y,p.eye2.x+1,p.eye2.symbol);

    mvaddch(p.nose.y,p.nose.x,' ');
    mvaddch(p.nose.y,p.nose.x+1,p.nose.symbol);

    p.x+=1;
    p.eyebrow1.x+=1;
    p.eyebrow2.x+=1;
    p.eye1.x+=1;
    p.eye2.x+=1;
    p.nose.x+=1;   

	refresh();

	return p;
}

int main(){

	WINDOW *w;
	Player p;	
	int ch;
	//initialize ncurses
	initscr();
	
	//add no echo so that entered keys are not printed to the screen
	noecho();	

	//height, width, start_y, start_x
	w = newwin(30,30, 1, 1);

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
	char h='|';

	/* These are placed here since the above border is not recognized 
	   by mvinch. This is done so the check in the while loop for
	   the border will work
	*/
	
	mvprintw(25,30,"%c",h);
	mvprintw(26,30,"%c",h);
	mvprintw(27,30,"%c",h);

	p=createPlayer();

	drawPlayer(p);

	keypad(stdscr, TRUE);
	ch=getch();
	refresh();

	/* Direction checking:
	   KEY_UP
	   KEY_DOWN
	   KEY_LEFT
	*/
	
	while (1){
		if (ch == KEY_RIGHT){
			//check to see if the player can advance
			//i.e. is there an empty space
			if (mvinch(p.y, p.x+3) == ' ')
				p = movePlayerRight(p);

		}
		else if (ch == 'q'){
			break;
		}
		 ch=getch();
		 refresh();
	}

	//follow with a getch (get a single keystroke from the user)
    //otherwise you will not see any change on the screen
	getch();
	endwin();

	return 0;
}
