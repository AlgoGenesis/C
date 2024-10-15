#ifndef BOARD_H
#define BOARD_H

#include "game.h"
#include "geom.h"
#include "pieces.h"
#include "players.h"
#include "rules.h"
#include <stdbool.h>
#include <stdlib.h>

void init_board(board b) {

    for (int y = 0; y < N_FILES; y++) {
        for (int x = 0; x < N_RANKS; x++) {
            b[y][x] = EMPTY_SQUARE;
        }
    }

    for (int i = 0; i < N_FILES; i++) {
        b[BLACK_PAWN_ORIGIN][i] = BLACK | PAWN;
        b[WHITE_PAWN_ORIGIN][i] = WHITE | PAWN;
    }
    b[BLACK_BACK_RANK][0] = b[BLACK_BACK_RANK][N_FILES - 1] = BLACK | ROOK;
    b[BLACK_BACK_RANK][1] = b[BLACK_BACK_RANK][N_FILES - 2] = BLACK | KNIGHT;
    b[BLACK_BACK_RANK][2] = b[BLACK_BACK_RANK][N_FILES - 3] = BLACK | BISHOP;
    b[BLACK_BACK_RANK][3] = BLACK | QUEEN;
    b[BLACK_BACK_RANK][4] = BLACK | KING;

    b[WHITE_BACK_RANK][0] = b[WHITE_BACK_RANK][N_FILES - 1] = WHITE | ROOK;
    b[WHITE_BACK_RANK][1] = b[WHITE_BACK_RANK][N_FILES - 2] = WHITE | KNIGHT;
    b[WHITE_BACK_RANK][2] = b[WHITE_BACK_RANK][N_FILES - 3] = WHITE | BISHOP;
    b[WHITE_BACK_RANK][3] = WHITE | QUEEN;
    b[WHITE_BACK_RANK][4] = WHITE | KING;
}

typedef struct {
    int move_number;
    board b;
    int meta;
    int n_white_half_points;
    int n_black_half_points;
} Game;

void init_game(Game *g) {
    g->move_number = 1;
    init_board(g->b);
    g->meta = init_game_meta();
}

Game make_game(void) {
    Game g;
    init_game(&g);
    g.n_white_half_points = 0;
    g.n_black_half_points = 0;
    return g;
}

void copy_game(Game src, Game *dest) {
    copy_board(src.b, dest->b);
    dest->meta = src.meta;
    dest->move_number = src.move_number;
}

void reset_enpassant(Game *g, int x, int y) {
    if (g->meta & CAN_ENPASSANT_APAWN)
        g->meta ^= CAN_ENPASSANT_APAWN;
    if (g->meta & CAN_ENPASSANT_BPAWN)
        g->meta ^= CAN_ENPASSANT_BPAWN;
    if (g->meta & CAN_ENPASSANT_CPAWN)
        g->meta ^= CAN_ENPASSANT_CPAWN;
    if (g->meta & CAN_ENPASSANT_DPAWN)
        g->meta ^= CAN_ENPASSANT_DPAWN;
    if (g->meta & CAN_ENPASSANT_EPAWN)
        g->meta ^= CAN_ENPASSANT_EPAWN;
    if (g->meta & CAN_ENPASSANT_FPAWN)
        g->meta ^= CAN_ENPASSANT_FPAWN;
    if (g->meta & CAN_ENPASSANT_GPAWN)
        g->meta ^= CAN_ENPASSANT_GPAWN;
    if (g->meta & CAN_ENPASSANT_HPAWN)
        g->meta ^= CAN_ENPASSANT_HPAWN;

    int p = get_piece_owner(g->b[y][x]);
    if (p == WHITE && (g->meta & WHITE_CAN_ENPASSANT)) {
        g->meta ^= WHITE_CAN_ENPASSANT;
    } else if (p == BLACK && (g->meta & BLACK_CAN_ENPASSANT)) {
        g->meta ^= BLACK_CAN_ENPASSANT;
    }
}

void make_regular_move(Game *g, int x1, int y1, int x2, int y2) {
    int piece_owner = get_piece_owner(g->b[y1][x1]);
    if ( // Handle pawn promotion.
        get_piece_type(g->b[y1][x1]) == PAWN &&
        ((piece_owner == WHITE && y2 == BLACK_BACK_RANK) ||
         (piece_owner == BLACK && y2 == WHITE_BACK_RANK)))
        g->b[y2][x2] = QUEEN | piece_owner;
    else
        g->b[y2][x2] = g->b[y1][x1];

    reset_enpassant(g, x1, y1);
    if (get_piece_type(g->b[y1][x1]) == PAWN && abs(y2 - y1) == 2) {
        int file_flag = get_enpassant_flag(x1);
        int player_flag;
        if (piece_owner == WHITE)
            player_flag = BLACK_CAN_ENPASSANT;
        else
            player_flag = WHITE_CAN_ENPASSANT;
        g->meta |= file_flag | player_flag;
    }

    g->b[y1][x1] = EMPTY_SQUARE;
}

void make_enpassant_move(Game *g, int x1, int y1, int x2, int y2) {
    reset_enpassant(g, x1, y1);
    g->b[y2][x2] = g->b[y1][x1];
    g->b[y1][x1] = EMPTY_SQUARE;
    g->b[y1][x2] = EMPTY_SQUARE; // Remove passed pawn.
}

