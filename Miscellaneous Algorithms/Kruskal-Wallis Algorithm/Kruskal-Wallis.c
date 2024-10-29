//Kruskal-Wallis Algorithm

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    int group;
} DataPoint;

int compare(const void *a, const void *b) {
    return ((DataPoint *)a)->value > ((DataPoint *)b)->value ? 1 : -1;
}

void kruskal_wallis(int *groups, double *data, int n, int k) {
    DataPoint *points = (DataPoint *)malloc(n * sizeof(DataPoint));
    
    for (int i = 0; i < n; i++) {
        points[i].value = data[i];
        points[i].group = groups[i];
    }

    // Rank data
    qsort(points, n, sizeof(DataPoint), compare);
    double *rank = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        rank[i] = i + 1;  // Ranks start at 1
    }

    // Sum of ranks for each group
    double *rank_sum = (double *)calloc(k, sizeof(double));
    int *group_count = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < n; i++) {
        rank_sum[points[i].group - 1] += rank[i];
        group_count[points[i].group - 1]++;
    }

    // Calculate H
    double H = 0.0;
    for (int j = 0; j < k; j++) {
        H += (rank_sum[j] * rank_sum[j]) / group_count[j];
    }
    H = (12.0 / (n * (n + 1))) * H - 3 * (n + 1);

    // Free allocated memory
    free(points);
    free(rank);
    free(rank_sum);
    free(group_count);

    printf("Kruskal-Wallis H statistic: %lf\n", H);
}

int main() {
    int groups[] = {1, 1, 2, 2, 3, 3}; // Group identifiers
    double data[] = {10, 12, 20, 22, 30, 32}; // Observations
    int n = sizeof(data) / sizeof(data[0]);
    int k = 3; // Number of groups

    kruskal_wallis(groups, data, n, k);
    return 0;
}
