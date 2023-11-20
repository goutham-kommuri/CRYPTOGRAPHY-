#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char message[], char key[]);

int main() {
    char message[100];
    char key[26];

    // Input the message
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    // Input the key (ciphertext alphabet)
    printf("Enter the key (ciphertext alphabet): ");
    fgets(key, sizeof(key), stdin);

    // Ensure the key is in uppercase
    for (int i = 0; i < 26; i++) {
        key[i] = toupper(key[i]);
    }

    // Check if the key is valid (contains each letter exactly once)
    for (char c = 'A'; c <= 'Z'; c++) {
        if (strchr(key, c) == NULL) {
            printf("Error: Invalid key. The key must contain each letter of the alphabet exactly once.\n");
            return 1;
        }
    }

    // Encrypt the message
    encrypt(message, key);

    return 0;
}

void encrypt(char message[], char key[]) {
    int i;
    char encrypted[100];

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            // Encrypt alphabetic characters
            char base = (isupper(message[i])) ? 'A' : 'a';
            encrypted[i] = key[message[i] - base];
        } else {
            // Keep non-alphabetic characters unchanged
            encrypted[i] = message[i];
        }
    }

    // Null-terminate the encrypted string
    encrypted[i] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);
}

