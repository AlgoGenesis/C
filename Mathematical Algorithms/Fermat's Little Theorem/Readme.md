# Fermat's Little Theorem

# Description

This program implements Fermat's Little Theorem to check the primality of a given number. It uses a probabilistic approach to determine whether a number is prime by testing multiple randomly chosen bases.

# Functions

1. **long long power(long long x, unsigned int y, long long p)**:
   - Computes \(x^y \mod p\) using modular exponentiation.
   - Returns the result of the modular exponentiation.

2. **int isPrime(int n, int k)**:
   - Checks if the number \(n\) is probably prime using Fermat's Little Theorem.
   - Takes \(k\) iterations for accuracy.
   - Returns:
     - 1 if \(n\) is probably prime.
     - 0 if \(n\) is not prime.

# Main Function:

Details:

- Prompts the user to enter a number \(n\) to check for primality.
- Prompts the user to enter the number of iterations \(k\) for accuracy.
- Calls the `isPrime` function to determine if the number is probably prime.
- Prints whether the number is probably prime or not based on the results of the tests.

# Memory Management

- The program does not use dynamic memory allocation; hence, no explicit freeing of memory is required.

### Time Complexity:
- Each iteration takes \(O(k \cdot \log n)\), where \(k\) is the number of iterations and \(n\) is the number being tested.
- Overall complexity: \(O(k \cdot \log n)\), depending on the number of iterations chosen by the user.

### Usage:
1. Compile the program using a C compiler (e.g., `gcc fermat.c -o fermat`).
2. Run the program (`./fermat`).
3. Follow the prompts to enter a number and the number of iterations.
4. The program will output whether the number is probably prime or not.

### Example:
- Input: `n = 21`, `k = 7`
- Output: `13 is probably prime.`
