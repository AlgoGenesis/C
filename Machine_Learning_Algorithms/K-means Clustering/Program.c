#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// Struct for a 2D point
typedef struct {
    double x;
    double y;
    int cluster;
} Point;

// Function to calculate Euclidean distance between two points
double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to initialize random centroids
void initialize_centroids(Point *centroids, Point *points, int K, int num_points) {
    for (int i = 0; i < K; i++) {
        int random_index = rand() % num_points;
        centroids[i].x = points[random_index].x;
        centroids[i].y = points[random_index].y;
    }
}

// Function to assign each point to the nearest centroid
void assign_clusters(Point *points, Point *centroids, int K, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = DBL_MAX;
        int best_cluster = 0;
        
        // Check each centroid
        for (int j = 0; j < K; j++) {
            double distance = euclidean_distance(points[i], centroids[j]);
            if (distance < min_distance) {
                min_distance = distance;
                best_cluster = j;
            }
        }
        points[i].cluster = best_cluster;
    }
}

// Function to update centroids based on current clusters
void update_centroids(Point *centroids, Point *points, int K, int num_points) {
    int *cluster_sizes = (int *)calloc(K, sizeof(int));
    Point *new_centroids = (Point *)calloc(K, sizeof(Point));
    
    // Calculate the new centroids
    for (int i = 0; i < num_points; i++) {
        int cluster = points[i].cluster;
        new_centroids[cluster].x += points[i].x;
        new_centroids[cluster].y += points[i].y;
        cluster_sizes[cluster]++;
    }

    for (int i = 0; i < K; i++) {
        if (cluster_sizes[i] > 0) {
            centroids[i].x = new_centroids[i].x / cluster_sizes[i];
            centroids[i].y = new_centroids[i].y / cluster_sizes[i];
        }
    }

    free(cluster_sizes);
    free(new_centroids);
}

// Function to check if centroids have changed
int centroids_changed(Point *old_centroids, Point *new_centroids, int K, double threshold) {
    for (int i = 0; i < K; i++) {
        if (euclidean_distance(old_centroids[i], new_centroids[i]) > threshold) {
            return 1;
        }
    }
    return 0;
}

// K-Means clustering algorithm
void k_means(Point *points, int num_points, int K, int max_iters, double threshold) {
    Point *centroids = (Point *)malloc(K * sizeof(Point));
    Point *old_centroids = (Point *)malloc(K * sizeof(Point));
    
    initialize_centroids(centroids, points, K, num_points);

    int iter = 0;
    while (iter < max_iters) {
        // Copy current centroids to old_centroids
        for (int i = 0; i < K; i++) {
            old_centroids[i] = centroids[i];
        }

        // Assign points to clusters and update centroids
        assign_clusters(points, centroids, K, num_points);
        update_centroids(centroids, points, K, num_points);

        // Check for convergence
        if (!centroids_changed(old_centroids, centroids, K, threshold)) {
            break;
        }
        iter++;
    }

    printf("K-Means converged in %d iterations.\n", iter);

    // Print final centroids
    for (int i = 0; i < K; i++) {
        printf("Centroid %d: (%.2f, %.2f)\n", i, centroids[i].x, centroids[i].y);
    }

    free(centroids);
    free(old_centroids);
}

int main() {
    int num_points = 10;
    int K = 2; // Number of clusters
    int max_iters = 100;
    double threshold = 0.001;

    // Example points (2D)
    Point points[10] = {
        {1.0, 1.0, 0}, {2.0, 1.0, 0}, {4.0, 3.0, 0}, {5.0, 4.0, 0},
        {3.0, 4.0, 0}, {5.0, 2.0, 0}, {6.0, 2.0, 0}, {8.0, 3.0, 0},
        {8.0, 5.0, 0}, {7.0, 4.0, 0}
    };

    // Run K-Means clustering
    k_means(points, num_points, K, max_iters, threshold);

    // Print the final clusters
    for (int i = 0; i < num_points; i++) {
        printf("Point (%.2f, %.2f) is in cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }

    return 0;
}
