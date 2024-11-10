

# Predictive Scheduling in C

## Overview

This project implements a predictive scheduling algorithm using the Shortest Job First (SJF) method. The goal of predictive scheduling is to minimize the overall wait time by predicting each process's burst time and scheduling processes accordingly. The prediction model here uses exponential averaging, which calculates the predicted burst time based on previous burst times.

## Features

- Predicts the next burst time for each process using exponential averaging.
- Sorts processes based on their predicted burst times to simulate a "Shortest Predicted Job First" (SPJF) scheduling strategy.
- Adjustable smoothing factor (`alpha`) for predictions, making the model adaptable to different levels of variation in process burst times.

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC)

### Compilation
To compile the program, run:
```bash
gcc predictive_scheduling.c -o predictive_scheduling
```

### Usage
To run the program:
```bash
./predictive_scheduling
```

You will be prompted to:
1. Enter the number of processes.
2. Enter each process’s burst time.

### Example
```
Enter number of processes: 3
Enter burst time for process 1: 6
Enter burst time for process 2: 2
Enter burst time for process 3: 8

Scheduled Processes (in order of predicted burst time):
PID     Burst Time      Predicted Burst Time
2       2               2
1       6               4
3       8               5
```

## Code Explanation

### Key Components

1. **Predictive Burst Time Calculation**: Uses exponential averaging to predict each process's next burst time.
2. **Sorting by Predicted Burst Time**: Processes are sorted in ascending order of their predicted burst times to simulate a predictive scheduling strategy.

### Parameters

- `alpha`: Smoothing factor used for exponential averaging. A value of 0.5 is commonly used, but you can adjust it to make the prediction more or less sensitive to recent burst times.

## Complexity Analysis

### Time Complexity

1. **Predictive Burst Time Calculation**: This step is `O(n)`, where `n` is the number of processes. For each process, we calculate the predicted burst based on the previous burst time.
   
2. **Sorting Processes by Predicted Burst Time**: The sorting step has a time complexity of `O(n^2)` due to the bubble sort used here. This can be optimized to `O(n log n)` if we replace it with a more efficient sorting algorithm like quicksort or mergesort.

   **Overall Time Complexity**: `O(n^2)` (with bubble sort), but it can be improved to `O(n log n)` with a more efficient sorting algorithm.

### Space Complexity

1. **Process Storage**: We store `n` processes, each with three attributes (`pid`, `burstTime`, and `predictedBurst`), resulting in a space complexity of `O(n)`.

2. **Auxiliary Space**: Sorting does not require additional memory for bubble sort; hence, auxiliary space complexity is `O(1)`.

   **Overall Space Complexity**: `O(n)`

## Improvements

- **Sorting Optimization**: Replace bubble sort with quicksort or mergesort to improve time complexity.
- **Dynamic Prediction Models**: Implement other predictive models like linear regression for more accurate burst time predictions based on larger historical data.



