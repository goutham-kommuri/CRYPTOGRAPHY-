#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void createPlayfairMatrix(char key[], char matrix[SIZE][SIZE]);
void encryptPlayfair(char matrix[SIZE][SIZE], char plaintext[]);

int main() {
    char key[25];
    char matrix[SIZE][SIZE];
    char plaintext[100];

    // Input the key
    printf("Enter the key (without spaces, up to 25 characters): ");
    scanf("%s", key);

    // Input the plaintext
    printf("Enter the plaintext (without spaces): ");
    scanf("%s", plaintext);

    // Convert key to uppercase
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Create Playfair matrix
    createPlayfairMatrix(key, matrix);

    // Encrypt the plaintext
    encryptPlayfair(matrix, plaintext);

    return 0;
}

void createPlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int keyLength = strlen(key);
    int k = 0;

    // Fill the matrix with the key
    for (int i = 0; i < keyLength; i++) {
        int row = k / SIZE;
        int col = k % SIZE;
        matrix[row][col] = key[i];
        k++;
    }

    // Fill the remaining matrix with the remaining alphabet
    for (int i = 0; i < 26; i++) {
        if (strchr(key, alphabet[i]) == NULL) {
            int row = k / SIZE;
            int col = k % SIZE;
            matrix[row][col] = alphabet[i];
            k++;
        }
    }

    // Print the matrix
    printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void encryptPlayfair(char matrix[SIZE][SIZE], char plaintext[]) {
    printf("\nEncrypted Text:\n");

    for (int i = 0; i < strlen(plaintext); i += 2) {
        char first = plaintext[i];
        char second = (i + 1 < strlen(plaintext)) ? plaintext[i + 1] : 'X';

        // Find positions of the characters in the matrix
        int row1, col1, row2, col2;
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (matrix[row][col] == first) {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == second) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Same row
        if (row1 == row2) {
            printf("%c%c ", matrix[row1][(col1 + 1) % SIZE], matrix[row2][(col2 + 1) % SIZE]);
        }
        // Same column
        else if (col1 == col2) {
            printf("%c%c ", matrix[(row1 + 1) % SIZE][col1], matrix[(row2 + 1) % SIZE][col2]);
        }
        // Different row and column
        else {
            printf("%c%c ", matrix[row1][col2], matrix[row2][col1]);
        }
    }

    printf("\n");
}

