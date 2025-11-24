#include <ncurses.h>
#include <stdio.h>
#include "level1.h"
#include "interface.h"  // For make_window() if needed

void first_level(void) {
    // Create a window for level 1
    WINDOW *lvl_win = make_window(20, 60, 5, 10);

    // Placeholder text
    mvwprintw(lvl_win, 1, 1, "First Level - TODO: Implement the game here");
    mvwprintw(lvl_win, 3, 1, "Press any key to continue...");
    wrefresh(lvl_win);

    getch();  // Wait for user input

    // Clean up
    delwin(lvl_win);
}