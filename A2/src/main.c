#include <ncurses.h>
#include "interface.h"

int main(void) {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    refresh();

    while (1) {
        int decision = main_menu();

        if (decision == 1) {
            first_level();
            break;  
        }
        else if (decision == 0) {
            goodBye(stdscr);
            break;  
        }
        else if (decision == 2) {
            // Go back to title + main menu
            // Loop continues
            continue;
        }
    }

    endwin();
    return 0;
}