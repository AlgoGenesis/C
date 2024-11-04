# Smith-Waterman Algorithm

## Description

The Smith-Waterman algorithm is a dynamic programming algorithm used for local sequence alignment. It finds the optimal alignment of a subset of one sequence against another. Unlike global alignment algorithms, Smith-Waterman focuses on finding the most similar region between two sequences, making it ideal for biological applications such as DNA or protein sequence matching.

### Problem Definition

Given:
- A sequence `seq1` of length `m`
- A sequence `seq2` of length `n`

Objective:
- Find the best local alignment of `seq1` and `seq2`

### Algorithm Overview

1. **Initialization**:
   - Create a scoring matrix with dimensions `(m+1) x (n+1)` initialized to zeros.

2. **Scoring**:
   - For each cell in the matrix, calculate the score based on the match/mismatch and gap penalties.
   - Track the maximum score and its position.

3. **Traceback**:
   - Start from the cell with the highest score and trace back to reconstruct the optimal local alignment.

### Key Features

- Finds local alignments by allowing partial overlaps of sequences.
- Uses a scoring system for matches, mismatches, and gaps.
- Backtracks from the cell with the highest score to find the optimal alignment.
- Time complexity: O(mn), where `m` and `n` are the lengths of the sequences.

### Time Complexity

- **Worst Case**: O(mn), where `m` is the length of `seq1` and `n` is the length of `seq2`

### Space Complexity

- O(mn), since a matrix of size `(m+1) x (n+1)` is required to store the scores.

## Implementation

The implementation in C demonstrates the Smith-Waterman algorithm for local sequence alignment. It includes:

1. A function to initialize and populate the scoring matrix.
2. The Smith-Waterman function to compute the alignment score and perform the traceback to find the aligned sequences.
3. A demonstration of how to use the algorithm on two sample sequences.

## Usage

Compile the program and run it. The example in the `main` function demonstrates how the Smith-Waterman algorithm can be used to align two sequences.

```bash
gcc smith_waterman.c -o smith_waterman
./smith_waterman
```

## Limitations

- The algorithm works for short to medium-length sequences but can be memory-intensive for very long sequences due to the need for a full scoring matrix.
- The current implementation assumes equal penalties for all types of mismatches and gaps. These can be adjusted as needed for specific applications.

## Extensions

- The algorithm can be extended by using affine gap penalties, which distinguish between opening and extending a gap.
- It can also be adapted for approximate matching in non-biological contexts, such as comparing textual or binary data.