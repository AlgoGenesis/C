#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAXLEN 1000

// Structure for a state in the automaton
typedef struct State {
    int length, link;
    int transitions[ALPHABET_SIZE];
} State;

State states[MAXLEN * 2];
int stateCount = 1, lastState = 0;

// Function to initialize a new state
void initState(int idx) {
    states[idx].length = 0;
    states[idx].link = -1;
    memset(states[idx].transitions, -1, sizeof(states[idx].transitions));
}

// Function to add a character to the automaton
void extend(char c) {
    int current = stateCount++;
    initState(current);
    states[current].length = states[lastState].length + 1;

    int p = lastState;
    while (p != -1 && states[p].transitions[c - 'a'] == -1) {
        states[p].transitions[c - 'a'] = current;
        p = states[p].link;
    }

    if (p == -1) {
        states[current].link = 0;
    } else {
        int q = states[p].transitions[c - 'a'];
        if (states[p].length + 1 == states[q].length) {
            states[current].link = q;
        } else {
            int clone = stateCount++;
            states[clone] = states[q];
            states[clone].length = states[p].length + 1;
            while (p != -1 && states[p].transitions[c - 'a'] == q) {
                states[p].transitions[c - 'a'] = clone;
                p = states[p].link;
            }
            states[q].link = states[current].link = clone;
        }
    }
    lastState = current;
}

// Function to build the suffix automaton
void buildSuffixAutomaton(const char* str) {
    initState(0);
    for (int i = 0; str[i]; i++) {
        extend(str[i]);
    }
}

// Function to check if a substring exists
int substringExists(const char* pattern) {
    int currentState = 0;
    for (int i = 0; pattern[i]; i++) {
        int c = pattern[i] - 'a';
        if (states[currentState].transitions[c] == -1) {
            return 0; // Pattern not found
        }
        currentState = states[currentState].transitions[c];
    }
    return 1; // Pattern found
}

int main() {
    char str[MAXLEN];
    printf("Enter the string: ");
    scanf("%s", str);

    buildSuffixAutomaton(str);

    char pattern[MAXLEN];
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);

    if (substringExists(pattern)) {
        printf("Pattern exists in the string.\n");
    } else {
        printf("Pattern does not exist.\n");
    }

    return 0;
}




//by shubham (heizshubham)