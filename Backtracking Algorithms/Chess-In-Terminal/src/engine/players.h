#ifndef PLAYERS_H
#define PLAYERS_H

typedef enum { NOOWNER = -1, WHITE = 1, BLACK = 2 } Player;

int flip_player(int player) {
    if (player == NOOWNER)
        return player;
    else if (player == WHITE)
        return BLACK;
    else {
        return WHITE;
    }
}
#endif
