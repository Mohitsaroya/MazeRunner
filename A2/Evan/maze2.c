
#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include"maze2.h"
void maze2(void)
{
 initscr(); // initialized the suer input
 WINDOW *win=newwin(15,15,0,0);// makes the boarder
 noecho();// prevents printing the user input
 refresh();
 wrefresh(win);
 for(int i=0;i<30;i++)// for loop allows to reprint the special characters to mvprintw to prevent the player to accidentally move out
 {
  mvprintw(i,0,"%c",'|');
  mvprintw(i,90,"%c",'|');
 }

 for(int b=0;b<89;b++)
 {
 mvprintw(0,b,"%c",'-');
 mvprintw(30,b,"%c",'-');
 }
 mvprintw(0,89,"%c",'-');// these prints makes the exit
 mvprintw(30,90,"%c",'|');
 mvprintw(30,88,"%c",'|');
 mvprintw(31,89,"%c",'-');
 mvprintw(30,90,"%c",'|');

 for(int a=1;a<31;a++)
 {
   mvprintw(3,a,"%c",'_');
 }
 for(int b=34;b<88;b++)
 {
  mvprintw(3,b,"%c",'_');
  mvprintw(6,b,"%c",'_');

 }


 mvprintw(4,30,"%c",'|');
 mvprintw(5,30,"%c",'|');
 mvprintw(6,30,"%c",'|');
 mvprintw(7,30,"%c",'|');
 mvprintw(4,87,"%c",'|');
 mvprintw(5,87,"%c",'|');
 mvprintw(4,87,"%c",'|');

 for(int c=3;c<31;c++)
 {
  mvprintw(7,c,"%c",'_');
  mvprintw(10,c,"%c",'_');

 }

 mvprintw(6,3,"%c",'|');
 mvprintw(5,3,"%c",'|');

 for (int d=7; d<13;d++)
 {
  mvprintw(d,33,"%c",'|');
 }

 for (int e=80;e<90;e++)
 {
  mvprintw(8,e,"%c",'_');
 }

 for (int f=9;f<25;f++)
 {
  mvprintw(f,80,"%c",'|');
  mvprintw(f,78,"%c",'|');
 }
 mvprintw(25,78,"%c",'|');
 mvprintw(26,78,"%c",'|');
 mvprintw(7,78,"%c",'|');
 mvprintw(8,78,"%c",'|');

 for(int g=2;g<34;g++)
 {
  mvprintw(13,g,"%c",'_');
 }

 for(int h=2;h<79;h++)
 {
 mvprintw(16,h,"%c",'_');
 }
 for(int j=16;j<24;j++)
 {
  mvprintw(j,20,"%c",'|');
 }
 for(int k=78;k<90;k++)
 {
  mvprintw(27,k,"%c",'_');
 }

 for(int l= 0;l<21;l++)
 {
  mvprintw(26,l,"%c",'_');
 }

 for(int m=29;m<51;m++)
 {
  mvprintw(26,m,"%c",'_');
 }

 for(int n=51;n<61;n++)
 {
  mvprintw(18,n,"%c",'_');
 }

 mvprintw(28,51,"%c",'|');
 mvprintw(19,51,"%c",'|');
 mvprintw(20,51,"%c",'|');
 mvprintw(21,51,"%c",'|');
 mvprintw(22,51,"%c",'|');
 mvprintw(23,51,"%c",'|');
 mvprintw(24,51,"%c",'|');
 mvprintw(25,51,"%c",'|');
 mvprintw(26,51,"%c",'|');
 mvprintw(27,51,"%c",'|');
 mvprintw(29,51,"%c",'|');

 mvprintw(28,61,"%c",'|');
 mvprintw(19,61,"%c",'|');
 mvprintw(20,61,"%c",'|');
 mvprintw(21,61,"%c",'|');
 mvprintw(22,61,"%c",'|');
 mvprintw(23,61,"%c",'|');
 mvprintw(24,61,"%c",'|');
 mvprintw(25,61,"%c",'|');
 mvprintw(26,61,"%c",'|');
 mvprintw(27,61,"%c",'|');
 mvprintw(29,61,"%c",'|');

 wrefresh(win);

 return;
}
