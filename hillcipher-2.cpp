#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to encrypt a message using the Hill cipher
void hillCipherEncrypt(char *message, int key[2][2]) {
    int len = strlen(message);
    int i, j;
    int encrypted[len];

    for (i = 0; i < len; i += 2) {
        int p1 = message[i] - 'a';
        int p2 = (i + 1 < len) ? message[i + 1] - 'a' : 0;

        encrypted[i] = (key[0][0] * p1 + key[0][1] * p2) % 26;
        encrypted[i + 1] = (key[1][0] * p1 + key[1][1] * p2) % 26;
    }

    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", encrypted[i] + 'a');
    }
    printf("\n");
}

int main() {
    int key[2][2] = {
        {6, 24},
        {1, 13}
    };

    char message[] = "hello";

    for (int i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }

    hillCipherEncrypt(message, key);

    return 0;
}

