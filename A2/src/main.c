#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "title.h"

void title_screen() {
    // when ran, this is going to be the title screen that when interacted with takes you to the main menu
    initscr();
    WINDOW *win = newwin(40,100,2,2);
    refresh();

    box(win, '-', '/');
    wrefresh(win);
    MazaRunner(win);
    getch();
    endwin();
    return;
}

void end_game(void) {
    // the ending sequence (display summary ig)
    return;
}

void first_level() {
    // code for all the first level goes in here
    return;
}

void second_level() {
    // code for all the second level goes in here
    return;
}

void main_menu() {
    title_screen();
    return;
}

int main(void) {
    // only going to call the functions
    main_menu();
    return 0;
}
