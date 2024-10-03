# Happy Number

## Description

A number is called happy if it leads to 1 after a sequence of steps wherein each step number is replaced by the sum of squares of its digit that is if we start with Happy Number and keep replacing it with digits square sum, we reach 1. 

### Problem Definition

Given a non-negative integer `n`, compute the square sum of the each digit.

### Examples:
- **Input**: `n = 19`  
  **Output**: `True` 
  19 is Happy Number,
  1^2 + 9^2 = 82
  8^2 + 2^2 = 68
  6^2 + 8^2 = 100
  1^2 + 0^2 + 0^2 = 1
  As we reached to 1, 19 is a Happy Number.


- **Input**: `n = 20`  
  **Output**: `False`

### Detailed Steps:

1. **Function Definition**: Define a function that computes the square sum of `n`.
2. **Base Condition**: If `n == 1`, return `True`.


### Time Complexity

Time Complexity: O(n*log(n)). 
Auxiliary Space: O(n) since using extra set for storage.
