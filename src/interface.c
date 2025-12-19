/**
 * @file interface.c
 * @brief Implementation of high-level ncurses UI and menu handling functions.
 * 
 * Provides window creation, title/menu/pause/retry screens, quit confirmation,
 * and goodbye message display using ncurses and the gameCards module.
 * 
 * @author Mohit Saroya
 */

#include <ncurses.h>
#include "interface.h"
#include "gameCards.h"

/**
 * @brief Create and return a boxed ncurses window.
 *
 * Allocates a new window of size `h` x `w` at position (`y`, `x`), draws a
 * box border and refreshes before returning.
 *
 * @param h Height in rows.
 * @param w Width in columns.
 * @param y Upper-left row coordinate.
 * @param x Upper-left column coordinate.
 * @return WINDOW* Pointer to the new window.
 */
WINDOW *make_window(int h, int w, int y, int x) {
    WINDOW *win = newwin(h, w, y, x);
    box(win, '-', '/');
    wrefresh(win);
    return win;
}

/**
 * @brief Display the title screen and wait for a key press.
 *
 * Creates a full-size title window, draws the ASCII-art title, and waits for
 * the user to press any key before cleaning up and returning.
 */
void title_screen() {
    WINDOW *titlewin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
    titleCard(titlewin);
    wrefresh(titlewin);

    wgetch(titlewin);
    delwin(titlewin);
}

/**
 * @brief Display a quit confirmation prompt and return user choice.
 *
 * Creates a window with a quit confirmation card. Waits for 'y'/'Y' (return 1,
 * quit confirmed) or 'n'/'N' (return 0, don't quit). Refreshes parent window
 * if the user declines.
 *
 * @param parent Parent window to restore if user declines.
 * @return int 1 if user confirms quit, 0 otherwise.
 */
int quitScreen(WINDOW *parent) {
    WINDOW *q = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
    
    quitCard(q);
    wrefresh(q);

    int ch;
    while ((ch = wgetch(q))) {

        if (ch == 'y' || ch == 'Y') {
            delwin(q);
            return 1;   // YES, quit
        }

        if (ch == 'n' || ch == 'N') {
            delwin(q);
            touchwin(parent);
            wrefresh(parent);
            return 0;   // NO, return to menu without deleting the menu
        }
    }

    return 0;
}

/**
 * @brief Handle the in-game pause menu flow.
 *
 * Displays the pause card in a loop, handling user input (P=resume, M=main
 * menu, Q=quit). Returns appropriate decision codes as defined in interface.h.
 *
 * @param gamewin Game window to restore/refresh when leaving pause.
 * @return int Decision code: `P` (resume), `MENU` (back to menu), `QUIT` (quit game).
 */
int handle_pause_menu(WINDOW *gamewin) {
    wrefresh(gamewin);

    while (1) {
        WINDOW *pausewin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
        pauseCard(pausewin);
        wrefresh(pausewin);

        int choice = wgetch(pausewin);
        delwin(pausewin);

        if (choice == 'p' || choice == 'P') {
            touchwin(gamewin);
            wrefresh(gamewin);
            return P;
        }

        else if (choice == 'm' || choice == 'M') {
            erase();
            refresh();
            return MENU;  
        }

        else if (choice == 'q' || choice == 'Q') {
            int confirm = quitScreen(gamewin);

            if (confirm == 1) {
                return QUIT;
            } else {
                continue;
            }
        }
    }
}

/**
 * @brief Display the main menu and handle user selection.
 *
 * Creates and displays the menu window. Waits for input (P=play, Q=quit).
 * Returns appropriate decision codes as defined in interface.h.
 *
 * @return int `P` to play, `QUIT` to exit, or `MENU` to stay in the menu.
 */
int main_menu() {
    WINDOW *menuwin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
    menuCard(menuwin);
    wrefresh(menuwin);

    while (1) {
        int ch = wgetch(menuwin);

        if (ch == 'p' || ch == 'P') {
            delwin(menuwin);
            erase();
            refresh();
            return P;
        }

        if (ch == 'q' || ch == 'Q') {
            int confirm = quitScreen(menuwin);

            if (confirm == 1) {
                delwin(menuwin);
                erase();
                refresh();
                return QUIT;
            } else {
                // Stay in menu. Do NOT delete menuwin.
                touchwin(menuwin);
                wrefresh(menuwin);
                continue;
            }
        }
    }
}

/**
 * @brief Display a retry prompt and handle the player's decision.
 *
 * Shows a retry card asking whether to retry the level. Returns `RETRY` to
 * restart or `MENU` to return to the main menu. Runs in a loop until valid
 * input is received.
 *
 * @param gamewin Game window used as a reference for UI restoration.
 * @return int `RETRY` to retry, `MENU` to return to main menu.
 */
int handle_retry(WINDOW *gamewin) {

    while(1) {
        WINDOW *retrywin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
        retryCard(retrywin);
        wrefresh(retrywin);

        int choice = wgetch(retrywin);
        delwin(retrywin);

        if (choice == 'y' || choice == 'Y') {
            return RETRY;
        }

        else if (choice == 'n' || choice == 'N') {
            erase();
            refresh();
            return MENU;
        }

    }
    

}


/**
 * @brief Display a goodbye screen and wait for a key press.
 *
 * Creates a temporary window with a goodbye message, waits for any key press,
 * and cleans up before returning.
 *
 * @param parent Parent window used as a reference for positioning.
 */
void goodBye(WINDOW *parent) {
    WINDOW *goodbyewin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);

    mvwprintw(goodbyewin, 20, 25, "Thanks for playing!");
    mvwprintw(goodbyewin, 21, 25, "Press any key to exit...");
    mvwprintw(goodbyewin, 22, 25, "Goodbye :)");
    wrefresh(goodbyewin);

    wgetch(goodbyewin);
    delwin(goodbyewin);
}

