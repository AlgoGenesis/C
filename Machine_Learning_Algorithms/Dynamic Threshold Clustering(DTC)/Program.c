#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000         // Maximum number of data points
#define INITIAL_RADIUS 1.0      // Initial radius for neighbor search
#define MIN_DENSITY 2           // Minimum density to form a cluster
#define MIN_CLUSTER_SIZE 2      // Minimum size for a cluster

// Structure to represent a point in 2D space
typedef struct {
    double x;                  // x-coordinate
    double y;                  // y-coordinate
    int cluster_id;           // Cluster identifier
} Point;

// Function to calculate the Euclidean distance between two points
double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find neighbors of a given point within a specified radius
int find_neighbors(Point* data, int num_points, Point point, double radius, int* neighbors) {
    int count = 0; // Count of neighbors found
    for (int i = 0; i < num_points; i++) {
        // Check if the distance to the current point is within the radius
        if (euclidean_distance(point, data[i]) <= radius) {
            neighbors[count++] = i; // Add the index of the neighbor
        }
    }
    return count; // Return the total number of neighbors found
}

// Function to calculate the dynamic threshold for clustering
double calculate_dynamic_threshold(Point* data, int num_points) {
    // Simple example: average distance between all pairs of points
    double total_distance = 0;
    int count = 0;
    for (int i = 0; i < num_points; i++) {
        for (int j = i + 1; j < num_points; j++) {
            total_distance += euclidean_distance(data[i], data[j]);
            count++;
        }
    }
    return count > 0 ? total_distance / count : INITIAL_RADIUS; // Return average distance or initial radius
}

// Main function to perform dynamic threshold clustering
void dynamic_threshold_clustering(Point* data, int num_points, int* clusters, int* noise) {
    int cluster_id = 0; // Initialize cluster identifier
    int visited[MAX_POINTS] = {0}; // Array to track visited points
    double dynamic_threshold = calculate_dynamic_threshold(data, num_points); // Calculate the dynamic threshold

    // Iterate through each point in the dataset
    for (int i = 0; i < num_points; i++) {
        if (visited[i]) continue; // Skip already visited points

        int neighbors[MAX_POINTS]; // Array to store indices of neighbors
        int neighbor_count = find_neighbors(data, num_points, data[i], INITIAL_RADIUS, neighbors); // Find neighbors

        // If the number of neighbors meets the dynamic threshold
        if (neighbor_count >= dynamic_threshold) {
            clusters[i] = cluster_id; // Assign cluster ID to the current point
            cluster_id++; // Increment cluster ID

            // Assign cluster ID to all neighboring points
            for (int j = 0; j < neighbor_count; j++) {
                int neighbor_index = neighbors[j];
                visited[neighbor_index] = 1; // Mark as visited
                clusters[neighbor_index] = cluster_id - 1; // Assign the same cluster ID
            }
        } else {
            noise[i] = 1; // Mark current point as noise
        }
        visited[i] = 1; // Mark current point as visited
    }
}

int main() {
    // Example dataset with points
    Point data[MAX_POINTS] = {
        {1.0, 2.0}, {1.1, 2.1}, {10.0, 10.0}, {10.5, 10.5}, {5.0, 5.0}
    };
    int num_points = 5; // Number of points in the dataset
    int clusters[MAX_POINTS] = {-1}; // Array to store cluster IDs (-1 indicates unassigned)
    int noise[MAX_POINTS] = {0}; // Array to mark noise points (0 indicates not noise)

    // Perform clustering
    dynamic_threshold_clustering(data, num_points, clusters, noise);

    // Output the clustering results
    printf("Clusters:\n");
    for (int i = 0; i < num_points; i++) {
        if (clusters[i] != -1) {
            printf("Point (%.1f, %.1f) -> Cluster %d\n", data[i].x, data[i].y, clusters[i]);
        } else {
            printf("Point (%.1f, %.1f) is noise\n", data[i].x, data[i].y);
        }
    }

    return 0; // End of program
}
