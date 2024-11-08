#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *features;  // Array of features
    int label;         // Class label
} Point;

// Calculate Euclidean distance between two points
double euclidean_distance(Point p1, Point p2, int feature_count) {
    double sum = 0;
    for (int i = 0; i < feature_count; i++) {
        sum += pow(p1.features[i] - p2.features[i], 2);
    }
    return sqrt(sum);
}

// Sort the distances and return the majority label (KNN)
int knn_classify(Point *data, int data_count, Point target, int feature_count, int k) {
    double *distances = (double *)malloc(data_count * sizeof(double));
    int *labels = (int *)malloc(data_count * sizeof(int));

    for (int i = 0; i < data_count; i++) {
        distances[i] = euclidean_distance(data[i], target, feature_count);
        labels[i] = data[i].label;
    }

    // Simple sorting (Selection Sort)
    for (int i = 0; i < data_count - 1; i++) {
        for (int j = i + 1; j < data_count; j++) {
            if (distances[i] > distances[j]) {
                double temp_dist = distances[i];
                distances[i] = distances[j];
                distances[j] = temp_dist;

                int temp_label = labels[i];
                labels[i] = labels[j];
                labels[j] = temp_label;
            }
        }
    }

    // Majority voting (for binary classification)
    int label_counts[2] = {0, 0};
    for (int i = 0; i < k; i++) {
        label_counts[labels[i]]++;
    }

    free(distances);
    free(labels);

    return (label_counts[0] > label_counts[1]) ? 0 : 1;
}

int main() {
    int data_count, feature_count, k;
    
    // Input for number of data points and features
    printf("Enter number of data points: ");
    scanf("%d", &data_count);
    printf("Enter number of features: ");
    scanf("%d", &feature_count);
    
    Point *data = (Point *)malloc(data_count * sizeof(Point));
    
    // Input the data points
    for (int i = 0; i < data_count; i++) {
        data[i].features = (double *)malloc(feature_count * sizeof(double));
        printf("Enter features for data point %d: ", i + 1);
        for (int j = 0; j < feature_count; j++) {
            scanf("%lf", &data[i].features[j]);
        }
        printf("Enter label (0 or 1) for data point %d: ", i + 1);
        scanf("%d", &data[i].label);
    }

    // Input the value of k for KNN
    printf("Enter value of k: ");
    scanf("%d", &k);

    // Input target point
    Point target;
    target.features = (double *)malloc(feature_count * sizeof(double));
    printf("Enter features for target point: ");
    for (int j = 0; j < feature_count; j++) {
        scanf("%lf", &target.features[j]);
    }

    // Classify the target point using KNN
    int result = knn_classify(data, data_count, target, feature_count, k);
    printf("The predicted class of the target point is: %d\n", result);

    // Free allocated memory
    for (int i = 0; i < data_count; i++) {
        free(data[i].features);
    }
    free(data);
    free(target.features);

    return 0;
}
