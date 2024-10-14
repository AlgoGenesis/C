# Gray Code Via Recurrsion 

## Description

This project implements an algorithm to generate **Gray Codes** using a recursive approach. Gray codes are binary sequences where two consecutive values differ by only one bit, making them ideal for minimizing errors in digital systems. The recursive method efficiently constructs Gray codes for any specified number of bits, leveraging the properties of reflection and bit manipulation.

**Key Features:**

* **Recursive Function** : The algorithm recursively generates Gray codes for nn**n** bits by reflecting previously generated codes and prepending '0' and '1'.

* **Memory Management** : Utilizes dynamic memory allocation to handle strings efficiently, ensuring optimal memory usage.
* **User Interaction** : Prompts users to input the desired number of bits and displays the corresponding Gray codes

**Use Cases:**

* Digital circuit design where minimizing transition errors is critical.
* Applications in robotics, computer graphics, and data encoding where binary representation is required.

### Problem Definition

The goal of this project is to generate **n-bit Gray codes** using a recursive algorithm. A Gray code is a binary numeral system where two successive values differ in only one bit. The problem can be defined as follows:

**Given:**

An integer nn**n** representing the number of bits.

**Requirement:**

Generate a sequence of Gray codes for nn**n** bits such that:

1. Each code in the sequence must differ from the previous code by exactly one bit.
2. The total number of Gray codes for nn**n** bits is 2n2^n**2**n.

### Constraints:

* The function must efficiently handle memory allocation for the generated codes.
* The output should be in the form of strings representing the binary Gray codes.

### Expected Output:

* A list of 2n2^n**2**n Gray codes in the correct order for the given number of bits nn**n**.

### Examples:

1. **Example 2: n=2**

   **Input:** `2`

   **Output:**

   00
   01
   11
   10
2. **Example 3: n=3n = 3**n**=**3****

   * **Input:** `3`
   * **Output:**

     000
     001
     011
     010
     110
     111
     101
     100
3. **Example 4: n=4n = 4**n**=**4****

   * **Input:** `4`
   * **Output:**

   0000
   0001
   0011
   0010
   0110
   0111
   0101
   0100
   1100
   1101
   1111
   1110
   1010
   1011
   1001
   1000


### Algorithm Overview

The Gray code generation algorithm uses recursion to construct a sequence of Gray codes for a given number of bits nn**n**. The recursive approach is based on two key components: the **base case** and the  **recursive case** .

1. **Base Case**:

   * When n=1n = 1 **n**=**1**:
     * The sequence consists of the two Gray codes: `0` and `1`.
     * This is the simplest case and serves as the foundation for building higher-order Gray codes.
2. **Recursive Case**:

   For n>1.  **Generate Gray Codes for n−1** :

* Recursively call the function to generate Gray codes for **n**−**1** bits.
* Let’s denote this sequence as G(n−1)

 **Construct the n****-bit Gray Codes** :* The nn**n**-bit Gray code sequence G(n) is constructed by:

* Prepending `0` to each code in G(n−1) (this forms the first half of the nn**n**-bit Gray codes).
* Prepending `1` to each code in the reverse order of G(n−1) (this forms the second half of the **n**-bit Gray codes).

### Detailed Steps:

1. **Input Handling:**
   * Prompt the user to enter the number of bits n.
   * Validate the input to ensure **n** is a non-negative integer.
2. **Memory Allocation:**
   * Allocate an array of strings to hold the generated Gray codes. The size of the array should be 2^n since there are 2^n Gray codes for **n** bits.
3. **Base Case Implementation:**
   * Define the base case for the recursive function:
     * If n=1:
       * Store the Gray codes `0` and `1` in the array.
       * Set the size of the array to 2.
4. **Recursive Function Call:**
   * For n>1:
     * Recursively call the function to generate Gray codes for n−1 bits.
     * Store the resulting Gray codes in the array.
5. **Constructing n**-bit Gray Codes:**
   * Determine the current size of the generated codes from the previous step.
   * Prepend `0` to each code in the existing array. This forms the first half of the **n**-bit Gray codes.
   * Create a new section of the array to store the reversed Gray codes from the previous step.
   * Prepend `1` to each reversed code. This forms the second half of the n-bit Gray codes.
6. **Memory Management:**
   * Ensure that dynamic memory allocation is handled properly. Free any allocated memory when it is no longer needed to avoid memory leaks.
7. **Output:**
   * Print the generated Gray codes for the specified number of bits.
   * Display the codes in a user-friendly format.
8. **End of Program:**
   * Free any remaining allocated memory.
   * Terminate the program gracefully.

### Example Execution Flow:

1. User inputs n=3.
2. Function calls `generateGrayCode(3)`.
   * Calls `generateGrayCode(2)`.
     * Calls `generateGrayCode(1)`:
       * Base case: store `0` and `1`.
     * Constructs **G**(**2**):
       * Prepend `0`: `00`, `01`.
       * Prepend `1` to reverse: `11`, `10`.
   * Constructs G(3):
     * Prepend `0`: `000`, `001`, `011`, `010`.
     * Prepend `1` to reverse: `110`, `111`, `101`, `100`.
3. Print the resulting Gray codes for n=3.

### Time Complexity

* **Time Complexity:** O(2n)O(2^n)**O**(**2**n**)**
* **Explanation:**
  * The algorithm generates 2n2^n**2**n Gray codes for nn**n** bits.
  * Each recursive call constructs Gray codes by iterating through 2(n−1)2^{(n-1)}**2**(**n**−**1**) codes.
  * The exponential growth of the number of codes results in the overall time complexity being O(2n)O(2^n)**O**(**2**n**)**.
