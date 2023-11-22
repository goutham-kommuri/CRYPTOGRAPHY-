#include <stdio.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

void breakAffineCipher(int ciphertextB, int ciphertextU, int m) {
    // Find a such that a * x1 % m = ciphertextB and a * x2 % m = ciphertextU
    int a, b;

    // Brute force through possible values of a
    for (a = 1; a < m; a++) {
        if ((a * modInverse(a, m)) % m == 1) {
            // a and a^-1 are coprime
            break;
        }
    }

    // Calculate b using the given equations
    b = (ciphertextB - a) % m;
    if (b < 0) {
        b += m;
    }

    printf("Key parameters found: a = %d, b = %d\n", a, b);
}

int main() {
    // Input ciphertext values for 'B' and 'U'
    int ciphertextB, ciphertextU;
    
    printf("Enter the ciphertext value for 'B': ");
    scanf("%d", &ciphertextB);

    printf("Enter the ciphertext value for 'U': ");
    scanf("%d", &ciphertextU);

    int m = 26; // Size of the English alphabet

    breakAffineCipher(ciphertextB, ciphertextU, m);

    return 0;
}

