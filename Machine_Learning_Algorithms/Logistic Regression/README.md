# Logistic Regression Algorithm

## Description

Logistic Regression is a statistical method for binary classification that models the relationship between a dependent binary variable and one or more independent variables. It uses a logistic function to model the probability of the default class (usually labeled as 1) based on the input features. Logistic Regression can be extended to multiple classes through techniques such as One-vs-Rest (OvR).

## Key Features
- **Binary Classification**: Primarily used for predicting two classes.
- **Probability Output**: Provides a probability score that indicates the likelihood of a data point belonging to the positive class.
- **Linear Decision Boundary**: Creates a linear decision boundary in the feature space to separate classes.
- **Interpretability**: Coefficients can be interpreted to understand feature impacts.

## Problem Definition

Given a dataset, Logistic Regression predicts the probability that a given input belongs to the default class. The algorithm applies a logistic function to transform the linear combination of input features into a probability.

- **Input**: A dataset with features (independent variables) and a binary target variable (dependent variable).
- **Output**: The predicted probability of the positive class, which can be thresholded to classify data points.

## Algorithm Review

### 1. Initialization
Choose the initial coefficients for the independent variables, which will be optimized during training.

### 2. Sigmoid Function
Calculate the predicted probability using the sigmoid function:
\[ P(y=1 | X) = \frac{1}{1 + e^{-z}} \]
where \( z \) is the linear combination of input features and their coefficients.

### 3. Cost Function
Define the cost function (log loss) to measure the difference between predicted probabilities and actual labels:
\[ J(\theta) = -\frac{1}{m} \sum_{i=1}^{m} [y^{(i)} \log(h_{\theta}(x^{(i)})) + (1 - y^{(i)}) \log(1 - h_{\theta}(x^{(i)}))] \]

### 4. Optimization
Use optimization algorithms (e.g., Gradient Descent or Newton's Method) to minimize the cost function and update the coefficients iteratively.

### 5. Prediction
After training, use the learned coefficients to predict probabilities for new instances. Apply a threshold (commonly 0.5) to classify them into binary categories.

## Time Complexity

- **Training Phase**: O(n * d), where `n` is the number of data points and `d` is the number of features (due to matrix operations).
- **Prediction Phase**: O(d) for calculating probabilities.

## Applications

Logistic Regression is widely used in:
- **Medical Diagnosis**: Predicting the presence or absence of diseases.
- **Spam Detection**: Classifying emails as spam or not spam.
- **Credit Scoring**: Assessing the probability of default on loans.

## Conclusion

Logistic Regression is a fundamental algorithm in machine learning that is easy to implement and interpret. Despite its simplicity, it serves as a baseline for binary classification tasks and is effective for linearly separable data. Its probability outputs and ease of interpretation make it valuable in various domains.
