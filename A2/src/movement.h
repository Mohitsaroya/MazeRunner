#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <ncurses.h>

typedef struct {
    int x;
    int y;
    WINDOW *win;
} movement;

movement make_player(int y, int x, WINDOW *win);
movement move_right(movement m);
movement move_left(movement m);
movement move_up(movement m);
movement move_down(movement m);

#endif
