#include "movement.h"
#include <ncurses.h>

movement make_player(int y, int x, WINDOW *win)
{
    movement m = { x, y, win };
    mvwaddch(win, y, x, '@');
    wrefresh(win);
    return m;
}

movement move_right(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.x++;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}

movement move_left(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.x--;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}

movement move_up(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.y--;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}

movement move_down(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');
    m.y++;
    mvwaddch(m.win, m.y, m.x, '@');
    wrefresh(m.win);
    return m;
}
