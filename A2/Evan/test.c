#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include"maze2.h"
#include"maze1.h"
movement make_player() // makes the character
{
 movement m;
 m.x=1;
 m.y=1;
 mvaddch(m.x,m.y,'@');// starts the player at that position
 return m;
}

movement move_right(movement m)// moves player ->
{
 mvaddch(m.y,m.x,' ');// replaces the player original position to empty space 
 mvaddch(m.y,m.x+1,'@');// makes the character where the user input 
 m.x+=1; // updates the position 
return m;// returns the info
}

movement move_left(movement m)// moves player <-
{
 mvaddch(m.y,m.x,' ');
 mvaddch(m.y,m.x-1,'@');
 m.x-=1;
 return m;
}

movement move_up(movement m)//moves player ^
{
 mvaddch(m.y,m.x,' ');
 mvaddch(m.y-1,m.x,'@');
 m.y-=1;
 return m;
}

movement move_down(movement m)// moves player down
{
 mvaddch(m.y,m.x,' ');
 mvaddch(m.y+1,m.x,'@');
 m.y+=1;
 return m;
}

int main(void)
{
 int ch;// initialized the user input
 movement m;// allows access to the x & y
 maze1();
 m=make_player();// makes the player character
 keypad(stdscr,TRUE);// make it so it can read special keys like the arrow pad
 ch=getch();// gets the user input
 refresh();

 mvprintw(22,1,"dave has trapped you in this maze, you must find a way to escape");
 getch();
 mvprintw(22,1,"                                                                      ");


 while(1)//runs forever until you press q
 {
  if (ch == KEY_RIGHT)// reads the user input and prompt the apporiprated if statement
  {
   if(mvinch(m.y,m.x+1) ==' ')// these are used to see that if the user input will move the player into a empty space
   {
    m =move_right(m);
   }
  }
  else if (ch == KEY_LEFT)
  {
   if(mvinch(m.y,m.x-1) == ' ')
   {
    m = move_left(m);
   }
  }
  else if (ch == KEY_UP)
  {
   if(mvinch(m.y-1,m.x) == ' ')
   {
    m = move_up(m);
   }
  }
  else if (ch == KEY_DOWN)
  {
   if(mvinch(m.y+1,m.x) == ' ')
   {
     m = move_down(m);
   }
  }
  else if (ch == 'q')
  {
   break;// allows to quit the game
  }

  if(m.y == 19 && m.x == 39)
  {
   mvprintw(25,25,"escaped");
  }

  if(m.y == 18 && m.x == 30)
  {
   mvprintw(22,1,"opps, you went the wrong way. Do you think it was that simple.");
   getch();
   mvprintw(22,1,"                                                                 ");
  }

  if(m.y == 16 && m.x ==36)
  {
   mvprintw(22,1,"you found the exit, you can finally leave this maze");
   getch();
   mvprintw(22,1,"                                                       " );
  }
  ch=getch();// after the first user input is taken, this takes the next one
  refresh();// refreshes the page to move the player if the next spot is empty
 }
 endwin();
 return 0;
}
