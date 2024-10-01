N-Queens Problem Solver
Description
The N-Queens Problem Solver is a C program that employs a backtracking algorithm to find solutions for placing N queens on an N×N chessboard such that no two queens threaten each other. This classic problem is an excellent illustration of the backtracking technique in algorithm design.

Features
Multiple Solutions: Capable of finding and displaying multiple valid arrangements of queens on the chessboard.
Customizable Board Size: The size of the chessboard can be easily adjusted by modifying the constant N in the code.
Algorithm Overview
The program utilizes the following steps:

Recursive Backtracking: The algorithm attempts to place queens in each column of the chessboard and checks for safety using the isSafe function.

Solution Validation: If a valid position is identified, the queen is placed, and the algorithm recurses to place the next queen in the subsequent column.

Backtracking: If no valid position can be found for a queen, the algorithm backtracks by removing the previously placed queen and trying the next row in the current column.

How to Run
To execute the program, follow these steps:

Compile the Code: Use a C compiler to compile the source code. For example:

bash
gcc -o n_queens n_queens.c
Run the Compiled Program: Execute the compiled program using:

bash
./n_queens
Example Output
Upon execution, the program will display the board with queens placed in valid positions. For instance, the output for a 4×4 board might look like this:

 1  0  0  0 
 0  0  1  0 
 0  0  0  1 
 0  1  0  0 
Limitations
The default implementation is set to solve the 4-Queens problem, but users can easily change the constant N to solve for different board sizes.
License
This project is licensed under the MIT License.
