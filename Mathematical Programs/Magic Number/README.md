# Magic Number

## Description

A number is said to be a magic number, if the sum of its digits are calculated till a single digit recursively by adding the sum of the digits after every addition. If the single digit comes out to be 1,then the number is a magic number. 

### Examples:
- **Input**: `n = 50113`  
  **Output**: `Magic Number` 
  => 5 + 0 + 1 + 1 +3 = 10
  => 1 + 0 = 1

- **Input**: `n = 1234`  
  **Output**: `Magic Number`
  =>5 + 0 + 1 + 1 + 3 = 10
  =>1 + 0 =10

### Algorithm Overview
 
The approach used brute force. The function keeps adding digits until a single digit sum is reached.

### Time Complexity

The time complexity of this **O(n)**, where `n` is the input value. 
