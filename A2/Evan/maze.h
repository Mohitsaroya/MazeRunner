/****************************
* @File maze.h
* @Brief Public interface for desiging the maze
* @Author Evan Wong
* @Date Dec.4,2025
************************/
#ifndef MAZE_H
#define MAZE_H
#include <ncurses.h>
/**
* @Brief this struct defines where will the eexitpoint will be in the maze
*/
typedef struct ExitPoint {
    int y;
    int x;
} ExitPoint;

#define HEIGHT_MAZE1 20
#define WIDTH_MAZE1 40

#define HEIGHT_MAZE2 28
#define WIDTH_MAZE2 90
/**
* @Brief this makes the boarder around the game
* @Param window functios, heigh and width of the maze, y and x coordinates of the starting area
* @Return none
*/
void draw_maze(WINDOW *win, int height, int width, int start_y, int start_x);
/**
* @Brief makes the maze 1 level
* @Param window functions, y and x coord of the starting position
* @Return none
*/
void maze1(WINDOW *win, int start_y, int start_x);
/**
* @Brief makes the maze 2 level
* @Param window functions,y and x coordinates of stating position
* @Return none 
*/
void maze2(WINDOW *win, int start_y, int start_x);

/**
* @Brief makes where the exit point location would be depending which maze it is
* @Param window function, y and x coordinates of the top right of the box and y and x of the maze height and width
* @Return ep for the exit point
*/
ExitPoint create_exit_point(int start_y, int start_x, int maze_h, int maze_w);

/**
* @Brief makse the exit point character
* @param window functions and ExitPoint exit for access on the ep
* @Return ep(location of the exitpoint)
*/
void draw_exit_point(WINDOW *win, ExitPoint exit);

/**
* @Brief argument on if the player madee it to the exit
* @Param y and x coordinates of the player and ExitPoint exit for access on ep
& @Return True or false argument if player y and x and exit y and x are the same
*/
int reached_exit(int player_y, int player_x, ExitPoint exit);

#endif
