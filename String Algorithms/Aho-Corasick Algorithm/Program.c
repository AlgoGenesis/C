#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 500
#define MAXC 26

int out[MAXS];
int f[MAXS];
int g[MAXS][MAXC];

int buildMatchingMachine(char *arr[], int k) {
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);

    int states = 1;

    for (int i = 0; i < k; ++i) {
        const char *word = arr[i];
        int currentState = 0;

        for (int j = 0; word[j] != '\0'; ++j) {
            int ch = word[j] - 'a';

            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;

            currentState = g[currentState][ch];
        }

        out[currentState] |= (1 << i);
    }

    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    memset(f, -1, sizeof f);

    return states;
}

int findNextState(int currentState, char nextInput) {
    int answer = currentState;
    int ch = nextInput - 'a';

    while (g[answer][ch] == -1)
        answer = f[answer];

    return g[answer][ch];
}

void searchWords(char arr[][MAXS], int k, char *text) {
    buildMatchingMachine(arr, k);

    int currentState = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        currentState = findNextState(currentState, text[i]);

        if (out[currentState] == 0)
            continue;

        for (int j = 0; j < k; ++j) {
            if (out[currentState] & (1 << j)) {
                printf("Word %s appears from %d to %d\n", 
                       arr[j], i - strlen(arr[j]) + 1, i);
            }
        }
    }
}

int main() {
    char arr[][MAXS] = {"he", "she", "hers", "his"};
    char text[] = "ahishers";
    int k = sizeof(arr)/sizeof(arr[0]);

    searchWords(arr, k, text);

    return 0;
}