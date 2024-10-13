#ifndef GUI_H
#define GUI_H

#include "board_gui.h"
#include "dialog_gui.h"
#include "info_gui.h"
#include <ncurses.h>
#include <stdbool.h>

bool is_board_focused;

void new_game_window(Game g) {
    new_win_board(g);
    new_win_info();
}

void setup(Game g) {
    is_board_focused = false;
    new_game_window(g);
    switch_dialog_mode(DIALOG_START_MODE);
    new_win_dialog(g);
}

void teardown(void) {
    delwin(win_board);
    delwin(win_info);
    delwin(win_dialog);
    endwin();
}

void handle_dialog_signal(Game *g, int signal_type) {
    switch (signal_type) {
    case DIALOG_START_SIGNAL:
        is_board_focused = true;
        switch_dialog_mode(DIALOG_MID_MODE);
        hide_win_dialog();
        break;
    case DIALOG_RESTART_SIGNAL:
        is_board_focused = true;
        init_game(g);
        init_info_data();
        hide_win_dialog();
        new_game_window(*g);
        break;
    case DIALOG_RESUME_SIGNAL:
        is_board_focused = true;
        hide_win_dialog();
        break;
    case DIALOG_EXIT_SIGNAL:
        teardown();
        break;
    }
}
void handle_board_signal(Game g, int signal_type) {
    switch (signal_type) {
    case BOARD_NULL_SIGNAL:
        break;
    case BOARD_UPDATE_SIGNAL:
        update_info_event(g);
        break;
    case BOARD_MATE_SIGNAL:
        update_info_event(g);
        is_board_focused = false;
        switch_dialog_mode(DIALOG_END_MODE);
        new_win_dialog(g);
        break;
    default:
        break;
    }
}

void run_game_gui(Game *g) {
    setup(*g);
    while (1) {
        if (is_board_focused) {
            int ch = wgetch(win_board);
            if (ch == 27) { // Esc or Alt pressed.
                is_board_focused = false;
                switch_dialog_mode(DIALOG_MID_MODE);
                new_win_dialog(*g);
            } else {
                int board_signal_type = board_driver(ch, g);
                handle_board_signal(*g, board_signal_type);
            }
        } else {
            int ch = wgetch(win_dialog);
            int dialog_signal_type = dialog_driver(ch, g);
            if (dialog_signal_type == DIALOG_EXIT_SIGNAL)
                break;
            handle_dialog_signal(g, dialog_signal_type);
        }
    }
    teardown();
}

#endif
