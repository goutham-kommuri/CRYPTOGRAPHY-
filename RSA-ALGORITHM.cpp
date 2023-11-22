#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RSA_KEY_BITS 2048

// Function to generate RSA key pair
RSA* generateRSAKeyPair() {
    RSA *rsa = RSA_generate_key(RSA_KEY_BITS, RSA_F4, NULL, NULL);
    return rsa;
}

// Function to perform RSA encryption
int rsaEncrypt(const char *plaintext, const RSA *key, char *ciphertext) {
    int len = RSA_public_encrypt(strlen(plaintext) + 1, (const unsigned char *)plaintext, (unsigned char *)ciphertext, key, RSA_PKCS1_PADDING);
    return len;
}

// Function to perform RSA decryption
int rsaDecrypt(const char *ciphertext, const RSA *key, char *decryptedtext) {
    int len = RSA_private_decrypt(RSA_size(key), (const unsigned char *)ciphertext, (unsigned char *)decryptedtext, key, RSA_PKCS1_PADDING);
    return len;
}

int main() {
    // Generate RSA key pair
    RSA *rsaKeyPair = generateRSAKeyPair();

    // Original message
    const char *plaintext = "Hello, RSA!";

    // Buffer for ciphertext and decrypted text
    char ciphertext[RSA_size(rsaKeyPair)];
    char decryptedtext[RSA_size(rsaKeyPair)];

    // Encrypt the message
    int ciphertextLen = rsaEncrypt(plaintext, rsaKeyPair, ciphertext);
    if (ciphertextLen == -1) {
        fprintf(stderr, "Encryption failed\n");
        return 1;
    }

    printf("Original Message: %s\n", plaintext);
    printf("Encrypted Message: ");

    for (int i = 0; i < ciphertextLen; i++) {
        printf("%02X", ciphertext[i]);
    }

    printf("\n");

    // Decrypt the message
    int decryptedtextLen = rsaDecrypt(ciphertext, rsaKeyPair, decryptedtext);
    if (decryptedtextLen == -1) {
        fprintf(stderr, "Decryption failed\n");
        return 1;
    }

    printf("Decrypted Message: %s\n", decryptedtext);

    // Clean up
    RSA_free(rsaKeyPair);

    return 0;
}

