# Caesar Cipher Implementation in C

## Description

This project implements the Caesar Cipher, one of the simplest and most widely known encryption techniques. Named after Julius Caesar, who used it in his private correspondence, the cipher is a type of substitution cipher where each letter in the plaintext is 'shifted' a certain number of places down the alphabet.

## Features

- Encrypt and decrypt messages using the Caesar Cipher
- Handles both uppercase and lowercase letters
- Preserves non-alphabetic characters
- Allows user to specify the shift value

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

3. Follow the prompts to enter your message and the shift value.

4. The program will display the original text, encrypted text, and decrypted text.

## Limitations

- The Caesar Cipher is very weak by modern standards and is easily broken.
- It should not be used for securing sensitive information.
- The implementation only works with the 26 letters of the English alphabet.