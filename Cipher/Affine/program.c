#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate modular multiplicative inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to encrypt a single character
char encrypt_char(char ch, int a, int b) {
    if (isalpha(ch)) {
        return (char)((((a * (ch - 'A')) + b) % ALPHABET_SIZE) + 'A');
    }
    return ch;
}

// Function to decrypt a single character
char decrypt_char(char ch, int a, int b) {
    if (isalpha(ch)) {
        int a_inv = mod_inverse(a, ALPHABET_SIZE);
        return (char)((a_inv * (ch - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE + 'A');
    }
    return ch;
}

// Function to encrypt an entire message
void encrypt(char *message, int a, int b) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = encrypt_char(toupper(message[i]), a, b);
    }
}

// Function to decrypt the message
void decrypt(char *message, int a, int b) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] = decrypt_char(toupper(message[i]), a, b);
    }
}

int main() {
    char message[1000];
    int a, b;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of 'b': ");
    scanf("%d", &b);

    if (mod_inverse(a, ALPHABET_SIZE) == -1) {
        printf("Error: 'a' is not coprime with 26\n");
        return 1;
    }

    printf("\nOriginal message: %s\n", message);

    encrypt(message, a, b);
    printf("Encrypted message: %s\n", message);

    decrypt(message, a, b);
    printf("Decrypted message: %s\n", message);

    return 0;
}