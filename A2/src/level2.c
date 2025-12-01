#include <ncurses.h>
#include "maze.h"
#include "level2.h"
#include "interface.h"  
#include "movement.h"
#include "gameCards.h"
#include "npc.h"

int second_level_maze(void)
{
    erase();
    refresh();

    WINDOW *l2 = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);

    mvwprintw(l2, 2, 2, "Use arrow keys to move");
    mvwprintw(l2, 3, 2, "Press P to pause the game");
    mvwprintw(l2, 4, 2, "Reach '$' to proceed to the next level");

    WINDOW *npc_win = npc_init(HEIGHT_MAX - 2, WIDTH_MAX - 2);
    draw_dave_face(npc_win);

    int ch;
    movement m;

    int start_y = (HEIGHT_MAX - HEIGHT_MAZE2) / 2;
    int start_x = (WIDTH_MAX - WIDTH_MAZE2) / 2;

    draw_maze(l2, HEIGHT_MAZE2, WIDTH_MAZE2, start_y, start_x);
    maze2(l2, start_y, start_x);

    m = make_player(start_y + 1, start_x + 1, l2);

    ExitPoint ep = create_exit_point(start_y, start_x, HEIGHT_MAZE2, WIDTH_MAZE2);
    draw_exit_point(l2, ep);

    keypad(l2, TRUE);

    dave_says(npc_win,
              "Hi, I'm dave and I'm evil muhehehehe",
              "If you don't complete the maze, I will blow it up!",
              NULL);

    ch = wgetch(l2);

    while (1)
    {
        chtype next;

        if (ch == KEY_RIGHT)
        {
            next = mvwinch(l2, m.y, m.x + 1) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_right(m);
        }
        else if (ch == KEY_LEFT)
        {
            next = mvwinch(l2, m.y, m.x - 1) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_left(m);
        }
        else if (ch == KEY_UP)
        {
            next = mvwinch(l2, m.y - 1, m.x) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_up(m);
        }
        else if (ch == KEY_DOWN)
        {
            next = mvwinch(l2, m.y + 1, m.x) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_down(m);
        }
        else if (ch == 'p' || ch == 'P')
        {
            int pause_result = 0;
            while (1) {
                pause_result = handle_pause_menu(l2); // blocks until valid option

                if (pause_result == P) {   // Resume
                    touchwin(l2);
                    wrefresh(l2);
                    touchwin(npc_win);
                    wrefresh(npc_win);
                    break;
                }
                else if (pause_result == MENU) { // Main menu
                    delwin(npc_win);
                    delwin(l2);
                    return MENU;
                }
                else if (pause_result == QUIT) { // Quit
                    delwin(npc_win);
                    delwin(l2);
                    return QUIT;
                }
            }
        }


        wrefresh(l2);
        ch = wgetch(l2);

        if (reached_exit(m.y, m.x, ep))
        {
            dave_says(npc_win,
                      "You found the exit!",
                      "You can finally leave the maze.",
                      NULL);

            wrefresh(l2);
            wgetch(l2);
            delwin(npc_win);
            delwin(l2);
            return 2;
        }
    }

    delwin(npc_win);
    delwin(l2);
    return 0;
}

int level2Phase(void) {
    erase();
    refresh();

    WINDOW *level2Win = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);
    level2Card(level2Win);
    getch();
    delwin(level2Win);

    refresh();

    int res = second_level_maze();

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
