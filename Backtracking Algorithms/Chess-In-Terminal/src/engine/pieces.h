#ifndef PIECES_H
#define PIECES_H

#include "players.h"

typedef enum {
    EMPTY_SQUARE = 0x0,
    PAWN = 0x4,
    KNIGHT = 0x8,
    BISHOP = 0x10,
    ROOK = 0x20,
    QUEEN = 0x40,
    KING = 0x80
} PieceType;

int get_piece_owner(int piece) {
    if (piece == EMPTY_SQUARE) {
        return NOOWNER;
    } else {
        if ((piece & WHITE) == WHITE) {
            return WHITE;
        } else {
            return BLACK;
        }
    }
}

int get_piece_type(int piece) {
    if (piece == EMPTY_SQUARE) {
        return EMPTY_SQUARE;
    }
    return piece ^ get_piece_owner(piece);
}

int get_piece(PieceType type, Player player) {
    if (type == EMPTY_SQUARE || player == NOOWNER) {
        return EMPTY_SQUARE;
    }
    return player & type;
}

char get_piece_repr(PieceType type) {
    switch (type) {
    case EMPTY_SQUARE:
        return ' ';
    case PAWN:
        return 'p';
    case KNIGHT:
        return 'k';
    case BISHOP:
        return 'B';
    case ROOK:
        return 'R';
    case QUEEN:
        return 'Q';
    case KING:
        return 'K';
    default:
        return '!';
    }
}

#endif
