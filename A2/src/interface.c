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
    WINDOW *titlewin = make_window(HEIGTH_MAX, WIDTH_MAX, BORDER, BORDER);
    titleCard(titlewin);
    wrefresh(titlewin);

    getch();  
    delwin(titlewin);
}


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

    }
}


int main_menu() {
    
    WINDOW *menuwin = make_window(HEIGTH_MAX, WIDTH_MAX, BORDER, BORDER);
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

    }
}


void goodBye(WINDOW *parent) {
    WINDOW *goodbyewin = make_window(HEIGTH_MAX, WIDTH_MAX, BORDER, BORDER);

    mvwprintw(goodbyewin, 20, 50, "Thanks for playing!");
    mvwprintw(goodbyewin, 21, 50, "Goodbye :)");
    wrefresh(goodbyewin);

    getch(); // any key to close
    delwin(goodbyewin);
}
