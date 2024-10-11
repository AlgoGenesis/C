## Word Search in 2D Grid

### Problem Description
The problem gives us a 2D grid of characters called board and a string word. Our task is to determine if word exists in the grid. A word is said to exist in the grid if it can be formed by tracing a path through adjacent cells. Cells are considered adjacent if they are directly above, below, to the left, or to the right of one another (diagonal adjacency is not allowed). As we trace the path to form the word, we cannot use the same cell more than once. The goal is to return true if the word can be constructed from the grid following these rules, otherwise, we return false.

## Does the problem have small constraints?

Yes: The constraints are small enough that a solution involving exploration of all possible paths (like checking every potential start position for the word) could be feasible.

Here's the thinking process for arriving at the DFS solution approach:

Start at Every Cell: We need to consider every cell in the grid as a potential starting point of our word.

Explore Adjacent Cells: Once we've picked a starting cell, we look at its adjacent cells. If the current cell contains the correct letter (the next letter in word that we're looking for), we can move onto this adjacent cell.

Track Where We've Been: In order not to use the same cell twice, we temporarily modify the current cell in the grid to mark it as 'visited'. This way, we avoid re-visiting cells on the current path. It's important to remember to reset this cell back to its original state after we finish searching from that cell.

Use Recursion for Simplicity: Implementing our DFS as a recursive function is convenient because it allows us to easily backtrack (undo our choice of the current letter and try a different path) if we realize we can't spell out the entire word from the current path.

Termination Conditions: The DFS should terminate when we have successfully found the last letter of word, or when we have run out of valid paths to pursue. In the first case, we immediately return true, and in the second case, once all possibilities have been exhausted from a certain cell, we return false.

Writing this logic into a recursive function dfs, we're able to perform a thorough search from each starting cell until we find a path that matches word. By using the function any(), we execute our DFS starting from each cell and return true as soon as at least one call to dfs returns true.

## Solution Approach
The solution utilizes a recursive Depth-First Search (DFS) algorithm to navigate through the board. Let's walk through the key components of the implementation.

Base Case
Each recursive dfs call has a base case that compares the length of the word we're looking for with the index k:

if k == len(word) - 1:
    return board[i][j] == word[k]
This condition checks if we've reached the end of the word. If so, we compare the current cell's character with the last character of the word. If they match, it means we've successfully found word in the board.

Current Letter Match Check
Before diving deeper, we ensure that the current cell's character matches the current letter in word we're looking for:

if board[i][j] != word[k]:
    return False
If it doesn't match, there's no point in continuing from this cell, so we return False.

Avoiding Re-use of the Same Cell
To avoid revisiting the same cell, the solution marks the cell with a placeholder "0":

c = board[i][j]
board[i][j] = "0"
After the placeholder assignment, DFS exploration continues, and once done, the cell is reset to its original state:

board[i][j] = c
Exploring Adjacent Cells
To navigate through adjacent cells, we use a loop that iterates through coordinate offsets. Instead of a standard for loop, it uses pairwise() combined with a tuple (-1, 0, 1, 0, -1) to generate the pairs of offsets representing up, right, down, and left moves:
for a, b in pairwise((-1, 0, 1, 0, -1)):
    x, y = i + a, j + b
The move is valid if it's within the bounds of the grid and the cell has not been visited (marked as '0'):

ok = 0 <= x < m and 0 <= y < n and board[x][y] != "0"
If the move is valid, the dfs is called recursively for the next cell with the index k + 1 to check the following character in the word:

if ok and dfs(x, y, k + 1):
    return True
Kickstarting DFS and Returning Result
The dfs function is invoked for each cell in the grid by using a combination of any() and a nested for loop, which iterates through each cell's indices (i, j):

return any(dfs(i, j, 0) for i in range(m) for j in range(n))
The search terminates and returns true as soon as any starting cell leads to a successful dfs exploration that finds the word.

Imagine we have the following grid and word:

board = [
    ['A', 'B', 'C', 'E'],
    ['S', 'F', 'C', 'S'],
    ['A', 'D', 'E', 'E']
]
word = "SEE"
We want to know whether we can find the word "SEE" in the grid by moving to adjacent cells without reusing any cell.

Start at Every Cell: We initiate our DFS from board[0][0] with A. Since A is not S (the first letter of "SEE"), the search does not continue from here. Next, we try board[0][1] which is B, again not matching 'S'. We continue this process until we find S at board[1][0].

Explore Adjacent Cells: From board[1][0] (which is S), we look at the adjacent cells (board[0][0], board[1][1], board[2][0] and board[1][0] as vowel cells are not considered).

Track Where We've Been: We mark board[1][0] as visited by setting it to "0".

Use Recursion for Simplicity: We start a recursive call from board[1][1] where we find F—not the correct letter, so the call returns False, and we continue the DFS.

Termination Conditions: Continuing the search, board[2][0] is A (also not E), so we move on to board[2][1] (which is D), and finally to board[2][2] which is E - this matches the second letter of "SEE".

The next recursive call starts from board[2][2], and we mark it visited. Its adjacent cells (excluding the one we just came from and marked ones) are checked. board[2][3] is E—the last letter we're looking for.
The base case is met (we are at the last letter of the word), and since board[2][3] matches the last letter of "SEE", the recursive call returns True.

We backtrack, unmarking the visited cells, and propagate the True value upwards through the recursion stack, ultimately return True from the initial call.

Since we've found at least one path that spells "SEE", we can stop the search and return True. No need to check further cells.

##Time Complexity
The time complexity of the problem is O(m*n*k) where m is the number of rows, n is the number of columns and k is the length of the word

 ## Space Complexity 
 Auxiliary space:O(k), recursion stack space 
