#ifndef RULES_H
#define RULES_H

#include "game.h"
#include "geom.h"
#include "pieces.h"
#include "players.h"
#include <stdbool.h>

#define ADJ_M_WIDTH N_RANKS *N_FILES

typedef enum {
    INVALID_MOVE = 0,
    REGULAR_MOVE = 1,
    TAKING_MOVE = 2,
    CASTLING = 3,
    ENPASSANT = 4
} MoveCodes;

int transform_to_adj(int i, int j) { return i + (N_RANKS * j); }

void transform_from_adj(int v, int *x, int *y) {
    int i = v % N_RANKS;
    int j = (v - i) / N_RANKS;
    *x = i;
    *y = j;
}

void add_directional_edges(int m[][ADJ_M_WIDTH], board b, int x0, int y0,
                           int dx, int dy, int max_steps) {
    int x, y, curr_node, curr_node_owner;
    int src_node_owner = get_piece_owner(b[y0][x0]);
    int src_node = transform_to_adj(x0, y0);

    int n_steps = 1;
    int prev_node = src_node;
    while (1) {
        x = x0 + (dx * n_steps);
        y = y0 + (dy * n_steps);
        if (x < 0 || x >= N_FILES || y < 0 || y >= N_RANKS)
            break;
        curr_node = transform_to_adj(x, y);
        curr_node_owner = get_piece_owner(b[y][x]);

        if (curr_node_owner != src_node_owner) {
            if (curr_node_owner == flip_player(src_node_owner))
                m[prev_node][curr_node] = TAKING_MOVE;
            else
                m[prev_node][curr_node] = REGULAR_MOVE;
        }
        if (curr_node_owner != NOOWNER) { // Blocking piece
            break;
        }

        prev_node = curr_node;
        n_steps++;
        if (max_steps != -1 && n_steps > max_steps)
            break;
    }
}

void add_diag_edges(int m[][ADJ_M_WIDTH], board b, int x0, int y0,
                    int max_steps) {
    const int dx[] = {1, -1, -1, 1};
    const int dy[] = {1, 1, -1, -1};
    for (int i = 0; i < (sizeof(dx) / sizeof(int)); i++) {
        add_directional_edges(m, b, x0, y0, dx[i], dy[i], max_steps);
    }
}

void add_straight_edges(int m[][ADJ_M_WIDTH], board b, int x0, int y0,
                        int max_steps) {
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < (sizeof(dx) / sizeof(int)); i++) {
        add_directional_edges(m, b, x0, y0, dx[i], dy[i], max_steps);
    }
}

void add_pawn_like_edges(int m[][ADJ_M_WIDTH], board b, int game_meta, int x0,
                         int y0) {
    int curr_node, direction, can_enpassant, enpassant_rank, x;
    int src_owner = get_piece_owner(b[y0][x0]);
    int src_node = transform_to_adj(x0, y0);
    bool is_on_back_rank = false;
    if (src_owner == WHITE) {
        can_enpassant = game_meta & WHITE_CAN_ENPASSANT;
        enpassant_rank = BLACK_PAWN_ORIGIN + 1;
        is_on_back_rank = y0 == WHITE_PAWN_ORIGIN;
        direction = -1;
    } else if (src_owner == BLACK) {
        can_enpassant = game_meta & BLACK_CAN_ENPASSANT;
        enpassant_rank = WHITE_PAWN_ORIGIN - 1;
        is_on_back_rank = y0 == BLACK_PAWN_ORIGIN;
        direction = 1;
    } else {
        return;
    }

    int y = y0 + 2 * direction;
    if (is_on_back_rank && b[y][x0] == EMPTY_SQUARE) {
        curr_node = transform_to_adj(x0, y);
        m[src_node][curr_node] = REGULAR_MOVE;
    }
    y = y0 + direction;
    if (b[y][x0] == EMPTY_SQUARE) {
        curr_node = transform_to_adj(x0, y);
        m[src_node][curr_node] = REGULAR_MOVE;
    }

    int enpassant_file = get_enpassant_file(game_meta);
    const int dx[] = {1, -1};
    for (int i = 0; i < (sizeof(dx) / sizeof(int)); i++) {
        x = x0 + dx[i];
        if (x < 0 || x >= N_FILES)
            continue;
        curr_node = transform_to_adj(x, y);
        if (b[y][x] == EMPTY_SQUARE && can_enpassant && x == enpassant_file &&
            y == enpassant_rank) {
            m[src_node][curr_node] = ENPASSANT;
        } else if (b[y][x] != EMPTY_SQUARE &&
                   get_piece_owner(b[y][x]) != src_owner) {
            m[src_node][curr_node] = TAKING_MOVE;
        }
    }
}

void add_knight_like_edges(int m[][ADJ_M_WIDTH], board b, int x0, int y0) {
    int x, y, curr_node, curr_node_owner;
    const int dx[] = {1, -1, 2, -2, 2, -2, 1, -1};
    const int dy[] = {2, 2, 1, 1, -1, -1, -2, -2};
    int src_node_owner = get_piece_owner(b[y0][x0]);
    int src_node = transform_to_adj(x0, y0);
    for (int i = 0; i < (sizeof(dx) / sizeof(int)); i++) {
        x = x0 + dx[i];
        y = y0 + dy[i];
        if (x < 0 || x >= N_FILES || y < 0 || y >= N_RANKS)
            continue;
        curr_node_owner = get_piece_owner(b[y][x]);
        if (curr_node_owner != src_node_owner) {
            curr_node = transform_to_adj(x, y);
            if (curr_node_owner == flip_player(src_node_owner))
                m[src_node][curr_node] = TAKING_MOVE;
            else
                m[src_node][curr_node] = REGULAR_MOVE;
        }
    }
}

