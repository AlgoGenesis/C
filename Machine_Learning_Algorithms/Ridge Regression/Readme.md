# Ridge Regression in C

## Description

This project implements **Ridge Regression** in the C programming language. Ridge Regression is a regularized version of linear regression, adding a penalty term to the loss function to shrink coefficients and avoid overfitting. This implementation allows users to solve ridge regression problems for multiple features and output variables, using basic matrix operations like multiplication, transposition, and inversion. The code is written in plain C to demonstrate how Ridge Regression works under the hood without relying on advanced machine learning libraries.

## Key Features

- Implementation of Ridge Regression using matrix operations in C.
- Regularization using the L2 norm to avoid overfitting and improve generalization.
- Supports multivariate linear regression with multiple input features.
- Handles small datasets, but can be scaled for larger data with optimized matrix operations.
- Matrix inversion using **Gauss-Jordan Elimination** for solving normal equations.
- Easy-to-extend implementation that can be adapted for other regression algorithms.

## Problem Definition

In the ordinary least squares linear regression, the objective is to find the coefficients \( \beta \) that minimize the residual sum of squares between observed outcomes \( y \) and predicted outcomes \( X\beta \). However, in cases where the number of predictors is large, the model can overfit the training data, leading to poor generalization to new data.

Ridge Regression addresses this issue by adding a regularization term to the cost function, which penalizes large coefficients, shrinking them toward zero. The optimization problem is defined as:

\[
J(\beta) = ||y - X\beta||^2 + \lambda ||\beta||^2
\]

Where:
- \( X \) is the matrix of input features (with rows corresponding to data points and columns to features),
- \( y \) is the target vector,
- \( \beta \) is the vector of coefficients,
- \( \lambda \) is the regularization parameter.

## Algorithm Review

The Ridge Regression solution is derived from solving the following optimization equation:

\[
\hat{\beta} = (X^TX + \lambda I)^{-1}X^Ty
\]

### Steps Involved:
1. **Matrix Transposition:** Compute the transpose of the input matrix \( X \).
2. **Matrix Multiplication:** Multiply \( X^T \) by \( X \) to get the Gram matrix.
3. **Regularization Term:** Add \( \lambda I \) to \( X^T X \), where \( I \) is the identity matrix and \( \lambda \) is the regularization parameter.
4. **Matrix Inversion:** Invert the matrix \( (X^T X + \lambda I) \) using Gauss-Jordan elimination.
5. **Final Multiplication:** Multiply the inverted matrix by \( X^T y \) to obtain the coefficients \( \beta \).

## Time Complexity

- **Matrix Transposition:** \( O(n \times d) \) where \( n \) is the number of data points, and \( d \) is the number of features.
- **Matrix Multiplication \( X^T \times X \):** \( O(d^2 \times n) \)
- **Matrix Addition \( X^T X + \lambda I \):** \( O(d^2) \)
- **Matrix Inversion (Gauss-Jordan Elimination):** \( O(d^3) \)
- **Final Matrix Multiplication \( (X^T X + \lambda I)^{-1} \times X^T y \):** \( O(d^2) \)

Overall time complexity is dominated by matrix inversion, making it \( O(d^3) \).

## Applications

Ridge Regression is widely used in various fields for predictive modeling where multicollinearity (high correlation between predictors) is present. Some key applications include:

1. **Econometrics:** To model economic processes where data might be noisy and multicollinear.
2. **Genomics:** Predicting gene expression from high-dimensional genomic data with many correlated variables.
3. **Medical Studies:** Modeling relationships between multiple medical factors and outcomes to prevent overfitting in studies with a small sample size.
4. **Finance:** Forecasting trends in financial markets with large datasets and correlated predictors.
5. **Computer Vision:** Predicting outputs from images or video frames where pixel intensities are features.

## Conclusion

This project demonstrates the implementation of Ridge Regression in C using basic matrix operations. By adding a regularization term, Ridge Regression controls overfitting, especially in datasets with many correlated predictors. While this implementation focuses on small datasets, its structure can be optimized or parallelized for large-scale applications. It offers insight into how machine learning algorithms can be implemented from scratch and how linear algebra operations play a fundamental role in regression analysis.

For improvements, you could explore more efficient matrix inversion methods or implement alternative regularization techniques like **Lasso Regression**, which uses an L1 penalty.


## To compile and run the program:
gcc ridge_regression.c -o ridge_regression
./ridge_regression
