#ifndef GAMECARDS_H
#define GAMECARDS_H

#include <ncurses.h>

void titleCard(WINDOW *win);
void menuCard(WINDOW *win);
void quitCard(WINDOW *win);
void level1Card(WINDOW *win);
void level2Card(WINDOW *win);
void retryCard(WINDOW *win);
void pauseCard(WINDOW *win);

#endif
