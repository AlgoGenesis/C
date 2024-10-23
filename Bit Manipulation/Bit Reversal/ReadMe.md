# Bit Reversal Using Bit Manipulation

This project demonstrates how to reverse the bits of a 32-bit unsigned integer using bit manipulation techniques in C. The algorithm efficiently reverses the bits by iterating through each bit position and setting the corresponding bit in the reversed position.

## Features

- Reverses the bits of a 32-bit unsigned integer.
- Utilizes bit manipulation techniques for efficient processing.

## Algorithm

The bit reversal algorithm involves the following steps:

1. **Initialize** a variable to store the reversed bits.
2. **Calculate** the total number of bits in the integer (32 bits for this implementation).
3. **Iterate** through each bit position of the integer:
   - Check if the current bit is set.
   - If the bit is set, set the corresponding bit in the reversed variable.
4. Return the reversed integer.

## Sample Input and Output

1. **Input**: `1`
   - **Output**: `2147483648`
   
2. **Input**: `2`
   - **Output**: `1073741824`
   
3. **Input**: `43261596`
   - **Output**: `964176192`
   
4. **Input**: `4294967295`
   - **Output**: `4294967295`
   
5. **Input**: `0`
   - **Output**: `0`

## How to Compile and Run

1. **Save the Code**: Save the provided C code in a file named `bit_reversal.c`.
2. **Open a Terminal**: Use your terminal application on macOS or Linux.
3. **Navigate to the Directory**: Use the `cd` command to navigate to the directory where `bit_reversal.c` is saved.
4. **Compile the Code**: Use the following command to compile the code:
   ```sh
   gcc -o bit_reversal bit_reversal.c
