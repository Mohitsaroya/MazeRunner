#include<ncurses.h>
void printSnake(WINDOW *gamewin,int length
	, char *body, int *yLoc, int *xloc);

void mvSnake(WINDOW *gamewin,int length
	, char *body, int *yLoc, int *xloc,char* dir, int pressK);

