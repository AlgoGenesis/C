# Caesar Cipher

## Description

The Caesar cipher is a simple and classic encryption technique that shifts the letters of the plaintext by a fixed number of positions in the alphabet. Named after Julius Caesar, who reportedly used it for secure communication, this substitution cipher is easy to understand and implement.

## Steps

1. **Choose a Shift Value**: Select a number that represents how many positions each letter will be shifted. Common values include 1, 3, or 13.
  
2. **Encrypt the Message**:
   - For each letter in the plaintext:
     - Convert the letter to its corresponding position in the alphabet (A=0, B=1, ..., Z=25).
     - Shift the letter by the chosen value.
     - Wrap around to the beginning of the alphabet if necessary (e.g., shifting from Z back to A).
  
3. **Handle Non-Alphabetic Characters**: Non-alphabetic characters (like spaces, punctuation, etc.) remain unchanged.

4. **Return the Encrypted Message**: Combine the shifted letters and unchanged characters to form the ciphertext.

### Time Complexity

The time complexity of the Caesar cipher is O(n), where n is the length of the input text. This makes it efficient for short messages.

### Security
The Caesar cipher is not secure by modern standards due to:

- A limited number of possible shifts (only 25).
- Vulnerability to brute-force and frequency analysis attacks.
