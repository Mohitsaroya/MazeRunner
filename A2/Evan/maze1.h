#ifndef MAZE1_H
#define MAZE1_H
#include<ncurses.h>
typedef struct movement
{
 int y;
 int x;
} movement;

movement make_player();
movement move_right(movement m);
movement move_left(movement m);
movement move_up(movement m);
movement move_down(movement m);

void maze1(void);

#endif
