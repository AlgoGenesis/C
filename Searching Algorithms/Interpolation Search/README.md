# Interpolation Search Algorithm

## Overview

Interpolation Search is an efficient search algorithm for finding the position of a target value within a sorted array. It works on the principle of estimating the position of the target based on the values at the endpoints of the current search range, making it particularly effective for uniformly distributed data.

## Features

- **Time Complexity:** O(log log n) on average for uniformly distributed data.
- **Space Complexity:** O(1), as it uses a constant amount of additional space.
- **Best Suited For:** Large, sorted arrays with uniformly distributed values.

## How It Works

1. **Initialization:**
   - Start with two pointers, `lo` and `hi`, which represent the bounds of the array segment being searched.

2. **Condition Check:**
   - The search continues as long as the target value is within the range defined by the values at the `lo` and `hi` indices.

3. **Position Estimation:**
   - Calculate the probe position using the formula:
     \[
     \text{pos} = \text{lo} + \left(\frac{(\text{hi} - \text{lo})}{(\text{arr[hi]} - \text{arr[lo]})} \times (x - \text{arr[lo]})\right)
     \]
   - This formula helps to estimate where the target value might be located based on the current bounds.

4. **Comparison:**
   - If the value at the probe position matches the target, return the index.
   - If the target is greater than the value at the probe position, adjust the lower bound (`lo`).
   - If the target is smaller, adjust the upper bound (`hi`).

5. **Result:**
   - If the target is not found, return -1.