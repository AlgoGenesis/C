#include <stdio.h>

// Function to calculate the slope and intercept for linear regression
void linear_regression(double x[], double y[], int n, double* slope, double* intercept) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }

    *slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    *intercept = (sum_y - (*slope) * sum_x) / n;
}

// Function to predict y values using the trained model
double predict(double slope, double intercept, double x) {
    return slope * x + intercept;
}

int main() {
    // Example training data
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {1, 2, 1.3, 3.75, 2.25};
    int n = 5;

    double slope, intercept;
    linear_regression(x, y, n, &slope, &intercept);

    printf("Trained model: y = %.2fx + %.2f\n", slope, intercept);

    // Predict a new value
    double new_x = 6;
    double predicted_y = predict(slope, intercept, new_x);
    printf("Predicted value for x=%.2f: y=%.2f\n", new_x, predicted_y);

    return 0;
}
