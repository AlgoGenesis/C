## Algorithm: Counting the Number of 1s (Hamming Weight) Using Bit Manipulation

### Description

The **Hamming Weight** algorithm counts the number of `1`s in the binary representation of an integer. This method is essential in various domains such as digital signal processing, cryptography, and error detection.

### Why It’s Useful
- **Efficiency**: The algorithm runs in O(log n) time complexity, where `n` is the value of the integer. This ensures it is highly efficient, even for large numbers.
- **Practicality**: Understanding and applying bit manipulation techniques is critical for low-level programming and optimizing code performance.

### Algorithm Explanation
The algorithm processes each bit of the integer to count the number of `1`s. Here’s how it works:

1. **Initialize Count**: Start with a count of 0.
2. **Iterate Through Bits**: Use a loop to repeatedly check the least significant bit (LSB) of the number.
3. **Increment Count**: If the LSB is `1`, increment the count.
4. **Right-Shift the Number**: Shift the number one bit to the right to process the next bit.
5. **Repeat**: Continue steps 2-4 until all bits are processed (i.e., until the number becomes 0).

This approach ensures each bit is examined, and the total number of `1`s is counted efficiently.

### Time Complexity

The time complexity of the Hamming Weight algorithm is O(log n), where `n` is the integer whose bits are being counted. This is because the number of bits in the integer is proportional to the logarithm (base 2) of the integer.

### Example

Consider the integer `29`. Its binary representation is `11101`. Here’s a step-by-step breakdown of the algorithm:

1. Initial number: `29` (binary: `11101`)
2. Check LSB (`1`), increment count to `1`, right-shift to get `1110`
3. Check LSB (`0`), count remains `1`, right-shift to get `111`
4. Check LSB (`1`), increment count to `2`, right-shift to get `11`
5. Check LSB (`1`), increment count to `3`, right-shift to get `1`
6. Check LSB (`1`), increment count to `4`, right-shift to get `0`
7. The process stops as the number is now `0`

Thus, the Hamming Weight of `29` is `4`.

### How to Run the Code

The implementation of the Hamming Weight algorithm is in the file named `hamming_weight.c`. Follow these steps to compile and run the code:

1. **Ensure a C Compiler is Installed**: Verify that you have a C compiler (e.g., `gcc`) installed on your system.
2. **Navigate to the Directory**: Open a terminal and navigate to the directory containing `hamming_weight.c`.
3. **Compile the Code**: Use the following command to compile the code:
   ```sh
   gcc -o hamming_weight hamming_weight.c
   ```
4. **Execute the Program**: Run the compiled program with:
   ```sh
   ./hamming_weight
   ```
5. **Output**: The program will output the number of `1`s in the binary representation of the example number.

