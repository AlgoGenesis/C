# Wave Sort Program in C

## Overview
This program sorts an array of integers using the Wave Sort algorithm. The array is sorted in such a way that every even-indexed element is greater than its adjacent odd-indexed elements. 

For example, if the input array is `[3, 6, 5, 10, 7, 20]`, the wave sorted output will be `[6, 3, 10, 5, 20, 7]`.

## How It Works
The algorithm iterates through the array with a step size of 2, comparing each element with its neighbors:
- If the current element is smaller than the previous element (on the left), they are swapped.
- If the current element is smaller than the next element (on the right), they are swapped.

### Key Function
- **`waveSort(int arr[], int n)`**: This function rearranges the elements of the array into a wave-like structure.
  - It swaps the elements to ensure that `arr[i] >= arr[i-1]` and `arr[i] >= arr[i+1]` for every even `i`.

## Requirements
- A C compiler (e.g., GCC)

## How to Compile and Run
1. Copy the code into a file named `wave_sort.c`.
2. Open a terminal and navigate to the folder where `wave_sort.c` is located.
3. Compile the program using the following command:
   ```bash
   gcc wave_sort.c -o wave_sort

To run the program : 
  ./wave_sort
