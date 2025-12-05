/*********************************
* @File level1.c
* @Brief Definition of the function of level1.h
* @Author Evan Wong
* @Date dec.4,2025
********************************/
#include <ncurses.h>
#include "maze.h"
#include "level1.h"
#include "interface.h"  
#include "movement.h"
#include "gameCards.h"
#include "npc.h"

int first_level_maze(void)
{
    erase();// wipes the screen
    refresh();

    WINDOW *l1 = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);//makes the boarder around the game

    mvwprintw(l1, 2, 2, "Use arrow keys to move");// creates commands for the game
    mvwprintw(l1, 3, 2, "Press P to pause the game");
    mvwprintw(l1, 4, 2, "Reach '$' to proceed to the next level");


    WINDOW *npc_win = npc_init(HEIGHT_MAX-2, WIDTH_MAX-2);//boarder around the npc text
    draw_dave_face(npc_win);// makes the npc face
    //used to save the user inputs and character movements
    int ch;
    movement m;

    int start_y = (HEIGHT_MAX - HEIGHT_MAZE1) / 2 - 3;
    int start_x = (WIDTH_MAX - WIDTH_MAZE1) / 2;

    draw_maze(l1, HEIGHT_MAZE1, WIDTH_MAZE1, start_y, start_x);// makes a box
    maze1(l1, start_y, start_x);// fills the box with maze objects
    m = make_player(start_y + 1, start_x + 1, l1);// used to make the player character

    ExitPoint ep = create_exit_point(start_y, start_x, HEIGHT_MAZE1, WIDTH_MAZE1);// creates an argument that allows the player to leave the maze
    draw_exit_point(l1, ep);// makes the exit $

    keypad(l1, TRUE);// allows the usage of special keys

    dave_says(npc_win,
              "Hi I'm dave and I'm evil muhehehehe",
              "I've trapped you in this maze! Find a way to escape if you can...",
              NULL);// what the npc says


    while (1) {
        chtype next;
        ch = wgetch(l1);// saves user inputs

        if (ch == KEY_RIGHT) {// all the KEY moves the character, delete the character was originally in, and saves the movement
            next = mvwinch(l1, m.y, m.x + 1) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_right(m);
        }
        else if (ch == KEY_LEFT) {
            next = mvwinch(l1, m.y, m.x - 1) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_left(m);
        }
        else if (ch == KEY_UP) {
            next = mvwinch(l1, m.y - 1, m.x) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_up(m);
        }
        else if (ch == KEY_DOWN) {
            next = mvwinch(l1, m.y + 1, m.x) & A_CHARTEXT;
            if (next == ' ' || next == '$')
                m = move_down(m);
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
                if (next_ch == 'x' || next_ch == 'X') {//character needed to leave the maze by pressing x
                    return NEXT;
                } 
            }
        }

        else if (ch == 'p' || ch == 'P')
        {
            int pause_result = 0;
                while (1) {// this while loop opens up a pause screen and excute function depending on what was pressed
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
    level1Card(level1Win);// calls for the level 1 splash screen
    getch();
    delwin(level1Win);

    refresh();

    int res = first_level_maze();// this calls first_level_maze() to make the game

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

