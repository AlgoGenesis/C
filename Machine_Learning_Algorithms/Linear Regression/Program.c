#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 1000

// Function to calculate the mean
double mean(double arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the linear regression coefficients
void linear_regression(double x[], double y[], int n, double *slope, double *intercept) {
    double x_mean = mean(x, n);
    double y_mean = mean(y, n);
    
    double numerator = 0.0, denominator = 0.0;
    for (int i = 0; i < n; i++) {
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }

    *slope = numerator / denominator;
    *intercept = y_mean - (*slope) * x_mean;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n > MAX_DATA) {
        printf("Too many data points! Limit is %d\n", MAX_DATA);
        return 1;
    }

    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));

    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("Data point %d - x: ", i + 1);
        scanf("%lf", &x[i]);
        printf("Data point %d - y: ", i + 1);
        scanf("%lf", &y[i]);
    }

    double slope, intercept;
    linear_regression(x, y, n, &slope, &intercept);

    printf("Linear Regression Equation: y = %.2fx + %.2f\n", slope, intercept);

    free(x);
    free(y);

    return 0;
}
