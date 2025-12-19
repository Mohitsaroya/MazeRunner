/**
* @file movement.c
* @brief defintion of the functions in movement.h
*
* This file contains the implementation of player movement functions.
*
* @author Evan Wong
* @date Dec.4,2025
*/

#include "movement.h"
#include <ncurses.h>

/**
 * @brief Create and draw a player at the specified start coordinates.
 *
 * Initializes a `movement` structure for the player and draws the player
 * glyph at the provided coordinates inside `win`.
 *
 * @param y Start row where the player should be placed.
 * @param x Start column where the player should be placed.
 * @param win ncurses window in which the player will be drawn.
 * @return movement Initialized movement structure containing the start
 *         coordinates and `win` pointer.
 */
movement make_player(int y, int x, WINDOW *win)
{
    movement m = { x, y, win };
    mvwaddch(win, y, x, '@');
    wrefresh(win);
    return m;
}

/**
 * @brief Move the player one column to the right when possible.
 *
 * Updates the `x` coordinate in `m` and redraws the player in `m.win`.
 * This function assumes the caller has validated that the destination cell is
 * walkable. It clears the previous position and writes the player glyph at
 * the new position.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving right.
 */
movement move_right(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.x++;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}

/**
 * @brief Move the player one column to the left when possible.
 *
 * Updates the `x` coordinate in `m` and redraws the player in `m.win`.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving left.
 */
movement move_left(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.x--;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}

/**
 * @brief Move the player one row up when possible.
 *
 * Updates the `y` coordinate in `m` and redraws the player in `m.win`.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving up.
 */
movement move_up(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.y--;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}

/**
 * @brief Move the player one row down when possible.
 *
 * Updates the `y` coordinate in `m` and redraws the player in `m.win`.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving down.
 */
movement move_down(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.y++;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}
