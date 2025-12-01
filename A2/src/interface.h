#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>
#define WIDTH_MAX 100
#define HEIGHT_MAX 40
#define BORDER 2

#define EXIT 111
#define MENU 222
#define QUIT 333
#define P 123
#define NEXT 456

WINDOW *make_window(int h, int w, int y, int x);
void title_screen(void);
int main_menu(void);
void pause_screen(void);
int handle_pause_menu(WINDOW *gamewin);
int quitScreen(WINDOW *parent);
void goodBye(WINDOW *parent);
#endif