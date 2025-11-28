#ifndef MAZE2_H
#define MAZE2_H
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
void maze2(void);

#endif

