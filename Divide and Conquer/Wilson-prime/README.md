# Wilson Prime Algorithm

## Description

The **Wilson Prime Algorithm** is a number-theory-based algorithm that checks whether a given prime number is a Wilson prime. Wilson primes are a special category of prime numbers that satisfy Wilson’s Theorem. Wilson’s Theorem states that a prime number `p` is a Wilson prime if it satisfies the following condition:

\[
(p-1)! \equiv -1 \ (\text{mod} \ p^2)
\]

A Wilson prime is rare, with only three known examples: 5, 13, and 563.

### Problem Definition
The goal of the algorithm is to determine whether a given prime number `p` is a Wilson prime by computing the factorial of `p-1`, taking modulo `p^2`, and checking if the result equals `p^2 - 1`.

Given:

A prime number `p` to be evaluated for Wilson prime status.

Objective:

- **Efficiency**: Although computing factorial values can be computationally expensive, Wilson’s prime algorithm focuses on the modular arithmetic properties of primes.
- **Factorial Modulo**: The algorithm calculates the factorial of `p-1` and computes its remainder when divided by `p^2`. If the result is `p^2 - 1`, then the number is a Wilson prime.

### Algorithm Overview

The `is_wilson_prime()` function first calls the `factorial_mod()` function, which computes the factorial of `p-1` modulo `p^2` to prevent overflow. Then, `is_wilson_prime()` checks if the result is equal to `p^2 - 1`.

The steps of the algorithm are as follows:

1. **Factorial Modulo Calculation**: Calculate `(p-1)! % (p^2)`.
2. **Wilson Prime Check**: Verify whether the result equals `p^2 - 1`. If true, `p` is a Wilson prime.
3. **Prime Verification**: Before performing the Wilson prime check, the number `p` is verified to be prime using a simple primality check.

### Time Complexity

The time complexity of the Wilson Prime Algorithm depends primarily on the factorial calculation. For a given prime `p`, computing the factorial of `p-1` takes `O(p)` iterations, and the modulo operation is performed in constant time. Thus, the overall time complexity is **O(p)**. However, since the factorial grows very fast, the algorithm is not efficient for large prime numbers.