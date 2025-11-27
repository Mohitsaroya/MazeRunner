#include <ncurses.h>
#include <stdio.h>
#include "level1.h"
#include "interface.h"  
#include "movement.h"

void first_level(void) {
    // Create a window for level 1
    
    WINDOW *lvl_win = make_window(HEIGTH_MAX, WIDTH_MAX, BORDER, BORDER);


    mvwprintw(lvl_win, 3, 1, "Press any key to continue...");
    wrefresh(lvl_win);

    getch();  // Wait for user input

    // Clean up
    delwin(lvl_win);
}