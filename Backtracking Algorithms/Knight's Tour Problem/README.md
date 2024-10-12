# Knight's Tour Problem

The **Knight's Tour Problem** is a classic backtracking problem that involves finding a sequence of moves for a knight on a chessboard such that it visits every square exactly once. The knight moves in an L-shape, meaning it moves two squares in one direction and then one square perpendicular to that direction. 

The problem can be solved using backtracking algorithms, and it has two variations:
1. **Open Tour**: The knight does not have to return to the starting position.
2. **Closed Tour**: The knight returns to the starting square after visiting all squares.

## Problem Details
- **Chessboard size**: 8x8
- **Objective**: Find a sequence of knight moves such that all 64 squares are visited exactly once.
- **Solution Approach**: The solution uses backtracking to try out all possible moves the knight can make, marking visited squares, and backtracking when no valid move is available.

## How to Run
1. Compile the C program using a C compiler like `gcc`.
    ```bash
    gcc program.c -o knight_tour
    ```
2. Run the compiled program.
    ```bash
    ./knight_tour
    ```

## Example Output
The program will print the sequence of moves in an 8x8 matrix where each number represents the step at which the knight visited that square.

## Files
- `program.c`: C code implementing the Knight's Tour using backtracking.
- `README.md`: This documentation file.

## Future Improvements
- Implement the closed tour version where the knight returns to the starting square.
- Visualize the knight’s movement on a graphical chessboard.


