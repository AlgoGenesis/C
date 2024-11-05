#include <stdio.h>

void scale3D(float x, float y, float z, float scaleX, float scaleY, float scaleZ, float *x_scaled, float *y_scaled, float *z_scaled) {
    *x_scaled = x * scaleX;
    *y_scaled = y * scaleY;
    *z_scaled = z * scaleZ;
}

int main() {
    float x, y, z;               // Original coordinates
    float scaleX, scaleY, scaleZ; // Scaling factors
    float x_scaled, y_scaled, z_scaled;

    // Taking user input
    printf("Enter the coordinates (x, y, z): ");
    scanf("%f %f %f", &x, &y, &z);

    printf("Enter the scaling factors (scaleX, scaleY, scaleZ): ");
    scanf("%f %f %f", &scaleX, &scaleY, &scaleZ);

    // Applying scaling transformation
    scale3D(x, y, z, scaleX, scaleY, scaleZ, &x_scaled, &y_scaled, &z_scaled);

    // Displaying the result
    printf("Scaled coordinates: (%.2f, %.2f, %.2f)\n", x_scaled, y_scaled, z_scaled);

    return 0;
}
