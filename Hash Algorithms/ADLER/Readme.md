# 32-bit Adler-32 Checksum

## Description

Adler-32 is a checksum algorithm that was originally designed for use in the zlib compression library. It combines the simplicity of the checksum with a good balance of speed and error detection capabilities. The Adler-32 checksum is particularly useful for data integrity checks and is known for its efficiency.

## How It Works

The Adler-32 algorithm calculates a checksum by maintaining two values: a sum of the bytes modulo 65521 (the largest prime number less than 65536) and a second sum that accumulates the first sum.

### Steps

1. **Initialize Values**:
   - Set `A` to `1` (the first part of the checksum).
   - Set `B` to `0` (the second part of the checksum).
   
2. **Process Input Data**: For each byte in the input data:
   - Update `A` and `B`:
     - `A = (A + byte) % 65521`
     - `B = (B + A) % 65521`

3. **Combine Values**: The final Adler-32 checksum is computed as:
   \[
   \text{checksum} = (B << 16) | A
   \]
   This combines both parts into a single 32-bit value.

### Time Complexity

The time complexity of the Adler-32 algorithm is O(n), where n is the length of the input data. This efficiency makes it suitable for large datasets.

### Use Cases
Adler-32 is commonly used in:

- Data compression algorithms (e.g., zlib).
- File integrity checks.
- Network protocols for error detection.
