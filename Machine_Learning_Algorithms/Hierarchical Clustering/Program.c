#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Function to calculate Euclidean distance
double euclidean_distance(double *point1, double *point2, int dimension) {
    double sum = 0.0;
    for (int i = 0; i < dimension; i++) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// Function to perform Agglomerative Hierarchical Clustering
void hierarchical_clustering(double data[MAX][MAX], int num_points, int dimension) {
    int clusters[MAX], cluster_count = num_points;

    // Initialize clusters
    for (int i = 0; i < num_points; i++) {
        clusters[i] = i;
    }

    // Main clustering loop
    while (cluster_count > 1) {
        double min_distance = INFINITY;
        int cluster1 = -1, cluster2 = -1;

        // Find the closest clusters
        for (int i = 0; i < num_points; i++) {
            for (int j = i + 1; j < num_points; j++) {
                if (clusters[i] != clusters[j]) {
                    double distance = euclidean_distance(data[i], data[j], dimension);
                    if (distance < min_distance) {
                        min_distance = distance;
                        cluster1 = clusters[i];
                        cluster2 = clusters[j];
                    }
                }
            }
        }

        // Merge clusters
        for (int i = 0; i < num_points; i++) {
            if (clusters[i] == cluster2) {
                clusters[i] = cluster1;
            }
        }

        cluster_count--;
        printf("Merged clusters: %d and %d\n", cluster1, cluster2);
    }
}

int main() {
    double data[MAX][MAX];
    int num_points, dimension;

    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    printf("Enter the number of dimensions: ");
    scanf("%d", &dimension);

    printf("Enter the data points:\n");
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < dimension; j++) {
            scanf("%lf", &data[i][j]);
        }
    }

    hierarchical_clustering(data, num_points, dimension);

    return 0;
}
