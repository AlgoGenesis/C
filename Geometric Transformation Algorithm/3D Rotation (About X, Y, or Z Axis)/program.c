#include <stdio.h>
#include <math.h>
#include <ctype.h>

void rotate(int *x, int *y, int *z, float angle, char axis) {
    float rad = angle * (M_PI / 180);  // Convert angle to radians
    int newX = *x, newY = *y, newZ = *z;

    if (axis == 'X') {  // Rotate about the X-axis
        newY = round(*y * cos(rad) - *z * sin(rad));
        newZ = round(*y * sin(rad) + *z * cos(rad));
    } else if (axis == 'Y') {  // Rotate about the Y-axis
        newX = round(*x * cos(rad) + *z * sin(rad));
        newZ = round(-*x * sin(rad) + *z * cos(rad));
    } else if (axis == 'Z') {  // Rotate about the Z-axis
        newX = round(*x * cos(rad) - *y * sin(rad));
        newY = round(*x * sin(rad) + *y * cos(rad));
    }

    printf("\nAfter rotation about %c-axis:\n", axis);
    printf("(%d, %d, %d) -> (%d, %d, %d)\n", *x, *y, *z, newX, newY, newZ);
}

int main() {
    int x, y, z;
    float angle;
    char axis;

    printf("Enter the coordinates of the point (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Enter the axis of rotation (X, Y, or Z): ");
    scanf(" %c", &axis);  // Space before %c to avoid newline issue
    axis = toupper(axis); // Ensure consistency with uppercase

    printf("Enter the rotation angle (in degrees): ");
    scanf("%f", &angle);

    rotate(&x, &y, &z, angle, axis);
    return 0;
}
