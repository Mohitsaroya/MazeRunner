#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include"maze.h"
void maze(void)
{
 initscr(); // initialized the suer input
 WINDOW *win=newwin(100,40,0,0);// makes the boarder
 noecho();// prevents printing the user input
 refresh();
 wborder(win, '|','|','-','-','+','+','+','+');// designs the borader
 wrefresh(win);
 for(int i=0;i<50;i++)// for loop allows to reprint the special characters to mvprintw to prevent the player to accidentally move out
 {
  mvprintw(0,i,"%c",'-');
  mvprintw(50,i,"%c",'-');
  mvprintw(i,0,"%c",'|');
  mvprintw(i,50,"%c",'|');
 }
 refresh();





 return;
}
