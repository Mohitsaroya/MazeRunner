#ifndef MOVEMENT_H
#define MOVEMENT_H

/**
 * @file movement.h
 * @brief Public interface for player movement utilities.
 *
 * Functions and types for creating and updating the player's position in a
 * maze window. Movement helpers update the internal `movement` structure and
 * are responsible for erasing/redrawing the player glyph in the associated
 * `WINDOW` when called.
 *
 * @author Evan Wong
 * @date Dec 4, 2025
 */

#include <ncurses.h>

/**
 * @brief Player movement state.
 *
 * Stores the player's current coordinates and the ncurses `WINDOW` where the
 * player is drawn. `y` is the row and `x` is the column within `win`.
 *
 * @field x Current column (horizontal) position of the player.
 * @field y Current row (vertical) position of the player.
 * @field win Pointer to the ncurses window used for drawing the player.
 */
typedef struct {
    int x;
    int y;
    WINDOW *win;
} movement;

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
movement make_player(int y, int x, WINDOW *win);

/**
 * @brief Move the player one column to the right when possible.
 *
 * Updates the `x` coordinate in `m` and redraws the player in `m.win`. This
 * function does not perform collision checks — the caller should ensure the
 * destination cell is walkable before calling, or accept that the function
 * will overwrite the character at the destination.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving right.
 */
movement move_right(movement m);

/**
 * @brief Move the player one column to the left when possible.
 *
 * Updates the `x` coordinate in `m` and redraws the player in `m.win`.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving left.
 */
movement move_left(movement m);

/**
 * @brief Move the player one row up when possible.
 *
 * Updates the `y` coordinate in `m` and redraws the player in `m.win`.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving up.
 */
movement move_up(movement m);

/**
 * @brief Move the player one row down when possible.
 *
 * Updates the `y` coordinate in `m` and redraws the player in `m.win`.
 *
 * @param m Current movement state for the player.
 * @return movement Updated movement state after moving down.
 */
movement move_down(movement m);

#endif
