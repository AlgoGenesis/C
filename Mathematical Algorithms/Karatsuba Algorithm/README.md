# Karatsuba Algorithm

## Description

The Karatsuba Algorithm is a divide-and-conquer algorithm for multiplying two numbers. It is more efficient than the traditional grade-school multiplication method, particularly for large numbers. The algorithm reduces the multiplication of two n-digit numbers to at most three multiplications of n/2-digit numbers, thus achieving a time complexity of \( O(n^{\log_2 3}) \) or approximately \( O(n^{1.585}) \).

### Problem Definition

Given:
- Two integers \( x \) and \( y \).

Objective:
- Compute the product \( z = x \times y \) using the Karatsuba algorithm.

### Algorithm Overview

1. **Base Case**: If \( x \) or \( y \) is less than 10, return their product.
2. **Splitting**:
   - Split \( x \) and \( y \) into two halves:
     - \( x = a \times 10^{m} + b \)
     - \( y = c \times 10^{m} + d \)
   - Here, \( m \) is the number of digits in the larger number divided by 2, \( a \) and \( c \) are the high parts, and \( b \) and \( d \) are the low parts.
3. **Recursive Multiplication**:
   - Compute three products recursively:
     - \( z_0 = b \times d \)
     - \( z_1 = (a + b) \times (c + d) \)
     - \( z_2 = a \times c \)
4. **Combine Results**:
   - Combine the results to get the final product:
   \[
   z = z_2 \times 10^{2m} + (z_1 - z_2 - z_0) \times 10^{m} + z_0
   \]

### Time Complexity

The time complexity of the Karatsuba algorithm is \( O(n^{\log_2 3}) \), which is approximately \( O(n^{1.585}) \), making it more efficient than the naive \( O(n^2) \) approach for large numbers.

