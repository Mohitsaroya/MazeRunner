#include <stdio.h>
#include <ncurses.h>
#include "main.h"
#include "title.h"

void MazaRunner(WINDOW *win) {
    mvwprintw(win, 10, 15, " __        __                 _________   _______");
    mvwprintw(win, 11, 15, "|   \\    /   |      /\\       |_____   /  |   ____|");
    mvwprintw(win, 12, 15, "|    \\  /    |     /  \\          /   /   |  |__");
    mvwprintw(win, 13, 15, "|  |  \\/  |  |    /    \\        /   /    |   __|");
    mvwprintw(win, 14, 15, "|  |      |  |   /  /\\  \\      /   /     |  |");
    mvwprintw(win, 15, 15, "|  |      |  |  /  /  \\  \\    /   /___   |  |____");
    mvwprintw(win, 16, 15, "|__|      |__| /__/    \\__\\  /________|  |_______|");

    mvwprintw(win, 19, 20, " ______    __    __    ____     __    ____     __    _______   ______");
    mvwprintw(win, 20, 20, "|      \\  |  |  |  |  |    \\   |  |  |    \\   |  |  |   ____|  |      \\");
    mvwprintw(win, 21, 20, "|  |O|  | |  |  |  |  |     \\  |  |  |     \\  |  |  |  |__     |  |O|  |");
    mvwprintw(win, 22, 20, "|    __/  |  |  |  |  |  |\\  \\ |  |  |  |\\  \\ |  |  |   __|    |    __/");
    mvwprintw(win, 23, 20, "|  |\\  \\  |  |  |  |  |  | \\  \\|  |  |  | \\  \\|  |  |  |       |  |\\  \\");
    mvwprintw(win, 24, 20, "|  | |  | |  \\__/  |  |  |  \\     |  |  |  \\     |  |  |____   |  | |  |");
    mvwprintw(win, 25, 20, "|__| |__|  \\______/   |__|   \\____|  |__|   \\____|  |_______|  |__| |__|");

    
    mvwprintw(win, 35, 60, "Press any key to continue...");
    wrefresh(win);
}

