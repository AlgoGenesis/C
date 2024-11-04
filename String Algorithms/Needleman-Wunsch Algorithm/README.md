# Needleman-Wunsch Algorithm

## Description

The Needleman-Wunsch algorithm is a dynamic programming algorithm used for sequence alignment. It is particularly useful for aligning nucleotide or protein sequences in bioinformatics but can also be applied to string matching in computer science.

### Problem Definition

Given:
- Two sequences (or strings) **S1** and **S2**

Objective:
- Align the two sequences by introducing gaps (if necessary) to maximize the match score while minimizing the penalty for mismatches and gaps.

### Algorithm Overview

1. **Initialize Score Matrix**: 
   - Create a score matrix with dimensions `(len(S1) + 1)` x `(len(S2) + 1)` and initialize the first row and column with gap penalties.
2. **Matrix Filling**: 
   - Fill the matrix by choosing the optimal score for each cell based on the previous cells, using:
     - Match/Mismatch score
     - Insertion/Deletion (gap) score
3. **Traceback**: 
   - Trace back through the matrix to determine the optimal alignment of the two sequences.

### Key Features

- Global alignment algorithm
- Handles mismatches and gaps with penalties
- Constructs an optimal alignment based on a scoring system
- Suitable for aligning sequences of varying lengths

### Time Complexity

- **Time Complexity**: O(m * n), where `m` is the length of sequence S1, and `n` is the length of sequence S2. This is due to the need to fill in a score matrix of size `m x n`.
- **Space Complexity**: O(m * n), due to the storage required for the score matrix.

### Scoring

- **Match**: +1 (reward for matching characters)
- **Mismatch**: -1 (penalty for different characters)
- **Gap**: -2 (penalty for inserting gaps)

## Implementation

The implementation in C demonstrates the Needleman-Wunsch algorithm for aligning two sequences. It includes:

1. **Score Matrix Calculation**: Initializes and fills the score matrix based on matches, mismatches, and gaps.
2. **Traceback**: Recovers the optimal alignment by tracing back through the score matrix.
3. **Alignment Output**: Prints the aligned sequences.

## Usage

1. **Compile**: Use a C compiler to compile the program.
   ```bash
   gcc needleman_wunsch.c -o needleman_wunsch
   ```

2. **Run**: Execute the program with two predefined sequences.
   ```bash
   ./needleman_wunsch
   ```

The example in the `main` function aligns the sequences "GATTACA" and "GCATGCU" and prints the optimal alignment and the corresponding score matrix.