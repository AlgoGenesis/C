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
#### **Output**: A list of all prime numbers ≤ **n**

1. **Create a boolean array** `isPrime[]` of size **n + 1**, initialized to `true`. Set `isPrime[0]` and `isPrime[1]` to `false` because 0 and 1 are not prime.
   
2. **Iterate through the numbers** starting from 2 up to **√n**:
    - For each prime number **p** (i.e., `isPrime[p]` is `true`):
        - Mark all multiples of **p** starting from **p²** (since smaller multiples of **p** have already been marked) as non-prime (i.e., set `isPrime[j] = false` for multiples **j**).
        
3. **Collect all numbers** that are still marked `true` in the `isPrime[]` array — these are the prime numbers ≤ **n**.

---

### **Pseudocode**:

```python
SieveOfEratosthenes(n):
    Create an array isPrime[0..n] and initialize all elements to true
    Set isPrime[0] = false and isPrime[1] = false  # 0 and 1 are not primes

    for p = 2 to √n do:
        if isPrime[p] == true:
            # Mark all multiples of p from p² to n as non-prime
            for j = p*p to n do:
                isPrime[j] = false

    # Collect all primes
    primes = []
    for p = 2 to n do:
        if isPrime[p] == true:
            primes.append(p)

    return primes
```

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

### **Time Complexity**:

The time complexity of the Sieve of Eratosthenes is **O(n log log n)**.

- The outer loop runs approximately **√n** times.
- For each prime **p**, marking its multiples takes approximately **n/p** operations.
- Summing over all primes, this results in **O(n log log n)**.

This makes the Sieve of Eratosthenes extremely efficient for large inputs, especially compared to checking each number for primality individually, which would take **O(n√n)**.

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

### **Conclusion**:

The Sieve of Eratosthenes is a powerful and efficient algorithm for finding all prime numbers up to a given limit **n**. Its simplicity, combined with its efficiency, makes it one of the most popular algorithms for prime number generation, especially for large values of **n**. The time complexity **O(n log log n)** and space complexity **O(n)** make it suitable for large inputs, and it can be further optimized using techniques like segmentation.

