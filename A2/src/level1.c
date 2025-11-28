#include <ncurses.h>
#include "movement.h"
#include "maze.h"
#include "interface.h"
#include "level1.h"

#define HEIGHT_MAZE1 20
#define WIDTH_MAZE1 40

int first_level(void)
{
    erase();
    refresh();

    WINDOW *l1 = make_window(HEIGHT_MAX, WIDTH_MAX, BORDER, BORDER);

    int ch;
    movement m;

    int start_y = (HEIGHT_MAX - HEIGHT_MAZE1) / 2;
    int start_x = (WIDTH_MAX - WIDTH_MAZE1) / 2;

    draw_maze(l1, HEIGHT_MAZE1, WIDTH_MAZE1, start_y, start_x);

    m = make_player(start_y + 1, start_x + 1, l1);

    keypad(l1, TRUE);

    ch = wgetch(l1);

    while (1) {
        if (ch == KEY_RIGHT && mvwinch(l1, m.y, m.x + 1) == ' ')
            m = move_right(m);
        else if (ch == KEY_LEFT && mvwinch(l1, m.y, m.x - 1) == ' ')
            m = move_left(m);
        else if (ch == KEY_UP && mvwinch(l1, m.y - 1, m.x) == ' ')
            m = move_up(m);
        else if (ch == KEY_DOWN && mvwinch(l1, m.y + 1, m.x) == ' ')
            m = move_down(m);
        else if (ch == 'q')
            break;

        ch = wgetch(l1);
        wrefresh(l1);
    }

    return 0;
}
