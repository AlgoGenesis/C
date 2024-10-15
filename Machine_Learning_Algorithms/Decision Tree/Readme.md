# Decision Tree Algorithm

## Description

A Decision Tree is a flowchart-like structure where each internal node represents a decision based on a feature, each branch represents the outcome of that decision, and each leaf node represents a class label (or continuous value in regression). It is used for both classification and regression tasks.

## Key Features
- **Tree Structure**: Hierarchical structure of decisions that leads to a final outcome.
- **Feature-Based Decisions**: Splits data based on feature values to make decisions.
- **Non-Linear Model**: Can capture non-linear relationships between features and the output.
- **Easy Interpretation**: Visual representation makes it easy to understand and interpret.

## Problem Definition

Given a dataset with features and labels, the Decision Tree splits the data recursively based on feature values until it reaches pure subsets (or a stopping condition).

- **Input**: Training data with features and labels.
- **Output**: A decision tree that can classify new data points.

## Algorithm Review

### 1. Data Splitting
Recursively split the data by choosing the feature and threshold that best separates the data points (based on metrics like Gini Index, Entropy).

### 2. Node Creation
For each split, create a decision node. If a node becomes pure (i.e., contains only one class label) or meets a stopping criterion, it becomes a leaf node.

### 3. Prediction
To classify a new data point, traverse the tree from the root node, making decisions based on feature values until reaching a leaf node. The label of the leaf node is the predicted class.

## Time Complexity

- **Tree Construction**: O(n log n), where `n` is the number of data points.
- **Prediction**: O(log n) as we only traverse the height of the tree.

## Applications

Decision Trees are widely used in:
- **Classification Tasks**: Spam detection, fraud detection, etc.
- **Regression Tasks**: Predicting continuous values (e.g., housing prices).
- **Feature Importance**: Understanding the importance of features in the decision-making process.

## Conclusion

Decision Trees are a powerful and interpretable tool for both classification and regression tasks. They are non-parametric models, capable of capturing complex decision boundaries. However, they are prone to overfitting, so techniques like pruning and ensemble methods (Random Forests) are often applied.
