#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 10

typedef struct {
    int transitions[MAX_STATES][MAX_SYMBOLS];
    int finalStates[MAX_STATES];
    int numStates;
    int numSymbols;
    int numFinalStates;
} DFA;

void inputDFA(DFA *dfa) {
    printf("Enter the number of states: ");
    scanf("%d", &dfa->numStates);
    printf("Enter the number of symbols: ");
    scanf("%d", &dfa->numSymbols);

    printf("Enter the transition table (row: states, columns: symbols):\n");
    for (int i = 0; i < dfa->numStates; i++) {
        for (int j = 0; j < dfa->numSymbols; j++) {
            scanf("%d", &dfa->transitions[i][j]);
        }
    }

    printf("Enter the number of final states: ");
    scanf("%d", &dfa->numFinalStates);
    printf("Enter the final states:\n");
    for (int i = 0; i < dfa->numFinalStates; i++) {
        scanf("%d", &dfa->finalStates[i]);
    }
}

void initializePartitions(int *P, int numStates, int *finalStates, int numFinalStates) {
    for (int i = 0; i < numStates; i++) {
        P[i] = 0;
    }
    for (int i = 0; i < numFinalStates; i++) {
        P[finalStates[i]] = 1;
    }
}

void printPartitions(int *P, int numStates) {
    printf("Current Partition:\n");
    for (int i = 0; i < numStates; i++) {
        printf("State %d: %d\n", i, P[i]);
    }
    printf("\n");
}

int areEquivalent(DFA *dfa, int *P, int state1, int state2) {
    for (int symbol = 0; symbol < dfa->numSymbols; symbol++) {
        if (P[dfa->transitions[state1][symbol]] != P[dfa->transitions[state2][symbol]]) {
            return 0;
        }
    }
    return 1;
}

void refinePartitions(DFA *dfa, int *P) {
    int newPartition[MAX_STATES];
    int changed = 1;

    while (changed) {
        changed = 0;
        for (int i = 0; i < dfa->numStates; i++) {
            newPartition[i] = P[i];
        }

        for (int i = 0; i < dfa->numStates - 1; i++) {
            for (int j = i + 1; j < dfa->numStates; j++) {
                if (P[i] == P[j] && !areEquivalent(dfa, P, i, j)) {
                    newPartition[j] = newPartition[i] + 1;
                    changed = 1;
                }
            }
        }

        for (int i = 0; i < dfa->numStates; i++) {
            P[i] = newPartition[i];
        }
        printPartitions(P, dfa->numStates);
    }
}

void minimizeDFA(DFA *dfa) {
    int P[MAX_STATES];
    initializePartitions(P, dfa->numStates, dfa->finalStates, dfa->numFinalStates);

    printf("Initial partition:\n");
    printPartitions(P, dfa->numStates);

    refinePartitions(dfa, P);

    printf("Final minimized DFA:\n");
    printPartitions(P, dfa->numStates);
}

int main() {
    DFA dfa;
    inputDFA(&dfa);
    minimizeDFA(&dfa);
    return 0;
}
