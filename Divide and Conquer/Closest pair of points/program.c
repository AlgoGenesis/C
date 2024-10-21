#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// A structure to represent a Point in 2D plane
struct Point
{
	int x, y;
};

// Sort array of points according to X coordinate
int compareX(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}
// Sort array of points according to Y coordinate
int compareY(const void* a, const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

// Find the distance between two points
float dist(Point p1, Point p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
				(p1.y - p2.y)*(p1.y - p2.y)
			);
}

// Return the smallest distance between two points
float bruteForce(Point P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

// Find a minimum of two float values
float min(float x, float y)
{
	return (x < y)? x : y;
}


// Find the distance between the closest points of strip of a given size.
float stripClosest(Point strip[], int size, float d)
{
	float min = d;

	qsort(strip, size, sizeof(Point), compareY); 

	// Pick all points one by one and try the next points till the difference between y coordinates is smaller than d.
	for (int i = 0; i < size; ++i)
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);

	return min;
}

// A recursive function to find the smallest distance
float closestUtil(Point P[], int n)
{
	if (n <= 3)
		return bruteForce(P, n);

	int mid = n/2;
	Point midPoint = P[mid];

	// calculate the smallest distance dl on left of middle point and dr on right side
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n-mid);

	float d = min(dl, dr);

	Point strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	return min(d, stripClosest(strip, j, d) );
}

// Finds the smallest distance
float closest(Point P[], int n)
{
	qsort(P, n, sizeof(Point), compareX);

	return closestUtil(P, n);
}

int main()
{
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]);
	printf("The smallest distance is %f ", closest(P, n));
	return 0;
}
