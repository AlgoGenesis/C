# Searching for an Element in a Matrix

Searching for an element in a matrix involves checking each element of the matrix to find a specific value. This operation can be performed in different ways, depending on the structure of the matrix (e.g., unsorted or sorted). For simplicity, this document focuses on searching in an unsorted matrix.

## Approach:

Linear Search: The most straightforward method is to use a linear search, which examines each element in the matrix one by one. This method works well for unsorted matrices, as there is no specific order to take advantage of.

## Example:

Consider the following 3x3 matrix:

Matrix A:

        1 2
        3 4 

## To search for the element 4:

Start at the first element (1) and compare it with the target.
Move through the matrix row by row until the element is found or all elements have been checked.
If we find 4, the output will indicate the position (row and column) of the element

## Program Explanation:
In this program, we:

Prompt the user to input the dimensions and elements of the matrix.
Ask for the target element to search for.
Implement a linear search algorithm to traverse the matrix and check each element against the target.
Display the result indicating whether the element was found and its position in the matrix, or if it was not found.
Complexity:
Time Complexity: O(m×n) where m is the number of rows and n is the number of columns.
Space Complexity: O(1) since no additional space is used beyond variables for indices and the target.