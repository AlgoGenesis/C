#ifndef BOARD_GUI_H
#define BOARD_GUI_H

#include "board.h"
#include "game.h"
#include "geom.h"
#include "gui_geom.h"
#include "pieces.h"
#include "players.h"
#include "rules.h"

#include <ncurses.h>
#include <stdbool.h>

#define BLACK_PIECE_COLOUR COLOR_RED
#define WHITE_PIECE_COLOUR COLOR_BLUE
#define BLACK_TILE_COLOUR COLOR_BLACK
#define WHITE_TILE_COLOUR COLOR_WHITE
#define WHITE_HIGHLIGHTED_TILE_COLOUR COLOR_CYAN
#define BLACK_HIGHLIGHTED_TILE_COLOUR COLOR_MAGENTA

typedef enum {
    WHITE_TILE = 0x2,
    BLACK_TILE = 0x4,
    WHITE_HIGHLIGHTED_TILE = 0x8,
    BLACK_HIGHLIGHTED_TILE = 0x10
} TileBackgroundType;

enum {
    BOARD_NULL_SIGNAL,
    BOARD_UPDATE_SIGNAL,
    BOARD_MATE_SIGNAL
} BoardSignalType;

MEVENT mevent;
WINDOW *win_board;
int last_move_type, last_x1, last_y1, last_x2, last_y2;
int cursor_x1, cursor_y1, cursor_x2, cursor_y2;
bool is_white_tile(const int i, const int j) { return i % 2 ^ j % 2; }

void transform_to_win(int *x, int *y) {
    *x = (TILE_WIDTH * (*x)) + WIN_PADDING;
    *y = (*y + WIN_PADDING);
}

void transform_to_board(int *x, int *y) {
    *x = (*x - WIN_PADDING) / TILE_WIDTH;
    *y = (*y - WIN_PADDING);
}

bool init_colours(void) {
    const int tile_background_types[] = {
        WHITE_TILE, BLACK_TILE, WHITE_HIGHLIGHTED_TILE, BLACK_HIGHLIGHTED_TILE};
    const int tile_background_colours[] = {WHITE_TILE_COLOUR, BLACK_TILE_COLOUR,
                                           WHITE_HIGHLIGHTED_TILE_COLOUR,
                                           BLACK_HIGHLIGHTED_TILE_COLOUR};

    for (int i = 0; i < sizeof(tile_background_types) / sizeof(int); i++) {
        init_pair(WHITE | tile_background_types[i], WHITE_PIECE_COLOUR,
                  tile_background_colours[i]);
        init_pair(BLACK | tile_background_types[i], BLACK_PIECE_COLOUR,
                  tile_background_colours[i]);
    }
    return true;
}

int get_tile_colour_pair(Game g, int x, int y, bool is_highlighted,
                         int selected_tile_owner) {
    int background_type;
    if (is_highlighted) {
        background_type = selected_tile_owner == WHITE ? WHITE_HIGHLIGHTED_TILE
                                                       : BLACK_HIGHLIGHTED_TILE;
    } else {
        background_type = is_white_tile(x, y) ? WHITE_TILE : BLACK_TILE;
    }

    int tile_owner = get_piece_owner(g.b[y][x]);
    if (tile_owner == NOOWNER)
        tile_owner = g.meta & WHITES_TURN ? WHITE : BLACK;

    return COLOR_PAIR(tile_owner | background_type);
}

int get_tile_attr(Game g, int x, int y, bool is_selected_tile,
                  bool is_cursored_tile, bool is_highlighted_tile,
                  int selected_tile_owner) {
    int attr =
        get_tile_colour_pair(g, x, y, is_highlighted_tile, selected_tile_owner);

    if (is_cursored_tile) { // Is cursor tile
        attr |= A_REVERSE;
    } else if (is_selected_tile) {
        attr |= A_REVERSE | A_BOLD;
    }
    return attr;
}

void draw_board_tile(Game g, int x, int y, bool is_selected_tile,
                     bool is_cursored_tile, bool is_highlighted_tile,
                     int selected_tile_owner) {

    int attr = get_tile_attr(g, x, y, is_selected_tile, is_cursored_tile,
                             is_highlighted_tile, selected_tile_owner);

    int piece_type = get_piece_type(g.b[y][x]);
    char piece_repr = get_piece_repr(piece_type);

    wattron(win_board, attr);
    transform_to_win(&x, &y);
    mvwprintw(win_board, y, x, " %c ", piece_repr);
    wattroff(win_board, attr);
}

void draw_board(Game g) {
    // Highlight dest cursor
    // If src cursor, then highlight.
    int cursor_x1_t = cursor_x1;
    int cursor_y1_t = cursor_y1;
    bool has_selected_tile = cursor_x1 != -1 && cursor_y1 != -1;
    int selected_tile_owner = NOOWNER;
    int m[ADJ_M_WIDTH][ADJ_M_WIDTH] = {{INVALID_MOVE}};
    int i = -1;
    if (has_selected_tile) {
        transform_to_board(&cursor_x1_t, &cursor_y1_t);
        fill_adjacency_matrix(g.b, g.meta, cursor_x1_t, cursor_y1_t, m);
        i = transform_to_adj(cursor_x1_t, cursor_y1_t);
        selected_tile_owner = get_piece_owner(g.b[cursor_y1_t][cursor_x1_t]);
    }
    int cursor_x2_t = cursor_x2;
    int cursor_y2_t = cursor_y2;
    transform_to_board(&cursor_x2_t, &cursor_y2_t);
    for (int y = 0; y < N_FILES; y++) {
        for (int x = 0; x < N_RANKS; x++) {
            bool is_cursored_tile = x == cursor_x2_t && y == cursor_y2_t;
            bool is_selected_tile = x == cursor_x1_t && y == cursor_y1_t;
            bool is_highlighted_tile = false;
            if (has_selected_tile) {
                int j = transform_to_adj(x, y);
                is_highlighted_tile = has_path(m, i, j);
            }
            draw_board_tile(g, x, y, is_selected_tile, is_cursored_tile,
                            is_highlighted_tile, selected_tile_owner);
        }
    }
    wrefresh(win_board);
}

