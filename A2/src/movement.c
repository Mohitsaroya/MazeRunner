#include <ncurses.h>
#include "movement.h"

movement make_player() {
    movement m;
    m.x = 1;
    m.y = 1;
    mvaddch(m.y, m.x, '@');
    return m;
}

movement move_right(movement m) {
    mvaddch(m.y, m.x, ' ');
    mvaddch(m.y, m.x + 1, '@');
    m.x += 1;
    return m;
}

movement move_left(movement m) {
    mvaddch(m.y, m.x, ' ');
    mvaddch(m.y, m.x - 1, '@');
    m.x -= 1;
    return m;
}

movement move_up(movement m) {
    mvaddch(m.y, m.x, ' ');
    mvaddch(m.y - 1, m.x, '@');
    m.y -= 1;
    return m;
}

movement move_down(movement m) {
    mvaddch(m.y, m.x, ' ');
    mvaddch(m.y + 1, m.x, '@');
    m.y += 1;
    return m;
}
