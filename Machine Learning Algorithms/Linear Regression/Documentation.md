## 2. Linear Regression

### Algorithm Overview
Linear Regression is a **supervised learning** algorithm used for **regression** tasks, which predicts continuous values. It fits a line to the data that minimizes the sum of squared differences between observed and predicted values (using the **least squares method**).

### Steps:
1. **Calculate the slope (`m`) and intercept (`b`):**
   - `m = (N * Σxy - Σx * Σy) / (N * Σx^2 - (Σx)^2)`
   - `b = (Σy - m * Σx) / N`
2. **Prediction:** Use the formula `y = mx + b` to predict new data points.

### Use Cases:
- **Stock market prediction** (e.g., predicting future stock prices based on historical data).
- **Sales forecasting** (e.g., predicting future sales based on past sales data).
- **Medical research** (e.g., predicting patient outcomes based on clinical data).

### Potential Limitations:
- **Assumes linearity** between the input variables and the output, which may not hold for real-world problems.
- **Sensitive to outliers**, as they can significantly skew the regression line.
- **Collinearity issues** arise when features are highly correlated, affecting model performance.

### Test Case for Linear Regression:
```c
double x[] = {1, 2, 3, 4, 5};
double y[] = {1, 2, 1.3, 3.75, 2.25};
int n = 5;

double slope, intercept;
linear_regression(x, y, n, &slope, &intercept);

// Predict the value for x = 6
double new_x = 6;
double predicted_y = predict(slope, intercept, new_x);
```

### Example Dataset:
- **Features (x):** Hours of study per week.
- **Labels (y):** Scores on a math test.
```c
double x[] = {2, 4, 6, 8, 10};  // Hours of study
double y[] = {50, 60, 65, 70, 80};  // Test scores
```

---
