# Chinese Remainder Theorem (CRT)

The **Chinese Remainder Theorem (CRT)** is a fundamental theorem in number theory that provides a way to solve systems of simultaneous congruences. The theorem is particularly useful in fields such as cryptography and computer science, allowing for efficient calculations with modular arithmetic.

## **Description**
The Chinese Remainder Theorem (CRT) states that if you have a system of congruences with pairwise coprime moduli, there exists a unique solution modulo the product of these moduli. 

Specifically, if you have integers \( a_1, a_2, \ldots, a_k \) and moduli \( m_1, m_2, \ldots, m_k \) such that:

- \( x \) is congruent to \( a_1 \) modulo \( m_1 \)
- \( x \) is congruent to \( a_2 \) modulo \( m_2 \)
- ...
- \( x \) is congruent to \( a_k \) modulo \( m_k \)

Then there exists a unique integer \( x \) such that \( 0 \leq x < M \), where \( M \) is the product of all the moduli \( m_1, m_2, \ldots, m_k \).


## **Algorithm**
Here's a step-by-step breakdown of how to apply the CRT:

1. **Input**: Arrays of integers **a** (remainders) and **m** (moduli).
2. **Compute** \( M \), the product of all moduli.
3. **For each modulus** \( m_i \):
   - Calculate \( M_i = \frac{M}{m_i} \).
   - Find the modular multiplicative inverse of \( M_i \) modulo \( m_i \) (denoted as \( inv_i \)).
   - Update \( x \) as \( x += a_i \cdot M_i \cdot inv_i \).
4. **Output**: The result is \( x \mod M \).

### **Pseudocode**
```plaintext
  CRT(a[], m[], k)
   // Input: Arrays of remainders a[] and moduli m[]
   // Output: The solution x satisfying the system of congruences
   M ← Product of all m[i]
   x ← 0
   for i ← 0 to k-1 do
       M_i ← M / m[i]
       inv_i ← modInverse(M_i, m[i])
       x ← (x + a[i] * M_i * inv_i) % M
   return x
```
## Time Complexity
The time complexity of the CRT algorithm is \( O(k) \), where \( k \) is the number of equations in the system. This is due to the need to compute the product of the moduli and the modular inverses.

## Space Complexity
The space complexity is \( O(1) \), as the algorithm only requires a constant amount of space for a few variables (the result and the product of moduli).

## Efficiency for Large Inputs
The Chinese Remainder Theorem is efficient for large integers due to:

- **Modular Arithmetic**: The operations involved (multiplication, addition, and finding inverses) are efficient, even for large numbers.
- **Parallel Computation**: The calculations for each modulus can be performed independently, allowing for potential parallelization.
- **Applications in Cryptography**: CRT is commonly used in RSA encryption, improving the efficiency of modular exponentiation.
