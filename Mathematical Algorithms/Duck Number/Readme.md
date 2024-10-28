## Duck Number

### Problem Description
A **Duck Number** is a positive integer that contains at least one `0` in any position except the first. Duck Numbers do not start with the digit `0`, but they must have at least one `0` in other positions to qualify.

### Example
- **405**: Duck Number (contains `0` at the second position).
- **102**: Duck Number (contains `0` at the second position).
- **1205**: Duck Number (contains `0` at the third position).
- **321**: Not a Duck Number (no `0` present).
- **0351**: Not a Duck Number (starts with `0`).

### Solution Approach
1. **Input Validation**: Convert the number to a string to easily access each digit.
2. **First Digit Check**: Ensure that the number does not start with `0`, which disqualifies it from being a Duck Number.
3. **Presence of `0` Check**: Scan each position after the first to verify if there’s at least one `0`.
4. **Output Result**: If both conditions are met, the number is a Duck Number; otherwise, it is not.

### Complexity Analysis
- **Time Complexity**: O(n), where n is the number of digits in the number. This is because we check each digit after the first for the presence of `0`.
- **Space Complexity**: O(1), as we only require a constant amount of extra space for the checking process.

### Additional Context
This problem is a classic coding interview question that tests knowledge of number properties, string manipulation, and basic control structures. Understanding Duck Numbers is helpful in exploring other numeric concepts, such as Harshad Numbers, Armstrong Numbers, and Prime Numbers.

### Edge Cases to Consider
1. **Leading Zeros**: Numbers like `0123` should return `false` since they start with `0`.
2. **No Zeros in the Number**: Numbers like `123` should return `false`.
3. **Single-Digit Numbers**: Numbers like `0` or `5` should return `false` since they do not meet the criteria.
4. **Negative Numbers**: If negative numbers are allowed, the function may need adjustments.

### Related Topics
- Number Theory
- String Manipulation
- Basic Algorithms for Interview Preparation
