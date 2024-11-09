# Josephus Problem Algorithm (Recursive Solution)

## Overview

The **Josephus Problem** is a theoretical problem related to a group of people standing in a circle, where every `k`-th person is eliminated in each round until only one person remains. The challenge is to determine the position in which a person should stand to avoid elimination and be the last one standing.

This repository contains a C program that solves the Josephus Problem using a recursive approach. The program takes two inputs:
- `n`: the total number of people in the circle.
- `k`: the step count at which people are eliminated.

## Theory

In the Josephus Problem:
- If there is only one person, they will be the survivor by default (base case).
- For any other number of people, the problem can be reduced recursively. Each time a person is eliminated, the circle effectively shrinks, and the position of the next person changes.

The recursive formula for finding the safe position is:
\[ \text{Josephus}(n, k) = (\text{Josephus}(n-1, k) + k) \% n \]
where:
- `n` is the number of people remaining,
- `k` is the step count.

Using this recursive relation, we start with one person (`n = 1`) and build up to the solution for `n` people.

## Code Example

The main code logic is implemented in the function `josephus(int n, int k)`. Here’s the pseudocode outline:
1. Base case: If there’s only one person, they are the survivor.
2. Recursive case: For more than one person, recursively calculate the safe position for `n - 1` people, adjust by the step count `k`, and use modulo `n` to wrap around the circle.

### Time Complexity

The time complexity of this recursive approach is **O(n)**. This is because each recursive call reduces the problem size by 1, and there are `n` calls in total (one for each person).

### Space Complexity

The space complexity is **O(n)** due to the recursive stack, which holds up to `n` frames as the function calls itself for each person until reaching the base case.

## Usage

### Input
The program prompts the user for:
1. The number of people in the circle (`n`).
2. The step count for elimination (`k`).

### Output
The program outputs the safe position, which is the position a person should occupy to be the last one standing.

### Sample Output

For `n = 7` people and `k = 3` as the step count:
```plaintext
Enter the number of people (n): 7
Enter the step count (k): 3
The safe position is 4
```

### How to Run
1. Compile the program using a C compiler:
   ```bash
   gcc josephus.c -o josephus
   ```
2. Run the compiled program:
   ```bash
   ./josephus
   ```

## Conclusion

The Josephus Problem is a classic example of a recursive solution that reduces the problem size with each step. The algorithm demonstrates the power of recursion in solving combinatorial problems efficiently by using a mathematical recurrence relation. This solution, while optimal in time complexity, has a space complexity of `O(n)` due to recursion depth, making it efficient for moderate values of `n`.
