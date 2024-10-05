#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesar_encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        
        // Encrypt uppercase letters
        if (isupper(ch)) {
            ciphertext[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            ciphertext[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Keep non-alphabetic characters unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext string
}

void caesar_decrypt(char *ciphertext, int shift, char *plaintext) {
    caesar_encrypt(ciphertext, 26 - (shift % 26), plaintext); // Decrypt by shifting backwards
}

int main() {
    char plaintext[] = "HELLO, WORLD!";
    int shift = 3;
    char ciphertext[100];
    char decrypted[100];

    caesar_encrypt(plaintext, shift, ciphertext);
    caesar_decrypt(ciphertext, shift, decrypted);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
