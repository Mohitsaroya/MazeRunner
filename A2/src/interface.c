#include <ncurses.h>
#include "interface.h"
#include "gameCards.h"

/* ----------------------------------------------------
   WINDOW HELPERS
---------------------------------------------------- */

WINDOW *make_window(int h, int w, int y, int x) {
    WINDOW *win = newwin(h, w, y, x);
    box(win, '-', '/');
    wrefresh(win);
    return win;
}

/* ----------------------------------------------------
   TITLE SCREEN
---------------------------------------------------- */

void title_screen() {
    WINDOW *titlewin = make_window(40, 100, 2, 2);
    titleCard(titlewin);
    wrefresh(titlewin);

    getch();  
    delwin(titlewin);
}

/* ----------------------------------------------------
   QUIT CONFIRMATION SCREEN
   Only accepts: Y or N
---------------------------------------------------- */

int quitScreen(WINDOW *win) {
    while (1) {
        werase(win);
        box(win, '-', '/');

        quitCard(win);
        mvwprintw(win, 26, 48, "(Y/N)");
        wrefresh(win);

        char ch = getch();

        if (ch == 'y' || ch == 'Y')
            return 1;
        if (ch == 'n' || ch == 'N')
            return 0;

        // Invalid input → stay on screen
    }
}

/* ----------------------------------------------------
   MAIN MENU
   Only accepts: P or Q
---------------------------------------------------- */

int main_menu() {
    title_screen();

    WINDOW *menuwin = make_window(40, 100, 2, 2);
    menuCard(menuwin);
    wrefresh(menuwin);

    while (1) {
        int ch = wgetch(menuwin);

        if (ch == 'p' || ch == 'P') {
            delwin(menuwin);
            return 1;
        }

        if (ch == 'q' || ch == 'Q') {
            int confirm = quitScreen(menuwin);
            delwin(menuwin);
            return confirm ? 0 : 2;
        }

        // Invalid input → ignore and remain on this screen
    }
}

/* ----------------------------------------------------
   GOODBYE SCREEN
---------------------------------------------------- */

void goodBye(WINDOW *parent) {
    WINDOW *goodbyewin = make_window(40, 100, 2, 2);

    mvwprintw(goodbyewin, 20, 50, "Thanks for playing!");
    mvwprintw(goodbyewin, 21, 50, "Goodbye :)");
    wrefresh(goodbyewin);

    getch(); // any key to close
    delwin(goodbyewin);
}
