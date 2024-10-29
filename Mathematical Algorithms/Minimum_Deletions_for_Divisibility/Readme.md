# Minimum Deletions to Make Array Divisible by Array's GCD

## Description

The **Minimum Deletions to Make Array Divisible by Array's GCD** algorithm determines the minimum number of deletions required to make all elements in an array divisible by the array’s greatest common divisor (GCD). This ensures uniformity in the divisibility of array elements, which is useful in contexts like data processing, modular arithmetic, and mathematical computations requiring standardized factors.

## Key Features
- **GCD Calculation**: Finds the GCD of the array to identify the required divisor for all elements.
- **Divisibility Check**: Counts elements not divisible by the GCD, as these must be removed to achieve the goal.
- **Minimum Deletions Calculation**: Outputs the minimum deletions needed for the array to be fully divisible by its GCD.

## Problem Definition

Given an integer array `arr`, the goal is to:
1. Calculate the GCD of all elements in the array.
2. Count the number of elements that are not divisible by this GCD.
3. Return this count as the minimum deletions required for full divisibility by the array's GCD.

- **Input**: An integer array, `arr`.
- **Output**: The minimum number of deletions required for all elements in the array to be divisible by the array's GCD.

## Algorithm Review

### 1. Calculate the GCD of the Array
- Traverse the array and calculate the GCD of all elements using the GCD of each successive pair.

### 2. Check Divisibility of Elements
- For each element in the array, check if it’s divisible by the calculated GCD.
- Count elements that are not divisible, as these need to be deleted to meet the requirement.

### 3. Return Result
- Return the count of non-divisible elements as the minimum deletions needed.

## Time Complexity
- **GCD Calculation**: \(O(n \cdot \log(\text{min}(a, b)))\), where \(n\) is the number of elements and \(a\) and \(b\) are elements in the array.
- **Divisibility Check**: \(O(n)\), since each element is checked once.

Overall, the algorithm has a time complexity of \(O(n \cdot \log(\text{min}(a, b)))\).

## Applications

This algorithm is useful in scenarios requiring uniform divisibility in data elements:
- **Data Validation**: Ensures uniform factors in datasets, commonly used in data pipelines.
- **Mathematical Computations**: Simplifies modular arithmetic and operations by ensuring elements align with the array’s GCD.
- **Array Processing**: Provides an efficient method for preparing arrays in applications requiring homogeneous divisibility.

## Conclusion

The **Minimum Deletions to Make Array Divisible by Array's GCD** algorithm offers an efficient way to enforce uniformity in divisibility within an array. This algorithm finds applications in fields like data processing, modular arithmetic, and number theory, where uniform divisibility is beneficial for simplifying computations and ensuring data consistency.
