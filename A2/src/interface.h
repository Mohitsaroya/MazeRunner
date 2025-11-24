#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>

WINDOW *make_window(int h, int w, int y, int x);
void title_screen(void);
int quitScreen(WINDOW *win);
int main_menu(void);
void goodBye(WINDOW *win);
void first_level(void);
void second_level(void);

#endif