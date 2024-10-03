# Reversing a Number

## Description

The reverse of a number means reversing the order of digits of a number.

### Problem Definition

Given a non-negative integer `n`, compute the reverse of `n`.
### Examples:
- **Input**: `n = 5176`  
  **Output**: `6715` 

- **Input**: `n = 0`  
  **Output**: `0`

### Algorithm Overview

Input: num
(1) Initialize rev_num = 0
(2) Loop while num > 0
     (a) Multiply rev_num by 10 and add remainder of num
          divide by 10 to rev_num
               rev_num = rev_num*10 + num%10;
     (b) Divide num by 10
(3) Return rev_num

### Time Complexity

Time Complexity: O(log(n)), where n is the input number. 
Auxiliary Space: O(1)

