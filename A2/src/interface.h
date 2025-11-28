#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>
#define WIDTH_MAX 100
#define HEIGHT_MAX 40
#define BORDER 2

WINDOW *make_window(int h, int w, int y, int x);
void title_screen(void);
int quitScreen(WINDOW *win);
int main_menu(void);
void goodBye(WINDOW *win);

#endif