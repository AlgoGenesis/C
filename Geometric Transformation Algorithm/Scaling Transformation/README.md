# README for 3D Scaling Program

This project implements a 3D scaling transformation in C. The program allows the user to input a 3D point and apply scaling factors along the X, Y, and Z axes, resizing the point's coordinates accordingly.

## Process

### User Input:
1. The user is prompted to enter the coordinates of the point in 3D: `(x, y, z)`.
2. The user specifies scaling factors for each axis: `scaleX`, `scaleY`, and `scaleZ`.

### Scaling Calculation:
The program applies the scaling transformation to the input point using the following formulas:

```c
x_scaled = x * scaleX;
y_scaled = y * scaleY;
z_scaled = z * scaleZ;
```

### Output:
The program prints the new coordinates of the point after applying the scaling transformation.

## Example Run

**Input:**

Enter the coordinates of the point (x y z): 2 3 4
Enter the scaling factors (scaleX scaleY scaleZ): 1.5 2.0 0.5

**Output:**  

Scaled coordinates: (3.00, 6.00, 2.00)

## Complexity Analysis

- **Time Complexity:**  O(1)   
  The program performs a constant number of operations regardless of input size.

- **Space Complexity:**  O(1) 
  Only basic variables are used for coordinates and calculations, so no additional memory allocation is required.

## Assumptions

- The program assumes valid numeric input for the coordinates and scaling factors.
- Each scaling factor affects only its respective axis.
