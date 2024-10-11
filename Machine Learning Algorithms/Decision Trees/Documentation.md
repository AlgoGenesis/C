
## 3. Decision Trees

### Algorithm Overview
Decision Trees are a **supervised learning** algorithm used for both **classification** and **regression** tasks. They work by recursively splitting the data based on features to create a tree of decisions. Each internal node represents a decision (based on a feature), and the leaf nodes represent class labels or predicted values.

### Steps:
1. **Splitting the Data:** Choose a feature and split the dataset into branches based on feature values.
2. **Recursion:** Repeat this process for each branch, creating a tree structure.
3. **Prediction:** Classify new data by traversing the tree based on the feature values of the test data.

### Use Cases:
- **Medical diagnosis** (e.g., diagnosing a disease based on symptoms).
- **Loan approval** (e.g., predicting whether a loan will be approved based on financial history).
- **Customer segmentation** (e.g., categorizing customers based on purchasing behavior).

### Potential Limitations:
- **Prone to overfitting**, especially with deep trees. This can be mitigated by pruning the tree or setting a maximum depth.
- **Sensitive to noisy data**, which can lead to overly complex trees.
- **Non-linear relationships** may not be handled well without proper preprocessing.

### Test Case for Decision Trees:
```c
struct Node* tree = build_tree();
double test_data[1] = {3.0};
int predicted_label = predict(tree, test_data);
```

### Example Dataset:
- **Features:** Patient age (in years).
- **Labels:** 0 (no disease), 1 (disease present).
```c
DataPoint train_data[] = {
    {{25}, 0}, {{45}, 1}, {{35}, 0}, {{60}, 1}, {{50}, 1}
};
```

---

## Test Cases and Example Datasets:

### 1. **KNN Example Dataset:**
- **Scenario:** Classifying types of flowers based on petal length and width.
```c
DataPoint train_data[] = {
    {{1.5, 0.2}, 0}, {{2.3, 0.3}, 0}, {{4.5, 1.5}, 1}, {{5.1, 1.8}, 1}, {{5.9, 2.3}, 2}
};
double test_point[] = {3.2, 0.8};  // Classify this point
```

### 2. **Linear Regression Example Dataset:**
- **Scenario:** Predicting house prices based on size.
```c
double x[] = {1000, 1500, 2000, 2500, 3000};  // House size in sq ft
double y[] = {150, 200, 250, 300, 350};       // Price in thousands
```

### 3. **Decision Trees Example Dataset:**
- **Scenario:** Classifying risk levels for loan approval.
```c
DataPoint train_data[] = {
    {{30}, 0}, {{45}, 1}, {{35}, 0}, {{60}, 1}, {{50}, 1}
};
double test_data[1] = {40};  // Test for age 40
```
