#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptVigenere(char plaintext[], char key[]);
char shift(char ch, int key);

int main() {
    char plaintext[100];
    char key[100];

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Input the key
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    strtok(plaintext, "\n");
    strtok(key, "\n");

    // Convert both plaintext and key to uppercase
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = toupper(plaintext[i]);
    }
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the plaintext using the Vigenère cipher
    encryptVigenere(plaintext, key);

    return 0;
}

void encryptVigenere(char plaintext[], char key[]) {
    printf("\nEncrypted Text: ");

    int keyLength = strlen(key);
    int j = 0;

    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            char encryptedChar = shift(plaintext[i], key[j] - 'A');
            printf("%c", encryptedChar);
            j = (j + 1) % keyLength;
        } else {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}

char shift(char ch, int key) {
    return (ch - 'A' + key) % 26 + 'A';
}

