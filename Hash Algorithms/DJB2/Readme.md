# DJB2 Hash Algorithm

## Description

The DJB2 algorithm is a widely used hashing function created by Daniel J. Bernstein. It is particularly effective for generating hash values from strings and is often employed in hash tables and similar data structures. The algorithm combines bitwise operations and arithmetic to produce a hash value that distributes inputs uniformly.

## Steps

1. **Initialize Hash Value**: Start with a hash value (`hash_value`) set to a specific constant, typically `5381`.
2. **Iterate Through Characters**: For each character in the input string:
   - Convert the character to its ASCII value using `ord()`.
   - Update the hash value using the formula:
     \[
     \text{hash\_value} = ((\text{hash\_value} << 5) + \text{hash\_value}) + \text{ASCII value}
     \]
   - This can also be expressed as:
     \[
     \text{hash\_value} = \text{hash\_value} \times 33 + \text{ASCII value}
     \]
3. **Return the Final Hash Value**: After processing all characters, return the final `hash_value`.

### Time Complexity

The time complexity of the DJB2 hash algorithm is O(n), where n is the length of the input string. This means it processes each character once, making it efficient for hashing strings of various lengths.

### Use Cases
The DJB2 hash algorithm is suitable for:

- Hash tables for fast data retrieval.
- Checksums for verifying data integrity.
- General-purpose hashing in applications where speed and distribution are important.
