#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point in 2D plane
struct Point
{
    int x, y;
};

// A utility function to calculate the distance between two points
float distance(struct Point p1, struct Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

// A comparison function to sort points according to their x-coordinates
int compareX(const void *a, const void *b)
{
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return (p1->x - p2->x);
}

// A comparison function to sort points according to their y-coordinates
int compareY(const void *a, const void *b)
{
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return (p1->y - p2->y);
}

// A brute force method to return the smallest distance between two points in P[] of size n
float bruteForce(struct Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distance(P[i], P[j]) < min)
                min = distance(P[i], P[j]);
    return min;
}

// A utility function to find the minimum of two float values
float min(float x, float y)
{
    return (x < y) ? x : y;
}

// A function to find the distance between the closest points in the strip.
// The points in strip[] are sorted according to their y-coordinates.
// This function uses the fact that a closest pair of points in a strip
// is at most 6 comparisons.
float stripClosest(struct Point strip[], int size, float d)
{
    float min = d; // Initialize the minimum distance as d

    // Pick all points one by one and try the next points until the difference
    // between y-coordinates is smaller than d.
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (distance(strip[i], strip[j]) < min)
                min = distance(strip[i], strip[j]);

    return min;
}

// A recursive function to find the smallest distance in P[] of size n.
float closestUtil(struct Point P[], struct Point Y[], int n)
{
    // If there are 3 or fewer points, use brute force
    if (n <= 3)
        return bruteForce(P, n);

    // Find the middle point
    int mid = n / 2;
    struct Point midPoint = P[mid];

    // Divide points in y sorted array into two halves
    struct Point YLeft[mid];
    struct Point YRight[n - mid];
    int li = 0, ri = 0; // Indices for left and right halves
    for (int i = 0; i < n; i++)
    {
        if (Y[i].x <= midPoint.x)
        {
            YLeft[li++] = Y[i];
        }
        else
        {
            YRight[ri++] = Y[i];
        }
    }

    // Recursively find the smallest distances in left and right halves
    float dl = closestUtil(P, YLeft, mid);
    float dr = closestUtil(P + mid, YRight, n - mid);

    // Find the smaller of the two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains points close (closer than d) to the line passing through the middle point
    struct Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Y[i].x - midPoint.x) < d)
            strip[j] = Y[i], j++;

    // Find the closest points in strip. Return the minimum of d and the closest distance in strip[]
    return min(d, stripClosest(strip, j, d));
}

// The main function that finds the smallest distance between points in P[] of size n.
float closest(struct Point P[], int n)
{
    struct Point Y[n];
    for (int i = 0; i < n; i++)
        Y[i] = P[i];

    // Sort the points according to their x-coordinates
    qsort(P, n, sizeof(struct Point), compareX);
    // Sort the points according to their y-coordinates
    qsort(Y, n, sizeof(struct Point), compareY);

    // Use recursive function closestUtil() to find the smallest distance
    return closestUtil(P, Y, n);
}

// Driver program to test above functions
int main()
{
    struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f\n", closest(P, n));
    return 0;
}
