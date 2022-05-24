#include <stdio.h>
#include <string.h>

#include "rc4.h"


int main() {

    char* key = "hello world";
    int keylength = 11;

    struct RC4_State* state1 = new_rc4_state(key, keylength);
    struct RC4_State* state2 = new_rc4_state(key, keylength);
    struct RC4_State* state3 = new_rc4_state(key, keylength);

    char* plaintext = malloc(22 * sizeof(char));
    strcpy(plaintext, "THIS IS THE PLAINTEXT\n");
    char* ciphertext = malloc(22 * sizeof(char));
    strcpy(ciphertext, "THIS IS THE PLAINTEXT\n");
    char* decrypted = malloc(22 * sizeof(char));
    strcpy(decrypted, "THIS IS THE PLAINTEXT\n");

    encrypt(state1, ciphertext, 22);
    encrypt(state2, decrypted, 22);
    encrypt(state3, decrypted, 22);

    printf("%s\n%s\n%s\n", plaintext, ciphertext, decrypted);

    return 0;
}
