
## Overview
The **Cascade Search** algorithm is a sequential filtering process where data points are passed through multiple stages, each with progressively stricter criteria (thresholds). If a data point fails to meet the threshold at any stage, it is discarded, reducing the number of data points that need to be processed at subsequent stages. This approach can significantly improve efficiency, especially in applications such as object detection, where irrelevant data can be filtered early.

In this C code implementation, we generate a list of random values and filter them through three stages, each with a specified threshold.

## How to Use

### Prerequisites
This code requires a C compiler, such as GCC.

### Compilation and Execution
1. **Compile** the code:
   ```bash
   gcc cascade_search.c -o cascade_search
   ```
2. **Run** the compiled program:
   ```bash
   ./cascade_search
   ```

### Code Structure
- **`generate_data`**: Generates an array of random integers between 0 and 99.
- **`print_data`**: Prints the generated array.
- **`cascade_stage`**: Checks if a data point meets a specified threshold.
- **`cascade_search`**: Applies the three-stage filtering process on the generated data array, printing values that pass all thresholds.

### Example Output
The program first displays the randomly generated data, then iteratively prints values that pass each of the three stages.

```
Generated Data:
32 73 24 85 ... 97 43 22

Running Cascade Search...
Stage 1 (Threshold: 50):
Data[1] = 73 passed Stage 1
Data[3] = 85 passed Stage 1
...
Data[3] = 85 passed Stage 2
...
Data[9] = 97 passed Stage 3
```

## Time Complexity
The time complexity of this cascade search algorithm depends on the input size \( N \) and the percentage of data points that pass each stage:
- **Best Case**: \( O(N) \), if all data points fail the first stage (minimal filtering required).
- **Average Case**: \( O(N) \), assuming a constant fraction of data points pass each stage.
- **Worst Case**: \( O(N) \), if all elements pass all stages, requiring every data point to go through each threshold.

Since each stage in this code operates independently with constant-time comparisons, time complexity per stage remains linear relative to the input size.

## Space Complexity
The space complexity of this algorithm is:
- **\( O(N) \)** for the array to store generated data.
- **\( O(1) \)** additional space, since no extra data structures are used.

Overall, the space complexity is **\( O(N) \)**.



