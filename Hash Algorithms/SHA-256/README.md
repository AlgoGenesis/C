# SHA-256 Hashing Algorithm 

## Overview

SHA-256 (Secure Hash Algorithm 256-bit) is a member of the SHA-2 family of cryptographic hash functions. It produces a fixed 256-bit (32-byte) hash value, regardless of input size, and is widely used for data integrity verification, password hashing, digital signatures, and blockchain applications. SHA-256 is known for its strong resistance to pre-image and collision attacks, making it a secure choice for cryptographic operations.

---

## Key Features

- **Fixed Output Size**: SHA-256 generates a `256-bit` (32-byte) hash value.
- **Deterministic**: The same input always results in the same output hash.
- **Collision-Resistant**: Designed to prevent two different inputs from producing the same hash.
- **Efficient**: Computation of the hash is fast, making it suitable for real-time applications.
- **Widely Supported**: Used in many security protocols, such as TLS, SSL, and digital certificates.

---

## Problem Definition

Given any input message, the SHA-256 algorithm aims to generate a unique `256-bit` hash that:

1. **Is Irreversible**: Cannot be converted back to the original message.
2. **Is Collision-Resistant**: Prevents two different messages from producing the same hash.
3. **Is Uniformly Distributed**: Ensures small changes in input yield completely different hash outputs (avalanche effect).

### Input
- Any binary data (text, files, etc.) of arbitrary length.

### Output
- A fixed `256-bit` (32-byte) hash representing the original data uniquely and securely.

---

## Algorithm Steps

### 1. Pre-Processing
   - **Padding**: Add padding bits to make the message length a multiple of 512 bits. Append a `1` bit, followed by `0`s, and finally the length of the message in bits as a `64-bit` integer.
   - **Message Parsing**: Divide the padded message into `512-bit` blocks.

### 2. Initialize Hash Values
   - Use eight constant `32-bit` words as the initial hash values:
     ```plaintext
     H0 = 0x6a09e667, H1 = 0xbb67ae85, H2 = 0x3c6ef372, H3 = 0xa54ff53a,
     H4 = 0x510e527f, H5 = 0x9b05688c, H6 = 0x1f83d9ab, H7 = 0x5be0cd19
     ```

### 3. Initialize Round Constants
   - Use 64 constant `32-bit` words (derived from cube roots of the first 64 primes), denoted as `K[0]` to `K[63]`.

### 4. Process Each 512-bit Block
   - **Message Schedule Array**: Create an array `W[0]` to `W[63]` for each 512-bit block:
     - First 16 words are directly derived from the `512-bit` block.
     - Remaining words are generated using specific functions to mix the previous values.

   - **Compression Function**: Iterate through 64 rounds of processing for each `512-bit` block:
     - Perform bitwise operations, shifts, and modular additions on the eight hash values using the `K` constants and `W` words.
     - Update hash values through the rounds, ensuring diffusion and avalanche effect.

### 5. Concatenate Final Hash
   - After processing all blocks, concatenate the final values of `H0` through `H7` to form the final `256-bit` hash.

---

## Mathematical Functions Used

SHA-256 relies on several logical functions to mix data and increase security:

- **Ch**: `Ch(x, y, z) = (x AND y) XOR (NOT x AND z)`
- **Maj**: `Maj(x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)`
- **Σ0** and **Σ1**: Rotate and XOR operations for mixing message schedule values.
- **σ0** and **σ1**: Rotate and XOR operations for further scrambling message blocks.

---

## Example Code (Simplified in C)

Here’s a high-level outline of SHA-256 implementation in C (full implementation requires detailed bitwise operations and block processing).

```c
#include <stdint.h>
#include <string.h>

void sha256(uint8_t *message, uint32_t length, uint8_t hash[32]) {
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // 1. Padding and parsing into 512-bit blocks.
    // 2. Initialize round constants K[0] through K[63].
    // 3. Process each 512-bit block:
    //    - Message schedule W[0] through W[63]
    //    - Compression function using Ch, Maj, Σ0, Σ1, σ0, σ1
    // 4. Concatenate H[0] through H[7] to form final hash.
}
```

markdown
Copy code
# SHA-256 Hashing Algorithm Documentation

## Overview

SHA-256 (Secure Hash Algorithm 256-bit) is a member of the SHA-2 family of cryptographic hash functions. It produces a fixed `256-bit` (32-byte) hash value, regardless of input size, and is widely used for data integrity verification, password hashing, digital signatures, and blockchain applications. 
SHA-256 is known for its strong resistance to pre-image and collision attacks, making it a secure choice for cryptographic operations.

