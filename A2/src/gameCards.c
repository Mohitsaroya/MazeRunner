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
    
    mvwprintw(win, 18, 20, " ______     __    __    ____     __    ____     __    _______    ______");
    mvwprintw(win, 19, 20, "|      \\   |  |  |  |  |    \\   |  |  |    \\   |  |  |   ____|  |      \\");
    mvwprintw(win, 20, 20, "|  |0|  |  |  |  |  |  |     \\  |  |  |     \\  |  |  |  |__     |  |0|  |");
    mvwprintw(win, 21, 20, "|    __/   |  |  |  |  |  |\\  \\ |  |  |  |\\  \\ |  |  |   __|    |    __/");
    mvwprintw(win, 22, 20, "|  |\\  \\   |  |  |  |  |  | \\  \\|  |  |  | \\  \\|  |  |  |       |  |\\  \\");
    mvwprintw(win, 23, 20, "|  | |  |  |  \\__/  |  |  |  \\     |  |  |  \\     |  |  |____   |  | |  |");
    mvwprintw(win, 24, 20, "|__| |__|   \\______/   |__|   \\____|  |__|   \\____|  |_______|  |__| |__|");


    mvwprintw(win, 35, 60, "Press any key to continue...");
}

// ASCII art for menu
void menuCard(WINDOW *win) {
    mvwprintw(win, 7, 15, " __        __                 _________   _______");
    mvwprintw(win, 8, 15, "|   \\    /   |      /\\       |_____   /  |   ____|");
    mvwprintw(win, 9, 15, "|    \\  /    |     /  \\          /   /   |  |__");
    mvwprintw(win, 10, 15, "|  |  \\/  |  |    /    \\        /   /    |   __|");
    mvwprintw(win, 11, 15, "|  |      |  |   /  /\\  \\      /   /     |  |");
    mvwprintw(win, 12, 15, "|  |      |  |  /  /  \\  \\    /   /___   |  |____");
    mvwprintw(win, 13, 15, "|__|      |__| /__/    \\__\\  /________|  |_______|");
    
    mvwprintw(win, 15, 20, " ______     __    __    ____     __    ____     __    _______    ______");
    mvwprintw(win, 16, 20, "|      \\   |  |  |  |  |    \\   |  |  |    \\   |  |  |   ____|  |      \\");
    mvwprintw(win, 17, 20, "|  |0|  |  |  |  |  |  |     \\  |  |  |     \\  |  |  |  |__     |  |0|  |");
    mvwprintw(win, 18, 20, "|    __/   |  |  |  |  |  |\\  \\ |  |  |  |\\  \\ |  |  |   __|    |    __/");
    mvwprintw(win, 19, 20, "|  |\\  \\   |  |  |  |  |  | \\  \\|  |  |  | \\  \\|  |  |  |       |  |\\  \\");
    mvwprintw(win, 20, 20, "|  | |  |  |  \\__/  |  |  |  \\     |  |  |  \\     |  |  |____   |  | |  |");
    mvwprintw(win, 21, 20, "|__| |__|   \\______/   |__|   \\____|  |__|   \\____|  |_______|  |__| |__|");

    mvwprintw(win, 25, 46, "PLAY_(P)");
    mvwprintw(win, 28, 46, "QUIT_(Q)");
}

// ASCII art for quit confirmation
void quitCard(WINDOW *win) {
    mvwprintw(win, 15, 25, " ________    __    __    ______    ______    _____");
    mvwprintw(win, 16, 25, "/   __   \\  |  |  |  |  |__  __|  |__  __|  |__   \\");
    mvwprintw(win, 17, 25, "|  |  |  |  |  |  |  |    |  |      |  |       \\   |");
    mvwprintw(win, 18, 25, "|  |  |  |  |  |  |  |    |  |      |  |       /  /");
    mvwprintw(win, 19, 25, "|  | _|  |  |  |  |  |    |  |      |  |      |__|");
    mvwprintw(win, 20, 25, "|  \\_\\ \\ |  |  \\__/  |  __|  |__    |  |       __");
    mvwprintw(win, 21, 25, "\\_____\\ \\    \\______/   |______|    |__|      |__|");
    mvwprintw(win, 22, 25, "       \\_\\");
    
}