void new_win_board(Game g) {
    init_colours();
    win_board = newwin(WIN_HEIGHT, WIN_WIDTH, (LINES - WIN_HEIGHT) / 2,
                       (COLS - WIN_WIDTH) / 2);
    keypad(win_board, TRUE);
    box(win_board, 0, 0);
    cursor_x1 = -1;
    cursor_y1 = -1;
    cursor_x2 = WIN_PADDING;
    cursor_y2 = WIN_HEIGHT - 1 - WIN_PADDING;
    draw_board(g);
}

int board_state_update_event(Game g) {
    draw_board(g);
    if (g.meta & WHITE_IN_MATE || g.meta & BLACK_IN_MATE)
        return BOARD_MATE_SIGNAL;
    return BOARD_UPDATE_SIGNAL;
}

int board_cursor_update_event(Game g) {
    draw_board(g);
    return BOARD_NULL_SIGNAL;
}

bool is_board_move_accepted(Game *g) {
    int x1_t = cursor_x1;
    int y1_t = cursor_y1;
    int x2_t = cursor_x2;
    int y2_t = cursor_y2;
    transform_to_board(&x1_t, &y1_t);
    transform_to_board(&x2_t, &y2_t);

    int move_type = make_move(g, x1_t, y1_t, x2_t, y2_t);
    if (move_type == INVALID_MOVE)
        return false;

    last_move_type = move_type;
    last_x1 = x1_t;
    last_y1 = y1_t;
    last_x2 = x2_t;
    last_y2 = y2_t;
    return true;
}

bool is_tile_selection_accepted(Game g) {
    int cursor_x2_t = cursor_x2;
    int cursor_y2_t = cursor_y2;
    transform_to_board(&cursor_x2_t, &cursor_y2_t);
    int player = get_piece_owner(g.b[cursor_y2_t][cursor_x2_t]);
    if ((g.meta & WHITES_TURN && player == BLACK) ||
        (g.meta & BLACKS_TURN && player == WHITE))
        return false;

    int m[ADJ_M_WIDTH][ADJ_M_WIDTH] = {{INVALID_MOVE}};
    fill_adjacency_matrix(g.b, g.meta, cursor_x2_t, cursor_y2_t, m);
    int i = transform_to_adj(cursor_x2_t, cursor_y2_t);
    bool has_any_moves = false;
    for (int j = 0; j < ADJ_M_WIDTH; j++) {
        if (i != j && m[i][j] != INVALID_MOVE) {
            has_any_moves = true;
            break;
        }
    }
    return has_any_moves;
}

int board_selection_update_event(Game *g) {
    if (cursor_x1 == -1 && cursor_y1 == -1) {
        if (is_tile_selection_accepted(*g)) {
            cursor_x1 = cursor_x2;
            cursor_y1 = cursor_y2;
            return board_cursor_update_event(*g);
        }
    } else {
        if (is_board_move_accepted(g)) {
            cursor_x1 = -1;
            cursor_y1 = -1;
            return board_state_update_event(*g);
        } else {
            cursor_x1 = -1;
            cursor_y1 = -1;
            return board_cursor_update_event(*g);
        }
    }
    return BOARD_NULL_SIGNAL;
}

int board_driver(int ch, Game *g) {
    switch (ch) {
    case KEY_UP:
        if (cursor_y2 == WIN_PADDING)
            cursor_y2 = WIN_HEIGHT - WIN_PADDING - 1;
        else
            cursor_y2--;
        return board_cursor_update_event(*g);
    case KEY_DOWN:
        if (cursor_y2 == WIN_HEIGHT - WIN_PADDING - 1)
            cursor_y2 = WIN_PADDING;
        else
            cursor_y2++;
        return board_cursor_update_event(*g);
    case KEY_LEFT:
        if (cursor_x2 == 1)
            cursor_x2 = WIN_WIDTH - WIN_PADDING - TILE_WIDTH;
        else
            cursor_x2 -= TILE_WIDTH;
        return board_cursor_update_event(*g);
    case KEY_RIGHT:
        if (cursor_x2 >= WIN_WIDTH - WIN_PADDING - TILE_WIDTH)
            cursor_x2 = WIN_PADDING;
        else
            cursor_x2 += TILE_WIDTH;
        return board_cursor_update_event(*g);
    case KEY_MOUSE:
        if (getmouse(&mevent) == OK) {
            if (mevent.bstate & BUTTON1_PRESSED) {
                if (!wmouse_trafo(win_board, &mevent.y, &mevent.x, false))
                    break;
                cursor_x2 = mevent.x;
                cursor_y2 = mevent.y;
                board_cursor_update_event(*g);
                return board_selection_update_event(g);

            } else if (mevent.bstate & BUTTON3_PRESSED) {
                cursor_x1 = -1;
                cursor_y1 = -1;
                return board_selection_update_event(g);
            }
        }
        break;
    case ' ':
        return board_selection_update_event(g);
    default:
        break;
    }
    return BOARD_NULL_SIGNAL;
}
#endif
