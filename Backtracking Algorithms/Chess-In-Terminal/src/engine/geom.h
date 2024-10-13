#ifndef GEOM_H
#define GEOM_H

#define N_RANKS 8
#define N_FILES 8
#define WHITE_BACK_RANK N_RANKS - 1
#define BLACK_BACK_RANK 0
#define WHITE_PAWN_ORIGIN WHITE_BACK_RANK - 1
#define BLACK_PAWN_ORIGIN BLACK_BACK_RANK + 1

typedef short int board[N_FILES][N_RANKS];

void copy_board(board src, board dest) {
    for (int y = 0; y < N_FILES; y++) {
        for (int x = 0; x < N_RANKS; x++) {
            dest[y][x] = src[y][x];
        }
    }
}

#endif
