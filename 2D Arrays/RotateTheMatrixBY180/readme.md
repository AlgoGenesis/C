## Explanation

# Function rotate:
1. Purpose: Rotates a given matrix by 180 degrees.
2. Parameters:
     1. int mat[MAX][MAX]: The matrix to be rotated.
     2. int row: Number of rows in the matrix.
     3. int c: Number of columns in the matrix.
3. Logic:
     1. The function iterates over half of the rows (row / 2).
     2. For each element in the opposite corner, they swap with each other.
     3. If the number of rows is odd, it additionally swaps the elements in the middle row.
-----

# Function printm:
1. Purpose: Prints the matrix to the console.
2. Parameters:
    1. int mat[MAX][MAX]: The matrix to print.
    2. int row: Number of rows.
    3. int c: Number of columns.
3. Logic: Uses nested loops to iterate through each element of the matrix and prints it.
-----

# main Function:
1. Initializes a matrix mat[MAX][MAX] and variables for rows and columns.
2. Asks the user to input the number of rows and columns, followed by the matrix elements.
3. Calls printm to display the original matrix.
4. Calls rotate to rotate the matrix by 180 degrees.
5. Calls printm again to display the rotated matrix.
-----

# Key Points 
1. The code is designed for a maximum matrix size of 10x10.
2. The rotation doesn't require additional memory for a new matrix.
3. The program ensures that both even and odd row counts are handled correctly for the rotation.
-----

# Complexity
Time Complexity: O(row*c)
Space Complexity: O(1)

# input-sample example:
Enter number of rows and columns: 3 3
Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9
# output-sample example:
Original Matrix:
1 2 3 
4 5 6 
7 8 9 
Matrix after 180-degree rotation:
9 8 7 
6 5 4 
3 2 1 