#include "maze.h"
#include <ncurses.h>

void draw_maze(WINDOW *win, int height, int width, int start_y, int start_x)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
                mvwaddch(win, start_y + y, start_x + x, '#');
            else
                mvwaddch(win, start_y + y, start_x + x, ' ');
        }
    }
    wrefresh(win);
}
