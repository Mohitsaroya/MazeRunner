#include "npc.h"
#include "maze.h"
#include <ncurses.h>

const char *dave_face[] = {
    "  _ _  ",
    " (O_O) "
};

void draw_dave_face(WINDOW *npc_win) {
    for (int i = 0; i < DAVE_HEIGHT; i++) {
        mvwprintw(npc_win, i + 1, 2, "%s", dave_face[i]);
    }
    wrefresh(npc_win);
}


WINDOW* npc_init(int parent_height, int parent_width) {
    int dialogue_height = parent_height * 0.15;
    int dialogue_start_y = parent_height - (dialogue_height - 3);
    int dialogue_width = parent_width-5;
    int dialogue_start_x = 5;

    WINDOW *npc_win = newwin(dialogue_height, dialogue_width, dialogue_start_y, dialogue_start_x);
    box(npc_win, 0, 0);
    wrefresh(npc_win);
    return npc_win;
}

void dave_says(WINDOW *npc_win, const char *line1, const char *line2, const char *line3) {
    werase(npc_win);
    box(npc_win, 0, 0);

    draw_dave_face(npc_win);

    int text_col = DAVE_WIDTH + 4; // leave space for face
    if (line1) mvwprintw(npc_win, 1, text_col, "%s", line1);
    if (line2) mvwprintw(npc_win, 2, text_col, "%s", line2);
    if (line3) mvwprintw(npc_win, 3, text_col, "%s", line3);

    wrefresh(npc_win);
}