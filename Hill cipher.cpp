#include <stdio.h>
#include <string.h>
#include <cctype>  

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
        {9, 4},
        {5, 7}
    };

    
    char message[] = "meet me at the usual place at ten rather than eight oclock";

   
    for (int i = 0; message[i]; i++) {
        message[i] = tolower(message[i]);
    }

    
    hillCipherEncrypt(message, key);0

    return 0;
}

