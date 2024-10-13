## Modular Multiplicative Inverse (MMI)

The **Modular Multiplicative Inverse (MMI)** of a number \( a \) under a modulo \( M \) is a number \( x \) such that:

**\[ (a \times x) \mod M = 1 \]**

This MMI is essential in modular arithmetic and finds applications in cryptography, combinatorics, and solving equations in modular fields. When \( M \) is a prime number, the MMI of \( a \) can be efficiently calculated using **Fermat's Little Theorem**.

### **Description**

For a prime \( M \), Fermat’s Little Theorem states:

**\[ a^{M-1} \equiv 1 \pmod{M} \]**

To isolate \( x \), we can rewrite this as:

**\[ x = a^{M-2} \mod M \]**

This leads us to calculate \( a^{M-2} \mod M \), which can be efficiently done using **Binary Exponentiation**. This approach has a time complexity of \( O(\log(M)) \).

### **Algorithm**

1. **Input**: A base integer **a** and a prime integer **M**.
2. **Calculate**: The MMI as \( a^{M-2} \mod M \) using the binary exponentiation technique.
3. **Output**: The computed Modular Multiplicative Inverse of **a** under modulo **M**.

### **Pseudocode**

binaryExpo(a, b, M)
// Computes (a^b) % M using binary exponentiation
// Input: Integers a, b, M
// Output: (a^b) % M
if b == 0:
return 1
rec = binaryExpo(a, b / 2, M)
rec = (rec _ rec) % M
if b is odd:
rec = (rec _ a) % M
return rec

mmi(a, M)
// Computes the Modular Multiplicative Inverse of a under modulo M
return binaryExpo(a, M - 2, M)

### **Time Complexity**

The time complexity of the MMI calculation using binary exponentiation is O(log M). This efficiency comes from halving the exponent with each recursive call, making it ideal for large values of 𝑀.

### **Space Complexity**

The space complexity is O(1), requiring constant space to store intermediate results for each recursive call.
