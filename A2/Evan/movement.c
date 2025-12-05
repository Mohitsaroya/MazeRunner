/**************************
* @File movement.c
* @Brief defintion of the functions in movement.h
* @Author Evan Wong
* @Date Dec.4,2025
***********************/
#include "movement.h"
#include <ncurses.h>

movement make_player(int y, int x, WINDOW *win)
{
    movement m = { x, y, win };
    mvwaddch(win, y, x, '@');// makse the player characer
    wrefresh(win);
    return m;
}

movement move_right(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');// empty space on player original place
    m.x++;// updatse x coordinates
    mvwaddch(m.win, m.y, m.x, '@');// prints charater to the right
    wrefresh(m.win);
    return m;
}

movement move_left(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');// empty space on the player original place
    m.x--;// updates x coordinates
    mvwaddch(m.win, m.y, m.x, '@');// prints character to the left
    wrefresh(m.win);
    return m;
}

movement move_up(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');// empty space on the player original place
    m.y--;// updatese y coordinates
    mvwaddch(m.win, m.y, m.x, '@');// prints character tup
    wrefresh(m.win);
    return m;
}

movement move_down(movement m)
{
    mvwaddch(m.win, m.y, m.x, ' ');// empty space on the player original place
    m.y++;// updates y coordinates
    mvwaddch(m.win, m.y, m.x, '@');// print characyer down
    wrefresh(m.win);
    return m;
}
