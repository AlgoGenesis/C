
# Fibonacci Number Calculator

## Overview
This repository contains a C implementation for calculating Fibonacci numbers using matrix exponentiation. This is a divide and conquer algorithm which efficiently computes the nth Fibonacci number in O(log n) time, making it suitable for large values of n.

## Features
- **Matrix Exponentiation**: Utilizes the properties of matrices to compute Fibonacci numbers efficiently.
- **Fast Computation**: Achieves O(log n) time complexity for calculations.


## What are Fibonacci Numbers?
Fibonacci numbers are a sequence where each number is the sum of the two preceding ones, usually starting with 0 and 1. The sequence is formally defined as:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1

The Fibonacci sequence is commonly used in various computational algorithms and real-world applications.

## How does Matrix Exponentiation work?
Matrix exponentiation leverages the transformation matrix for Fibonacci numbers:
![image](https://github.com/user-attachments/assets/ebfeeb1b-1e4b-4978-920b-68e4aea59116)

By raising this matrix to the power of n-1, the top-left cell of the resulting matrix will contain the nth Fibonacci number. This method significantly reduces the number of calculations required compared to iterative or recursive methods.

## Usage
To use the Fibonacci number calculator, compile the provided C code and run the executable. The program prompts the user for input and returns the corresponding Fibonacci number.

