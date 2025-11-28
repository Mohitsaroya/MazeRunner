#include <ncurses.h>
#include "movement.h"
#include "interface.h"
#include "level1.h"

void maze(void)
{

    for (int y = 0; y < HEIGHT_MAX; y++)
    {
        for (int x = 0; x < WIDTH_MAX; x++)
        {
            if (y == 0 || y == HEIGHT_MAX-1 || x == 0 || x == WIDTH_MAX-1)
                mvaddch(y, x, '#');    // border
            else
                mvaddch(y, x, ' ');    // inside space
        }
    }
    refresh();
}

int first_level(void)
{
    int ch;
    movement m;

    maze();
    m = make_player();

    keypad(stdscr, TRUE);
    ch = getch();
    refresh();

    while (1) {
        if (ch == KEY_RIGHT && mvinch(m.y, m.x+1) == ' ')
            m = move_right(m);

        else if (ch == KEY_LEFT && mvinch(m.y, m.x-1) == ' ')
            m = move_left(m);

        else if (ch == KEY_UP && mvinch(m.y-1, m.x) == ' ')
            m = move_up(m);

        else if (ch == KEY_DOWN && mvinch(m.y+1, m.x) == ' ')
            m = move_down(m);

        else if (ch == 'q')
            break;

        ch = getch();
        refresh();
    }

    return 0;
}
