#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_MODULUS 23
#define BASE_GENERATOR 5


int mod_exp(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    
    int private_key_alice = 6;
    int private_key_bob = 15;

    int public_value_alice = mod_exp(BASE_GENERATOR, private_key_alice, PRIME_MODULUS);
    int public_value_bob = mod_exp(BASE_GENERATOR, private_key_bob, PRIME_MODULUS);

    printf("Alice sends Bob: %d\n", public_value_alice);
    printf("Bob sends Alice: %d\n", public_value_bob);

    int shared_secret_alice = mod_exp(public_value_bob, private_key_alice, PRIME_MODULUS);
    int shared_secret_bob = mod_exp(public_value_alice, private_key_bob, PRIME_MODULUS);

    printf("Shared secret key for Alice: %d\n", shared_secret_alice);
    printf("Shared secret key for Bob: %d\n", shared_secret_bob);

    return 0;
}

