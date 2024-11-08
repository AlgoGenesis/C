# DFA to NFA Conversion

## Description

This program converts a Deterministic Finite Automaton (DFA) to a Non-Deterministic Finite Automaton (NFA). The conversion process utilizes a state transition table where each DFA state and symbol combination maps to a specific transition in the NFA.

### Problem Definition

Given:
- A DFA represented as a transition table, with each state having a specific transition for each input symbol.
- A set of states and symbols, defined by the user.

Objective:
- Convert the DFA to an equivalent NFA by representing each transition of the DFA as an NFA transition in a dynamically allocated data structure.

### Algorithm Overview

1. **Input the DFA Transition Table**:
   - Prompt the user for the number of states and symbols.
   - For each state and symbol combination, input the transition to the next state. Use `-1` to indicate no transition.

2. **Initialize NFA Representation**:
   - Create a three-dimensional array to hold the NFA transitions, where each entry for a state-symbol pair can point to multiple states (or none).

3. **Convert DFA Transitions to NFA Transitions**:
   - For each DFA state-symbol pair, if a transition exists, update the NFA transition table to reflect the corresponding transition.

4. **Display NFA Transitions**:
   - Print each state-symbol combination and its reachable states in the NFA.

### Time Complexity

The time complexity of this DFA-to-NFA conversion is `O(states * symbols)`, as each state-symbol pair is processed only once.

### Example Code

Below is the complete code for the DFA-to-NFA conversion:

```c
#include <stdio.h>
#include <stdlib.h>

void convertDFAtoNFA(int **dfa, int states, int symbols) {
    int ***nfa = (int ***)malloc(states * sizeof(int **));
    for (int i = 0; i < states; i++) {
        nfa[i] = (int **)malloc(symbols * sizeof(int *));
        for (int j = 0; j < symbols; j++) {
            nfa[i][j] = (int *)calloc(states, sizeof(int));
        }
    }

    for (int s = 0; s < states; s++) {
        for (int sym = 0; sym < symbols; sym++) {
            int next_state = dfa[s][sym];
            if (next_state != -1) {
                nfa[s][sym][next_state] = 1;
            }
        }
    }

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

    printf("Enter the number of states in the DFA: ");
    scanf("%d", &states);
    printf("Enter the number of symbols in the DFA: ");
    scanf("%d", &symbols);

    int **dfa = (int **)malloc(states * sizeof(int *));
    for (int i = 0; i < states; i++) {
        dfa[i] = (int *)malloc(symbols * sizeof(int));
    }

    for (int s = 0; s < states; s++) {
        for (int sym = 0; sym < symbols; sym++) {
            printf("Enter transition for state %d with symbol %d (-1 for no transition): ", s, sym);
            scanf("%d", &dfa[s][sym]);
        }
    }

    convertDFAtoNFA(dfa, states, symbols);

    for (int i = 0; i < states; i++) {
        free(dfa[i]);
    }
    free(dfa);

    return 0;
}
```

### Example Walkthrough

Given a DFA with 3 states and 2 symbols, let's assume the following transitions:

- **DFA Table**:
  - State 0: Symbol 0 -> State 1, Symbol 1 -> State 2
  - State 1: Symbol 0 -> State 2, Symbol 1 -> -1 (no transition)
  - State 2: Symbol 0 -> State 0, Symbol 1 -> State 1

#### Example Input

```
Enter the number of states in the DFA: 3
Enter the number of symbols in the DFA: 2

Enter transition for state 0 with symbol 0 (-1 for no transition): 1
Enter transition for state 0 with symbol 1 (-1 for no transition): 2
Enter transition for state 1 with symbol 0 (-1 for no transition): 2
Enter transition for state 1 with symbol 1 (-1 for no transition): -1
Enter transition for state 2 with symbol 0 (-1 for no transition): 0
Enter transition for state 2 with symbol 1 (-1 for no transition): 1
```

#### Expected Output

```
NFA Representation:
State 0, Symbol 0: 1
State 0, Symbol 1: 2
State 1, Symbol 0: 2
State 1, Symbol 1:
State 2, Symbol 0: 0
State 2, Symbol 1: 1
```

In this output, each line represents the possible states that can be reached from a specific state on a given symbol in the NFA representation.

### Memory Management

- The program dynamically allocates memory for both the DFA and NFA tables and frees the memory at the end of the program to avoid memory leaks.

### Key Points

- The DFA is represented by a 2D array where each state-symbol pair has a single deterministic transition.
- The NFA is represented by a 3D array where each state-symbol pair can transition to multiple states.
- The algorithm ensures that each DFA transition is correctly represented in the NFA format.

This code provides an efficient solution for converting DFA to NFA while ensuring memory is managed dynamically.