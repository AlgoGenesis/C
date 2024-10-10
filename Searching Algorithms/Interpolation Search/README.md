### Problem Statement

Interpolation Search is an algorithm used to search for a given target value within a sorted array. It is an improvement over Binary Search for instances where the values in the array are uniformly distributed. The algorithm estimates the position of the target value based on the values at the start and end of the array, rather than always checking the middle element as in Binary Search.

### Algorithm Overview

1. **Initialization**: Start with two pointers, `low` and `high`, which point to the first and last elements of the array, respectively.

2. **Position Estimation**: Calculate the estimated position of the target value using the formula:
   \[
   \text{pos} = \text{low} + \left(\frac{(\text{target} - \text{arr[low]}) \times (\text{high} - \text{low})}{\text{arr[high]} - \text{arr[low]}}\right)
   \]
   This formula assumes that the target value is linearly distributed between `arr[low]` and `arr[high]`.

3. **Comparison**:
   - If `arr[pos]` is the target value, return `pos`.
   - If `arr[pos]` is less than the target, update `low` to `pos + 1`.
   - If `arr[pos]` is greater than the target, update `high` to `pos - 1`.

4. **Repeat**: Continue the process until `low` is less than or equal to `high` and the target is within the range of `arr[low]` to `arr[high]`.

5. **Termination**: If the target is not found, return an indication (e.g., `-1`) that the target is not present in the array.

### Time Complexity

The average time complexity of Interpolation Search is \(O(\log \log n)\) when the elements are uniformly distributed. However, in the worst case, such as when the elements are not uniformly distributed, the time complexity can degrade to \(O(n)\).
