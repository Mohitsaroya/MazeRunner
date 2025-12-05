/**
 * @file gameCards.c
 * @brief Implementation of UI "card" drawing functions used by MazeRunner.
 * 
 * Each function draws a specific screen into the provided ncurses `WINDOW`.
 * 
 * @author Mohit Saroya
 
 */

#include <ncurses.h>
#include "gameCards.h"

/**
 * @brief Draw the title card into `win` and refresh the window.
 *
 * Renders ASCII-art title text and a prompt to continue. This function does
 * not consume input itself; the caller may wait for a key press using
 * `wgetch` if desired.
 *
 * @param win ncurses window to draw the title into.
 */
void titleCard(WINDOW *win) {
    mvwprintw(win, 10, 15, " __        __                 _________   _______");
    mvwprintw(win, 11, 15, "|   \\    /   |      /\\       |_____   /  |   ____|");
    mvwprintw(win, 12, 15, "|    \\  /    |     /  \\          /   /   |  |__");
    mvwprintw(win, 13, 15, "|  |  \\/  |  |    /    \\        /   /    |   __|");
    mvwprintw(win, 14, 15, "|  |      |  |   /  /\\  \\      /   /     |  |");
    mvwprintw(win, 15, 15, "|  |      |  |  /  /  \\  \\    /   /___   |  |____");
    mvwprintw(win, 16, 15, "|__|      |__| /__/    \\__\\  /________|  |_______|");
    
    mvwprintw(win, 18, 20, " ______     __    __    ____     __    ____     __    _______    ______");
    mvwprintw(win, 19, 20, "|      \\   |  |  |  |  |    \\   |  |  |    \\   |  |  |   ____|  |      \\");
    mvwprintw(win, 20, 20, "|  |0|  |  |  |  |  |  |     \\  |  |  |     \\  |  |  |  |__     |  |0|  |");
    mvwprintw(win, 21, 20, "|    __/   |  |  |  |  |  |\\  \\ |  |  |  |\\  \\ |  |  |   __|    |    __/");
    mvwprintw(win, 22, 20, "|  |\\  \\   |  |  |  |  |  | \\  \\|  |  |  | \\  \\|  |  |  |       |  |\\  \\");
    mvwprintw(win, 23, 20, "|  | |  |  |  \\__/  |  |  |  \\     |  |  |  \\     |  |  |____   |  | |  |");
    mvwprintw(win, 24, 20, "|__| |__|   \\______/   |__|   \\____|  |__|   \\____|  |_______|  |__| |__|");


    mvwprintw(win, 35, 60, "Press any key to continue...");
    wrefresh(win);
}

/**
 * @brief Draw the main menu card into `win`.
 *
 * Displays ASCII-art and labels for available actions (play, quit). The
 * function refreshes `win` after drawing; input handling is performed by the
 * caller.
 *
 * @param win ncurses window to draw the menu into.
 */
void menuCard(WINDOW *win) {
    mvwprintw(win,  7, 15, " __        __                 _________   _______");
    mvwprintw(win,  8, 15, "|   \\    /   |      /\\       |_____   /  |   ____|");
    mvwprintw(win,  9, 15, "|    \\  /    |     /  \\          /   /   |  |__");
    mvwprintw(win, 10, 15, "|  |  \\/  |  |    /    \\        /   /    |   __|");
    mvwprintw(win, 11, 15, "|  |      |  |   /  /\\  \\      /   /     |  |");
    mvwprintw(win, 12, 15, "|  |      |  |  /  /  \\  \\    /   /___   |  |____");
    mvwprintw(win, 13, 15, "|__|      |__| /__/    \\__\\  /________|  |_______|");
    
    mvwprintw(win, 15, 20, " ______     __    __    ____     __    ____     __    _______    ______");
    mvwprintw(win, 16, 20, "|      \\   |  |  |  |  |    \\   |  |  |    \\   |  |  |   ____|  |      \\");
    mvwprintw(win, 17, 20, "|  |0|  |  |  |  |  |  |     \\  |  |  |     \\  |  |  |  |__     |  |0|  |");
    mvwprintw(win, 18, 20, "|    __/   |  |  |  |  |  |\\  \\ |  |  |  |\\  \\ |  |  |   __|    |    __/");
    mvwprintw(win, 19, 20, "|  |\\  \\   |  |  |  |  |  | \\  \\|  |  |  | \\  \\|  |  |  |       |  |\\  \\");
    mvwprintw(win, 20, 20, "|  | |  |  |  \\__/  |  |  |  \\     |  |  |  \\     |  |  |____   |  | |  |");
    mvwprintw(win, 21, 20, "|__| |__|   \\______/   |__|   \\____|  |__|   \\____|  |_______|  |__| |__|");

    mvwprintw(win, 25, 46, "PLAY_(P)");
    mvwprintw(win, 28, 46, "QUIT_(Q)");
    wrefresh(win);
}

