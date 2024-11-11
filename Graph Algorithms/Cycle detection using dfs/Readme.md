# Longest Increasing Subsequence in C

This program calculates the **Longest Increasing Subsequence (LIS)** in an array of integers, using dynamic programming. It allows users to input the array size and its elements, then outputs the length of the longest increasing subsequence.

## How It Works

The program uses a dynamic programming approach where:
- An auxiliary array, `lis`, is maintained to store the LIS length at each index.
- For each element, it calculates the maximum LIS that ends at that position by considering all previous elements.
- Finally, it finds the maximum value in the `lis` array to determine the length of the longest increasing subsequence.

### Time Complexity
The time complexity of this approach is **O(n²)** due to the nested loops.

### Space Complexity
The space complexity is **O(n)**, as it uses an auxiliary array `lis` of the same length as the input array.

## Getting Started

### Prerequisites

- A C compiler (like GCC).

### Running the Program

1. **Clone the Repository** (optional if using version control):
   ```bash
   git clone https://github.com/your-username/longest-increasing-subsequence
   cd longest-increasing-subsequence
2. **Compile the Code **:

```bash
    Copy code
    gcc lis.c -o lis

3. **Run the Program**:

```bash
    Copy code
    ./lis

**Example Usage**
```bash
Enter the number of elements in the array: 9
Enter the elements of the array:
10 22 9 33 21 50 41 60 80
Length of LIS is 6

In this example, the longest increasing subsequence is [10, 22, 33, 50, 60, 80] with a length of 6.