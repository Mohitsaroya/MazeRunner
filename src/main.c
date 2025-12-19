/**
 * @file main.c
 * @brief Program entry point and top-level control flow for MazeRunner.
 * 
 * Initializes the ncurses environment, displays the title screen, and
 * runs the main menu loop. The main loop calls the level phases
 * (`level1Phase`, `level2Phase`) and responds to their return codes
 * (`NEXT`, `MENU`, `QUIT`) to progress, return to menu, or quit.
 * 
 * @author Mohit Saroya
 */

#include <ncurses.h>
#include "interface.h"
#include "level1.h"
#include "level2.h"

/**
 * @brief Program entry point.
 *
 * Initializes ncurses, presents the title and main menu, and coordinates
 * level execution. The function ensures a clean ncurses teardown via
 * `endwin()` and displays a goodbye screen before exiting.
 *
 * @return int Returns 0 on normal termination.
 */
int main(void) {
    // Initiallizing the game
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    refresh();

    // title screen shown only once when the game is booted up
    title_screen();

    while (1) {
        int decision = main_menu(); // main menu has the option to either play the game or quit
        if (decision == P) {
            
            // Run Level 1, happens when 'p' or 'P' is pressed in the main menu
            int lvl1_result = level1Phase();
            if (lvl1_result == NEXT) {
                
                // Run Level 2, happens when the player completes the first level
                int lvl2_result = level2Phase();
                if (lvl2_result == NEXT) {
                    break; // goes back to the main menu
                }
                else if (lvl2_result == MENU) { // if player pauses the game and wants to go back to main menu in 2nd level
                    continue;
                }
                else if (lvl2_result == QUIT) { // if player pauses the game and wants to quit game in 2nd level
                    break;
                }
            }
            else if (lvl1_result == MENU) { // if player pauses the game and wants to go back to main menu in 1st level
                continue;
            }
            else if (lvl1_result == QUIT) { // if player pauses the game and wants to quit game in 1st level
                break;
            }
        }
        else if (decision == QUIT) { // when player wants to quit game in the main menu itself
            break;
        }
    }

    goodBye(stdscr); // shows a goodbye screen and asks user to enter any key for a clean exit
    endwin();
    return 0;
}
