# Vigenère Cipher Implementation in C

## Description

This project implements the Vigenère Cipher, a polyalphabetic substitution cipher. Named after Blaise de Vigenère, this cipher uses a keyword to shift each letter of the plaintext, making it significantly more secure than monoalphabetic ciphers like the Caesar Cipher.

## Features

- Encrypt and decrypt messages using the Vigenère Cipher
- Handles both uppercase and lowercase letters
- Preserves non-alphabetic characters
- Allows user to specify a keyword of any length

## Complexity

- Time Complexity: O(n), where n is the length of the input text
- Space Complexity: O(1), as the encryption is done in-place

## Usage

1. Compile the program:
   ```
   gcc program.c -o program.exe
   ```

2. Run the program:
   ```
   ./program
   ```

3. Follow the prompts to enter your message and the keyword.

4. The program will display the original text, encrypted text, and decrypted text.

## Limitations

- While more secure than simple substitution ciphers, the Vigenère Cipher can still be broken with sufficient ciphertext and computational power.
- It should not be used for securing sensitive information in modern applications.
- The implementation only works with the 26 letters of the English alphabet.