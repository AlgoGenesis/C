# Fibonacci Series
## What is Fibonacci?
The Fibonacci series is a sequence of numbers in which each number is the sum of the two preceding ones. The sequence typically starts with 0 and 1. The Fibonacci sequence can be expressed mathematically as:
- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) for n > 1
  The first few terms of the Fibonacci sequence are:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

The Fibonacci series has various applications in mathematics, computer science, and nature, including modeling population growth, financial markets, and biological settings.

  ## Pseudocode
  ### Iterative Approach
```bash
FUNCTION fibonacci_iterative(n):
    a = 0
    b = 1
    PRINT "Fibonacci Series (Iterative):"
    FOR i FROM 0 TO n - 1 DO:
        IF i == 0 THEN:
            PRINT a
        ELSE IF i == 1 THEN:
            PRINT b
        ELSE:
            next = a + b
            PRINT next
            a = b
            b = next
    END FOR
END FUNCTION
```
## Explanation
### 1.Initialization:
  - Two variables, a and b, are initialized to 0 and 1, representing the first two numbers in the Fibonacci sequence.<br>
### 2.Printing the Series:
  - The function prints a header indicating the start of the Fibonacci series.
### 3.Looping:
  - A FOR loop iterates from 0 to n-1, controlling how many terms of the Fibonacci series will be generated.<br>
  - **First Term (i = 0):** If i is 0, the function prints a, which is 0.
  - **Second Term (i = 1):** If i is 1, the function prints b, which is 1.
  - Subsequent Terms (i >= 2):
  - The next Fibonacci number is calculated as next = a + b.
  - The calculated next number is printed.
  - The values of a and b are updated for the next iteration.<br>
### 4.End of Function:
The loop continues until all n terms are printed.
### Recursive Approach
```bash
FUNCTION fibonacci_recursive(n):
    IF n < 0 THEN:
        RETURN
    ELSE IF n == 0 THEN:
        PRINT 0
        RETURN
    ELSE IF n == 1 THEN:
        PRINT 0
        PRINT 1
        RETURN

    a = 0
    b = 1
    PRINT "Fibonacci Series (Recursive):"
    PRINT a
    PRINT b

    FOR i FROM 2 TO n - 1 DO:
        next = a + b
        PRINT next
        a = b
        b = next
    END FOR
END FUNCTION
```
## Time Complexity
### Iterative Approach:

- **Time Complexity:** O(n)
The iterative method computes the Fibonacci numbers in a single loop that runs n times.
- **Space Complexity:** O(1)
The iterative approach uses a constant amount of space.
Recursive Approach:

- **Time Complexity:** O(2^n)
The naive recursive method generates an exponential number of calls due to overlapping subproblems.
- **Space Complexity:** O(n)
The recursive approach uses space on the call stack for each recursive call.

## Applications of the Fibonacci Series
The Fibonacci series has various applications, including:
- **Mathematics:** It appears in various mathematical contexts and problems, such as the Fibonacci spiral, which approximates the golden ratio.
- **Computer Science:** The series is often used in algorithms and data structures, particularly in dynamic programming and recursion examples.
Nature: Fibonacci numbers frequently occur in biological settings, such as the arrangement of leaves, flowers, and fruits.
- **Financial Markets:** Some traders use Fibonacci retracement levels to identify potential reversal levels in asset prices.

