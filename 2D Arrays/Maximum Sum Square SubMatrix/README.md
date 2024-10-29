
# Maximum Sum Sub-Square Matrix Program

## Overview
This C program efficiently finds the maximum sum of a sub-square matrix of size `k x k` within a given square matrix of size `n x n` (where `k ≤ n`). The algorithm runs in `O(n^2)` time complexity, making it suitable for relatively large matrices. It uses a preprocessing step to calculate the sum of strips (subarrays of `k x 1`), which helps in efficiently determining the sum of sub-square matrices.

## Features
- **Matrix Size**: The program works with a matrix of size `5 x 5` (modifiable via the `N` constant).
- **Sub-square Size**: The program allows you to specify the sub-square size `k` (in the example, it's set to `3 x 3`).
- **Efficient Calculation**: It optimizes the sum calculation using a strip sum approach, minimizing redundant operations.

## How it Works
1. **Preprocessing Step**: 
   - The algorithm first computes the sum of vertical strips of size `k x 1` for each column. This is stored in an auxiliary matrix `stripSum`. This step ensures that future sub-square sums can be computed efficiently by adding or removing parts of the strip sums.
   
2. **Sub-Square Sum Calculation**:
   - For each potential top-left position of a `k x k` sub-square, the program calculates the sum using the precomputed strip sums. It efficiently adjusts this sum when shifting horizontally across the matrix.

3. **Tracking Maximum Sum**:
   - As it calculates the sums of various sub-squares, the program keeps track of the maximum sum found and its corresponding top-left position in the matrix.

4. **Output**:
   - Finally, the program prints the sub-square with the maximum sum.

## Input/Output
### Input:
- A hardcoded `5 x 5` matrix, but it can be easily modified to handle other sizes by adjusting the `N` constant and the matrix definition.
- The size `k` of the sub-square matrix is also predefined in the code, but can be changed.

### Output:
- The program prints the `k x k` sub-square matrix with the maximum sum.

## Example

For the matrix:
```
1 1 1 1 1
2 2 2 2 2
3 8 6 7 3
4 4 4 4 4
5 5 5 5 5
```

And sub-square size `k = 3`, the program outputs:
```
8 6 7
4 4 4
5 5 5
```

## Time Complexity
- **Preprocessing Step**: `O(n^2)`, where `n` is the size of the matrix.
- **Sub-Square Calculation**: `O(n^2)`, since each sub-square sum is computed in constant time after preprocessing.
- **Overall Complexity**: The total time complexity is `O(n^2)`.

## How to Modify
- **Matrix Size**: Change the `#define N 5` to the desired size of the square matrix.
- **Sub-square Size**: Adjust the value of `k` in the `main()` function to find the maximum sum for different sub-square sizes.

## Usage
1. Compile the program using a C compiler:
   ```
   gcc maxsum.c -o maxsum
   ```
2. Run the program:
   ```
   ./maxsum
   ```
