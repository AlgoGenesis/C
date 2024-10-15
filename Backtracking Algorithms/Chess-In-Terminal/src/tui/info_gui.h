#ifndef INFO_GUI_H
#define INFO_GUI_H

#include "board_gui.h"
#include "gui_geom.h"
#include "ncurses.h"
#include "notation.h"
WINDOW *win_info;

const int default_info_axis_0_size = 0;
const int default_info_axis_1_size = 12;
const int default_axis_1_cursor = 0;

char **info_ptr;
int info_axis_0_size;
int info_axis_1_size;
int axis_1_cursor;

void new_win_info(void) {
    int starty = (LINES - WIN_HEIGHT) / 2;
    int startx = ((COLS - WIN_WIDTH) / 2) + WIN_WIDTH + 1;
    win_info = newwin(WIN_HEIGHT, 2 * WIN_WIDTH / 3, starty, startx);
    box(win_info, 0, 0);
    wrefresh(win_info);
}

void init_info_data(void) {
    info_ptr = malloc(sizeof(char *));
    info_axis_0_size = default_info_axis_0_size;
    info_axis_1_size = default_info_axis_1_size;
    axis_1_cursor = default_axis_1_cursor;
}

void update_info_data(Game g) {
    if (info_ptr == NULL)
        init_info_data();

    char tmp[10];
    notate_move(g, last_x1, last_y1, last_x2, last_y2, last_move_type, tmp);
    if (g.move_number % 2 == 0) {
        info_axis_0_size++;
        void *rtn = realloc(info_ptr, info_axis_0_size * sizeof(char *));
        if (rtn == NULL) {
            exit(1);
        }
        info_ptr = rtn;
        info_ptr[info_axis_0_size - 1] =
            malloc(info_axis_1_size * sizeof(char));
        sprintf(info_ptr[info_axis_0_size - 1], "%d. %s", g.move_number / 2,
                tmp);
    } else {
        sprintf(info_ptr[info_axis_0_size - 1], "%s %s",
                info_ptr[info_axis_0_size - 1], tmp);
    }
}

void update_info_gui(void) {
    int i = 0;
    int start_ix = 0;
    int max_y = getmaxy(win_info) - 2;
    if (info_axis_0_size > max_y)
        start_ix = info_axis_0_size - max_y;

    wclear(win_info);
    box(win_info, 0, 0);
    while (start_ix + i < info_axis_0_size && i < max_y) {
        mvwprintw(win_info, i + 1, 1, "%s", info_ptr[start_ix + i]);
        i++;
    }
    wrefresh(win_info);
}

void update_info_event(Game g) {
    update_info_data(g);
    update_info_gui();
}

#endif
