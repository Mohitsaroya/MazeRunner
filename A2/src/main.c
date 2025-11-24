#include <ncurses.h>
#include "interface.h"

int main(void) {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    refresh();

    int decision;

    do {
        decision = main_menu();

        if (decision == 1) {
            first_level();
        } else if (decision == 0) {
            goodBye(stdscr);
        }

        // if decision == 2, loop back to main menu automatically
    } while (decision == 2);

    endwin();
    return 0;
}