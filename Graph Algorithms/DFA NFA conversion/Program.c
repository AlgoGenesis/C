#include <stdio.h>
#include <stdlib.h>

void convertDFAtoNFA(int **dfa, int states, int symbols) {
    // Dynamically allocate memory for NFA transitions
    int ***nfa = (int ***)malloc(states * sizeof(int **));
    for (int i = 0; i < states; i++) {
        nfa[i] = (int **)malloc(symbols * sizeof(int *));
        for (int j = 0; j < symbols; j++) {
            nfa[i][j] = (int *)calloc(states, sizeof(int));  // Initialize to zero
        }
    }

    // Populate the NFA based on DFA transitions
    for (int s = 0; s < states; s++) {
        for (int sym = 0; sym < symbols; sym++) {
            int next_state = dfa[s][sym];
            if (next_state != -1) {
                nfa[s][sym][next_state] = 1;  // Mark transition in NFA
            }
        }
    }

    // Display the NFA transition table
    printf("NFA Representation:\n");
    for (int s = 0; s < states; s++) {
        for (int sym = 0; sym < symbols; sym++) {
            printf("State %d, Symbol %d: ", s, sym);
            for (int ns = 0; ns < states; ns++) {
                if (nfa[s][sym][ns] == 1) {
                    printf(" %d", ns);
                }
            }
            printf("\n");
        }
    }

    // Free dynamically allocated memory for NFA
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < symbols; j++) {
            free(nfa[i][j]);
        }
        free(nfa[i]);
    }
    free(nfa);
}

int main() {
    int states, symbols;

    // Prompt user for the number of states and symbols in DFA
    printf("Enter the number of states in the DFA: ");
    scanf("%d", &states);
    printf("Enter the number of symbols in the DFA: ");
    scanf("%d", &symbols);

    // Dynamically allocate memory for DFA transition table
    int **dfa = (int **)malloc(states * sizeof(int *));
    for (int i = 0; i < states; i++) {
        dfa[i] = (int *)malloc(symbols * sizeof(int));
    }

    // User input for DFA transitions
    for (int s = 0; s < states; s++) {
        for (int sym = 0; sym < symbols; sym++) {
            printf("Enter transition for state %d with symbol %d (-1 for no transition): ", s, sym);
            scanf("%d", &dfa[s][sym]);
        }
    }

    // Convert DFA to NFA and display the result
    convertDFAtoNFA(dfa, states, symbols);

    // Free dynamically allocated memory for DFA
    for (int i = 0; i < states; i++) {
        free(dfa[i]);
    }
    free(dfa);

    return 0;
}
