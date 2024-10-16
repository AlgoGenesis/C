# Flood Fill Algorithm Via Recurrsion

The **Flood Fill Algorithm** is a popular recursive algorithm used to determine the area connected to a given node in a multi-dimensional array. It is widely applied in computer graphics, image editing, and game development for filling regions, similar to the "bucket fill" tool found in image editors.

In this implementation, the algorithm starts at a specified point and recursively fills adjacent pixels that match the initial color with a new color. The algorithm checks the four neighbors (up, down, left, and right) of the starting pixel and applies the same logic, spreading the fill across the connected region.

## Problem Definition

 **Objective** : Implement the **Flood Fill Algorithm** to replace all connected pixels of a given color in a 2D grid starting from a specified position with a new color.

### Problem Statement:

Given a 2D matrix (grid) representing a screen where each cell contains an integer representing a color, your task is to perform a flood fill operation starting from a specific cell. Replace the color of the starting cell and all its connected neighbors (4-directionally: up, down, left, right) with a new color, provided they match the original color of the starting cell.

### Input:

1. A 2D grid `screen[r][c]` where each element is an integer representing a color.
2. Two integers `x` and `y` representing the starting position for the flood fill.
3. An integer `newColor` representing the new color to apply.

### Output:

Modify the input grid such that all connected components (including the starting cell) that have the same color as the starting cell are replaced by `newColor`. Return the modified grid.

### Constraints:

1. The grid dimensions `r` (rows) and `c` (columns) are positive integers.
2. The starting position `(x, y)` must be a valid cell inside the grid (0 ≤ x < r, 0 ≤ y < c).
3. The new color may be the same or different from the original color of the starting cell.
4. The grid may have varying values, and not all cells may be connected.

## Algorithm Overview

The **Flood Fill Algorithm** is a recursive approach used to replace the color of a connected region in a 2D grid, starting from a given pixel and propagating to its neighbors that have the same color.

### Key Points:

* **Recursive Algorithm** : The core of the flood fill technique is its recursive nature, where each pixel triggers further exploration of its neighbors.
* **Connectivity** : Only 4-directional neighbors (up, down, left, right) are considered in this version of flood fill, though 8-directional versions also exist.
* **Efficiency** : The algorithm ensures that every pixel in the connected region is visited exactly once, making it efficient with respect to both time and space (though space may increase due to recursion depth).

### Time Complexity:

* **O(r * c)** , where `r` is the number of rows and `c` is the number of columns in the grid. The algorithm visits each pixel at most once.

### Space Complexity:

* **O(r * c)** due to the recursive call stack. In the worst case, all pixels could be part of the connected region, and the stack depth could reach the total number of pixels.

Example:

Original Screen:
1 1 1
1 1 0
1 0 1

After floodFill(x = 1, y = 1, newColor = 2):

2 2 2
2 2 0
2 0 1

## Limitations


1. **Stack Overflow Risk** :
   Large grids cause recursion depth issues.
2. **Inefficiency in Complex Regions** :
   Irregular regions increase unnecessary visits.
3. **High Memory Usage** :
   Recursive calls consume stack memory.
4. **Limited Neighbor Connectivity** :
   Only handles 4-directional neighbors.
5. **No Support for Floating-Points** :
   Works with discrete values only.
6. **Assumes Regular Grid Structure** :
   Not suitable for non-uniform grids.
7. **Not Ideal for Real-Time** :
   Slower performance in dynamic applications.
8. **Degrades with Large Areas** :
   Performance drops with big fill regions.
