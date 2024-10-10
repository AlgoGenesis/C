# Binary String Generator

## Description
The Binary String Generator is an algorithm that utilizes the Branch and Bound technique to generate all possible binary strings of a specified length \( N \). A binary string consists of digits that can either be 0 or 1. The goal is to systematically explore and print all combinations of binary strings of the given length.

## Problem Definition
Given:
- An integer \( N \) representing the length of the binary strings.

Objective:
- Generate and print all possible binary strings of length \( N \), where each position in the string can either be 0 or 1.

## Algorithm Overview
The algorithm constructs binary strings using a recursive approach. Starting from an empty string, it appends either a 0 or a 1 at each level of recursion until the desired length \( N \) is reached. When a binary string of length \( N \) is formed, it is printed.

### Steps:
1. **Node Creation**: Initialize a root node representing the start of the binary string generation.
2. **Recursive Generation**:
   - If the current string length matches \( N \), print the generated binary string.
   - If not, for each possible binary digit (0 and 1), create a child node, assign the current binary string, and make a recursive call to generate further.
3. **Memory Management**: Free allocated memory for nodes after use to prevent memory leaks.

## Functions:
- `createNode(Node* parent, int level, int N)`: Allocates memory for a new node and initializes its members.
- `generate(Node* n, int N)`: Recursively generates binary strings, prints completed strings, and manages node creation.
- `main()`: Manages user input and initiates the binary string generation process.

## Time Complexity
The time complexity of generating binary strings of length \( N \) is \( O(2^N) \). This complexity arises because there are \( 2^N \) possible combinations of binary digits, as each position can independently be either 0 or 1. Each combination is printed as it is formed, leading to an exponential growth in the number of strings generated as \( N \) increases.
