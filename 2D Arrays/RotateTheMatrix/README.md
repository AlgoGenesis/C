# Matrix Rotation

Matrix rotation is the process of shifting the elements of a matrix either clockwise or counterclockwise by 90 degrees. The most common rotation is by 90 degrees clockwise, which involves rearranging the elements in a way that turns the matrix without changing its shape.

## 90-Degree Clockwise Rotation:
To rotate a matrix by 90 degrees clockwise:

Transpose the matrix (i.e., swap the rows and columns).
Reverse the order of the elements in each row.
Example:
If we have the following 2X2 matrix:

Matrix A:

        1 2
        3 4 

After rotating 90 degrees clockwise, the matrix becomes:

Matrix A (Rotated 90° Clockwise):

        3 1
        4 2

## Steps to Rotate:

Transpose the matrix: This step converts rows into columns.

Transposed matrix:

        1 3
        2 4

Reverse each row: This gives us the final rotated matrix.

Rotated matrix:

        3 1
        4 2

## Program Explanation:

In this program, we:

Prompt the user to input the dimensions and elements of the matrix.
Transpose the matrix by swapping rows and columns.
Reverse the rows to complete the 90-degree clockwise rotation.
Display the rotated matrix.

## Other Rotations:

90-Degree Counterclockwise: To rotate the matrix 90 degrees counterclockwise, first transpose the matrix, then reverse the columns instead of rows.
180-Degree Rotation: To rotate a matrix by 180 degrees, reverse both rows and columns without transposing.