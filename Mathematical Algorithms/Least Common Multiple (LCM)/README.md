# Least Common Multiple
## Description
The **Least Common Multiple (LCM)** of two integers is the smallest positive integer that is divisible by both numbers. In other words, it is the smallest number into which both original numbers can be evenly divided without leaving a remainder.

## How to Calculate the LCM:
There are several methods to find the LCM of two numbers:
### 1. Using Prime Factorization:
- Factorize each number into its prime factors.
- Identify all prime numbers that appear in either factorization.
- For each prime factor, select the highest power that appears in the factorizations.
- Multiply these prime powers together to get the LCM.<br><br>
  **Example:** To find the LCM of 12 and 18<br><br>
   - **Prime factorization of 12:** &nbsp; 2² × 3¹<br>
   - **Prime factorization of 18:** &nbsp;2¹ × 3²<br>
   - **Take the highest powers:** &nbsp; 2² and 3² <br>
   - **LCM Calculation:** &nbsp; LCM = 2² × 3² = 4 × 9 = 36<br>

### 2. Using the Formula with GCD:
- The LCM of two numbers can be calculated using their Greatest Common Divisor (GCD):
                          
                  LCM(a, b) = |a × b| / GCD(a, b)

- First, find the GCD using the Euclidean algorithm.
- Then, use the formula to compute the LCM.
-  **Example:**
    - For numbers 12 and 18, the GCD is 6.
    - LCM = (12 x 18) / 6 =36

### 3. Using Incremental Multiples:
- Start with the larger of the two numbers.
- Check if this number is divisible by both numbers; if not, increment by the larger number and check again.
- Continue this process until finding a common multiple.
- Example:
   - For 12 and 18, start with 18.
   - The first multiple of 18 that is also divisible by 12 is 36.
## Why LCM is Important:
- **In Fractions:** When adding or subtracting fractions with different denominators, the LCM of the denominators is used as a common denominator.
- **In Scheduling:** For events that repeat at different intervals, the LCM helps find when both events will coincide.
- **In Problem Solving:** LCM is useful for solving various types of mathematical problems, especially those involving periodicity or repeated patterns.
 
Among the methods for calculating the Least Common Multiple (LCM), using the formula with the Greatest Common Divisor (GCD) is generally considered the most optimal. Here's why:
## Optimal Method: Using the GCD Formula
Formula:
The relationship between LCM and GCD can be expressed as:<br>

                          LCM(a, b) = |a × b| / GCD(a, b)

 ## Pseudocode for Optimized LCM Calculation
 ```bash
FUNCTION GCD(a, b)
    WHILE b ≠ 0 DO
        temp = b
        b = a MOD b
        a = temp
    END WHILE
    RETURN a
END FUNCTION

FUNCTION LCM(a, b)
    RETURN (|a × b|) / GCD(a, b)
END FUNCTION

// Example usage
SET num1 = 12
SET num2 = 18
SET result = LCM(num1, num2)
PRINT "The LCM of", num1, "and", num2, "is", result
```
## Explanation of Pseudocode

### GCD Function:
Uses the Euclidean algorithm to efficiently calculate the GCD of two numbers by repeatedly replacing a with b and b with a MOD b until b is zero.
### LCM Function:
Calculates the LCM using the formula 
### Example Usage:
Demonstrates how to call the LCM function with numbers (12 and 18) and prints the result. 

## ​Advantages of Using GCD to Find LCM:
1.**Efficiency:**
- The GCD can be computed efficiently using the Euclidean algorithm, which has a time
  complexity of O(log(min(a,b))).This is significantly faster than the iterative or prime factorization methods, especially for large numbers.<br>
2. **Constant Time for LCM Calculation:**
  - Once you have the GCD, calculating the LCM using the formula involves a few arithmetic operations (multiplication and division), which is done in constant time, 
O(1).<br>

## Time Complexity Comparison:
1.**Prime Factorization Method:**
Time complexity can vary based on the number of prime factors but is generally slower than the GCD method, especially for larger numbers. Finding prime factors can take up to **O(√n)** for each number.<br><br>
2.**Incremental Multiples Method:**
This method can have a time complexity of up to **O(a×b)** in the worst case, especially if the two numbers are coprime (meaning they share no common factors other than 1). The number of iterations could be quite large, leading to inefficiency.<br><br>
3.**Using GCD Formula:**
The time complexity for finding LCM using the GCD formula is primarily determined by the GCD calculation, which is **O(log(min(a,b)))**. Thus, this method is highly efficient and optimal for both small and large integers.

## program output
![image](https://github.com/user-attachments/assets/f249526a-cf0f-4926-816c-c36525d81617)



​

​



