/**
 * @file npc.c
 * @brief NPC drawing and dialog helpers for MazeRunner.
 * @author Mohit Saroya
 * Defines ASCII art for a simple NPC (Dave), manages a small NPC window and
 * provides utilities to render the NPC face, a "lost" indicator, and dialog
 * lines.
 */

#include "npc.h"
#include "maze.h"
#include <ncurses.h>

const char *dave_face[] = {
    "  _ _  ",
    " (O_O) "
};

const char *lost_player[] = {
    "*"
};

int lost_state = 0;

/**
 * @brief Draw Dave's face into the provided NPC window.
 *
 * The face artwork is defined in `dave_face` and drawn starting at row 1,
 * column 2 of `npc_win`. The window is refreshed after drawing.
 *
 * @param npc_win ncurses window to draw the face into.
 */
void draw_dave_face(WINDOW *npc_win) {
    for (int i = 0; i < DAVE_HEIGHT; i++) {
        mvwprintw(npc_win, i + 1, 2, "%s", dave_face[i]);
    }
    wrefresh(npc_win);
}

/**
 * @brief Draw a simple "lost" NPC indicator in the maze window.
 *
 * The function optionally toggles the `lost_state` when `player_input` is
 * non-zero to animate the indicator between `first_y` and `second_y` rows.
 * It clears previous characters at the anchor column before drawing the
 * current indicator and refreshes the parent window.
 *
 * @param mazewin Parent maze window where the indicator should be drawn.
 * @param first_y Row index for the first indicator position.
 * @param second_y Row index for the second indicator position.
 * @param fixed_x Column position to draw the indicator.
 * @param player_input Non-zero to toggle animation state, zero to leave it.
 */
void draw_lost_npc (WINDOW *mazewin, int first_y, int second_y, int fixed_x, int player_input) {
    if (player_input) {
        lost_state = !lost_state;
    }
    mvwprintw(mazewin, first_y,  fixed_x, " ");
    mvwprintw(mazewin, second_y, fixed_x, " ");
    int y = (lost_state == 0)? first_y : second_y;
    mvwprintw(mazewin, y, fixed_x, "%s", lost_player[0]);
    wrefresh(mazewin);
}


/**
 * @brief Initialize and return an NPC dialog window sized relative to parent.
 *
 * The dialog height is computed as approximately 15% of the parent height
 * and is positioned near the bottom of the parent region. The returned window
 * is boxed and refreshed before being returned. Caller is responsible for
 * destroying the window when no longer needed.
 *
 * @param parent_height Height (rows) of the parent region or terminal.
 * @param parent_width Width (columns) of the parent region or terminal.
 * @return WINDOW* Newly created npc window, or NULL on allocation failure.
 */
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

/**
 * @brief Display up to three dialog lines from Dave inside `npc_win`.
 *
 * The function clears the NPC window, draws a box, renders Dave's face and
 * then prints the provided text lines to the right of the face area. Any of
 * `line1`/`line2`/`line3` may be NULL to skip that line.
 *
 * @param npc_win Window used to display dialog.
 * @param line1 First line of dialog (or NULL).
 * @param line2 Second line of dialog (or NULL).
 * @param line3 Third line of dialog (or NULL).
 */
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