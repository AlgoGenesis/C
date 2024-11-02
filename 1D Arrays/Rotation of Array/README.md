# Rotation of Array Algorithm

## Description

The Rotation of Array algorithm is used to shift the elements of an array to the left or right by a specified number of positions. When elements are shifted beyond the array bounds, they wrap around to the other end. This algorithm is commonly applied in circular queues, data shuffling, and simulations where cyclic movement of elements is required.

```
Example:

Input: arr = [1, 2, 3, 4, 5]
Let positions = 2, direction = 'R'
Output: arr = [4, 5, 1, 2, 3]
```

### Problem Definition

Given:
- An array `arr[]` of size `n`.
- An integer `positions` specifying the number of positions to rotate.
- A character `direction` ('L' for left or 'R' for right) indicating the rotation direction.

Objective:
- Shift elements in `arr[]` by `positions` in the specified direction(Left/Right), with **wrap-around**.

### Algorithm Overview

1. **Input Validation**:
   - If `positions` is greater than the array length, reduce it to `positions % n` to avoid redundant rotations.

2. **Temporary Array Storage**:
   - Create a temporary array to store the rearranged elements during the rotation.

3. **Left Rotation**:
   - For each element at index `i` in the original array, move it to `(i + positions) % n` in the `temp`(temporary) array.
   - This shift allows elements that exceed the array length to wrap back to the beginning.

4. **Right Rotation**:
   - For each element at index `i` in the original array, move it to `(i - positions + n) % n` in the `temp`(temporary) array.
   - This shift allows elements that exceed the array length to wrap back to the beginning.

5. **Copy Back**:
   - Copy the temporary array back to the original array for the final rotated result.

### Key Features

- Supports both left and right rotation with wrap-around handling.
- Efficiently manages large rotation values by using modular arithmetic.
- Uses an auxiliary array to simplify rotation and improve readability.

### Time Complexity

- **Best case**: O(n) for all cases, as each element is moved once.
- **Worst case**: O(n), even when `positions` is very large, since we use `positions % n`.

### Space Complexity

- O(n) due to the temporary array storing the rearranged elements.

## Implementation

The implementation in C includes:

1. **Rotation Function** to shift elements left or right with wrap-around.
2. **Helper Function** to print the array after rotation.
3. **Main Function** to take user input for the `array`, `number of positions`, and `direction`, and demonstrate the usage of the Rotation of Array algorithm.

## Usage

Compile and run the program. Enter the array elements, rotation count, and direction. The program will output the array before and after rotation. This example demonstrates the flexibility of the Rotation of Array algorithm to shift elements in any specified direction while handling wrap-around.