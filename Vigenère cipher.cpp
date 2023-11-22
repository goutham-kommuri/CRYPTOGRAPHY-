#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
void generateKey(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + rand() % 26; 
    }
    key[length] = '\0';
}
void encryptVigenere(char *plaintext, char *key, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + key[i] - 'A') % 26 + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

// Function to perform one-time pad Vigenère decryption
void decryptVigenere(char *ciphertext, char *key, char *decryptedtext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            decryptedtext[i] = (ciphertext[i] - key[i] + 26) % 26 + base;
        } else {
            decryptedtext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[] = "HELLO";
    int plaintextLength = strlen(plaintext);

    char key[plaintextLength + 1];
    generateKey(key, plaintextLength);

    char ciphertext[plaintextLength + 1];
    encryptVigenere(plaintext, key, ciphertext);

    char decryptedtext[plaintextLength + 1];
    decryptVigenere(ciphertext, key, decryptedtext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key:       %s\n", key);
    printf("Ciphertext:%s\n", ciphertext);
    printf("Decrypted: %s\n", decryptedtext);

    return 0;
}

