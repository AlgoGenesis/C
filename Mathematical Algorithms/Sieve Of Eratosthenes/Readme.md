### **Sieve of Eratosthenes**

The **Sieve of Eratosthenes** is an ancient and efficient algorithm used to find all prime numbers up to a given number **n**. It is based on the simple idea of iteratively marking the multiples of each prime number, starting from 2, as non-prime. By the end of the process, the numbers that remain unmarked are prime.

---

### **Description**:
1. **Start with a list of consecutive integers** from 2 to **n**.
2. **Mark the first number (2)** as prime and eliminate all its multiples from the list.
3. **Move to the next unmarked number** (the next prime), mark it as prime, and eliminate all its multiples.
4. **Repeat the process** for each subsequent number until you reach a number whose square exceeds **n**.
5. The remaining unmarked numbers are primes.

---

### **Algorithm**:

#### **Input**: A positive integer **n > 1**  
#### **Output**: Array **L** containing all prime numbers less than or equal to **n**

1. **Initialize the array**:
   - Create an array **A** of size **n+1**.
   - Set **A[p] = p** for all **p** from 2 to **n**.

2. **Mark non-prime numbers**:
   - For each number **p** from 2 to **√n**:
     - If **A[p] ≠ 0** (i.e., **p** is prime):
       - Set **j = p * p** (start eliminating from **p²**).
       - While **j ≤ n**:
         - Set **A[j] = 0** (mark the multiple of **p** as non-prime).
         - Increment **j** by **p** (move to the next multiple of **p**).

3. **Collect prime numbers**:
   - Initialize an empty list **L** to store prime numbers.
   - For each number **p** from 2 to **n**:
     - If **A[p] ≠ 0**, add **A[p]** to the list **L**.

4. **Return the list**:
   - Return the list **L** of prime numbers.

---

### **Generalized Pseudocode**:

```text
Sieve(n)
    # Step 1: Initialize the array A
    for p ← 2 to n do
        A[p] ← p

    # Step 2: Mark non-prime numbers
    for p ← 2 to √n do
        if A[p] ≠ 0 then   # If p is prime
            j ← p * p       # Start from p^2
            while j ≤ n do
                A[j] ← 0    # Mark multiple as non-prime
                j ← j + p   # Move to next multiple of p

    # Step 3: Collect prime numbers into list L
    i ← 0
    for p ← 2 to n do
        if A[p] ≠ 0 then
            L[i] ← A[p]     # Add prime number to L
            i ← i + 1

    # Step 4: Return the list of primes
    return L
```

---

### **Explanation of Key Steps**:
- **Step 1**: Initializes an array **A** where each index represents a number from 2 to **n**.
- **Step 2**: Eliminates the multiples of each prime number starting from **p²** because all smaller multiples will have been eliminated in previous steps.
- **Step 3**: After marking all multiples of primes, collects the remaining non-zero values in **A**, which represent the prime numbers.
- **Step 4**: Returns the list of all prime numbers less than or equal to **n**.

This pseudocode describes the logic of the Sieve of Eratosthenes in a simple and general format.

---

### **Example**:

Let's find all primes up to **n = 30** using the Sieve of Eratosthenes.

#### **Step 1: Initialization**:
Create a list of integers from 2 to 30:

`[2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]`

#### **Step 2: Start with the first prime (2)**:
- Mark multiples of 2 (4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30) as non-prime.

Remaining list:

`[2, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29]`

#### **Step 3: Move to the next prime (3)**:
- Mark multiples of 3 (9, 12, 15, 18, 21, 24, 27, 30) as non-prime.

Remaining list:

`[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]`

#### **Step 4: Next prime (5)**:
- Mark multiples of 5 (25) as non-prime.

Remaining list:

`[2, 3, 5, 7, 11, 13, 17, 19, 23, 29]`

At this point, the algorithm stops because **p² > n** (i.e., 7² > 30). The remaining numbers are the primes up to 30.

---

Here’s the explanation formatted properly in markdown for your `README.md` file:

---

## Detailed Explanation of Time Complexity \( O(n \cdot \log(\log(n))) \) for the Sieve of Eratosthenes

To understand why the time complexity of the Sieve of Eratosthenes is \( O(n \cdot \log(\log(n))) \), we need to break down how the algorithm works and introduce the concept of **Harmonic Progression** and **Euler’s product formula**. Here's a step-by-step explanation:

### 1. Basic Concept of the Algorithm

The Sieve of Eratosthenes iterates through all numbers from 2 up to \( n \). For each prime \( p \), the algorithm marks all multiples of \( p \) (i.e., \( p^2, p^2 + p, p^2 + 2p, \ldots \)) as composite. The goal is to find the time taken by the algorithm to mark composite numbers.

