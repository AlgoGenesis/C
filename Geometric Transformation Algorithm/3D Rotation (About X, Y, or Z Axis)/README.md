# README for 3D Rotation (User-Specified Axis)

This project implements a 3D Rotation algorithm in C, where the user specifies the axis of rotation (X, Y, or Z) along with the rotation angle. It transforms a 3D point to new coordinates after rotation.

## Process

### User Input:
1. The user is prompted to enter the coordinates of the point in 3D: (x, y, z).
2. The user chooses the axis of rotation: X, Y, or Z.
3. The user specifies the rotation angle in degrees.

### Rotation Calculation:
The program rotates the input point about the chosen axis using trigonometric transformations:

#### X-axis Rotation:
-  newY = y * cos(angle) - z * sin(angle)  
-  newZ = y * sin(angle) + z * cos(angle)

#### Y-axis Rotation:
-   newX = x * cos(angle) + z * sin(angle)
-   newZ = -x * sin(angle) + z * cos(angle)

#### Z-axis Rotation:
-   newX = x * cos(angle) - y * sin(angle)  
-   newY = x * sin(angle) + y * cos(angle)

### Output:
The program prints the new coordinates of the point after rotation.

## Example Run

### Input:
Enter the coordinates of the point (x y z): 1 2 3  
Enter the axis of rotation (X, Y, or Z): Z  
Enter the rotation angle (in degrees): 90


### Output:
After rotation about Z-axis: (1, 2, 3) -> (-2, 1, 3)

# Complexity Analysis
### Time Complexity:𝑂(1) 
O(1) since the program performs a constant number of operations regardless of input size.

### Space Complexity:𝑂(1) 
O(1) as no extra memory is allocated beyond the basic variables for coordinates and calculations.

# Assumptions
The program assumes the angle is entered in degrees and converts it to radians internally.
It only rotates about one axis at a time.
The axis input is case-insensitive (X, Y, or Z)." format this file 
