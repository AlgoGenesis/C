## 1. K-Nearest Neighbors (KNN)

### Algorithm Overview
K-Nearest Neighbors (KNN) is a **supervised learning** algorithm used for **classification** tasks. The algorithm works by comparing a data point to its neighbors (the closest data points in terms of distance) and assigns a label based on the majority vote of its neighbors' labels.

### Steps:
1. **Distance Calculation:** Compute the Euclidean distance between the test data point and all training data points.
2. **Sorting Neighbors:** Identify the `K` nearest neighbors by sorting based on distance.
3. **Voting:** Use majority voting among the labels of the nearest neighbors to classify the new data point.

### Use Cases:
- **Image classification** (e.g., recognizing handwritten digits).
- **Text classification** (e.g., categorizing emails as spam or non-spam).
- **Recommendation systems** (e.g., finding similar users for recommendations).

### Potential Limitations:
- **Computationally expensive** for large datasets as it requires calculating the distance for every point in the dataset.
- **Memory-intensive** since it stores the entire training dataset.
- **Sensitive to irrelevant features**, so feature scaling or selection may be needed.
  
### Test Case for KNN:
```c
DataPoint train_data[] = {
    {{1.0, 2.0}, 0},  // Label 0
    {{2.0, 3.0}, 0},  // Label 0
    {{3.0, 3.0}, 1},  // Label 1
    {{5.0, 4.0}, 1},  // Label 1
    {{1.5, 2.5}, 0}   // Label 0
};
double test_point[] = {2.5, 3.5};
int k = 3;
int predicted_label = knn_classify(train_data, 5, test_point, k);
```

### Example Dataset:
- **Features:** Height (in feet) and weight (in kg).
- **Labels:** 0 (underweight), 1 (healthy weight), 2 (overweight).
```c
DataPoint train_data[] = {
    {{5.1, 50}, 0}, {{5.9, 68}, 1}, {{6.2, 72}, 1}, {{5.5, 45}, 0}, {{6.0, 80}, 2}
};
```

---

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
