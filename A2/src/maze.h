#ifndef MAZE_H
#define MAZE_H
#include <ncurses.h>

typedef struct ExitPoint {
    int y;
    int x;
} ExitPoint;

#define HEIGHT_MAZE1 20
#define WIDTH_MAZE1 40

#define HEIGHT_MAZE2 28
#define WIDTH_MAZE2 90

void draw_maze(WINDOW *win, int height, int width, int start_y, int start_x);
void maze1(WINDOW *win, int start_y, int start_x);
void maze2(WINDOW *win, int start_y, int start_x);


ExitPoint create_exit_point(int start_y, int start_x, int maze_h, int maze_w);

void draw_exit_point(WINDOW *win, ExitPoint exit);

int reached_exit(int player_y, int player_x, ExitPoint exit);

#endif
