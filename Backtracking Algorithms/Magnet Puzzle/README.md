### Magnet puzzle Solving Algorithm

## Description
The magnet puzzle is commonly referred to as "Magnet Puzzle Problem" or "Magnet Placement Problem". It is a type of combinatorial puzzle that can be solved using backtracking algorithms. This problem typically involves placing magnets (represented as poles) on a grid, adhering to specific rules and constraints.


### Explanation :
Grid Representation: The grid is represented by a 2D array rules where:

'L' and 'R' denote left and right parts of a horizontal magnet.
'T' and 'B' denote top and bottom parts of a vertical magnet.
'+' represents North pole, and '-' represents South pole.
'x' denotes cells that don't contain any magnet poles.
Backtracking Logic:

The function solveMagnets explores all possible ways to place magnets horizontally or vertically.
The function checks constraints with checkConstraints to ensure the placement matches the number of North and South poles in each row and column.
It tries different magnet configurations (+-, -+, xx) and recursively checks if the placement works.
If a valid configuration is found, the grid is printed.
Base Case: When the algorithm reaches the end of the grid (i == M and j == 0), it checks if the current configuration satisfies the constraints and prints the result.


### Code explanation with  Example: ###
L and R mean that a horizontal magnet can be placed here, where L is the left side and R is the right side.
T and B mean that a vertical magnet can be placed here, where T is the top side and B is the bottom side.
The goal is to fill the grid with North poles (+) and South poles (-) of magnets according to constraints for rows and columns, ensuring no magnets conflict with each other.
Step-by-Step Breakdown:
Understanding the Grid:

Each magnet consists of two parts: + (North pole) and - (South pole).
A horizontal magnet can be placed in the L and R cells as either +- or -+.
A vertical magnet can be placed in the T and B cells as either +- or -+.
Some cells can be left empty, marked with xx.
Initial Setup:

The program starts with the grid filled with L, R, T, B.
The algorithm begins at the top-left corner of the grid and tries to place magnets.
The goal is to place magnets in a way that satisfies some constraints (i.e., the number of + and - magnets per row and column).
What the Code Does:
Backtracking Process:

The algorithm starts with the first cell (0, 0) which is L. Since L is the left part of a magnet, it tries placing different horizontal patterns:
First Option: Place +- (North pole in L, South pole in R).
Second Option: Place -+ (South pole in L, North pole in R).
Third Option: Leave it empty (xx).
After trying one option, the algorithm moves to the next magnet location (in this case, (0, 2)), and repeats the same process.

Checking for Validity:

Each time the algorithm tries to place a magnet, it checks if the placement is valid using the canPutPatternHorizontally and canPutPatternVertically functions. These functions ensure that:
The magnet does not conflict with neighboring magnets (e.g., placing two North poles (+) side by side would be invalid).
Moving Through the Grid:

The algorithm continues placing magnets one by one, moving through the grid.
If it reaches the end of a row, it moves to the next row and continues.
Checking Constraints:

After placing magnets in the entire grid, the algorithm checks if the solution satisfies the given constraints for the number of + and - magnets in each row and column.
This is done by counting how many + and - magnets are in each row and column, and comparing these counts with the predefined constraints.

### Time Complexity
Number of Decisions:
At each cell where a magnet's left ('L') or top ('T') part is present, the algorithm makes three decisions:
Place a +- or -+ magnet.
Place no magnet (xx).
For every cell that contains L or T, there are 3 options. Given that each horizontal or vertical magnet occupies two cells, the number of decisions grows based on the number of magnet positions in the grid.
Recursive Depth:

The recursion goes as deep as the number of rows and columns of the grid, exploring different possibilities at each recursive level.
Total Possibilities:

Suppose the grid has k pairs of L/R or T/B where the algorithm makes decisions. Each pair has 3 possible states (place +-, place -+, or xx), leading to approximately 3^k possible configurations.
The value of k is less than or equal to M * N / 2, where M and N are the number of rows and columns of the grid, because each magnet occupies 2 cells (either horizontally or vertically).
Therefore, the time complexity is  O(3^(M×N)/2) in worst case.

### Space complexity: ###
Grid Storage:
The grid itself is of size M x N, so the space to store the grid is 𝑂(𝑀×𝑁).
The recursive depth can go as deep as the number of cells, i.e., O(M×N), because each recursive call processes one or more cells.
In the worst case, if the entire grid needs to be explored recursively, the recursion depth is proportional to the number of cells.
i.e Space Complexity: O(M×N)