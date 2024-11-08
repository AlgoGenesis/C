#ifndef GAME_H
#define GAME_H

#include "geom.h"

typedef enum {
    NULL_META = 0x00,
    WHITES_TURN = 0x01,
    BLACKS_TURN = 0x02,
    WHITE_IN_CHECK = 0x04,
    BLACK_IN_CHECK = 0x08,
    WHITE_IN_MATE = 0x10,
    BLACK_IN_MATE = 0x20,
    WHITE_CAN_CASTLE_KINGSIDE = 0x40,
    WHITE_CAN_CASTLE_QUEENSIDE = 0x80,
    BLACK_CAN_CASTLE_KINGSIDE = 0x100,
    BLACK_CAN_CASTLE_QUEENSIDE = 0x200,
    WHITE_CAN_ENPASSANT = 0x400,
    BLACK_CAN_ENPASSANT = 0x800,
    CAN_ENPASSANT_APAWN = 0x1000,
    CAN_ENPASSANT_BPAWN = 0x2000,
    CAN_ENPASSANT_CPAWN = 0x4000,
    CAN_ENPASSANT_DPAWN = 0x8000,
    CAN_ENPASSANT_EPAWN = 0x10000,
    CAN_ENPASSANT_FPAWN = 0x20000,
    CAN_ENPASSANT_GPAWN = 0x40000,
    CAN_ENPASSANT_HPAWN = 0x80000,
} GameMeta;

static const int ENPASSANT_FILES[] = {CAN_ENPASSANT_APAWN, CAN_ENPASSANT_BPAWN,
                                      CAN_ENPASSANT_CPAWN, CAN_ENPASSANT_DPAWN,
                                      CAN_ENPASSANT_EPAWN, CAN_ENPASSANT_FPAWN,
                                      CAN_ENPASSANT_GPAWN, CAN_ENPASSANT_HPAWN};

int get_enpassant_flag(int file) { return ENPASSANT_FILES[file]; }

int get_enpassant_file(GameMeta flag) {
    for (int i = 0; i < N_FILES; i++) {
        if (flag & ENPASSANT_FILES[i])
            return i;
    }
    return -1;
}

int init_game_meta(void) {
    return WHITES_TURN | WHITE_CAN_CASTLE_KINGSIDE |
           WHITE_CAN_CASTLE_QUEENSIDE | BLACK_CAN_CASTLE_KINGSIDE |
           BLACK_CAN_CASTLE_QUEENSIDE;
}

#endif