/**
 * @brief Draw a quit confirmation card into `win`.
 *
 * Presents a large "QUIT" label and a small "(Y/N)" prompt. Caller should
 * handle the user's keypress to determine whether to quit.
 *
 * @param win ncurses window to draw the confirmation into.
 */
void quitCard(WINDOW *win) {
    mvwprintw(win, 15, 25, " ________    __    __    ______    ______    _____");
    mvwprintw(win, 16, 25, "/   __   \\  |  |  |  |  |__  __|  |__  __|  |__   \\");
    mvwprintw(win, 17, 25, "|  |  |  |  |  |  |  |    |  |      |  |       \\   |");
    mvwprintw(win, 18, 25, "|  |  |  |  |  |  |  |    |  |      |  |       /  /");
    mvwprintw(win, 19, 25, "|  | _|  |  |  |  |  |    |  |      |  |      |__|");
    mvwprintw(win, 20, 25, "|  \\_\\ \\ |  |  \\__/  |  __|  |__    |  |       __");
    mvwprintw(win, 21, 25, "\\_____\\ \\    \\______/   |______|    |__|      |__|");
    mvwprintw(win, 22, 25, "       \\_\\");

    mvwprintw(win, 26, 48, "(Y/N)");
    wrefresh(win);
    
}

/**
 * @brief Draw the level 1 information card into `win`.
 *
 * Shows level title and a prompt to continue. The function refreshes `win`.
 * @param win ncurses window to draw the level card into.
 */
void level1Card(WINDOW *win) {
    mvwprintw(win, 15, 17, " __         _______    __     __    _______    __         __________");
    mvwprintw(win, 16, 17, "|  |       |   ____|  |  |   /  /  |   ____|  |  |       |___    ___|");
    mvwprintw(win, 17, 17, "|  |       |  |__     |  |  /  /   |  |__     |  |           |  |");
    mvwprintw(win, 18, 17, "|  |       |   __|    |  | /  /    |   __|    |  |           |  |");
    mvwprintw(win, 19, 17, "|  |       |  |       |  |/  /     |  |       |  |           |  |");
    mvwprintw(win, 20, 17, "|  |____   |  |____   |     /      |  |____   |  |____    ___|  |___");
    mvwprintw(win, 21, 17, "|_______|  |_______|  |____/       |_______|  |_______|  |__________|");

    mvwprintw(win, 35, 60, "Press any key to continue...");
    wrefresh(win);
}

/**
 * @brief Draw the level 2 information card into `win`.
 *
 * Shows level title and a prompt to continue. The function refreshes `win`.
 * @param win ncurses window to draw the level card into.
 */
void level2Card(WINDOW *win) {
    mvwprintw(win, 15, 15, " __         _______    __     __    _______    __         ______________");
    mvwprintw(win, 16, 15, "|  |       |   ____|  |  |   /  /  |   ____|  |  |       |___    _    __|");
    mvwprintw(win, 17, 15, "|  |       |  |__     |  |  /  /   |  |__     |  |           |  | |  |");
    mvwprintw(win, 18, 15, "|  |       |   __|    |  | /  /    |   __|    |  |           |  | |  |");
    mvwprintw(win, 19, 15, "|  |       |  |       |  |/  /     |  |       |  |           |  | |  |");
    mvwprintw(win, 20, 15, "|  |____   |  |____   |     /      |  |____   |  |____    ___|  |_|  |__");
    mvwprintw(win, 21, 15, "|_______|  |_______|  |____/       |_______|  |_______|  |______________|");

    mvwprintw(win, 35, 60, "Press any key to continue...");
    wrefresh(win);
}

