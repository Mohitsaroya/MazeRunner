/*************************
* @File maze.c
* @Brief definitions of the functions in maze.h
* @Author Evan Wong
* @Date dec.4,2025
**********************/
#include "maze.h"
#include <ncurses.h>


void draw_maze(WINDOW *win, int height, int width, int start_y, int start_x)// makes a box around the game
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

void maze1(WINDOW *win, int start_y, int start_x)// fills the box with maze game
{

    for (int a = 1; a < 5; a++)
        mvwaddch(win, start_y + 3, start_x + a, '-');

    for (int a = 1; a < 7; a++) {
        mvwaddch(win, start_y + a, start_x + 8, '|');
        mvwaddch(win, start_y + a, start_x + 12, '|');
    }

    for (int a = 8; a < 12; a++)
        mvwaddch(win, start_y + 6, start_x + a, '-');

    for (int a = 15; a < 24; a++)
        mvwaddch(win, start_y + 3, start_x + a, '-');

    for (int a = 27; a < 37; a++)
        mvwaddch(win, start_y + 3, start_x + a, '-');

    for (int a = 4; a < 9; a++)
        mvwaddch(win, start_y + a, start_x + 15, '|');

    for (int a = 4; a < 9; a++)
        mvwaddch(win, start_y + a, start_x + 23, '|');

    for (int a = 4; a < 9; a++)
        mvwaddch(win, start_y + a, start_x + 27, '|');

    for (int a = 4; a < 15; a++)
        mvwaddch(win, start_y + a, start_x + 36, '|');

    for (int a = 5; a < 15; a++)
        mvwaddch(win, start_y + 9, start_x + a, '-');

    for (int a = 10; a < 16; a++)
        mvwaddch(win, start_y + a, start_x + 5, '|');

    for (int a = 14; a < 26; a++)
        mvwaddch(win, start_y + 12, start_x + a, '-');

    for (int a = 6; a < 35; a++)
        mvwaddch(win, start_y + 16, start_x + a, '-');

    for (int a = 37; a < 39; a++)
        mvwaddch(win, start_y + 15, start_x + a, '-');

    for (int a = 27; a < 37; a++)
        mvwaddch(win, start_y + 13, start_x + a, '-');

    for (int a = 17; a < 19; a++)
        mvwaddch(win, start_y + a, start_x + 35, '|');

    for (int a = 11; a < 14; a++)
        mvwaddch(win, start_y + a, start_x + 26, '|');

    wrefresh(win);
}

void maze2(WINDOW *win, int start_y, int start_x)// fills the box with maze game
{

    for (int a = 2; a < 25; a++) {
        mvwaddch(win, start_y + 3, start_x + a, '-');
    }

    for (int a = 30; a < 85; a++) {
        mvwaddch(win, start_y + 3, start_x + a, '-');
    }

    for (int a = 30; a < 85; a++) {
        mvwaddch(win, start_y + 9, start_x + a, '-');
    }
    

    for (int a = 3; a < 10; a++) {
        mvwaddch(win, start_y + a, start_x + 25, '|');
    }

    for (int a = 3; a < 10; a++) {
        mvwaddch(win, start_y + a, start_x + 85, '|');
    }

    for (int a = 9; a < 25; a++) {
        mvwaddch(win, start_y + 9, start_x + a, '-');
    }

    for (int a = 5; a < 10; a++) {
        mvwaddch(win, start_y + a, start_x + 9, '|');
    }

    for (int a = 10; a < 20; a++) {
        mvwaddch(win, start_y + a, start_x + 30, '|');
    }

    for (int a = 5; a < 30; a++) {
        mvwaddch(win, start_y + 20, start_x + a, '-');
    }

    for (int a = 5; a < 28; a++) {
        mvwaddch(win, start_y + 16, start_x + a, '-');
    }

    for (int a = 12; a < 19; a++) {
        mvwaddch(win, start_y + a, start_x + 20, '|');
    }

    for (int a = 13; a < 25; a++) {
        mvwaddch(win, start_y + a, start_x + 60, '|');
    }

    for (int a = 25; a < 60; a++) {
        mvwaddch(win, start_y + 25, start_x + a, '-');
    }

    for (int a = 10; a < 22; a++) {
        mvwaddch(win, start_y + a, start_x + 50, '|');
    }

    for (int a = 20; a < 27; a++) {
        mvwaddch(win, start_y + a, start_x + 5, '|');
    }

    for (int a = 60; a < 89; a++) {
        mvwaddch(win, start_y + 13, start_x + a, '-');
    }

    for (int a = 20; a < 27; a++) {
        mvwaddch(win, start_y + a, start_x + 75, '|');
    }

    for (int a = 14; a < 19; a++) {
        mvwaddch(win, start_y + a, start_x + 75, '|');
    }
    
    wrefresh(win);
}




ExitPoint create_exit_point(int start_y, int start_x, int maze_h, int maze_w) {
    ExitPoint ep;

    ep.y = start_y + maze_h - 2;// these saves location on where the maze exit would be
    ep.x = start_x + maze_w - 2;

    return ep;// returns and save x and y coordinates
}

void draw_exit_point(WINDOW *win, ExitPoint exit) {// makes exit point character
    mvwaddch(win, exit.y, exit.x, '$');
    wrefresh(win);
}

int reached_exit(int player_y, int player_x, ExitPoint exit) {// returns true or false is the x and y of player and exit coordinates matches
    return (player_y == exit.y && player_x == exit.x);
}
