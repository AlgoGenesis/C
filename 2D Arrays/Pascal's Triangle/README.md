# Pascal's Triangle Generator in C

## Overview

This program generates Pascal's Triangle up to a specified number of rows, as defined by the user. Pascal's Triangle is a triangular array where each row contains the binomial coefficients for that row index. The triangle starts with a `1` at the top, and each subsequent row contains elements that are the sum of the elements directly above and to the left.

## Code Explanation

The C code is structured with the following functions:

### 1. `binomialCoeff(int n, int k)`
This function calculates the binomial coefficient, which is critical for determining the elements in Pascal's Triangle. Each element in row `n` and column `k` of Pascal's Triangle is a binomial coefficient, denoted by `C(n, k)` or "n choose k".

**Key Steps in `binomialCoeff`**:
- Adjusts `k` for efficiency (as `C(n, k) = C(n, n-k)`).
- Iteratively calculates the binomial coefficient using the formula:

    \[
    C(n, k) = \frac{n!}{k! \cdot (n-k)!}
    \]

### 2. `printPascalsTriangle(int rows)`
This function generates Pascal's Triangle by iterating through each row and column, printing the appropriate number of spaces for alignment, and then using the `binomialCoeff` function to print each element in the row.

**Key Steps in `printPascalsTriangle`**:
- Outer loop iterates over each row.
- Inner loop calculates each element using the `binomialCoeff` function.
- Each row is aligned to create the triangular shape.

### 3. `main`
The `main` function prompts the user to enter the number of rows and then calls `printPascalsTriangle` to generate the triangle.

## Complexity Analysis

### Time Complexity

1. **`binomialCoeff(int n, int k)`**:
   - For each coefficient, it iteratively computes values in a loop up to `k` times, where `k` is minimized by `k = min(k, n-k)`.
   - Therefore, the time complexity for a single call to `binomialCoeff` is \(O(n)\).

2. **`printPascalsTriangle(int rows)`**:
   - This function contains two nested loops: the outer loop runs `rows` times, iterating over each row, and the inner loop calculates the binomial coefficient for each element in the row.
   - The total number of elements in Pascal's Triangle for `rows` rows is \(1 + 2 + 3 + \dots + \text{rows} = \frac{\text{rows} \times (\text{rows} + 1)}{2}\), which is \(O(\text{rows}^2)\).
   - Each calculation of a binomial coefficient is \(O(\text{row})\), leading to an overall time complexity of \(O(\text{rows}^3)\).

**Overall Time Complexity of the Program**: \(O(\text{rows}^3)\).

### Space Complexity

1. **`binomialCoeff(int n, int k)`**:
   - This function uses a constant amount of space to store variables (`res` and `k`), resulting in a space complexity of \(O(1)\).

2. **`printPascalsTriangle(int rows)`**:
   - The function does not use additional data structures that grow with input size, and it prints values directly to the console. Thus, the space complexity is \(O(1)\).

**Overall Space Complexity of the Program**: \(O(1)\).

## Example Usage

When you run the program, it will prompt:

```bash
Enter the number of rows for Pascal's Triangle:
For an input of 5, the output will be:

    1 
   1 1 
  1 2 1 
 1 3 3 1 
1 4 6 4 1 
```
