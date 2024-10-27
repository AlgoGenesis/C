#include <stdio.h>

struct Point {
    int x;
    int y;
};

// Function to calculate the area of the polygon using the Shoelace formula
double polygonArea(struct Point points[], int n) {
    double area = 0.0;

    // Calculate area using the Shoelace formula
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // Wrap around to the first point
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }

    return fabs(area) / 2.0; // Return the absolute value of the area divided by 2
}

int main() {
    int n;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    struct Point points[n];

    // Input the vertices of the polygon
    printf("Enter the coordinates of the vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // Calculate the area
    double area = polygonArea(points, n);

    // Output the area
    printf("The area of the polygon is: %.2f\n", area);

    return 0;
}
