



# Huffman Encoding in C

This project implements Huffman Encoding, a lossless data compression algorithm, in the C programming language. The program reads a string from the user, calculates the frequency of each character, builds a Huffman Tree, generates Huffman codes, and encodes the input string using the generated codes.



## Features
- Reads an input string from the user.
- Calculates the frequency of each character in the input string.
- Builds a Huffman Tree using a priority queue (min-heap).
- Generates optimal binary Huffman codes for each character.
- Encodes the input string using these codes.
- Prints the encoded binary string and the generated Huffman codes.

## How Huffman Encoding Works
Huffman Encoding is a widely used compression technique based on the frequency of characters in a string. It assigns shorter codes to frequently occurring characters and longer codes to less frequent characters, minimizing the total number of bits required to represent the string.

### Steps:
1. *Frequency Calculation*: Determine the frequency of each character in the input string.
2. *Huffman Tree Construction*: Build a binary tree where each leaf node corresponds to a character and its frequency.
3. *Code Generation*: Traverse the Huffman Tree to generate binary codes for each character.
4. *Encoding*: Replace each character in the input string with its corresponding binary code.
   
## Installation and Compilation

### Prerequisites:
- A C compiler (like GCC)




# Usage
1. Run the program in your terminal.
2. Enter the string that you want to encode.
3. The program will display:
   - The Huffman code for each character.
   - The encoded binary string.

### Example:
```bash
$ ./huffman_encoding
Enter the string to encode: hello huffman
h: 000
e: 001
l: 01
o: 100
 : 101
f: 1100
m: 1101
a: 1110
n: 1111
Encoded string: 00000101010010110011101111
```

# Sample Output
Given the input string `hello huffman`, the output will look like this:

```
h: 000
e: 001
l: 01
o: 100
 : 101
f: 1100
m: 1101
a: 1110
n: 1111
Encoded string: 00000101010010110011101111
```

# Notes
- The Huffman encoding works optimally when there are multiple occurrences of characters. Single-character inputs may not benefit much from the compression.
- The program handles up to 256 unique characters (ASCII set).
- Memory management: The current implementation does not explicitly free dynamically allocated memory. Consider adding cleanup routines for more extensive use.

