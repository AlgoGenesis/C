# Huffman Coding

## Description

Huffman Coding is a popular algorithm used for data compression. It assigns variable-length codes to input characters based on their frequencies, with shorter codes assigned to more frequent characters. This method reduces the overall size of the data, making it an efficient way to store and transmit information.

### Problem Definition

Given:
- A string of characters with their corresponding frequencies.

Objective:
- Generate a prefix code (Huffman code) for each character that minimizes the total length of the encoded string.

### Algorithm Overview

1. **Build a Frequency Table**: Count the frequency of each character in the input string.
2. **Create a Priority Queue**: Insert all characters into a priority queue based on their frequencies.
3. **Build the Huffman Tree**:
   - While there is more than one node in the queue:
     - Remove the two nodes of the lowest frequency.
     - Create a new internal node with these two nodes as children and with a frequency equal to the sum of their frequencies.
     - Insert the new node back into the priority queue.
4. **Generate Codes**: Traverse the Huffman tree to generate binary codes for each character, where left edges correspond to '0' and right edges correspond to '1'.
5. **Encode the String**: Replace each character in the input string with its corresponding Huffman code.

### Time Complexity

The time complexity of Huffman Coding is \( O(n \log n) \), where \( n \) is the number of unique characters in the input string.

