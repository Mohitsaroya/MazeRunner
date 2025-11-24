#include <ncurses.h>
#include "interface.h"
#include "gameCards.h"

// Create a reusable window with border
WINDOW *make_window(int h, int w, int y, int x) {
    WINDOW *win = newwin(h, w, y, x);
    box(win, '-', '/');
    wrefresh(win);
    return win;
}

// Show the title screen
void title_screen(void) {
    WINDOW *titlewin = make_window(40, 100, 2, 2);
    titleCard(titlewin);
    wrefresh(titlewin);
    getch();
    delwin(titlewin);
}

// Show the quit confirmation screen
int quitScreen(WINDOW *win) {
    werase(win);
    box(win, '-', '/');
    quitCard(win);
    mvwprintw(win, 26, 48, "(Y/N)");
    wrefresh(win);

    int ch = getch();
    return (ch == 'y' || ch == 'Y') ? 1 : 0;
}

// Main menu logic
int main_menu(void) {
    title_screen();

    WINDOW *menuwin = make_window(40, 100, 2, 2);
    menuCard(menuwin);
    wrefresh(menuwin);

    int ch;
    while (1) {
        ch = wgetch(menuwin);

        if (ch == 'p' || ch == 'P') {
            delwin(menuwin);
            return 1;  // Start level 1
        }

        if (ch == 'q' || ch == 'Q') {
            int confirm = quitScreen(menuwin);
            delwin(menuwin);

            return confirm ? 0 : 2; // 0 = quit, 2 = loop back to menu
        }
    }
}

// Goodbye screen
void goodBye(WINDOW *win) {
    WINDOW *goodbyewin = make_window(40, 100, 2, 2);
    mvwprintw(goodbyewin, 20, 50, "Thanks for playing!");
    mvwprintw(goodbyewin, 21, 50, "Goodbye :)");
    wrefresh(goodbyewin);
    getch();
    delwin(goodbyewin);
}

// Placeholder first level
void first_level(void) {
    WINDOW *lvl1 = make_window(40, 100, 2, 2);
    mvwprintw(lvl1, 1, 1, "First Level - TODO");
    wrefresh(lvl1);
    getch();
    delwin(lvl1);
}

// Placeholder second level
void second_level(void) {
    WINDOW *lvl2 = make_window(40, 100, 2, 2);
    mvwprintw(lvl2, 1, 1, "Second Level - TODO");
    wrefresh(lvl2);
    getch();
    delwin(lvl2);
}