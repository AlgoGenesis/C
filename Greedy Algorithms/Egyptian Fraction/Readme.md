# Egyptian Fraction Algorithm

## Description

This program implements an Egyptian Fraction algorithm to express a fraction as a sum of distinct unit fractions. A unit fraction is a fraction with a numerator of 1 and a positive integer denominator. The program uses a greedy approach to represent any given fraction in this form.

## Structures

1. Fraction:
    - A structure to represent a fraction with a numerator and denominator.
      Members:
      ~ int numerator: The numerator of the fraction.
      ~ int denominator: The denominator of the fraction.

## Functions

1. void printEgyptianFraction(int numerator, int denominator):

2. Computes the Egyptian fraction representation of the given fraction.
3. Recursively finds and prints the unit fractions that sum up to the original fraction.
   int gcd(int a, int b):

4. Calculates the greatest common divisor (GCD) of two integers.
5. Returns the GCD of a and b.

## Main Function:

### Details:

- Prompts the user to enter the numerator and denominator of the fraction.
- Calls the printEgyptianFraction function to compute and display the Egyptian fraction representation.
- Outputs the series of unit fractions that represent the original fraction.

## Time Complexity:

- The algorithm runs in O(n) time, where n is the number of terms in the Egyptian fraction representation.

## Usage:

1. Compile the program using a C compiler (e.g., gcc egyptian_fraction.c -o egyptian_fraction).
2. Run the program (./egyptian_fraction).
3. Follow the prompts to enter the numerator and denominator of the fraction.
4. The program will output the Egyptian fraction representation.
## Example:

### Input:
Enter the numerator: 6
Enter the denominator: 14


### Output:
Egyptian Fraction representation of 6/14 is:
1/3 + 1/11 + 1/231

