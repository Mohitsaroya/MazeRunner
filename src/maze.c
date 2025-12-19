/**
* @file maze.c
* @brief definitions of the functions in maze.h
*
* This file contains the implementation of maze drawing and exit point functions.
*
* @author Evan Wong
* @date dec.4,2025
*/

#include "maze.h"
#include <ncurses.h>

/**
 * @brief Draw the maze bounding box in `win`.
 *
 * Draws a rectangular border for the maze area inside the provided
 * `WINDOW`. Interior cells are initialized to spaces. This function does not
 * populate level-specific walls or items; those are placed by `maze1`
 * or `maze2` after the border is drawn.
 *
 * @param win ncurses window in which to draw the maze border.
 * @param height Height (number of rows) of the maze area to draw.
 * @param width Width (number of columns) of the maze area to draw.
 * @param start_y Top row coordinate where the maze area should be placed.
 * @param start_x Left column coordinate where the maze area should be placed.
 */
void draw_maze(WINDOW *win, int height, int width, int start_y, int start_x) {
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

/**
 * @brief Populate the Level 1 maze layout into `win`.
 *
 * Places walls, paths and any level-specific decorations into the area that
 * was reserved by `draw_maze`. Coordinates `start_y` and `start_x` indicate
 * the top-left corner of the maze content area inside `win`.
 *
 * @param win ncurses window where the maze content will be drawn.
 * @param start_y Top row coordinate of the maze content area.
 * @param start_x Left column coordinate of the maze content area.
 */
void maze1(WINDOW *win, int start_y, int start_x) {

    for (int a = 1; a < 5; a++) {
        mvwaddch(win, start_y + 3, start_x + a, '-');
    }   

    for (int a = 1; a < 7; a++) {
        mvwaddch(win, start_y + a, start_x + 8, '|');
        mvwaddch(win, start_y + a, start_x + 12, '|');
    }

    for (int a = 8; a < 12; a++) {
        mvwaddch(win, start_y + 6, start_x + a, '-');
    }
        
    for (int a = 15; a < 24; a++){
        mvwaddch(win, start_y + 3, start_x + a, '-');
    }

    for (int a = 27; a < 37; a++) {
        mvwaddch(win, start_y + 3, start_x + a, '-');
    }

    for (int a = 4; a < 9; a++) {
        mvwaddch(win, start_y + a, start_x + 15, '|');
    }

    for (int a = 4; a < 9; a++) {
        mvwaddch(win, start_y + a, start_x + 23, '|');
    }

    for (int a = 4; a < 9; a++) {
        mvwaddch(win, start_y + a, start_x + 27, '|');
    }

    for (int a = 4; a < 15; a++) {
        mvwaddch(win, start_y + a, start_x + 36, '|');
    }

    for (int a = 5; a < 15; a++) {
        mvwaddch(win, start_y + 9, start_x + a, '-');
    }

    for (int a = 10; a < 16; a++) {
        mvwaddch(win, start_y + a, start_x + 5, '|');
    }

    for (int a = 14; a < 26; a++) {
        mvwaddch(win, start_y + 12, start_x + a, '-');
    }

    for (int a = 6; a < 35; a++) {
        mvwaddch(win, start_y + 16, start_x + a, '-');
    }

    for (int a = 37; a < 39; a++) {
        mvwaddch(win, start_y + 15, start_x + a, '-');
    }

    for (int a = 27; a < 37; a++) {
        mvwaddch(win, start_y + 13, start_x + a, '-');
    }

    for (int a = 17; a < 19; a++) {
        mvwaddch(win, start_y + a, start_x + 35, '|');
    }

    for (int a = 11; a < 14; a++) {
        mvwaddch(win, start_y + a, start_x + 26, '|');
    }

    wrefresh(win);
}

/**
 * @brief Populate the Level 2 maze layout into `win`.
 *
 * Similar to `maze1`, but places level 2 specific walls and regions. This
 * function assumes a border has already been drawn and uses `start_y` and
 * `start_x` to position the content inside the provided window.
 *
 * @param win ncurses window where the maze content will be drawn.
 * @param start_y Top row coordinate of the maze content area.
 * @param start_x Left column coordinate of the maze content area.
 */
void maze2(WINDOW *win, int start_y, int start_x) {

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




/**
 * @brief Create an ExitPoint for a maze placed at `start_y,start_x`.
 *
 * Computes the coordinates where the exit marker (typically '$') should be
 * drawn based on the maze's starting position and dimensions. The returned
 * ExitPoint contains absolute coordinates relative to the containing window.
 *
 * @param start_y Top row coordinate of the maze content area.
 * @param start_x Left column coordinate of the maze content area.
 * @param maze_h Height of the maze content area (rows).
 * @param maze_w Width of the maze content area (columns).
 * @return ExitPoint Structure with `y` and `x` coordinates for the exit.
 */
ExitPoint create_exit_point(int start_y, int start_x, int maze_h, int maze_w) {
    ExitPoint ep;

    ep.y = start_y + maze_h - 2;
    ep.x = start_x + maze_w - 2;

    return ep;
}

/**
 * @brief Draw the exit marker inside `win` at the location indicated by `exit`.
 *
 * Renders the character used to represent the exit (for example '$') at the
 * coordinates contained in `exit`. This function only draws the marker and
 * does not modify player or NPC state.
 *
 * @param win ncurses window where the exit marker will be drawn.
 * @param exit ExitPoint specifying the location for the marker.
 */
void draw_exit_point(WINDOW *win, ExitPoint exit) {
    mvwaddch(win, exit.y, exit.x, '$');
    wrefresh(win);
}

/**
 * @brief Check whether the player coordinates match the exit location.
 *
 * Compares the provided player position with the `exit` coordinates and
 * returns a non-zero value when they match (player reached the exit) or 0
 * otherwise.
 *
 * @param player_y Player's current row coordinate.
 * @param player_x Player's current column coordinate.
 * @param exit ExitPoint to compare against.
 * @return Non-zero if player is at the exit, zero otherwise.
 */
int reached_exit(int player_y, int player_x, ExitPoint exit) {
    return (player_y == exit.y && player_x == exit.x);
}
