#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  

#define ROWS 5
#define COLS 5
#define DELAY 500000  


void displayGrid(char grid[ROWS][COLS], int step) {
    printf("Step %d:\n", step);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void morphPattern(char pattern1[ROWS][COLS], char pattern2[ROWS][COLS]) {
    char current[ROWS][COLS];
    int step = 1;

    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            current[i][j] = pattern1[i][j];
        }
    }

    int steps = ROWS * COLS;
    for (int step_count = 0; step_count < steps; step_count++) {
        system("clear");  

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                
                if (current[i][j] != pattern2[i][j]) {
                    current[i][j] = pattern2[i][j];
                    displayGrid(current, step++);  
                    usleep(DELAY);  
                    goto next_step;  
                }
            }
        }
    next_step:;
    }
}

int main() {
    char pattern1[ROWS][COLS] = {
        {'X', ' ', 'X', ' ', 'X'},
        {' ', 'X', ' ', 'X', ' '},
        {'X', ' ', 'X', ' ', 'X'},
        {' ', 'X', ' ', 'X', ' '},
        {'X', ' ', 'X', ' ', 'X'}
    };

    char pattern2[ROWS][COLS] = {
        {' ', 'O', 'O', 'O', ' '},
        {'O', ' ', 'O', ' ', 'O'},
        {'O', 'O', ' ', 'O', 'O'},
        {'O', ' ', 'O', ' ', 'O'},
        {' ', 'O', 'O', 'O', ' '}
    };

    printf("Pattern Morphing from Pattern1 to Pattern2:\n");
    morphPattern(pattern1, pattern2);

    return 0;
}
