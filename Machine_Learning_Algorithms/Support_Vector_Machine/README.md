# Support Vector Machine (SVM) Algorithm

## Description
Support Vector Machine (SVM) is a supervised machine learning algorithm that is used for both classification and regression tasks. The main objective of SVM is to find a hyperplane in an N-dimensional space that distinctly classifies the data points. For non-linearly separable data, SVM uses a kernel trick to transform the data into a higher dimension where it can be separated by a hyperplane.

## Key Features

- **Hyperplane**: A decision boundary that best separates the classes.
- **Support Vectors**: Data points that are closest to the hyperplane and influence its position.
- **Maximal Margin**: SVM tries to maximize the margin between the two classes.
- **Kernel Trick**: Transforms non-linearly separable data into a higher dimension to make it linearly separable.

## Problem Definition
Given a dataset with features and labels, SVM tries to find the hyperplane that best separates different classes by maximizing the margin between them.

- **Input**: Training data with features and labels.
- **Output**: A decision boundary (hyperplane) that can classify new data points.

## Algorithm Review

### Finding the Optimal Hyperplane
SVM tries to find the hyperplane that best separates the data points by maximizing the margin between the closest points (support vectors) of each class.

### Kernel Trick (for Non-linear Data)
For data that is not linearly separable, SVM applies a kernel function (e.g., polynomial, radial basis function) to transform the data into a higher-dimensional space where it can be separated.

### Classification
Once the hyperplane is found, new data points are classified based on which side of the hyperplane they lie on.

## Time Complexity
- **Training**: O(n²) to O(n³) depending on the size of the dataset, where n is the number of training samples.
- **Prediction**: O(k), where k is the number of support vectors.

## Applications
- **Classification**: Text classification, image recognition, bioinformatics, etc.
- **Regression**: Predicting continuous values (e.g., stock prices).
- **Anomaly Detection**: Identifying outliers in datasets.

## Conclusion
SVM is a robust and versatile machine learning algorithm, particularly useful for classification tasks. It is effective in high-dimensional spaces and when the number of dimensions exceeds the number of samples. However, SVM can be computationally expensive, and its performance depends heavily on the choice of kernel and regularization parameter.
