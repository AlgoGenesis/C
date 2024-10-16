
# Modular Inverse Using Fermat's Little Theorem

## Overview

This C program computes the **modular multiplicative inverse** of a number `a` under a **prime modulus** `p` using **Fermat's Little Theorem**. The modular inverse of `a` under modulo `p` is the number `x` such that:

\[
a \times x \equiv 1 \ (\text{mod} \ p)
\]

Fermat's Little Theorem states that if `p` is a prime number, then the modular inverse of `a` (where \( 1 \leq a < p \)) can be computed as:

\[
a^{p-2} \mod p
\]

This program uses **binary exponentiation** (also called "exponentiation by squaring") to efficiently compute large powers modulo `p`.

## Prerequisites

- You need a C compiler (like GCC).
- The number `a` must be in the range \(1 \leq a < p\).
- The modulus `p` must be a **prime number**.

## How It Works

- The program takes two inputs from the user:
  1. A number `a` for which you want to find the modular inverse.
  2. A prime modulus `p`.

- The program uses Fermat's Little Theorem to compute \(a^{p-2} \mod p\), which is the modular inverse of `a` under modulo `p`.

## Example

Let’s find the modular inverse of `3` under modulo `11`.

We know that 11 is a prime number.

### Calculation:

Using Fermat's Little Theorem:

\[
3^{11-2} = 3^9 \mod 11
\]

The result is 4, which means the modular inverse of 3 under modulo 11 is 4. In other words:

\[
3 \times 4 \equiv 1 \ (\text{mod} \ 11)
\]

### Input:

- `a = 3`
- `p = 11`

### Output:

```
The modular inverse of 3 under modulo 11 is: 4
```

## Usage

1. Run the code

2. Enter the values of `a` and `p` as prompted.

### Sample Run:

```
Enter the number (a): 3
Enter the prime modulus (p): 11
The modular inverse of 3 under modulo 11 is: 4
```

## Code Explanation

- **`power_mod()`**: Implements binary exponentiation to compute large powers efficiently under a modulus.
- **`mod_inverse()`**: Uses Fermat's Little Theorem to calculate the modular inverse by calling `power_mod(a, p - 2, p)`.
- **`main()`**: Accepts user input, checks for valid inputs, and outputs the modular inverse.

## Edge Cases

- The program checks if `a = 0` or `p <= 1`, which would be invalid input (as the modulus must be prime and `a` must be non-zero).
- Make sure that `p` is a prime number when running the program, as Fermat's theorem is only valid for primes.

--- 
