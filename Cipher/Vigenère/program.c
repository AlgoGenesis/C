#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void vigenere_cipher(char *text, char *key, int encrypt) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int shift = toupper(key[j % key_len]) - 'A';
            if (!encrypt) shift = ALPHABET_SIZE - shift;
            text[i] = (text[i] - base + shift) % ALPHABET_SIZE + base;
            j++;
        }
    }
}

int main() {
    char text[1000], key[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove newline

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;  // Remove newline

    printf("Original text: %s\n", text);

    vigenere_cipher(text, key, 1);  // Encrypt
    printf("Encrypted text: %s\n", text);

    vigenere_cipher(text, key, 0);  // Decrypt
    printf("Decrypted text: %s\n", text);

    return 0;
}