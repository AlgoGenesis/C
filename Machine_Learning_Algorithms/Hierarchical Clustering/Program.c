#include <stdio.h>
#include <float.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTER 100

// Function to calculate Euclidean distance between two points
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Function to print clusters
void print_clusters(int clusters[][MAX_POINTS], int cluster_sizes[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: ", i + 1);
        for (int j = 0; j < cluster_sizes[i]; j++) {
            printf("%d ", clusters[i][j] + 1); // Output as 1-based index
        }
        printf("\n");
    }
    printf("\n");
}

// Function to find the closest pair of clusters (using single linkage)
void find_closest_clusters(double distance_matrix[MAX_POINTS][MAX_POINTS], int num_clusters, int clusters[][MAX_POINTS], int cluster_sizes[], int *min_i, int *min_j) {
    double min_distance = DBL_MAX;

    // Loop over all pairs of clusters
    for (int i = 0; i < num_clusters; i++) {
        for (int j = i + 1; j < num_clusters; j++) {
            // Find the minimum distance between points in cluster i and cluster j (single linkage)
            for (int p1 = 0; p1 < cluster_sizes[i]; p1++) {
                for (int p2 = 0; p2 < cluster_sizes[j]; p2++) {
                    int point_i = clusters[i][p1];
                    int point_j = clusters[j][p2];
                    double dist = distance_matrix[point_i][point_j];
                    if (dist < min_distance) {
                        min_distance = dist;
                        *min_i = i;
                        *min_j = j;
                    }
                }
            }
        }
    }
}

// Function to merge two clusters
void merge_clusters(int clusters[][MAX_POINTS], int cluster_sizes[], int min_i, int min_j) {
    // Merge cluster j into cluster i
    for (int i = 0; i < cluster_sizes[min_j]; i++) {
        clusters[min_i][cluster_sizes[min_i]++] = clusters[min_j][i];
    }
    
    // Shift the remaining clusters after j one step left
    for (int i = min_j; i < MAX_CLUSTER - 1; i++) {
        for (int j = 0; j < cluster_sizes[i + 1]; j++) {
            clusters[i][j] = clusters[i + 1][j];
        }
        cluster_sizes[i] = cluster_sizes[i + 1];
    }
}

int main() {
    int num_points;
    double points[MAX_POINTS][2];  // To store the coordinates of points
    double distance_matrix[MAX_POINTS][MAX_POINTS];  // Distance matrix
    int clusters[MAX_CLUSTER][MAX_POINTS];  // Clusters (each row stores the indices of points in that cluster)
    int cluster_sizes[MAX_CLUSTER];  // Size of each cluster
    int num_clusters;

    // Input the number of points
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    // Input the coordinates of the points
    printf("Enter the coordinates of the points (x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }

    // Initialize each point as its own cluster
    num_clusters = num_points;
    for (int i = 0; i < num_clusters; i++) {
        clusters[i][0] = i;
        cluster_sizes[i] = 1;
    }

    // Calculate the distance matrix
    for (int i = 0; i < num_points; i++) {
        for (int j = 0; j < num_points; j++) {
            if (i != j) {
                distance_matrix[i][j] = euclidean_distance(points[i][0], points[i][1], points[j][0], points[j][1]);
            } else {
                distance_matrix[i][j] = DBL_MAX;  // Set the distance of a point to itself as infinity
            }
        }
    }

    // Print initial clusters
    printf("\nInitial clusters:\n");
    print_clusters(clusters, cluster_sizes, num_clusters);

    // Perform hierarchical clustering
    while (num_clusters > 1) {
        int min_i = -1, min_j = -1;

        // Find the closest clusters
        find_closest_clusters(distance_matrix, num_clusters, clusters, cluster_sizes, &min_i, &min_j);

        // Merge the closest clusters
        merge_clusters(clusters, cluster_sizes, min_i, min_j);
        num_clusters--;

        // Print the clusters after merging
        printf("Clusters after merging:\n");
        print_clusters(clusters, cluster_sizes, num_clusters);
    }

    return 0;
}