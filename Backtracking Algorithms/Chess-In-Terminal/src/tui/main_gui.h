#ifndef MAIN_GUI_H
#define MAIN_GUI_H
#define MENU_WIDTH 20
#define MENU_HEIGHT (N_CHOICES + 2)
#define MENU_STARTX ((COLS - MENU_WIDTH) / 2)
#define MENU_STARTY ((LINES - MENU_HEIGHT) / 2)
#define TITLE_PAD 3
#define TITLE_BORDERY 2
#define TITLE_BORDERX 3
#define TITLE_BORDER_XSCALE 3

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "gui_utils.h"

typedef enum {
    ONE_PLAYER,
    TWO_PLAYER,
    QUIT,
} Choices;

int CHOICES[] = {
    // ONE_PLAYER
    TWO_PLAYER, QUIT};
char *CHOICE_LABELS[] = {
    //"One Player",
    "Two Player", "Quit"};
int N_CHOICES = sizeof(CHOICES) / sizeof(int);
char LEFT_FOOTER[] = "Licensed under GPL-3.0 in 2023";
char RIGHT_FOOTER[] = "github.com/billyvinning/nchess";
wchar_t *TITLE[] = {L"┌┐┌┌─┐┬ ┬┌─┐┌─┐┌─┐", L"││││  ├─┤├┤ └─┐└─┐",
                    L"┘└┘└─┘┴ ┴└─┘└─┘└─┘"};

void print_scr(void) {
    int title_nrows = (sizeof(TITLE) / sizeof(TITLE[0]));
    int title_ncols = wcslen(TITLE[0]);
    int title_starty = MENU_STARTY - title_nrows - TITLE_PAD;
    int title_startx = (COLS - title_ncols) / 2;
    // Print border around title
    int max_x = (title_ncols + (2 * TITLE_BORDERX));
    max_x -= max_x % TITLE_BORDER_XSCALE;
    for (int y = 0; y < (title_nrows + (2 * TITLE_BORDERY)); y++) {
        for (int x = 0; x < max_x; x++) {
            if (is_white_square(x / TITLE_BORDER_XSCALE, y))
                attron(A_REVERSE);
            mvprintw(y + title_starty - TITLE_BORDERY,
                     x + title_startx - TITLE_BORDERX, " ");
            if (is_white_square(x / TITLE_BORDER_XSCALE, y))
                attroff(A_REVERSE);
        }
    }

    // Print title
    for (int y = 0; y < title_nrows; y++) {
        mvaddwstr(y + title_starty, title_startx, TITLE[y]);
    }
    // Print header and footer
    mvprintw(LINES - 1, 0, "%s", LEFT_FOOTER);
    mvprintw(LINES - 1, COLS - strlen(RIGHT_FOOTER), "%s", RIGHT_FOOTER);
    refresh();
}

WINDOW *create_newwin(void) {
    int height = N_CHOICES + 2;
    int width = 20;
    WINDOW *win = newwin(MENU_HEIGHT, MENU_WIDTH, MENU_STARTY, MENU_STARTX);
    keypad(win, TRUE);

    box(win, 0, 0);
    wrefresh(win);
    return win;
}

void print_menu(WINDOW *win, int selected_choice) {
    for (int i = 0; i < N_CHOICES; i++) {
        int x = (getmaxx(win) - strlen(CHOICE_LABELS[i])) / 2;
        if (i == selected_choice)
            wattron(win, A_REVERSE);
        mvwprintw(win, i + 1, x, "%s", CHOICE_LABELS[i]);
        if (i == selected_choice)
            wattroff(win, A_REVERSE);
    }
    wrefresh(win);
}

int run_main_gui() {

    print_scr();
    WINDOW *win;
    win = create_newwin();
    MEVENT event;
    int selected_choice = 0;
    print_menu(win, selected_choice);
    while (1) {
        switch (wgetch(win)) {
        case KEY_UP:
            if (selected_choice-- == 0)
                selected_choice = N_CHOICES - 1;
            break;
        case KEY_DOWN:
            if (selected_choice++ == N_CHOICES - 1)
                selected_choice = 0;
            break;
        case KEY_MOUSE:
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_PRESSED) {
                    if (!wmouse_trafo(win, &event.y, &event.x, false))
                        break;
                }
            }
            break;
        case '\n':
        case ' ':
            delwin(win);
            return CHOICES[selected_choice];
        default:
            break;
        }
        print_menu(win, selected_choice);
    }
}

#endif
