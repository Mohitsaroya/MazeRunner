#ifndef NPC_H
#define NPC_H

#include <ncurses.h>

#define DAVE_HEIGHT 2
#define DAVE_WIDTH 7

extern const char *dave_face[];
extern const char *lost_player[];
extern int lost_state;

WINDOW* npc_init(int parent_height, int parent_width);

void draw_dave_face(WINDOW *npc_win);
void draw_lost_npc (WINDOW *mazewin, int first_y, int second_y, int fixed_x, int player_input);
void dave_says(WINDOW *npc_win, const char *line1, const char *line2, const char *line3);

#endif