The number of times each number is marked as composite depends on the prime numbers up to \( n \). To calculate this, we use the sum of inverses of primes, which leads to the logarithmic term \( \log(\log(n)) \).

### 2. Summing Over All Prime Multiples

For any prime \( p \), its multiples up to \( n \) are marked as non-prime. The number of multiples of a prime \( p \) less than \( n \) is approximately \( \frac{n}{p} \). The algorithm marks all multiples of primes starting from 2, 3, 5, 7, and so on. Therefore, the number of operations needed to mark composites can be expressed as:

\[
\frac{n}{2} + \frac{n}{3} + \frac{n}{5} + \frac{n}{7} + \ldots
\]

This sum counts how many numbers are marked as composite by each prime \( p \).

### 3. Simplifying the Expression

We take \( n \) common from the sum:

\[
n \left( \frac{1}{2} + \frac{1}{3} + \frac{1}{5} + \frac{1}{7} + \ldots \right)
\]

Now we need to calculate the sum of reciprocals of primes. The sum of the reciprocals of primes is related to the **Harmonic Progression**, but restricted only to prime numbers. Mathematically, this sum is known to converge to \( \log(\log(n)) \). Hence, we rewrite the equation as:

\[
n \cdot \log(\log(n))
\]

Thus, the number of times the loop runs in the Sieve of Eratosthenes is proportional to \( n \cdot \log(\log(n)) \).

### 4. Harmonic Progression and Proof

The next step is to understand why \( \frac{1}{2} + \frac{1}{3} + \frac{1}{5} + \ldots \approx \log(\log(n)) \). This is proven using **Euler's product formula**, which relates the sum of reciprocals of primes to the logarithmic function.

- **Harmonic Series**: The sum of the reciprocals of all integers up to \( n \) is given by the Harmonic series:

\[
H_n = 1 + \frac{1}{2} + \frac{1}{3} + \ldots + \frac{1}{n} \approx \log(n)
\]

This is a well-known result, and the logarithmic growth comes from the approximation of the Harmonic series.

- **Prime Harmonic Series**: The sum of the reciprocals of prime numbers follows a similar pattern but is restricted to primes only. Using **Euler’s product formula**, we have:

\[
\sum_{p \, \text{prime}} \frac{1}{p} \approx \log(\log(n))
\]

This means the sum of the reciprocals of primes grows much slower than the Harmonic series for all integers, and the double logarithm \( \log(\log(n)) \) emerges naturally.

### 5. Euler’s Product Formula

Euler's product formula is used to derive this result. It states that for any series involving reciprocals of primes, we can represent it as a product over primes:

\[
\sum_{n=1}^{\infty} \frac{1}{n^s} = \prod_{p \, \text{prime}} \frac{1}{1 - p^{-s}}
\]

For \( s = 1 \), this gives the relationship between the sum of reciprocals of primes and logarithmic functions. Applying logarithms to both sides of this product and simplifying with Taylor expansions, we eventually arrive at the approximation:

\[
\sum_{p \, \text{prime}} \frac{1}{p} \approx \log(\log(n))
\]

This step is crucial in proving that the time complexity is \( O(n \cdot \log(\log(n))) \).

### 6. Final Time Complexity

Combining everything, we conclude that the total number of operations performed by the algorithm is proportional to \( n \cdot \log(\log(n)) \). Thus, the time complexity of the Sieve of Eratosthenes is:

\[
O(n \cdot \log(\log(n)))
\]

This is highly efficient, as it grows only slightly faster than **linear time** and is suitable for large inputs.

### 7. Space Complexity

The space complexity of the Sieve of Eratosthenes is **O(n)** because we need to maintain an array of size **n+1** to track the primality of each number from 2 to \( n \).

---

### **Space Complexity**:

The space complexity is **O(n)**, as we need to store the boolean array `isPrime[]` of size **n + 1**.

---

### **Efficiency for Large Inputs**:

- **Memory**: The algorithm uses **O(n)** space, which is manageable for moderately large values of **n** (e.g., up to 10 million primes can be computed with modern systems using a reasonable amount of memory).
  
- **Time**: The time complexity **O(n log log n)** grows very slowly compared to **n**, meaning that it can handle large inputs efficiently. For example, finding all primes up to **1 billion** can be done in a few seconds with this algorithm on a modern computer.

### **Optimization for Large Inputs**:
- **Segmented Sieve**: When dealing with extremely large values of **n**, a segmented version of the Sieve of Eratosthenes can be used. It divides the range into smaller segments, reducing the memory footprint while maintaining the efficiency of the algorithm.

---

