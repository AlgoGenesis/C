# Power Function Using Binary Exponentiation (Recursive)

## Description

The power function calculates the result of raising a base to a given exponent, represented as `base^exp`. Binary exponentiation is an efficient technique that reduces the number of multiplication operations by dividing the exponent into smaller parts using the properties of exponents.

### Key Formula:

- If `exp == 0`, then `base^0 = 1`.
- If `exp` is even, then `base^exp = (base^(exp/2))^2`.
- If `exp` is odd, then `base^exp = base * (base^(exp/2))^2`.

This approach leverages the fact that exponentiation can be broken down into smaller problems, leading to a faster solution.

### Problem Definition

Given two integers, `base` and `exp`, the objective is to compute `base^exp` using binary exponentiation.

### Algorithm Overview

1. **Base Case**: 
    - If `exp == 0`, return `1` since any number raised to the power of `0` is `1`.
2. **Recursive Case**: 
    - If `exp` is even, compute `power(base, exp / 2)` and square the result.
    - If `exp` is odd, compute `power(base, exp / 2)`, square the result, and multiply by `base`.

### Example

Given `base = 2` and `exp = 10`, the function would compute `2^10` using these steps:

- `2^10 = (2^5)^2`
- `2^5 = 2 * (2^2)^2`
- `2^2 = (2^1)^2`
- `2^1 = 2 * (2^0)^2 = 2`

Thus, `2^10 = 1024`.

### Time Complexity

The time complexity of binary exponentiation is `O(log(exp))`, which is significantly more efficient than the traditional `O(exp)` time complexity.