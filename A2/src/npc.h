#ifndef NPC_H
#define NPC_H

#include <ncurses.h>

#define DAVE_HEIGHT 2
#define DAVE_WIDTH 7

extern const char *dave_face[];

WINDOW* npc_init(int parent_height, int parent_width);

void draw_dave_face(WINDOW *npc_win);

void dave_says(WINDOW *npc_win, const char *line1, const char *line2, const char *line3);

#endif
