# Find Missing Number in Array using XOR Method

This program finds the missing number in an array of integers using the XOR bit manipulation method. Given an array containing numbers from `1` to `N` with one number missing, the program identifies the missing number efficiently.

## Problem Statement

Given an array of size `N-1` that contains distinct integers in the range `1` to `N`, find the single missing number.

### Example

If the array is `{1, 2, 4, 5}`, and `N` is `5`, the program should output `3`, as `3` is the missing number.

## Approach

The program uses the **XOR method** to solve this problem:

1. XOR all numbers from `1` to `N`.
2. XOR all elements in the array.
3. The result of XORing these two results will be the missing number.

This method works because identical numbers cancel each other out with XOR, leaving only the missing number.

## How to Run the Program

1. Save the code in a file named `program.c`.
2. Compile the program
3. Run the program

## Example Output
For the input array `{1, 2, 4, 5}` and `N = 5`:

Missing number is: 3

## Complexity

   - Time Complexity: `O(N)`, where `N` is the range of numbers from `1 to N`.
   - Space Complexity: `O(1)`, as we only use a few additional variables for the XOR calculations.
