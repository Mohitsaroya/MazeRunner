#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>

/**
 * @file interface.h
 * @brief High-level ncurses UI helpers and menu handling for MazeRunner.
 * @author Mohit Saroya
 * This header exposes functions to create and manage windows, display the
 * title and menu screens, handle pause/retry flows, confirm quitting, and
 * show a goodbye message.
 */

/** @brief Default maximum window width (columns) used for subwindows. */
#define WIDTH_MAX 100

/** @brief Default maximum window height (rows) used for subwindows. */
#define HEIGHT_MAX 40

/** @brief Border offset from terminal edges when creating windows. */
#define BORDER 2

/* Decision/return codes used by menu handlers */
/** @brief Exit/application-quit code. */
#define EXIT 111
/** @brief Request to return to the main menu. */
#define MENU 222
/** @brief Request to quit the game. */
#define QUIT 333
/** @brief Play / resume code (used when user presses P). */
#define P 123
/** @brief Proceed to next step/level. */
#define NEXT 456
/** @brief Retry the current level. */
#define RETRY 100

/**
 * @brief Create and return a boxed ncurses window.
 *
 * Allocates a new window of size `h` x `w` at position (`y`, `x`), draws a
 * simple box around it and refreshes the window before returning it.
 *
 * @param h Window height in rows.
 * @param w Window width in columns.
 * @param y Row index of the window's upper-left corner.
 * @param x Column index of the window's upper-left corner.
 * @return WINDOW* Pointer to the newly created ncurses window.
 */
WINDOW *make_window(int h, int w, int y, int x);

/**
 * @brief Display the program title screen.
 *
 * Creates a full-size title window, draws the title card and waits for a key
 * press before destroying the window.
 */
void title_screen(void);

/**
 * @brief Display the main menu and wait for user selection.
 *
 * The function draws the menu and waits for keyboard input. Return values are
 * one of the decision macros defined above (for example `P` to start/play,
 * `QUIT` to exit, or `MENU` to stay in the menu).
 *
 * @return int Menu decision code (`P`, `QUIT`, `MENU`, etc.).
 */
int main_menu(void);

/**
 * @brief Handle the in-game pause menu.
 *
 * Displays the pause card and waits for the player's selection. Possible
 * return codes include `P` (resume), `MENU` (return to main menu), or
 * `QUIT` (confirm quit requested).
 *
 * @param gamewin The game window to restore/refresh after leaving pause.
 * @return int Decision code indicating the selected action.
 */
int handle_pause_menu(WINDOW *gamewin);

/**
 * @brief Display a retry prompt and handle the player's choice.
 *
 * Shows a retry card asking whether to retry the level. Returns `RETRY` to
 * restart the level or `MENU` to return to the main menu.
 *
 * @param gamewin The game window used as a reference for refreshing.
 * @return int `RETRY` to retry, `MENU` to go back to the menu.
 */
int handle_retry(WINDOW *gamewin);

/**
 * @brief Ask the user to confirm quitting the game.
 *
 * Presents a yes/no prompt and returns 1 if the user confirms quit ('y'/'Y')
 * or 0 if the user cancels ('n'/'N'). The parent window can be touched or
 * refreshed when the prompt is dismissed to restore the UI.
 *
 * @param parent Parent window used to restore/redraw after the prompt.
 * @return int 1 if confirmed, 0 otherwise.
 */
int quitScreen(WINDOW *parent);

/**
 * @brief Show a goodbye screen and wait for key press.
 *
 * Displays a simple goodbye message in a temporary window attached to
 * `parent`, waits for any key press, then destroys the temporary window.
 *
 * @param parent Parent window used as reference for positioning.
 */
void goodBye(WINDOW *parent);

#endif