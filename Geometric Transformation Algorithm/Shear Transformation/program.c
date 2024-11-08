#include <stdio.h>

void shear2D(int x[], int y[], int n, float shearX, float shearY) {
    printf("\nSheared Coordinates:\n");
    for (int i = 0; i < n; i++) {
        int newX = x[i] + shearX * y[i];
        int newY = y[i] + shearY * x[i];
        printf("(%d, %d) -> (%d, %d)\n", x[i], y[i], newX, newY);
    }
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    
    int x[n], y[n];
    printf("Enter the coordinates of the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    
    float shearX, shearY;
    printf("Enter the shear factors (shearX shearY): ");
    scanf("%f %f", &shearX, &shearY);

    shear2D(x, y, n, shearX, shearY);
    return 0;
}
