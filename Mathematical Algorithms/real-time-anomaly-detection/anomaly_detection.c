#include <stdio.h>
#include <math.h>

#define WINDOW_SIZE 3
#define THRESHOLD 1.5

void calculateRollingZScore(double data[], int size) {
    double sum = 0.0, mean = 0.0, variance = 0.0, stddev = 0.0, zScore;
    
    for (int i = 0; i < size; i++) {
        sum += data[i];
        if (i >= WINDOW_SIZE) sum -= data[i - WINDOW_SIZE];

        if (i >= WINDOW_SIZE - 1) {
            mean = sum / WINDOW_SIZE;
            variance = 0.0;

            for (int j = i - WINDOW_SIZE + 1; j <= i; j++)
                variance += pow(data[j] - mean, 2);

            stddev = sqrt(variance / WINDOW_SIZE);
            zScore = (data[i] - mean) / stddev;

            printf("Index %d: Value = %.2f, Mean = %.2f, StdDev = %.2f, Z-Score = %.2f\n", i, data[i], mean, stddev, zScore);

            if (fabs(zScore) > THRESHOLD) {
                printf("Anomaly detected at index %d: value = %.2f, zScore = %.2f\n", i, data[i], zScore);
            }
        }
    }
}

int main() {
    double data[] = {10, 12, 13, 12, 15, 55, 17, 19, 150, 20}; // Example time series with anomalies
    int size = sizeof(data) / sizeof(data[0]);

    calculateRollingZScore(data, size);

    return 0;
}
