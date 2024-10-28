#include <stdio.h>
#include <string.h>

#include "board.h"
#include "game.h"
#include "geom.h"
#include "pieces.h"
#include "rules.h"

#ifndef NOTATION_H
#define NOTATION_H

char notate_piece(int piece_type) {
    switch (piece_type) {
    case KNIGHT:
        return 'N';
    case BISHOP:
        return 'B';
    case ROOK:
        return 'R';
    case QUEEN:
        return 'Q';
    case KING:
        return 'K';
    default:
        return '\0';
    }
}

void notate_position(int x, int y, char *out, int buffersize) {
    static const char rank_labels[] = "abcdefgh";
    if (buffersize != 3)
        return;

    sprintf(out, "%c%d", rank_labels[x], N_RANKS - y);
}

void notate_move(Game g, int x1, int y1, int x2, int y2, int move_type,
                 char *out) {
    int cursor = 0;
    int piece_type = get_piece_type(g.b[y2][x2]);
    if (move_type == CASTLING) {
        if (x2 == N_RANKS - 2) {
            strcpy(&out[cursor], "O-O");
            cursor += 3;
        } else {
            strcpy(&out[cursor], "O-O-O");
            cursor += 5;
        }
    } else {
        char position_1[3];
        notate_position(x1, y1, position_1, 3);
        if (piece_type != PAWN)
            sprintf(&out[cursor++], "%c", notate_piece(piece_type));
        strcpy(&out[cursor], position_1);
        cursor += 2;

        if (move_type == TAKING_MOVE) {
            strcpy(&out[cursor++], "x");
        }

        char position_2[3];
        notate_position(x2, y2, position_2, 3);
        strcpy(&out[cursor], position_2);
        cursor += 2;
    }

    if (g.meta & WHITE_IN_MATE || g.meta & BLACK_IN_MATE) {
        out[cursor] = '#';
    } else if (g.meta & WHITE_IN_CHECK || g.meta & BLACK_IN_CHECK) {
        // out[cursor] = '+';
        strcpy(&out[cursor], "+");
    }
}

#endif