---

## Key Features

- **Fixed Output Size**: SHA-256 generates a 256-bit (32-byte) hash value.
- **Deterministic**: The same input always results in the same output hash.
- **Collision-Resistant**: Designed to prevent two different inputs from producing the same hash.
- **Efficient**: Computation of the hash is fast, making it suitable for real-time applications.
- **Widely Supported**: Used in many security protocols, such as TLS, SSL, and digital certificates.

---

## Problem Definition

Given any input message, the SHA-256 algorithm aims to generate a unique 256-bit hash that:

1. **Is Irreversible**: Cannot be converted back to the original message.
2. **Is Collision-Resistant**: Prevents two different messages from producing the same hash.
3. **Is Uniformly Distributed**: Ensures small changes in input yield completely different hash outputs (avalanche effect).

### Input
- Any binary data (text, files, etc.) of arbitrary length.

### Output
- A fixed 256-bit (32-byte) hash representing the original data uniquely and securely.

---

## Algorithm Steps

### 1. Pre-Processing
   - **Padding**: Add padding bits to make the message length a multiple of 512 bits. Append a `1` bit, followed by `0`s, and finally the length of the message in bits as a 64-bit integer.
   - **Message Parsing**: Divide the padded message into 512-bit blocks.

### 2. Initialize Hash Values
   - Use eight constant 32-bit words as the initial hash values:
     ```plaintext
     H0 = 0x6a09e667, H1 = 0xbb67ae85, H2 = 0x3c6ef372, H3 = 0xa54ff53a,
     H4 = 0x510e527f, H5 = 0x9b05688c, H6 = 0x1f83d9ab, H7 = 0x5be0cd19
     ```

### 3. Initialize Round Constants
   - Use 64 constant 32-bit words (derived from cube roots of the first 64 primes), denoted as `K[0]` to `K[63]`.

### 4. Process Each 512-bit Block
   - **Message Schedule Array**: Create an array `W[0]` to `W[63]` for each 512-bit block:
     - First 16 words are directly derived from the 512-bit block.
     - Remaining words are generated using specific functions to mix the previous values.

   - **Compression Function**: Iterate through 64 rounds of processing for each 512-bit block:
     - Perform bitwise operations, shifts, and modular additions on the eight hash values using the `K` constants and `W` words.
     - Update hash values through the rounds, ensuring diffusion and avalanche effect.

### 5. Concatenate Final Hash
   - After processing all blocks, concatenate the final values of `H0` through `H7` to form the final 256-bit hash.

---

## Mathematical Functions Used

SHA-256 relies on several logical functions to mix data and increase security:

- **Ch**: `Ch(x, y, z) = (x AND y) XOR (NOT x AND z)`
- **Maj**: `Maj(x, y, z) = (x AND y) XOR (x AND z) XOR (y AND z)`
- **Σ0** and **Σ1**: Rotate and XOR operations for mixing message schedule values.
- **σ0** and **σ1**: Rotate and XOR operations for further scrambling message blocks.

---

## Example Code (Simplified in C)

Here’s a high-level outline of SHA-256 implementation in C (full implementation requires detailed bitwise operations and block processing).

```c
#include <stdint.h>
#include <string.h>

void sha256(uint8_t *message, uint32_t length, uint8_t hash[32]) {
    uint32_t H[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // 1. Padding and parsing into 512-bit blocks.
    // 2. Initialize round constants K[0] through K[63].
    // 3. Process each 512-bit block:
    //    - Message schedule W[0] through W[63]
    //    - Compression function using Ch, Maj, Σ0, Σ1, σ0, σ1
    // 4. Concatenate H[0] through H[7] to form final hash.
}
```
## Applications
SHA-256 is widely used in areas requiring data integrity and secure hashing, such as:

  - **Digital Signatures:** Ensures document authenticity.
  - **Blockchain:** Used in transaction verification in cryptocurrencies.
  - **Password Hashing:** Secures stored passwords in databases.
  - **File Verification:** Ensures file integrity during transfer or storage.

## Security and Performance

SHA-256 is designed for high security but is not resistant to certain high-powered brute-force attacks.
While SHA-256 is secure for most applications, newer standards like SHA-3 are also recommended for added resilience against future advancements in computational power.

## Conclusion

SHA-256 is a highly secure, reliable, and efficient hashing algorithm. 
Its widespread adoption and strong collision resistance make it suitable for applications in cryptography, data verification, and blockchain technology. 
With a simple yet effective mechanism, SHA-256 offers robust security without sacrificing performance.

Keep coding...!
