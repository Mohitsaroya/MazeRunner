#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include "main.h"


void title_screen() {
    // when ran, this is going to be the title screen that when interacted with takes you to the main menu
    initscr();
    WINDOW *win = newwin(25,120,2,2);
    refresh();

    box(win, '-', '/');
    wrefresh(win);

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
    // the main menu, gives the option to start the game or end the program
    return;
}

int main(void) {
    // only going to call the functions
    title_screen();
    return 0;
}
