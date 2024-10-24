#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256
#define MAX_PATTERN_LENGTH 100

// Function to get the next state of the automaton
int getNextState(char* pattern, int M, int state, int x) {
    // If the character leads to the next state, increment state
    if (state < M && x == (unsigned char)pattern[state])
        return state + 1;

    // Start from the beginning of pattern to find longest prefix that is also suffix
    int ns, i;
    for (ns = state; ns > 0; ns--) {
        if (pattern[ns-1] == x) {
            for (i = 0; i < ns-1; i++) {
                if (pattern[i] != pattern[state-ns+1+i])
                    break;
            }
            if (i == ns-1)
                return ns;
        }
    }

    return 0;
}

// Function to build the Finite Automaton
void buildAutomaton(char* pattern, int M, int TF[][MAX_CHAR]) {
    int state, x;

    // Construct the transition function table
    // For each state and each possible input character
    for (state = 0; state <= M; ++state)
        for (x = 0; x < MAX_CHAR; ++x)
            TF[state][x] = getNextState(pattern, M, state, x);
}

// Function to find pattern in text using Finite Automaton
void searchFSA(char* pattern, char* text) {
    int M = strlen(pattern);
    int N = strlen(text);

    // Initialize the transition function table
    int (*TF)[MAX_CHAR] = (int (*)[MAX_CHAR])malloc((M + 1) * MAX_CHAR * sizeof(int));
    
    // Build the automaton
    buildAutomaton(pattern, M, TF);

    // Process the text over the constructed automaton
    int i, state = 0;
    for (i = 0; i < N; i++) {
        state = TF[state][(unsigned char)text[i]];
        if (state == M) {
            printf("Pattern found at index %d\n", i - M + 1);
        }
    }

    // Free allocated memory
    free(TF);
}

// Utility function to demonstrate multiple pattern search using FSA
void searchMultiplePatterns(char* text, char** patterns, int numPatterns) {
    printf("\nSearching for patterns in text: %s\n", text);
    for (int i = 0; i < numPatterns; i++) {
        printf("\nSearching for pattern: %s\n", patterns[i]);
        searchFSA(patterns[i], text);
    }
}

int main() {
    // Example usage
    char* text = "AABAACAADAABAAABAA";
    char* patterns[] = {
        "AABA",
        "AAB",
        "AAD"
    };
    int numPatterns = sizeof(patterns) / sizeof(patterns[0]);

    printf("Text: %s\n", text);
    printf("Patterns: ");
    for (int i = 0; i < numPatterns; i++) {
        printf("%s ", patterns[i]);
    }

    // Search for all patterns in the text
    searchMultiplePatterns(text, patterns, numPatterns);

    return 0;
}