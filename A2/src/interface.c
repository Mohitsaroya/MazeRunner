#include <ncurses.h>
#include "interface.h"
#include "gameCards.h"

WINDOW *make_window(int h, int w, int y, int x) {
    WINDOW *win = newwin(h, w, y, x);
    box(win, '-', '/');
    wrefresh(win);
    return win;
}

void title_screen() {
    WINDOW *titlewin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
    titleCard(titlewin);
    wrefresh(titlewin);

    wgetch(titlewin);
    delwin(titlewin);
}

int quitScreen(WINDOW *parent)
{
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


int handle_pause_menu(WINDOW *gamewin)
{
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


void goodBye(WINDOW *parent) {
    WINDOW *goodbyewin = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);

    mvwprintw(goodbyewin, 20, 25, "Thanks for playing!");
    mvwprintw(goodbyewin, 21, 25, "Press any key to exit...");
    mvwprintw(goodbyewin, 22, 25, "Goodbye :)");
    wrefresh(goodbyewin);

    wgetch(goodbyewin);
    delwin(goodbyewin);
}

