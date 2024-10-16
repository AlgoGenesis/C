# Tic-Tac-Toe Game

## Description

Tic-Tac-Toe is a classic two-player game where each player takes turns marking a 3x3 grid with their respective symbols (Player 1 uses 'X' and Player 2 uses 'O'). The objective is to be the first to align three marks in a row, column, or diagonal, thereby winning the game. The game can also be played against the computer in single-player mode.

### Problem Definition

Given:
- A 3x3 Tic-Tac-Toe grid (represented as a 1D array of 9 elements).
- Players either play against each other or against the computer.

Objective:
- Create a game where players take turns marking the grid, with the game concluding when a player wins by aligning three of their symbols, or the game results in a draw if all cells are filled without a winner.

### Game Modes

1. **Single-Player Mode (Player vs. Computer):** The player competes against the computer, with the computer placing its 'O' symbol randomly on the board.
2. **Two-Player Mode (Player vs. Player):** Two players take turns placing their respective symbols on the grid, competing to form a winning combination.

### Rules

- Players can place their symbol ('X' for Player 1, 'O' for Player 2 or the computer) on any empty slot in the 3x3 grid.
- The game checks after every move for a winner, or if the game ends in a draw when the board is full.

### Algorithm Overview

1. **Initialization:** 
   - The 3x3 board is represented as an array with 9 elements, initialized with `*` to indicate empty slots.
   
2. **Game Flow:** 
   - For each turn, the player selects a position on the board to place their mark. If it's a valid move, the mark is placed. If playing against the computer, the computer makes its move by randomly selecting an available slot.

3. **Check for Winner:** 
   - After each move, the game checks whether any player has won by aligning three of their symbols in a row, column, or diagonal.
   
4. **End of Game:** 
   - The game ends either when a player wins or when the board is full and the game is declared a draw.

### Example Output

```c
***************************************
************* TIC TAC TOE *************
***************************************
******* 1. YOU vs COMPUTER ************
******* 2. YOU vs PLAYER **************
******* 3. EXIT ***********************
Enter your choice: 1

* * * 
* * * 
* * * 
Your move (1-9): 5

* * * 
* X * 
* * * 
Computer placed 'O' at position 1

O * * 
* X * 
* * * 
```

### Time Complexity

- In **Single-Player Mode**, the time complexity for each turn is `O(1)` since the computer randomly selects an empty spot from the available positions.
- Checking for a winner requires `O(1)` time as only the relevant rows, columns, and diagonals are checked.

### Space Complexity

The space complexity is `O(1)` since only a fixed-size 1D array of 9 elements is used to represent the board.

This game provides a simple and fun experience for users, allowing them to play against a computer or another player with easy-to-understand rules and mechanics.