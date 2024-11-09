# Bézout’s Identity and Extended Euclidean Algorithm

## Overview

Bézout's Identity provides a way to express the greatest common divisor (GCD) of two integers as a linear combination of those integers. Specifically, for two integers \(a\) and \(b\), Bézout’s Identity states that there exist integers \(x\) and \(y\) such that:

\[
\text{gcd}(a, b) = a \cdot x + b \cdot y
\]

The Extended Euclidean Algorithm is an efficient method for finding these coefficients \(x\) and \(y\), which are often referred to as Bézout coefficients.

## Key Concepts

1. **Greatest Common Divisor (GCD)**: The largest integer that divides both \(a\) and \(b\) without leaving a remainder.
2. **Linear Combination**: A combination of integers where each term is multiplied by a constant and then summed. For example, \(a \cdot x + b \cdot y\) is a linear combination of \(a\) and \(b\).
3. **Bézout's Identity**: The equation that expresses the GCD of two integers as a linear combination of those integers.

## Purpose of Extended Euclidean Algorithm

The Extended Euclidean Algorithm finds integers \(x\) and \(y\) such that:

\[
a \cdot x + b \cdot y = \text{gcd}(a, b)
\]

These coefficients \(x\) and \(y\) are crucial for applications such as:

- Solving Diophantine equations.
- Finding modular inverses in cryptography.
- Simplifying fractions in number theory.

## Algorithm

The Euclidean Algorithm finds the GCD of two integers through repeated division. The Extended Euclidean Algorithm extends this process by keeping track of how each remainder is formed in terms of the previous remainders.

### Steps of the Extended Euclidean Algorithm

1. **Divide**: Divide \(a\) by \(b\) to get the quotient \(q\) and remainder \(r\):
   \[
   a = b \cdot q + r
   \]
   Where \(r = a \mod b\).
   
2. **Repeat**: Replace \(a\) with \(b\) and \(b\) with \(r\) and repeat the division until the remainder \(r\) becomes zero. The last non-zero remainder is the GCD.

3. **Track coefficients**: As you perform the division, track the coefficients for each step that can later be used to express the GCD as a linear combination of \(a\) and \(b\).

### Example: Finding the GCD and Bézout Coefficients

Let’s consider \(a = 30\) and \(b = 12\).

1. Divide \(30\) by \(12\): 
   \[
   30 = 12 \cdot 2 + 6
   \]
   Now, replace \(a = 12\) and \(b = 6\).

2. Divide \(12\) by \(6\):
   \[
   12 = 6 \cdot 2 + 0
   \]
   Since the remainder is zero, the GCD is the last non-zero remainder: \( \text{gcd}(30, 12) = 6 \).

Next, we trace back to find the coefficients \(x\) and \(y\):

3. From the equation \(30 = 12 \cdot 2 + 6\), we can express \(6\) as:
   \[
   6 = 30 - 12 \cdot 2
   \]
   
Thus, we have \(6 = 30 \cdot 1 + 12 \cdot (-2)\). Therefore, the Bézout coefficients are \(x = 1\) and \(y = -2\).

## Applications of Bézout’s Identity

1. **Modular Inverse**: In modular arithmetic, the Extended Euclidean Algorithm can be used to find the modular inverse of \(a\) modulo \(m\). The modular inverse \(a^{-1}\) is the value of \(x\) such that:
   \[
   a \cdot x \equiv 1 \pmod{m}
   \]
   
2. **Cryptography**: Bézout’s Identity plays a central role in cryptographic algorithms such as RSA, where it is used to compute the private key in modular arithmetic.

3. **Diophantine Equations**: The Extended Euclidean Algorithm helps solve equations of the form \(ax + by = c\), where \(a\), \(b\), and \(c\) are given integers.

## Conclusion

The Extended Euclidean Algorithm is a powerful tool in number theory and cryptography, allowing us to not only find the greatest common divisor of two numbers but also express it as a linear combination of the two numbers. It is widely used in solving Diophantine equations, finding modular inverses, and other applications where GCD computations are necessary.
