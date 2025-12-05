#ifndef NPC_H
#define NPC_H

#include <ncurses.h>

/**
 * @file npc.h
 * @brief Non-player character (NPC) utilities and drawing helpers.
 * @author Mohit Saroya
 * Declares layout constants, NPC art data and functions used to initialize
 * an NPC window and draw NPC content such as Dave's face, a "lost" NPC,
 * and dialog lines.
 */

/** @brief Height in rows for Dave's face artwork. */
#define DAVE_HEIGHT 2

/** @brief Width in columns for Dave's face artwork. */
#define DAVE_WIDTH 7

/** @brief ASCII-art for Dave's face (array of C strings). */
extern const char *dave_face[];

/** @brief Lines used when an NPC indicates the player is lost. */
extern const char *lost_player[];

/** @brief State flag used by NPC dialogue/behavior. */
extern int lost_state;

/**
 * @brief Initialize an NPC window sized relative to the parent.
 *
 * Allocates and returns a new ncurses `WINDOW` suitable for drawing NPC
 * art/dialog. The window size is computed from `parent_height` and
 * `parent_width` (caller still owns and should eventually destroy the window).
 *
 * @param parent_height Height (rows) of the parent region or terminal.
 * @param parent_width Width (columns) of the parent region or terminal.
 * @return WINDOW* Pointer to the newly created NPC window (or NULL on error).
 */
WINDOW* npc_init(int parent_height, int parent_width);

/**
 * @brief Draw Dave's small ASCII face inside `npc_win`.
 * @param npc_win Window to draw the face into.
 */
void draw_dave_face(WINDOW *npc_win);

/**
 * @brief Draw a "lost" NPC at the specified coordinates inside `mazewin`.
 *
 * This helper draws two-line artwork at rows `first_y` and `second_y` and a
 * fixed column `fixed_x`. `player_input` can be used to vary the drawing
 * depending on player actions (for example, to animate or flip the art).
 *
 * @param mazewin Parent window where the NPC should be drawn.
 * @param first_y Row index for the first line of the NPC art.
 * @param second_y Row index for the second line of the NPC art.
 * @param fixed_x Column index where the art should be anchored.
 * @param player_input Input/state value from the player to vary the drawing.
 */
void draw_lost_npc (WINDOW *mazewin, int first_y, int second_y, int fixed_x, int player_input);

/**
 * @brief Display up to three lines of dialog in the NPC window.
 *
 * Each of `line1`, `line2` and `line3` may be a C string or NULL. The
 * function formats and prints the provided lines inside `npc_win`.
 *
 * @param npc_win Window used to display dialog.
 * @param line1 First line of dialog (or NULL).
 * @param line2 Second line of dialog (or NULL).
 * @param line3 Third line of dialog (or NULL).
 */
void dave_says(WINDOW *npc_win, const char *line1, const char *line2, const char *line3);

#endif
