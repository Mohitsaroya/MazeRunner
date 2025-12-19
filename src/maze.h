#ifndef MAZE_H
#define MAZE_H

/**
 * @file maze.h
 * @brief Public interface for maze creation and utilities.
 *
 * This header declares functions and types used to draw mazes, create and
 * render the exit point, and query when the player reaches the exit. The
 * implementations produce ncurses windows that represent maze layouts for
 * different levels.
 *
 * @author Evan Wong
 * @date Dec 4, 2025
 */

#include <ncurses.h>

/**
 * @brief Exit point in a maze.
 *
 * Represents the coordinates of the maze exit relative to the containing
 * window. `y` is the row and `x` is the column where the exit marker is
 * drawn.
 *
 * @param y Row (vertical) coordinate of the exit.
 * @param x Column (horizontal) coordinate of the exit.
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
 * @brief Draw the maze bounding box in `win`.
 *
 * The function draws a rectangular box representing the maze area inside the
 * provided `WINDOW`. It does not populate the internal maze cells — that is
 * performed by `maze1`/`maze2` — but prepares borders and any necessary
 * background for the maze content.
 *
 * @param win ncurses window in which to draw the maze border.
 * @param height Height (number of rows) of the maze area to draw.
 * @param width Width (number of columns) of the maze area to draw.
 * @param start_y Top row coordinate where the maze area should be placed.
 * @param start_x Left column coordinate where the maze area should be placed.
 */
void draw_maze(WINDOW *win, int height, int width, int start_y, int start_x);

/**
 * @brief Populate the Level 1 maze layout into `win`.
 *
 * This function places walls, paths and level-specific items into the maze
 * area previously created by `draw_maze`. The coordinates `start_y` and
 * `start_x` indicate the top-left corner of the maze content area inside
 * the `win` window.
 *
 * @param win ncurses window where the maze content will be drawn.
 * @param start_y Top row coordinate of the maze content area.
 * @param start_x Left column coordinate of the maze content area.
 */
void maze1(WINDOW *win, int start_y, int start_x);

/**
 * @brief Populate the Level 2 maze layout into `win`.
 *
 * Similar to `maze1` but places level 2 specific walls, items and paths. The
 * function assumes the maze border has already been drawn and uses `start_y`
 * and `start_x` to position the content.
 *
 * @param win ncurses window where the maze content will be drawn.
 * @param start_y Top row coordinate of the maze content area.
 * @param start_x Left column coordinate of the maze content area.
 */
void maze2(WINDOW *win, int start_y, int start_x);

/**
 * @brief Create an ExitPoint for a maze placed at `start_y,start_x`.
 *
 * The function computes the coordinates where the exit marker (e.g. '$')
 * should be drawn based on the starting position and maze dimensions. The
 * returned `ExitPoint` contains the absolute row/column coordinates relative
 * to the containing window.
 *
 * @param start_y Top row coordinate of the maze content area.
 * @param start_x Left column coordinate of the maze content area.
 * @param maze_h Height of the maze content area (rows).
 * @param maze_w Width of the maze content area (columns).
 * @return ExitPoint Structure with `y` and `x` coordinates for the exit.
 */
ExitPoint create_exit_point(int start_y, int start_x, int maze_h, int maze_w);

/**
 * @brief Draw the exit marker inside `win` at the location indicated by `exit`.
 *
 * The function renders the character used to represent the exit (for
 * example '$') at the coordinates contained in `exit`. It is responsible for
 * placing the marker but does not change the player's or NPCs' positions.
 *
 * @param win ncurses window where the exit marker will be drawn.
 * @param exit ExitPoint specifying the location for the marker.
 */
void draw_exit_point(WINDOW *win, ExitPoint exit);

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
int reached_exit(int player_y, int player_x, ExitPoint exit);

#endif
