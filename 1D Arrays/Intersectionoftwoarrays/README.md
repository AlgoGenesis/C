# Intersection of Two Arrays in C

This project contains a C program that calculates the intersection of two integer arrays, provided by the user. The program takes the sizes and elements of two arrays as input, finds their intersection, and outputs the common elements.

## Process

1. **User Input**: 
   - The user is prompted to enter the number of elements and the elements themselves for two arrays, `arr1` and `arr2`.
   
2. **Intersection Calculation**:
   - The function `findIntersection` iterates through each element of `arr1` and checks if it exists in `arr2` using a nested `while` loop.
   - If an element in `arr1` matches any element in `arr2`, it is printed as part of the intersection.

3. **Output**:
   - The program prints the elements found in both arrays, representing the intersection.

### Example
Consider the example arrays `{1, 2, 3, 4, 5}` and `{1, 2, 3}`.

1. **Input**:
   - `arr1 = {1, 2, 3, 4, 5}`
   - `arr2 = {1, 2, 3}`
   
2. **Output**:
   -Intersection of the two arrays: `{1, 2, 3}`

## Complexity Analysis

### Time Complexity
- **Worst Case**: \(O(n1 \times n2)\), where `n1` is the length of `arr1` and `n2` is the length of `arr2`.
- This is because each element in `arr1` is checked against every element in `arr2`, resulting in a nested loop.

### Space Complexity
- **Space Complexity**: \(O(1)\) (excluding the input arrays).
- The program does not use any extra storage for results other than printing directly.

### Assumptions
- The program assumes the arrays contain only integer values.
- It does not handle duplicates in the output; if duplicates are present in the input arrays, each duplicate will be checked independently.


