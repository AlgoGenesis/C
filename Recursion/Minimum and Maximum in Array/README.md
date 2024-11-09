# Find Minimum and Maximum in an Array Using Recursion

## Description

This program demonstrates how to find the minimum and maximum elements in an array using a recursive algorithm. It is a useful technique in situations requiring array analysis without relying on iterative loops, showcasing the power of recursion in breaking problems into smaller subproblems.

```
Example:
Enter the size of the array: 5
Enter the elements of the array:
Element 1: 12
Element 2: 7
Element 3: 19
Element 4: 3
Element 5: 15

Output:
The elements of the array:
12 7 19 3 15
Minimum element in the array: 3
Maximum element in the array: 19

```

### Problem Definition

1.  **Given**:
- An integer array `arr[]` and its size `n`.

2.  **Objective**:
- Find the smallest (`min`) and largest (`max`) elements in the array using **recursive functions**.

### Algorithm Overview

1. **Base Case**:
   - If the current index is the last element of the array, return the element as it is the minimum or maximum of the subarray.

2. **Recursive Case**:
   - For each recursive call:
    - Compare the current element with the result of the recursive function applied to the rest of the array.
    - Return the smaller value for the minimum function and the larger value for the maximum function.

3. **Final Output**:
   - Combine the results from the recursive calls to find the overall minimum and maximum.
   
### Key Features

- Recursive approach eliminates the need for explicit loops.
- Minimal additional space required since recursion works in-place.
- Efficiently processes each element exactly once.

### Time Complexity

- **Best case**: O(n), where `n` is the number of elements in the array, as every element is visited once.
- **Worst case**: O(n) for the same reason.

### Space Complexity

- O(n) for the recursion stack in the worst case (when the recursion depth equals the number of elements).

## Implementation

The implementation in C includes:

1. **Recursive Functions to Find Minimum and Maximum**
    - A function `findMin` to recursively find the smallest element in the array.
    - A function `findMax` to recursively find the largest element in the array.

2. **User Input Handling**:
    - A dynamic array to accept user-defined input for the size and elements of the array.
    - A loop to populate the array with user inputs.

3. **Main Function to Demonstrate Usage**:
    - Accepts input for the array.
    - Calls the recursive functions to find the minimum and maximum elements.
    - Displays the results to the user.

## Usage

- Compile the program using a C compiler (e.g., gcc).
- Run the program and input the size and elements of the array as prompted.
- Observe the output displaying the minimum and maximum values.
