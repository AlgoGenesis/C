## Extended Euclidean Algorithm

The **Extended Euclidean Algorithm** is an extension of the **Euclidean Algorithm**. It not only computes the **Greatest Common Divisor (GCD)** of two integers but also finds integers **x** and **y** such that:

\[ ax + by = \text{gcd}(a, b) \]

These integers **x** and **y** are called the **coefficients** of the linear combination of **a** and **b**, and they are particularly useful for finding the **multiplicative inverse** of a number modulo **n** (if the GCD of the number and **n** is 1).

### **Description**
The key idea behind the **Extended Euclidean Algorithm** is to perform the Euclidean Algorithm to find the GCD, while also working backward to express the GCD as a linear combination of the two numbers. The coefficients **x** and **y** are updated in each iteration.

### **Algorithm**
Here's a step-by-step breakdown of the **Extended Euclidean Algorithm**:

1. **Input**: Two non-negative integers **a** and **b**.
2. **Initialize** \( x_1 = 1 \), \( y_1 = 0 \), \( x_2 = 0 \), and \( y_2 = 1 \).
3. **While** \( b \neq 0 \):
   - Compute \( q = \left\lfloor a / b \right\rfloor \) (quotient) and \( r = a \mod b \) (remainder).
   - Update: \( a = b \) and \( b = r \).
   - Update \( x = x_1 - q \cdot x_2 \) and \( y = y_1 - q \cdot y_2 \).
   - Swap values: \( x_1 = x_2 \), \( y_1 = y_2 \), \( x_2 = x \), and \( y_2 = y \).
4. **Output**: The GCD is \( a \), and the coefficients **x_1** and **y_1** satisfy \( a \cdot x_1 + b \cdot y_1 = \text{gcd}(a, b) \).

### **Pseudocode**
```plaintext
  extendedGCD(a, b)
    // Computes GCD and the coefficients x and y of the equation ax + by = gcd(a, b)
    // Input: Two nonnegative integers a and b
    // Output: (gcd(a, b), x, y)

    x1 ← 1, y1 ← 0, x2 ← 0, y2 ← 1
    while b ≠ 0 do
        q ← a // b     // Quotient
        r ← a mod b    // Remainder
        a ← b
        b ← r
        x ← x1 - q * x2
        y ← y1 - q * y2
        x1 ← x2
        y1 ← y2
        x2 ← x
        y2 ← y
    return (a, x1, y1)
```

### **Time Complexity**
Like the Euclidean Algorithm, the **Extended Euclidean Algorithm** has a time complexity of **O(log(min(a, b)))**. This is because it also relies on a series of divisions, where the size of the numbers decreases rapidly with each iteration.

### **Space Complexity**
The space complexity is **O(1)** because only a constant number of variables are required to store intermediate results, the quotient, and the remainder.

### **Applications**
The **Extended Euclidean Algorithm** has several important applications:
1. **Finding the Multiplicative Inverse**: Given two numbers **a** and **n**, if **gcd(a, n) = 1**, the algorithm can be used to find the multiplicative inverse of **a** modulo **n**.
2. **Solving Diophantine Equations**: The algorithm can be used to find integer solutions to equations of the form \( ax + by = c \), where **a**, **b**, and **c** are integers.
3. **Cryptography**: The algorithm is a critical part of cryptographic systems such as **RSA**, where it is used to compute modular inverses in key generation and encryption processes.

### **Example**
Here's a visual representation of the **Extended Euclidean Algorithm** for finding the GCD of **30** and **12** along with the coefficients **x** and **y** such that:

\[ 30x + 12y = \text{gcd}(30, 12) \]

#### **Step-by-Step Execution**

1. **First Iteration**:
   - \( a = 30 \), \( b = 12 \)
   - \( q = 30 // 12 = 2 \), \( r = 30 \mod 12 = 6 \)
   - Update \( x = x_1 - q \cdot x_2 = 1 - 2 \cdot 0 = 1 \)
   - Update \( y = y_1 - q \cdot y_2 = 0 - 2 \cdot 1 = -2 \)
   - New values: \( a = 12 \), \( b = 6 \), \( x_1 = 0 \), \( y_1 = 1 \), \( x_2 = 1 \), \( y_2 = -2 \)

2. **Second Iteration**:
   - \( a = 12 \), \( b = 6 \)
   - \( q = 12 // 6 = 2 \), \( r = 12 \mod 6 = 0 \)
   - Update \( x = x_1 - q \cdot x_2 = 0 - 2 \cdot 1 = -2 \)
   - Update \( y = y_1 - q \cdot y_2 = 1 - 2 \cdot -2 = 5 \)
   - New values: \( a = 6 \), \( b = 0 \), \( x_1 = 1 \), \( y_1 = -2 \), \( x_2 = -2 \), \( y_2 = 5 \)

3. **Result**:
   - When \( b = 0 \), the GCD is \( a = 6 \), and the coefficients are \( x = 1 \) and \( y = -2 \).
   - Therefore, \( 30 \cdot 1 + 12 \cdot (-2) = 6 \).


### **Efficiency for Large Inputs**
The **Extended Euclidean Algorithm** is highly efficient for large numbers, just like the Euclidean Algorithm. Its logarithmic time complexity ensures it can handle very large integers, making it suitable for applications like cryptography.

### **Conclusion**
The **Extended Euclidean Algorithm** extends the functionality of the Euclidean Algorithm by not only calculating the GCD of two numbers but also providing the coefficients that express this GCD as a linear combination of the two inputs. This algorithm is widely used in number theory, cryptography, and solving Diophantine equations.