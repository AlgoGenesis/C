# Powerful Divisors

## Description

This program calculates the number of "powerful divisors" for each integer in a list provided by the user. A powerful divisor is defined as a number whose count of divisors is a power of two. The program employs an efficient algorithm to count the divisors of each integer and uses a prefix sum approach to quickly determine the count of powerful divisors for the given inputs.

## Structures

1. **Input Data**

   - **Description**: An array to hold the input integers.
   - **Members**:
     - `int *A`: A pointer to an array of integers representing the input sequence.

2. **Output Data**

   - **Description**: An array to hold the results.
   - **Members**:
     - `int *ans`: A pointer to an array of integers representing the count of powerful divisors for each input integer.

## Functions

**int* powerfulDivisors(int* A, int n1, int *len1)**

   - **Parameters**:
     - `int* A`: A pointer to the array of integers.
     - `int n1`: The number of elements in the array.
     - `int *len1`: A pointer to an integer that will store the length of the result array.
   - **Returns**:
     - A pointer to an array containing the count of powerful divisors for each input integer.

   - **Description**: This function calculates the number of powerful divisors for each integer in the input array by:
     - Finding the maximum value in the input array to determine the range for divisor counting.
     - Counting the number of divisors for each integer in the range.
     - Identifying which counts are powers of two.
     - Constructing a prefix sum array to facilitate quick queries on powerful divisors.

## Main Function

- **Description**: The entry point of the program.
- **Details**:
  - Prompts the user to enter the number of elements in the array (`n`).
  - Prompts the user to enter the elements of the array.
  - Calls the `powerfulDivisors` function to compute the count of powerful divisors for each integer.
  - Prints the count of powerful divisors for each input integer.

## Example

### Input
Enter the number of elements: 3 Enter the elements: 3 5 10

### Output
Powerful Divisors Count: 1 0 2


## Notes

- The program is designed to be efficient, leveraging divisor counting techniques and prefix sums to handle potentially large input sizes.
- Ensure that the input values are non-negative integers for accurate results.
- Compile the program using GCC with the appropriate flags (e.g., `-std=c99`) to enable C99 features if needed.

