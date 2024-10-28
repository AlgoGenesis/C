# Strassen's Algorithm for Matrix Multiplication

This repository contains a C implementation of **Strassen's Algorithm** for matrix multiplication. Strassen's Algorithm is an efficient divide-and-conquer method for multiplying two square matrices, achieving a time complexity of approximately **O(n^2.81)**, which is faster than the standard **O(n^3)** matrix multiplication method.

## Features

- Efficient matrix multiplication using Strassen's Algorithm.
- Works for matrices whose size is a power of 2.
- Can handle matrices of any size by padding with zeros.
- Recursive divide-and-conquer approach.
- Fully documented and commented code for easy understanding.

## Getting Started

### Prerequisites

To run this code, you'll need a C compiler such as GCC. If you're on Linux or macOS, you likely already have GCC installed. For Windows, you can use MinGW or any other compiler of your choice.

## Time complexity
Here, we assume that integer operations take O(1) time. There are three for loops in this algorithm and one is nested in other. Hence, the algorithm takes O(n3) time to execute.