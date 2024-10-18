# Armstrong Number Evaluation for N Digits

## Description

This project implements an algorithm to evaluate whether a given number is an Armstrong number. An Armstrong number (also called a Narcissistic number) is a number that equals the sum of its own digits each raised to the power of the number of digits.

For example:

- 153 is an Armstrong number because 
  1^3 + 5^3 + 3^3 = 153

- 9474 is an Armstrong number because 
  9^4 + 4^4 + 7^4 + 4^4 = 9474

This project will handle input of any size and will efficiently compute whether the number is an Armstrong number.


## Problem Definition

Given a valid positive integer n, the task is to determine whether it is an Armstrong number. The solution must:

1. Accept any positive integer as input.
2. Compute the number of digits in the number.
3. Compute the sum of each digit raised to the power of the number of digits.
4. Compare the computed sum to the original number to check if it matches.


## Algorithm for Armstrong Number Evaluation

1. **Input the Number**:

- Accept input from the user (a positive integer).
- Store the input in a variable (e.g., n).

2. **Determine Number of Digits**:

- Count the number of digits in the input number. This can be done by repeatedly dividing the number by 10 until the quotient is 0.
- Store the count of digits in a variable (e.g., num_digits).

3. **Extract Each Digit**:

- Use modulus (%) to extract the last digit of the number.
- Raise this digit to the power of num_digits.
- Add the result to a sum accumulator.

4. **Repeat for Each Digit**:

- Perform integer division (//) to remove the last digit of the number.
- Repeat the modulus, exponentiation, and summation steps until all digits have been processed.

5. **Check if the Number is an Armstrong Number**:

- Compare the accumulated sum of digits raised to the power of num_digits with the original number.
- If the sum equals the original number, the input is an Armstrong number.

6. **Output the Result**:

- Print the result, indicating whether the input number is an Armstrong number or not.


## Example

For input number 153:

1. The number of digits (num_digits) is 3.
2. Evaluate 1^3 + 5^3 + 3^3 = 153.
3. Since the computed sum equals the original number, 153 is an Armstrong number.

For input number 9474:

1. The number of digits (num_digits) is 4.
2. Evaluate 9^4 + 4^4 + 7^4 + 4^4 = 9474.
3. Since the computed sum equals the original number, 9474 is an Armstrong number.


## Time Complexity

The time complexity of evaluating an Armstrong number is 𝑂(𝑑), where 𝑑 is the number of digits in the input number. Each digit is processed once, and each digit's power calculation is performed in constant time.


## Key Steps for Complexity:

- Counting the digits takes 𝑂(𝑑).
- Summing the digits raised to the power of num_digits takes 𝑂(𝑑).

Thus, the overall time complexity is linear, 𝑂(𝑑).


## Edge Cases to Consider

- **Single-digit numbers**: All single-digit numbers are Armstrong numbers because any number raised to the power of 1 is itself.
- **Very large numbers**: Efficient handling is required for large inputs due to potential high values during exponentiation.