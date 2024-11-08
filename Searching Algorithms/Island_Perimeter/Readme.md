## Island Perimeter

# Problem Description
You are given a 2D grid of 0s and 1s, where 1 represents land and 0 represents water. An island is formed by connecting adjacent lands (horizontally or vertically). The task is to calculate the perimeter of the island(s) in the grid. The perimeter is defined as the total length of the edges of the land cells that are either adjacent to water cells or are at the edge of the grid.

# Example

Input:
[
    [0, 1, 0, 0, 0],
    [1, 1, 0, 1, 1],
    [0, 0, 0, 0, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0]
]

Output:
The perimeter of the island is:16

# Solution Approach
Iterate Through the Grid: Loop through each cell in the 2D grid.
Check for Land Cells: When a cell contains a 1, it signifies land.
Calculate Perimeter Contributions:
For each land cell, check its four adjacent cells (up, down, left, right).
For each adjacent cell:
If it is out of bounds (i.e., the cell index is negative or exceeds the grid size) or if it is 0 (water), increment the perimeter count.
Return the Total Perimeter: After iterating through all cells, return the total perimeter count.

# Time Complexity
The time complexity of the algorithm is O(n * m), where n is the number of rows and m is the number of columns in the grid. This is because we iterate through every cell in the grid once, and for each land cell, we check its four adjacent cells.

# Space Complexity
The space complexity is O(1), as we are using a fixed amount of extra space (the perimeter variable and the directions array), regardless of the size of the input grid.