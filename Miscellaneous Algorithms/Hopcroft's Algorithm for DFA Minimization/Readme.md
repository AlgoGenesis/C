# DFA Minimization Using Hopcroft's Algorithm

This project implements Hopcroft's algorithm to minimize a given Deterministic Finite Automaton (DFA) in C.

## Overview

Hopcroft's algorithm is an efficient algorithm for minimizing a DFA, which reduces the number of states by merging equivalent states. It uses partition refinement to identify states that can be considered equivalent and therefore merged, resulting in a minimal DFA with the same language recognition capability as the original DFA.

## Features

- Accepts DFA states, transition table, and final states as input.
- Initializes partitions of final and non-final states.
- Iteratively refines partitions until no further changes are required.
- Displays minimized partitions and state classifications.

## How to Use

1. Clone or download this repository.
2. Compile the C program using a C compiler:
    ```bash
    gcc -o dfa_minimizer dfa_minimizer.c
    ```
3. Run the compiled program:
    ```bash
    ./dfa_minimizer
    ```
4. Input the DFA details when prompted:
    - Number of states
    - Number of symbols
    - Transition table (states and symbols)
    - Number of final states and final state indices

5. View the output for minimized partitions.

## Example

Here is an example of input/output for minimizing a sample DFA:

Enter the number of states: 4 
Enter the number of symbols: 2 
Enter the transition table (row: states, columns: symbols): 0 1 1 2 2 3 3 0 
Enter the number of final states: 1 
Enter the final states: 3


The output will show the minimized partitions step-by-step, with final minimized DFA partitions.


