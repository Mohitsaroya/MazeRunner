#include <ncurses.h>
#include "gameCards.h"

// ASCII art for title
void titleCard(WINDOW *win) {
    mvwprintw(win, 10, 15, " __        __                 _________   _______");
    mvwprintw(win, 11, 15, "|   \\    /   |      /\\       |_____   /  |   ____|");
    mvwprintw(win, 12, 15, "|    \\  /    |     /  \\          /   /   |  |__");
    mvwprintw(win, 13, 15, "|  |  \\/  |  |    /    \\        /   /    |   __|");
    mvwprintw(win, 14, 15, "|  |      |  |   /  /\\  \\      /   /     |  |");
    mvwprintw(win, 15, 15, "|  |      |  |  /  /  \\  \\    /   /___   |  |____");
    mvwprintw(win, 16, 15, "|__|      |__| /__/    \\__\\  /________|  |_______|");
    mvwprintw(win, 35, 60, "Press any key to continue...");
}

// ASCII art for menu
void menuCard(WINDOW *win) {
    mvwprintw(win, 5, 15, "== Maze Runner ==");
    mvwprintw(win, 25, 46, "PLAY_(P)");
    mvwprintw(win, 28, 46, "QUIT_(Q)");
}

// ASCII art for quit confirmation
void quitCard(WINDOW *win) {
    mvwprintw(win, 15, 15, "Are you sure you want to quit?");
}
