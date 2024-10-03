## Euclidean Algorithm

The **Euclidean Algorithm** is an ancient and efficient method for computing the **Greatest Common Divisor (GCD)** of two integers. The GCD of two numbers is the largest number that divides both of them without leaving a remainder. The algorithm is named after the ancient Greek mathematician Euclid, who first described it in his work "Elements."

### **Description**
The Euclidean Algorithm relies on the principle that the GCD of two numbers also divides their difference. The key observation is:

 ` **gcd(a, b) = gcd(b, a mod b)**`
Where:
- **a** is the larger number.
- **b** is the smaller number.
- **a mod b** is the remainder when **a** is divided by **b**.

This means that instead of working with the original numbers, we can replace the larger number with the remainder. The process is repeated until one of the numbers becomes zero. At that point, the other number will be the GCD.

### **Algorithm**
Here's a step-by-step breakdown of the Euclidean Algorithm:

1. **Input**: Two non-negative integers **a** and **b** (assume \( a \geq b \)).
2. **While** \( b != 0 \):
   - Calculate the remainder \( r = a mod b \).
   - Set \( a = b \) and \( b = r \).
3. **Output**: When \( b = 0 \), the GCD is \( a \).

### **Pseudocode**
```plaintext
function gcd(a, b)
    while b ≠ 0 do
        r ← a mod b
        a ← b
        b ← r
    return a
```

### **Time Complexity**
The time complexity of the Euclidean Algorithm is **O(log(min(a, b)))**. This is because with each iteration, the size of the numbers reduces significantly (at least by half), leading to a logarithmic number of iterations relative to the smaller of the two numbers.

### **Space Complexity**
The space complexity is **O(1)** because the algorithm only requires a constant amount of space to store a few variables (the two numbers and the remainder).

### **Efficiency for Large Inputs**
The Euclidean Algorithm is extremely efficient, even for large integers. Here’s why:

1. **Rapid Convergence**: The algorithm quickly reduces the size of the numbers involved. Each division step effectively halves the size of the larger number, leading to a rapid decrease in the number of digits required to represent the numbers.

2. **Use of Modulo**: The modulo operation helps in quickly finding the remainder, which is the essence of the algorithm. This operation is computationally efficient and can handle large numbers efficiently due to modern hardware optimizations.

3. **Application in Cryptography**: The algorithm is widely used in cryptographic applications, such as finding the GCD in key generation algorithms (e.g., RSA). Its efficiency ensures that even very large keys can be processed quickly.

### **Example**
Here's a visual representation of the Euclidean Algorithm for finding the GCD of 48 and 18:

1. **Start with** \( a = 48 \) and \( b = 18 \): 48 mod 18
   

2. **First Iteration**:
48 mod 18 = 12 => gcd(18, 12)

3. **Second Iteration**:
    18 mod 12 = 6 => gcd(12, 6)

4. **Third Iteration**:
   12 mod 6 = 0 => gcd(6, 0)

5. **Result**:
   - When \( b = 0 \), the GCD is \( a = 6 \).