void make_castling_move(Game *g, int x1, int y1, int x2, int y2) {
    reset_enpassant(g, x1, y1);
    g->b[y2][x2] = g->b[y1][x1];
    if (x2 == N_FILES - 2) { // Short castle.
        g->b[y2][x2 - 1] = g->b[y2][N_FILES - 1];
        g->b[y2][N_FILES - 1] = EMPTY_SQUARE;
    } else if (x2 == 2) { // Long castle.
        g->b[y2][x2 + 1] = g->b[y2][0];
        g->b[y2][0] = EMPTY_SQUARE;
    }
    g->b[y1][x1] = EMPTY_SQUARE;
}
int _make_move(Game *g, int x1, int y1, int x2, int y2) {
    int move_type = is_valid_move(g->b, g->meta, x1, y1, x2, y2);
    switch (move_type) {
    case INVALID_MOVE:
        return INVALID_MOVE;
    case REGULAR_MOVE:
        make_regular_move(g, x1, y1, x2, y2);
        break;
    case TAKING_MOVE:
        make_regular_move(g, x1, y1, x2, y2);
        break;
    case CASTLING:
        make_castling_move(g, x1, y1, x2, y2);
        break;
    case ENPASSANT:
        make_enpassant_move(g, x1, y1, x2, y2);
        break;
    default:
        return INVALID_MOVE;
    }
    return move_type;
}

bool is_in_mate(Game g, int p) {
    if (!is_in_check(g.b, p))
        return false;
    // Iterate through all players pieces and all their possible moves
    // and check whether still in mate.
    for (int x1 = 0; x1 < N_RANKS; x1++) {
        for (int y1 = 0; y1 < N_FILES; y1++) {
            if (get_piece_owner(g.b[y1][x1]) != p)
                continue;
            // Construct adjacency matrix.
            int m[ADJ_M_WIDTH][ADJ_M_WIDTH] = {{INVALID_MOVE}};
            fill_adjacency_matrix(g.b, g.meta, x1, y1, m);
            // Iterate through all possible moves.
            int i = transform_to_adj(x1, y1);
            for (int j = 0; j < ADJ_M_WIDTH; j++) {
                if (i != j && has_path(m, i, j)) {
                    Game g_copy = make_game();
                    copy_game(g, &g_copy);
                    int x2, y2;
                    transform_from_adj(j, &x2, &y2);
                    _make_move(&g_copy, x1, y1, x2, y2);
                    if (!(is_in_check(g_copy.b, p)))
                        return false;
                }
            }
        }
    }
    return true;
}

void update_castling_flags(Game *g, int player, int piece, int x1) {

    bool rm_kingside_flag = false;
    bool rm_queenside_flag = false;
    if (piece & ROOK) {
        if (x1 == 0) {
            rm_queenside_flag = true;
        } else if (x1 == N_FILES - 1) {
            rm_kingside_flag = true;
        }
    } else if (piece & KING) {
        rm_kingside_flag = true;
        rm_queenside_flag = true;
    }

    int kingside_flag = (player == WHITE) ? WHITE_CAN_CASTLE_KINGSIDE
                                          : BLACK_CAN_CASTLE_KINGSIDE;
    int queenside_flag = (player == WHITE) ? WHITE_CAN_CASTLE_QUEENSIDE
                                           : BLACK_CAN_CASTLE_QUEENSIDE;

    if (rm_kingside_flag && g->meta & kingside_flag) {
        g->meta ^= kingside_flag;
    }
    if (rm_queenside_flag && g->meta & queenside_flag) {
        g->meta ^= queenside_flag;
    }
}

void update_turn_flags(Game *g, int player) {

    g->move_number++;
    if (player == BLACK) {
        g->meta ^= BLACKS_TURN;
        g->meta |= WHITES_TURN;
    } else {
        g->meta ^= WHITES_TURN;
        g->meta |= BLACKS_TURN;
    }
}

void update_check_flags(Game *g) {
    if (is_in_check(g->b, WHITE)) {
        if (!(g->meta & WHITE_IN_CHECK))
            g->meta |= WHITE_IN_CHECK;
        if (is_in_mate(*g, WHITE)) {
            g->meta |= WHITE_IN_MATE;
            g->n_black_half_points += 2;
        }
    } else {
        if (g->meta & WHITE_IN_CHECK)
            g->meta ^= WHITE_IN_CHECK;
    }

    if (is_in_check(g->b, BLACK)) {
        if (!(g->meta & BLACK_IN_CHECK))
            g->meta |= BLACK_IN_CHECK;
        if (is_in_mate(*g, BLACK)) {
            g->meta |= BLACK_IN_MATE;
            g->n_white_half_points += 2;
        }
    } else {
        if (g->meta & BLACK_IN_CHECK)
            g->meta ^= BLACK_IN_CHECK;
    }
}

int make_move(Game *g, int x1, int y1, int x2, int y2) {
    int piece = g->b[y1][x1];
    int player = get_piece_owner(piece);
    int move_type = _make_move(g, x1, y1, x2, y2);
    if (move_type == INVALID_MOVE)
        return INVALID_MOVE;
    // Update castling rules
    update_castling_flags(g, player, piece, x1);
    // Switch sides and update turn number.
    update_turn_flags(g, player);
    // Check whether players are in check or checkmate
    update_check_flags(g);
    return move_type;
}
#endif
