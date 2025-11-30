#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include "maze1.h"
void maze1(void)
{
 initscr();
 WINDOW *win=newwin(15,15,0,0);
 noecho();
 refresh();
 wrefresh(win);
 for(int i=0;i<20;i++)
 {
  mvprintw(i,0,"%c",'|');
  mvprintw(i,40,"%c",'|');
 }

 for(int b=0;b<39;b++)
 {
  mvprintw(0,b,"%c",'-');
  mvprintw(20,b,"%c",'-');
 }

 mvprintw(0,39,"%c",'-');
 mvprintw(20,40,"%c",'|');
 mvprintw(20,38,"%c",'|');
 mvprintw(21,39,"%c",'-');

 for(int a=1;a<5;a++)
 {
  mvprintw(3,a,"%c",'_');
 }

 for(int a=1;a<7;a++)
 {
  mvprintw(a,8,"%c",'|');
  mvprintw(a,12,"%c",'|');
 }
 for(int a=8;a<12;a++)
 {
  mvprintw(6,a,"%c",'_');
 }
 for(int a=15;a<24;a++)
 {
  mvprintw(3,a,"%c",'_');
 }
 for(int a=27;a<37;a++)
 {
  mvprintw(3,a,"%c",'_');
 }
 for(int a=4;a<9;a++)
 {
  mvprintw(a,15,"%c",'|');
 }
 for(int a=4;a<9;a++)
 {
  mvprintw(a,23,"%c",'|');
 }
 for(int a=4;a<9;a++)
 {
  mvprintw(a,27,"%c",'|');
 }
 for(int a=4;a<15;a++)
 {
  mvprintw(a,36,"%c",'|');
 }
 for(int a=5;a<15;a++)
 {
  mvprintw(9,a,"%c",'_');
 }
 for(int a=10;a<16;a++)
 {
  mvprintw(a,5,"%c",'|');
 }
 for(int a=14;a<26;a++)
 {
  mvprintw(12,a,"%c",'_');
 }
 for(int a=6;a<35;a++)
 {
  mvprintw(16,a,"%c",'_');
 }
 for(int a=37;a<40;a++)
 {
  mvprintw(15,a,"%c",'_');
 }
 for(int a=27;a<37;a++)
 {
  mvprintw(13,a,"%c",'_');
 }
 for(int a=17;a<20;a++)
 {
  mvprintw(a,35,"%c",'|');
 }
 for(int a=11;a<14;a++)
 {
  mvprintw(a,26,"%c",'|');
 }
 wrefresh(win);
 return;
}
