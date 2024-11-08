# Moore's Algorithm

## Description

This program implements Moore's algorithm to find the majority element in an array. The majority element is defined as an element that appears more than n/2 times in an array of size n. Moore's algorithm is an efficient method that solves this problem in linear time and constant space.

## Algorithm Overview

Moore's algorithm works on the principle of pair cancellation. It iterates through the array once to find a candidate for the majority element and then verifies if this candidate is indeed the majority element in a second pass.

## Structures

1. No specific structures are required for this algorithm.

## Functions

1. `int findCandidate(int arr[], int size)`
   - Description: Finds a candidate for the majority element.
   - Parameters:
     - `arr[]`: The input array
     - `size`: The size of the array
   - Returns: The candidate element

2. `bool isMajority(int arr[], int size, int candidate)`
   - Description: Verifies if the candidate is the majority element.
   - Parameters:
     - `arr[]`: The input array
     - `size`: The size of the array
     - `candidate`: The candidate element to verify
   - Returns: `true` if the candidate is the majority element, `false` otherwise

## Main Function

- Description: The entry point of the program.
- Details:
  * Prompts the user to enter the size of the array.
  * Dynamically allocates memory for the array based on the size.
  * Prompts the user to enter the elements of the array.
  * Calls `findCandidate()` to get a potential majority element.
  * Calls `isMajority()` to verify if the candidate is indeed the majority element.
  * Prints the majority element if found, or a message if no majority element exists.
  * Frees the dynamically allocated memory for the array before exiting.

## Memory Management

- Dynamic Memory Allocation: Used for creating the input array.
- Freeing Memory: The allocated memory is freed after use to prevent memory leaks.

## Time Complexity

- O(n), where n is the number of elements in the array.

## Space Complexity

- O(1), as it uses only a constant amount of extra space.

## Usage

1. Compile the program using a C compiler (e.g., gcc):
   ```
   gcc Program.c -o moores_algorithm
   ```
2. Run the compiled program:
   ```
   ./Program
   ```
3. Follow the prompts to input the array size and elements.

## Example

```
Enter the size of the array: 7
Enter 7 elements:
2 2 1 1 1 2 2
The majority element is: 2
```

## Note

This implementation assumes that a majority element always exists in the input array. If you want to handle cases where a majority element might not exist, you can modify the `isMajority` function to return `false` if the candidate doesn't appear more than n/2 times.