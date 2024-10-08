# SDBM Hash Algorithm

## Description

The SDBM (Simple DataBase Manager) hash algorithm computes a hash value for a given string using a combination of multiplication and addition operations. It processes each character in the string to generate a hash that is efficient and spreads values uniformly across a range. This algorithm is commonly used in hash tables and other data structures.

## Steps

1. **Initialize Hash Value**: Start with a hash value (`hash_value`) set to `0`.
2. **Iterate Through Characters**: For each character in the input string:
   - Convert the character to its ASCII value using `ord()`.
   - Update the hash value using the formula:
     \[
     \text{hash\_value} = \text{hash\_value} \times 65599 + \text{ASCII value}
     \]
3. **Return the Final Hash Value**: After processing all characters, return the final `hash_value`.

### Time Complexity

The time complexity of the SDBM hash algorithm is O(n), where n is the length of the input string. 
This means it processes each character once, making it efficient for hashing strings of varying lengths.

### Use Cases
The SDBM hash algorithm is suitable for:

- Hash tables for quick data retrieval.
- Checksums for verifying data integrity.
- Any application needing a simple yet effective hash function.
