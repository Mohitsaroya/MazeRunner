#ifndef GAMECARDS_H
#define GAMECARDS_H

#include <ncurses.h>

/**
 * @file gameCards.h
 * @brief Functions that draw various UI "cards" used by the game.
 * 
 * Each function draws a specific screen (title, menu, quit confirmation,
 * level status, retry prompt, pause screen, etc.) into the provided ncurses
 * `WINDOW`.
 * 
 * @author Mohit Saroya
 
 */

/**
 * @brief Draw the title card into `win`.
 *
 * The title card typically shows the game name and a prompt to continue.
 * @param win The ncurses window to draw into.
 */
void titleCard(WINDOW *win);

/**
 * @brief Draw the main menu card into `win`.
 *
 * Shows available menu options (play, quit, etc.).
 * @param win The ncurses window to draw into.
 */
void menuCard(WINDOW *win);

/**
 * @brief Draw the quit confirmation card into `win`.
 *
 * Presents a yes/no prompt asking the user to confirm quitting.
 * @param win The ncurses window to draw into.
 */
void quitCard(WINDOW *win);

/**
 * @brief Draw the level 1 status/information card into `win`.
 *
 * Used to show level-specific instructions, objectives or status.
 * @param win The ncurses window to draw into.
 */
void level1Card(WINDOW *win);

/**
 * @brief Draw the level 2 status/information card into `win`.
 *
 * Used to show level-specific instructions, objectives or status.
 * @param win The ncurses window to draw into.
 */
void level2Card(WINDOW *win);

/**
 * @brief Draw a retry/prompt card into `win`.
 *
 * Displays a message prompting the player to retry or continue.
 * @param win The ncurses window to draw into.
 */
void retryCard(WINDOW *win);

/**
 * @brief Draw the pause screen card into `win`.
 *
 * Shows pause information and waits for a resume key. Does not block
 * input handling in other contexts.
 * @param win The ncurses window to draw into.
 */
void pauseCard(WINDOW *win);

#endif
