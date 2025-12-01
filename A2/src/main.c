#include <ncurses.h>
#include "interface.h"
#include "level1.h"
#include "level2.h"

int main(void) {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    refresh();

    title_screen();

    while (1) {
        int decision = main_menu();
        if (decision == P) {
            
            // Run Level 1 once
            int lvl1_result = level1Phase();
            if (lvl1_result == NEXT) {
                
                // Run Level 2 once
                int lvl2_result = level2Phase();
                if (lvl2_result == NEXT) {
                    break;
                }
                else if (lvl2_result == MENU) {
                    continue;
                }
                else if (lvl2_result == QUIT) {
                    break;
                }
            }
            else if (lvl1_result == MENU) {
                continue;
            }
            else if (lvl1_result == QUIT) {
                break;
            }
        }
        else if (decision == QUIT) {
            break;
        }
    }

    goodBye(stdscr);
    endwin();
    return 0;
}
