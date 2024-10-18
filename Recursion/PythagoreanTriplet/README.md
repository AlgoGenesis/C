# Recursive Pythagorean Triplet Finder

## Description

The **Recursive Pythagorean Triplet Finder** is a C program designed to identify and display all unique Pythagorean triplets within a specified range. A Pythagorean triplet consists of three positive integers **(**a**,**b**,**c**)** that satisfy the equation: a^2+b^**2**=c^2

### Problem Definition

The goal of the **Recursive Pythagorean Triplet Finder** is to identify and output all unique Pythagorean triplets within a specified range of positive integers. A Pythagorean triplet consists of three positive integers **(**a**,**b**,**c**)** that satisfy the equation:

In this context, the program uses recursion to explore potential values for **a**, **b**, and **c** up to a user-defined limit **n**. The conditions that need to be met are:

- **Integer Values** : All values of **a**, **b**, and **c** must be integers.
- **riplet Condition** : The triplet must satisfy a<b< c.
- **Limit** : The values of **a**, **b**, and **c** should not exceed the user-provided integer **n**.

  **Core Functionality**

1. **Recursive Exploration** :

- The algorithm starts with the smallest possible values for aa**a** and bb**b** and increments them recursively.
- For each combination of **a** and **b**, it calculates **c** using the relationship derived from the Pythagorean theorem. Specifically, **c** is determined as the square root of a^2+b^2.
- The algorithm checks whether **c** is an integer and greater than both **a** and **b** before considering it a valid triplet.

  2 . **User Interaction** :
- The program prompts the user for input, specifically the maximum integer **n**, and then it finds all triplets where **a**, **b**, and **c** are less than or equal to **n**.
- The results are printed in a user-friendly format, displaying all identified triplets.

  **Output** :
- The output consists of all valid Pythagorean triplets that meet the criteria. For example, if the user inputs **20**, the program might output:

  Pythagorean Triplet: (3, 4, 5)
  Pythagorean Triplet: (5, 12, 13)
  Pythagorean Triplet: (6, 8, 10)

  **Example Flow:**
- **Input** : The user inputs the value `20`.
- **Process** :
- The program starts by setting a=1 and incrementally tests values for **b** starting from **a**+**1**.
- For each pair **(**a**,**b**)**, it computes **c** and checks if it forms a valid triplet.

#### Advantages:

- **Educational Tool** : This program serves as a practical example of recursion in programming, illustrating how to handle combinatorial problems.
- **Efficiency** : Although it uses recursion, it maintains clarity and simplicity, making it suitable for beginners in the  programming and mathematics.

#### Potential Enhancements:

- The program could be optimized to reduce the number of unnecessary calculations, especially for larger values of nn**n**.
- A graphical interface could be added to visualize the triplets, making it more engaging for users.

### Time Complexity

The time complexity of the **Recursive Pythagorean Triplet Finder** is O(n^2)**. This is because the algorithm consists of a recursive function that iterates through all possible values of a** from 1 to n, and for each **a**, it checks values of **b** from **a**+**1** to n. The nested loops lead to a quadratic increase in the number of operations as **n** increases, making the algorithm less efficient for larger input sizes. However, it remains effective for moderate values of **n**.
