#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <ncurses.h>

typedef struct{
    int y;
    int x;
} movement;

movement make_player();
movement move_right(movement m);
movement move_left(movement m);
movement move_up(movement m);
movement move_down(movement m);

#endif
