#include <ncurses.h>
#include "maze.h"
#include "level1.h"
#include "interface.h"  
#include "movement.h"
#include "gameCards.h"
#include "npc.h"

int first_level_maze(void)
{
    erase();
    refresh();

    WINDOW *l1 = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);

    mvwprintw(l1, 2, 2, "Use arrow keys to move");
    mvwprintw(l1, 3, 2, "Press P to pause the game");
    mvwprintw(l1, 4, 2, "Reach '$' to proceed to the next level");


    WINDOW *npc_win = npc_init(HEIGHT_MAX-2, WIDTH_MAX-2);
    draw_dave_face(npc_win);

    int ch;
    movement m;

    int start_y = (HEIGHT_MAX - HEIGHT_MAZE1) / 2 - 3;
    int start_x = (WIDTH_MAX - WIDTH_MAZE1) / 2;

    draw_maze(l1, HEIGHT_MAZE1, WIDTH_MAZE1, start_y, start_x);
    maze1(l1, start_y, start_x);
    m = make_player(start_y + 1, start_x + 1, l1);

    ExitPoint ep = create_exit_point(start_y, start_x, HEIGHT_MAZE1, WIDTH_MAZE1);
    draw_exit_point(l1, ep);

    keypad(l1, TRUE);

    dave_says(npc_win,
              "Hi I'm dave and I'm evil muhehehehe",
              "I've trapped you in this maze! Find a way to escape if you can...",
              NULL);
    
    int lost_npc_y1 =  start_y + 5;
    int lost_npc_y2 = start_y + 6;
    int lost_npc_x = start_x + 20;
    
    while (1) {
        ch = wgetch(l1);

        int npc_y1 = lost_npc_y1;
        int npc_x1 = lost_npc_x;

        int npc_y2 = lost_npc_y2;
        int npc_x2 = lost_npc_x;

        if (ch == KEY_RIGHT) {
            int tx = m.x + 1, ty = m.y;

            /* block stepping into either NPC tile */
            if (!((tx == npc_x1 && ty == npc_y1) ||
                (tx == npc_x2 && ty == npc_y2))) {

                chtype next = mvwinch(l1, ty, tx) & A_CHARTEXT;
                if (next == ' ' || next == '$')
                    m = move_right(m);
            }
        }
        else if (ch == KEY_LEFT) {
            int tx = m.x - 1, ty = m.y;

            if (!((tx == npc_x1 && ty == npc_y1) ||
                (tx == npc_x2 && ty == npc_y2))) {

                chtype next = mvwinch(l1, ty, tx) & A_CHARTEXT;
                if (next == ' ' || next == '$')
                    m = move_left(m);
            }
        }
        else if (ch == KEY_UP) {
            int tx = m.x, ty = m.y - 1;

            if (!((tx == npc_x1 && ty == npc_y1) ||
                (tx == npc_x2 && ty == npc_y2))) {

                chtype next = mvwinch(l1, ty, tx) & A_CHARTEXT;
                if (next == ' ' || next == '$')
                    m = move_up(m);
            }
        }
        else if (ch == KEY_DOWN) {
            int tx = m.x, ty = m.y + 1;

            if (!((tx == npc_x1 && ty == npc_y1) ||
                (tx == npc_x2 && ty == npc_y2))) {

                chtype next = mvwinch(l1, ty, tx) & A_CHARTEXT;
                if (next == ' ' || next == '$')
                    m = move_down(m);
            }
        }

        draw_lost_npc(
            l1,
            lost_npc_y1,
            lost_npc_y2,
            lost_npc_x,
            ch
        );

        if ((m.y == npc_y1 && m.x == npc_x1 + 1) || 
            (m.y == npc_y1 && m.x == npc_x1 - 1) ||
            (m.y == npc_y1 + 1 && m.x == npc_x1) ||
            (m.y == npc_y1 - 1 && m.x == npc_x1) ||
            (m.y == npc_y2 && m.x == npc_x2 + 1) || 
            (m.y == npc_y2 && m.x == npc_x2 - 1) ||
            (m.y == npc_y2 + 1 && m.x == npc_x2) ||
            (m.y == npc_y2 - 1 && m.x == npc_x2)) {
            dave_says(npc_win,
                    "Hey! Stay back! That's the lost NPC.",
                    "Don't get too close... He has gone mad",
                    "For years, he has tried to get out of the maze but I put him back in here"
                );
        }

        if (reached_exit(m.y, m.x, ep)) {
            dave_says(npc_win,
                      "You found the exit!",
                      "You can finally leave the maze. But I have something else planned for you...",
                      NULL);
            mvwprintw(l1, 2, 65, "Press 'x' to open the next maze");
            wrefresh(l1);
            while(1) {
                int next_ch = wgetch(l1);
                if (next_ch == 'x' || next_ch == 'X') {
                    return NEXT;
                } 
            }
        }

        else if (ch == 'p' || ch == 'P')
        {
            int pause_result = 0;
                while (1) {
                    pause_result = handle_pause_menu(l1); // blocks until valid option

                    if (pause_result == P) {   // Resume
                        touchwin(l1);
                        wrefresh(l1);
                        touchwin(npc_win);
                        wrefresh(npc_win);
                        break;
                    }
                    else if (pause_result == MENU) { // Main menu
                        delwin(npc_win);
                        delwin(l1);
                        return MENU;
                    }
                    else if (pause_result == QUIT) { // Quit
                        delwin(npc_win);
                        delwin(l1);
                        return QUIT;
                    }
                }
            }
        }

    delwin(npc_win);
    delwin(l1);
    return 0;
}


int level1Phase(void) {
    erase();
    refresh();

    WINDOW *level1Win = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
    level1Card(level1Win);
    getch();
    delwin(level1Win);

    refresh();

    int res = first_level_maze();

    if (res == MENU) {
        return MENU;
    }
    else if (res == QUIT) {
        return QUIT;
    }
    else if (res == NEXT) {
        return NEXT;
    }

    else {
        return MENU;
    }
}