void add_castling_edges(int m[][ADJ_M_WIDTH], board b, int game_meta, int x0,
                        int y0) {
    int piece_owner = get_piece_owner(b[y0][x0]);
    bool can_castle_kingside =
        ((piece_owner == WHITE && (game_meta & WHITE_CAN_CASTLE_KINGSIDE)) ||
         (piece_owner == BLACK && (game_meta & BLACK_CAN_CASTLE_KINGSIDE)));

    bool can_castle_queenside =
        ((piece_owner == WHITE && (game_meta & WHITE_CAN_CASTLE_QUEENSIDE)) ||
         (piece_owner == BLACK && (game_meta & BLACK_CAN_CASTLE_QUEENSIDE)));

    if (!can_castle_kingside && !can_castle_queenside)
        return;
    int src_node = transform_to_adj(x0, y0);
    if (can_castle_kingside) {
        if (b[y0][x0 + 1] == EMPTY_SQUARE && b[y0][x0 + 2] == EMPTY_SQUARE) {
            int dest_node = transform_to_adj(x0 + 2, y0);
            m[src_node][dest_node] = CASTLING;
        }
    }
    if (can_castle_queenside) {
        if (b[y0][x0 - 1] == EMPTY_SQUARE && b[y0][x0 - 2] == EMPTY_SQUARE &&
            b[y0][x0 - 3] == EMPTY_SQUARE) {
            int dest_node = transform_to_adj(x0 - 2, y0);
            m[src_node][dest_node] = CASTLING;
        }
    }
}

int has_path(int m[][ADJ_M_WIDTH], int source, int dest) {
    if (m[source][dest] != INVALID_MOVE)
        return m[source][dest];
    for (int i = 0; i < ADJ_M_WIDTH; i++) {
        if (m[source][i] != INVALID_MOVE) {
            int rtn = has_path(m, i, dest);
            if (rtn != INVALID_MOVE)
                return rtn;
        }
    }
    return INVALID_MOVE;
}

void fill_adjacency_matrix(board b, int game_meta, int x1, int y1,
                           int m[][ADJ_M_WIDTH]) {
    switch (get_piece_type(b[y1][x1])) {
    case PAWN:
        add_pawn_like_edges(m, b, game_meta, x1, y1);
        break;
    case KNIGHT:
        add_knight_like_edges(m, b, x1, y1);
        break;
    case BISHOP:
        add_diag_edges(m, b, x1, y1, -1);
        break;
    case ROOK:
        add_straight_edges(m, b, x1, y1, -1);
        break;
    case QUEEN:
        add_straight_edges(m, b, x1, y1, -1);
        add_diag_edges(m, b, x1, y1, -1);
        break;
    case KING:
        add_straight_edges(m, b, x1, y1, 1);
        add_diag_edges(m, b, x1, y1, 1);
        add_castling_edges(m, b, game_meta, x1, y1);
        break;
    }
}

int is_valid_piece_move(board b, int game_meta, int x1, int y1, int x2,
                        int y2) {
    int m[ADJ_M_WIDTH][ADJ_M_WIDTH] = {{INVALID_MOVE}};
    fill_adjacency_matrix(b, game_meta, x1, y1, m);
    int i = transform_to_adj(x1, y1);
    int j = transform_to_adj(x2, y2);
    return has_path(m, i, j);
}

void find_players_king(board b, int p, int *x_out, int *y_out) {
    for (int x = 0; x < N_RANKS; x++) {
        for (int y = 0; y < N_FILES; y++) {
            if (b[y][x] == (p | KING)) {
                *x_out = x;
                *y_out = y;
                return;
            }
        }
    }
}

bool is_in_check(board b, int p) {
    if (p == NOOWNER)
        return false;
    int x2, y2;
    find_players_king(b, p, &x2, &y2);
    int game_meta = NULL_META;
    for (int x1 = 0; x1 < N_RANKS; x1++) {
        for (int y1 = 0; y1 < N_FILES; y1++) {
            int p2 = get_piece_owner(b[y1][x1]);
            if (p2 == p || p2 == NOOWNER)
                continue;
            else if (is_valid_piece_move(b, game_meta, x1, y1, x2, y2)) {
                return true;
            }
        }
    }
    return false;
}

int is_valid_move(board b, int game_meta, int x1, int y1, int x2, int y2) {
    int player = get_piece_owner(b[y1][x1]);
    if (player == WHITE && (game_meta & BLACKS_TURN)) {
        return false;
    } else if (player == BLACK && (game_meta & WHITES_TURN)) {
        return false;
    }

    if (b[y1][x1] == EMPTY_SQUARE)
        return INVALID_MOVE;
    else if (x1 == x2 && y1 == y2)
        return INVALID_MOVE;
    else if (get_piece_type(b[y2][x2]) == KING)
        return INVALID_MOVE;
    int rtn = is_valid_piece_move(b, game_meta, x1, y1, x2, y2);
    if (rtn == INVALID_MOVE) {
        return rtn;
    }

    board b_copy = {{INVALID_MOVE}};
    copy_board(b, b_copy);
    b_copy[y2][x2] = b_copy[y1][x1];
    b_copy[y1][x1] = EMPTY_SQUARE;
    if (is_in_check(b_copy, player)) {
        return INVALID_MOVE;
    }

    return rtn;
}
#endif
