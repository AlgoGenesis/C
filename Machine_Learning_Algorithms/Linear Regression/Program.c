#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 1000  // Maximum number of data points

// Function to calculate the mean of an array
double mean(double arr[], int size) {
    double sum = 0;  // Initialize sum to zero
    for (int i = 0; i < size; i++) {
        sum += arr[i];  // Accumulate the sum of the elements
    }
    return sum / size;  // Return the mean value
}

// Function to calculate the linear regression coefficients
void linear_regression(double x[], double y[], int n, double *slope, double *intercept) {
    double x_mean = mean(x, n);  // Calculate mean of x values
    double y_mean = mean(y, n);  // Calculate mean of y values
    
    double numerator = 0.0, denominator = 0.0;  // Initialize numerator and denominator for slope calculation
    for (int i = 0; i < n; i++) {
        // Calculate the numerator and denominator for the slope (m)
        numerator += (x[i] - x_mean) * (y[i] - y_mean);
        denominator += (x[i] - x_mean) * (x[i] - x_mean);
    }

    // Calculate the slope (m) and intercept (b) for the linear regression equation
    *slope = numerator / denominator;
    *intercept = y_mean - (*slope) * x_mean;
}

int main() {
    int n;  // Number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);  // Read the number of data points from user input

    // Check if the number of data points exceeds the maximum limit
    if (n > MAX_DATA) {
        printf("Too many data points! Limit is %d\n", MAX_DATA);
        return 1;  // Exit the program with an error code
    }

    // Allocate memory for x and y values
    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));

    // Read x and y values from user input
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("Data point %d - x: ", i + 1);
        scanf("%lf", &x[i]);  // Read x value for data point i
        printf("Data point %d - y: ", i + 1);
        scanf("%lf", &y[i]);  // Read y value for data point i
    }

    double slope, intercept;  // Variables to hold the slope and intercept of the regression line
    linear_regression(x, y, n, &slope, &intercept);  // Call the linear regression function

    // Output the linear regression equation
    printf("Linear Regression Equation: y = %.2fx + %.2f\n", slope, intercept);

    // Free the allocated memory for x and y values
    free(x);
    free(y);

    return 0;  // Exit the program successfully
}

