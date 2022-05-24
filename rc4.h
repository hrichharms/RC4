#include <stdio.h>
#include <stdlib.h>


struct RC4_State {
    unsigned char* S;
    int i, j;
};


char* ksa(char* key, int keylength) {

    unsigned char* S = calloc(256, sizeof(char));

    for (int i=0; i<256; i++) {
        S[i] = i;
    }

    int j = 0;
    unsigned char temp;
    for (int i=0; i<256; i++) {
        j = (j + S[i] + key[i % keylength]) % 256;

        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    return S;
}


struct RC4_State* new_rc4_state(char* key, int keylength) {

    struct RC4_State* new_state = malloc(sizeof(struct RC4_State));
    new_state->i = 0;
    new_state->j = 0;

    new_state->S = ksa(key, keylength);

    return new_state;

}


unsigned char pgra(struct RC4_State* state) {
    state->i = (state->i + 1) % 256;
    state->j = (state->j + state->S[state->i]) % 256;

    unsigned char temp;
    temp = state->S[state->i];
    state->S[state->i] = state->S[state->j];
    state->S[state->j] = temp;

    return state->S[(state->S[state->i] + state->S[state->j]) % 256];
}


void encrypt(struct RC4_State* state, unsigned char* plaintext, int plaintext_len) {
    for (int i=0; i<plaintext_len; i++) {
        plaintext[i] = plaintext[i] ^ pgra(state);
    }
}
