/*************************
* @File movement.h
* @Brief Public interface for the movement of the player
* @Author Evan Wong
* @Date Dec.4,2025
************************/
#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <ncurses.h>
/**
* @Brief this structure keeps track of th movement of the player
*/
typedef struct {
    int x;
    int y;
    WINDOW *win;
} movement;
/**
* @Brief this makes the player character
* @Param y and x coordinates and window function
* @Return m(saves the x and y coordinates of the player)
*/
movement make_player(int y, int x, WINDOW *win);
/**
* @Brief moves the player to the right
* @Param m allows access to the x and y coordinates movement
* @Return m with the updated values
*/
movement move_right(movement m);
/**
* @Brief moves player to the left
* @Param m allows acces to the x and y coordinates movement
* @Return m with the updated values
*/
movement move_left(movement m);
/**
* @Brief moves player up
* @Param m allows acces to the x and y coordinates movement
* @Return m with the updated values
*/
movement move_up(movement m);
/**
* @Brief moves player down
* @Param m allows access to the x and y coordinates movement
* @Return m with the updated values
*/
movement move_down(movement m);

#endif
