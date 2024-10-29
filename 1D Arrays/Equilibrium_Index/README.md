# Equilibrium Index Problem

## Description

This program determines whether there exists an equilibrium index in a list of integers provided by the user. An equilibrium index is defined as an index `i` such that the sum of elements at lower indices is equal to the sum of elements at higher indices. The program employs a linear-time algorithm to efficiently find the equilibrium index by calculating prefix and suffix sums.

## Structures

1. **Input Data**

   - **Description**: An array to hold the input integers.
   - **Members**:
     - `int *arr`: A pointer to an array of integers representing the input sequence.

## Functions

**int arrayEquilibriumIndex(int* arr, int n)**

   - **Parameters**:
     - `int* arr`: A pointer to the array of integers.
     - `int n`: The number of elements in the array.
   - **Returns**:
     - The equilibrium index if it exists.
     - `-1` if no equilibrium index is found.

   - **Description**: This function checks for the existence of an equilibrium index in the input array by:
     - Initializing arrays to store the prefix sums and suffix sums.
     - Iterating through the array to compare the left and right sums to find the equilibrium index.

## Main Function

- **Description**: The entry point of the program.
- **Details**:
  - Prompts the user to enter the number of elements in the array (n).
  - Prompts the user to enter the elements of the array.
  - Calls the `arrayEquilibriumIndex` function to check for the existence of the equilibrium index.
  - Prints the equilibrium index or indicates that none exists.

## Example

### Input
Enter the number of elements in the array: 6
Enter the elements of the array (space-separated): 1 7 3 6 5 6

### Output

Equilibrium Index: 3

## Notes

- The algorithm runs in O(n) time complexity and O(n) space complexity due to the auxiliary arrays used for prefix and suffix sums.
- This program is designed to handle inputs of varying lengths and values, ensuring robustness and efficiency.

