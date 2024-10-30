# README for 2D Shear Transformation

This project contains a 2D Shear Transformation program in C, which allows users to shear a set of points along both the X-axis and Y-axis based on user-specified shear factors.

## Process

### User Input:
1. The user inputs the number of points.
2. They enter the coordinates for each point as **(x, y)**.
3. They specify the shear factors: **shearX** for the X-axis and **shearY** for the Y-axis.

### Shear Calculation:
The coordinates are transformed using the following equations:  
newX = x[i] + shearX * y[i]   
newY = y[i] + shearY * x[i]  
Each point is updated independently based on the given shear factors.

### Output:
The program prints the new coordinates after applying the shear transformation.

## Example Run

**Input:**
Enter the number of points: 2   
Enter the coordinates of the points (x y): 1 2 3 4  
Enter the shear factors (shearX shearY): 1.0 0.5

**Output:**
Sheared Coordinates: (1, 2) -> (3, 2) (3, 4) -> (5, 5)

## Complexity Analysis

### Time Complexity:
- **O(n)**, where **n** is the number of points. Each point is processed once.

### Space Complexity:
- **O(1)**, as the program only uses input arrays and basic variables.

## Assumptions
- The shear factors are real numbers (floating-point values).
- The program does not validate whether the shear factors result in visually meaningful transformations.
- Input coordinates are assumed to be integers.
