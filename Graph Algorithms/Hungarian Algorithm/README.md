
# Hungarian Algorithm in C

This project contains an implementation of the Hungarian Algorithm (or Kuhn-Munkres algorithm) in C for solving the assignment problem. This algorithm is used to find the minimum-cost assignment of tasks to workers such that each worker is assigned exactly one task, and each task is completed by only one worker.

## Table of Contents
- [Description](#description)
- [Problem Statement](#problem-statement)
- [Solution Approach](#solution-approach)
- [Usage](#usage)
- [Example](#example)
- [Limitations](#limitations)


## Description

The Hungarian Algorithm is widely used in optimization, specifically in solving assignment problems like matching workers to jobs at the minimum cost. This algorithm leverages matrix reduction and optimal matching techniques to achieve an efficient solution.

### Problem Statement

Given an \( N \times N \) cost matrix, where each element represents the cost for assigning a task to a worker, the Hungarian Algorithm finds an assignment that minimizes the total cost.

### Solution Approach

The algorithm works as follows:
1. **Matrix Reduction**: Row and column reductions are performed to make it easier to find zero-cost assignments.
2. **Covering Zeros**: It then finds the minimum number of lines to cover all zero entries in the matrix.
3. **Adjustments and Iteration**: Adjustments are made to the matrix until an optimal assignment is found, corresponding to the minimum cost.

## Usage

### Requirements
- C compiler (e.g., GCC).

### Running the Program

1. **Compile** the code with the following command:
   ```bash
   gcc hungarian.c -o hungarian
   ```
2. **Execute** the program:
   ```bash
   ./hungarian
   ```

The program will output the minimum cost for the assignment and the optimal assignment of workers to tasks.

### Code Structure

- **`isSafe`**: Checks if it’s safe to assign a color to a vertex based on adjacent vertex colors.
- **`hungarian_algorithm`**: Implements the core logic of the Hungarian Algorithm.
- **`main`**: Initializes the cost matrix and invokes the `hungarian_algorithm()` function to compute the optimal assignment.

## Example

Given the following 4x4 cost matrix:
```plaintext
9  2  7  8
6  4  3  7
5  8  1  8
7  6  9  4
```

With this cost matrix, the program outputs:
```plaintext
Minimum cost: 13
Optimal assignment:
Worker 1 assigned to task 2
Worker 2 assigned to task 3
Worker 3 assigned to task 1
Worker 4 assigned to task 4
```

This assignment ensures that the total cost is minimized.

## Limitations

- **Matrix Size**: The algorithm is implemented for a square \( N \times N \) matrix.
- **Performance**: This implementation may not be optimized for very large matrices. Alternative, faster algorithms may be preferable for very large datasets.

