#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate letter frequencies in a given text
void calculateFrequency(char *text, int *frequency) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            frequency[tolower(text[i]) - 'a']++;
        }
    }
}

// Function to perform letter frequency attack
void letterFrequencyAttack(char *ciphertext, int topResults) {
    int frequency[ALPHABET_SIZE] = {0};
    calculateFrequency(ciphertext, frequency);

    // Create a mapping of letters to their frequencies
    struct LetterFrequency {
        char letter;
        int count;
    };

    struct LetterFrequency letterFrequencies[ALPHABET_SIZE];

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        letterFrequencies[i].letter = 'a' + i;
        letterFrequencies[i].count = frequency[i];
    }

    // Sort the array of letter frequencies in descending order
    for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
        for (int j = i + 1; j < ALPHABET_SIZE; j++) {
            if (letterFrequencies[i].count < letterFrequencies[j].count) {
                struct LetterFrequency temp = letterFrequencies[i];
                letterFrequencies[i] = letterFrequencies[j];
                letterFrequencies[j] = temp;
            }
        }
    }

    // Output the topResults possible plaintexts
    for (int i = 0; i < topResults; i++) {
        printf("Possible Plaintext #%d: ", i + 1);

        for (int j = 0; ciphertext[j] != '\0'; j++) {
            if (isalpha(ciphertext[j])) {
                char decryptedChar = 'a' + (tolower(ciphertext[j]) - 'a' + letterFrequencies[i].letter - 'a') % ALPHABET_SIZE;
                if (isupper(ciphertext[j])) {
                    decryptedChar = toupper(decryptedChar);
                }
                printf("%c", decryptedChar);
            } else {
                printf("%c", ciphertext[j]);
            }
        }

        printf("\n");
    }
}

int main() {
    char ciphertext[] = "GIVESMALLER";
    int topResults = 10;

    letterFrequencyAttack(ciphertext, topResults);

    return 0;
}