/**
 * @brief Draw a retry prompt card into `win`.
 *
 * Displays a retry message with a "(Y/N)" prompt. The caller should handle
 * the user's choice.
 *
 * @param win ncurses window to draw the retry prompt into.
 */
void retryCard(WINDOW *win) {
    mvwprintw(win, 10, 37, "You have run out of moves!");
    mvwprintw(win, 15, 20, " ______     _______    ______    ______    ___       __   _____");
    mvwprintw(win, 16, 20, "|      \\   |   ____|  |__  __|  |      \\   \\  \\    /  /  |__   \\");
    mvwprintw(win, 17, 20, "|  |0|  |  |  |__       |  |    |  |0|  |   \\  \\  /  /      \\   |");
    mvwprintw(win, 18, 20, "|    __/   |   __|      |  |    |    __/     \\  \\/  /       /  /");
    mvwprintw(win, 19, 20, "|  |\\  \\   |  |         |  |    |  |\\  \\      \\    /       |__|");
    mvwprintw(win, 20, 20, "|  | |  |  |  |____     |  |    |  | |  |     /   /         __");
    mvwprintw(win, 21, 20, "|__| |__|  |_______|    |__|    |__| |__|    /___/         |__|");
    
    mvwprintw(win, 26, 48, "(Y/N)");
    wrefresh(win);
}

/**
 * @brief Draw the pause screen card into `win`.
 *
 * Presents pause instructions and key hints (resume, main menu, exit). The
 * function refreshes `win` after drawing.
 *
 * @param win ncurses window to draw the pause card into.
 */
void pauseCard(WINDOW *win) {

    mvwprintw(win,  7, 15, " _________                 __        __    _______ ");
    mvwprintw(win,  8, 15, "|   ______|       /\\      |   \\    /   |  |   ____|");
    mvwprintw(win,  9, 15, "|  |             /  \\     |    \\  /    |  |  |__   ");
    mvwprintw(win, 10, 15, "|  |  _____     /    \\    |  |  \\/  |  |  |   __|  ");
    mvwprintw(win, 11, 15, "|  | |__   |   /  /\\  \\   |  |      |  |  |  |     ");
    mvwprintw(win, 12, 15, "|  |____|  |  /  /  \\  \\  |  |      |  |  |  |____ ");
    mvwprintw(win, 13, 15, "|__________| /__/    \\__\\ |__|      |__|  |_______|");
    
    mvwprintw(win, 15, 20, " ______                 __    __    _________    _______    _____");
    mvwprintw(win, 16, 20, "|      \\      /\\       |  |  |  |  \\   ______|  |   ____|  |     \\");
    mvwprintw(win, 17, 20, "|  |0|  |    /  \\      |  |  |  |   \\   \\       |  |__     |  |\\  \\");
    mvwprintw(win, 18, 20, "|   ___/    /    \\     |  |  |  |    \\   \\      |   __|    |  | \\  |");
    mvwprintw(win, 19, 20, "|  |       /  /\\  \\    |  |  |  |     \\   \\     |  |       |  | /  |");
    mvwprintw(win, 20, 20, "|  |      /  /  \\  \\   |  \\__/  |   ___\\   \\    |  |____   |  |/  /");
    mvwprintw(win, 21, 20, "|__|     /__/    \\__\\   \\______/   |________\\   |_______|  |_____/");

    mvwprintw(win, 26, 40, "Press (P) to resume");
    mvwprintw(win, 28, 40, "Press (M) to enter main menu");
    mvwprintw(win, 30, 40, "Press (Q) to exit game");
    wrefresh(win);
}
