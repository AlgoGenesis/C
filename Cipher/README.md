# Affine Cipher Implementation in C

## Description

This project implements the Affine Cipher, a monoalphabetic substitution cipher, in C. The Affine Cipher is a type of cryptographic algorithm that combines multiplication and addition to encrypt plaintext. It's an improvement over the Caesar Cipher as it uses two keys instead of one, making it slightly more secure.

The encryption function for a single letter is:

E(x) = (ax + b) mod m

Where:
- x is the numeric value of the letter (A=0, B=1, ..., Z=25)
- a and b are the keys of the cipher
- m is the size of the alphabet (26 for English)
- a must be coprime with m

The decryption function is:

D(y) = a^(-1)(y - b) mod m

Where a^(-1) is the modular multiplicative inverse of a modulo m.

## Features

- Encrypt and decrypt messages using the Affine Cipher
- Handles uppercase and lowercase letters
- Preserves non-alphabetic characters
- Includes input validation for the 'a' key

## Complexity

The time complexity of the Affine Cipher implementation is O(n), where n is the length of the user input message, and it is because so that we can perform a constant amount of work for each character in the message during both encryption and decryption processes.

Space complexity is also O(n), as we store the input message and manipulate it in place.

The modular multiplicative inverse calculation in the `mod_inverse` function has a time complexity of O(m), where m is the modulus (26 in this case). However, since m is constant (always 26 for the English alphabet), this can be considered O(1) in practice.

## Usage

1. Compile the program:
   ```
   gcc affine_cipher.c -o affine_cipher
   ```

2. Run the program:
   ```
   ./affine_cipher
   ```

3. Follow the prompts to enter your message and the 'a' and 'b' keys.

4. The program will display the original message, encrypted message, and decrypted message.

Note: The value of 'a' must be coprime with 26 (valid values are 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25).

## Limitations

- The given implementation can only work with the 26 letters of the English alphabet.
- The security of the Affine Cipher is weak fi you compared it to the modern encryption standards. It should not be used for securing sensitive information.