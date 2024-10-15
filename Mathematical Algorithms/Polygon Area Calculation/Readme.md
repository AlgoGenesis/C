# Polygon Area Calculation

## Description

This program calculates the area of a polygon given its vertices using the Shoelace formula. The user can input the coordinates of the polygon's vertices, and the program will output the calculated area.

## Structures

1. **Point**:
   - A structure to represent a 2D point with x and y coordinates.
   - Members:
     - `int x`: The x-coordinate of the point.
     - `int y`: The y-coordinate of the point.

## Functions

1. **double polygonArea(struct Point points[], int n)**:
   - Calculates the area of the polygon using the Shoelace formula.
   - Parameters:
     - `points[]`: An array of `Point` structures representing the vertices of the polygon.
     - `n`: The number of vertices in the polygon.
   - Returns: The area of the polygon as a double.

## Main Function:

### Details:

- Prompts the user to enter the number of vertices \(n\).
- Dynamically allocates memory for an array of `Point` structures.
- For each vertex, the user inputs the x and y coordinates, which are stored in the points array.
- Calls the `polygonArea` function to calculate the area of the polygon.
- Outputs the calculated area to the user.
- Frees the dynamically allocated memory for the points array before exiting.

## Memory Management

- Uses dynamic memory allocation for storing the vertices of the polygon.
- Frees allocated memory to prevent memory leaks.

### Time Complexity:
- The area calculation takes \(O(n)\), where \(n\) is the number of vertices.

### Usage:
1. Compile the program using a C compiler (e.g., `gcc polygon_area.c -o polygon_area`).
2. Run the program (`./polygon_area`).
3. Follow the prompts to enter the number of vertices and their coordinates.
4. The program will output the area of the polygon.

