# Maximum Sum Path in a Triangle Algorithm

## Problem Statement
The **Maximum Sum Path** in a Triangle algorithm is a dynamic programming approach to find the maximum sum path from the top to the bottom of a triangular grid of integers.

## Overview
Purpose: To find the maximum sum path from the top to the bottom of a triangular grid of integers using a dynamic programming approach.

## Pseudocode
function maximumSumPath(triangle):
    n = number of rows in triangle

    // Start from the second last row and move upwards
    for row from n-2 down to 0:
        for col from 0 to row:
            // Update the current element with the maximum sum path
            triangle[row][col] += max(triangle[row + 1][col], triangle[row + 1][col + 1])

    // The top element now contains the maximum sum path
    return triangle[0][0]

## Complexity
- Time Complexity: O(n^2), where n is the number of rows in the triangle.
- Space Complexity: O(1) additional space, as the triangle is modified in place.

## Applications
This algorithm can be applied in various scenarios, such as game development (finding optimal paths), financial modeling, and resource allocation problems.